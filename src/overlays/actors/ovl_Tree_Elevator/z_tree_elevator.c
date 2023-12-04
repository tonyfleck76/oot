/*
 * File: z_tree_elevator.c
 * Overlay: ovl_Tree_Elevator
 * Description: Switch-controlled elevator that looks like a tree
 */

#include "z_tree_elevator.h"
#include "assets/objects/object_tree_elevator/gTreeElevatorDL.h"
#include "assets/objects/object_tree_elevator/gTreeElevatorDL_collision.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

#define SWITCH_FLAG(this) (this->dyna.actor.params & 0x3F)
#define TREE_ELEVATOR_TRAVEL_DURATION 60
#define TREE_ELEVATOR_MAX_HEIGHT 180.0f

void TreeElevator_Init(Actor* thisx, PlayState* play);
void TreeElevator_Destroy(Actor* thisx, PlayState* play);
void TreeElevator_Update(Actor* thisx, PlayState* play);
void TreeElevator_Draw(Actor* thisx, PlayState* play);

void TreeElevator_SpawnDust(TreeElevator* this, PlayState* play);

void TreeElevator_SetupWaitForSwitch(TreeElevator* this, PlayState* play);
void TreeElevator_WaitForSwitch(TreeElevator* this, PlayState* play);

void TreeElevator_SetupRaise(TreeElevator* this, PlayState* play);
void TreeElevator_Raise(TreeElevator* this, PlayState* play);

void TreeElevator_SetupWaitToLower(TreeElevator* this, PlayState* play);
void TreeElevator_WaitToLower(TreeElevator* this, PlayState* play);

void TreeElevator_SetupLower(TreeElevator* this, PlayState* play);
void TreeElevator_Lower(TreeElevator* this, PlayState* play);

const ActorInit Tree_Elevator_InitVars = {
    ACTOR_TREE_ELEVATOR,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_TREE_ELEVATOR,
    sizeof(TreeElevator),
    (ActorFunc)TreeElevator_Init,
    (ActorFunc)TreeElevator_Destroy,
    (ActorFunc)TreeElevator_Update,
    (ActorFunc)TreeElevator_Draw
};

void TreeElevator_Init(Actor* thisx, PlayState* play) {
    TreeElevator* this = (TreeElevator*)thisx;

    CollisionHeader* colHeader = NULL;
    CollisionHeader_GetVirtual(&gTreeElevatorDL_collisionHeader, &colHeader);

    this->dyna.bgId = DynaPoly_SetBgActor(play, &play->colCtx.dyna, &this->dyna.actor, colHeader);

    TreeElevator_SetupWaitForSwitch(this, play);
}

void TreeElevator_Destroy(Actor* thisx, PlayState* play) {
    TreeElevator* this = (TreeElevator*)thisx;
    DynaPoly_DeleteBgActor(play, &play->colCtx.dyna, this->dyna.bgId);
}

void TreeElevator_Update(Actor* thisx, PlayState* play) {
    TreeElevator* this = (TreeElevator*)thisx;
    
    this->actionFunc(this, play);
}

void TreeElevator_Draw(Actor* thisx, PlayState* play) {
    TreeElevator* this = (TreeElevator*)thisx;
    Gfx_DrawDListOpa(play, gTreeElevatorDL);
}

void TreeElevator_SpawnDust(TreeElevator* this, PlayState* play) {
    Color_RGBA8 primColor = { 170, 130, 90, 255 };
    Color_RGBA8 envColor = { 100, 60, 20, 255 };
    s16 offsets[] = { 
        DEG_TO_BINANG(0.0f), 
        DEG_TO_BINANG(90.0f), 
        DEG_TO_BINANG(180.0f), 
        DEG_TO_BINANG(270.0f) 
    };

    Vec3f pos;
    Vec3f velocity = { 0.0f, 1.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.0f, 0.0f };
    s16 scale = 400;
    s16 scaleStep = 100;
    s16 life = 20;

    for (u8 i = 0; i < ARRAY_COUNT(offsets); i++) {
        pos = this->dyna.actor.home.pos;
        pos.x += Math_SinS(this->dyna.actor.shape.rot.y + offsets[i]) * 110.0f;
        pos.z += Math_CosS(this->dyna.actor.shape.rot.y + offsets[i]) * 110.0f;

        f32 randomDist = Rand_ZeroOne() * 2.0f;
        s16 randomAngle = Rand_S16Offset(0, DEG_TO_BINANG(360.0f));
        velocity.x = Math_SinS(randomAngle) * randomDist;
        velocity.z = Math_CosS(randomAngle) * randomDist;

        pos.x += Math_SinS(randomAngle) * randomDist;
        pos.z += Math_CosS(randomAngle) * randomDist;
        

        EffectSsDust_Spawn(play, 0, &pos, &velocity, &accel, &primColor, &envColor, scale, scaleStep, life, 0);
    }
}

// Accepts a value between 0 and 1
// returns a smoothed step value instead
f32 TreeElevator_SmoothStep(f32 x) {
    x = CLAMP(x, 0.0f, 1.0f);
    return x * x * x * (x * (x * 6.0f - 15.0f) + 10.0f);
}

void TreeElevator_SetupWaitForSwitch(TreeElevator* this, PlayState* play) {
    this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y;
    Flags_UnsetSwitch(play, SWITCH_FLAG(this));
    this->actionFunc = TreeElevator_WaitForSwitch;
}

void TreeElevator_WaitForSwitch(TreeElevator* this, PlayState* play) {
    if (Flags_GetSwitch(play, SWITCH_FLAG(this))) {
        TreeElevator_SetupRaise(this, play);
    }
}

void TreeElevator_SetupRaise(TreeElevator* this, PlayState* play) {
    this->timer = TREE_ELEVATOR_TRAVEL_DURATION;
    this->actionFunc = TreeElevator_Raise;
}

void TreeElevator_Raise(TreeElevator* this, PlayState* play) {
    f32 step = (TREE_ELEVATOR_TRAVEL_DURATION - this->timer) / ((f32)TREE_ELEVATOR_TRAVEL_DURATION);
    f32 offset = TREE_ELEVATOR_MAX_HEIGHT * TreeElevator_SmoothStep(step);
    this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + offset;

    if (DECR(this->timer) == 0) {
        TreeElevator_SetupWaitToLower(this, play);
    } else {
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_ELEVATOR_MOVE3 - SFX_FLAG);

        if (this->timer < TREE_ELEVATOR_TRAVEL_DURATION - 10 && this->timer > 10) {
            TreeElevator_SpawnDust(this, play);
        }
    }
}

void TreeElevator_SetupWaitToLower(TreeElevator* this, PlayState* play) {
    this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y + TREE_ELEVATOR_MAX_HEIGHT;
    this->timer = 20 * 5;
    Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BLOCK_BOUND);
    this->actionFunc = TreeElevator_WaitToLower;
}

void TreeElevator_WaitToLower(TreeElevator* this, PlayState* play) {
    if (DECR(this->timer) == 0) {
        TreeElevator_SetupLower(this, play);
    }
}

void TreeElevator_SetupLower(TreeElevator* this, PlayState* play) {
    this->timer = TREE_ELEVATOR_TRAVEL_DURATION;
    this->actionFunc = TreeElevator_Lower;
}

void TreeElevator_Lower(TreeElevator* this, PlayState* play) {
    f32 step = this->timer / ((f32)TREE_ELEVATOR_TRAVEL_DURATION);
    f32 offset = TREE_ELEVATOR_MAX_HEIGHT * TreeElevator_SmoothStep(step);
    this->dyna.actor.world.pos.y = this->dyna.actor.home.pos.y  + offset;

    if (DECR(this->timer) == 0) {
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_BLOCK_BOUND);
        TreeElevator_SetupWaitForSwitch(this, play);
    } else {
        Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_ELEVATOR_MOVE3 - SFX_FLAG);

        if ((this->timer < TREE_ELEVATOR_TRAVEL_DURATION - 10 && this->timer > 10)) {
            TreeElevator_SpawnDust(this, play);
        }
    }
}
