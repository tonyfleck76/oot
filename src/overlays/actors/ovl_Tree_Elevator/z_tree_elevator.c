/*
 * File: z_tree_elevator.c
 * Overlay: ovl_Tree_Elevator
 * Description: Switch-controlled elevator that looks like a tree
 */

#include "z_tree_elevator.h"
#include "assets/objects/object_tree_elevator/gTreeElevatorDL.h"
#include "assets/objects/object_tree_elevator/gTreeElevatorDL_collision.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)

void TreeElevator_Init(Actor* thisx, PlayState* play);
void TreeElevator_Destroy(Actor* thisx, PlayState* play);
void TreeElevator_Update(Actor* thisx, PlayState* play);
void TreeElevator_Draw(Actor* thisx, PlayState* play);

void TreeElevator_SpawnDust(TreeElevator* this, PlayState* play);

void TreeElevator_SetupWaitForSwitch(TreeElevator* this, PlayState* play);
void TreeElevator_WaitForSwitch(TreeElevator* this, PlayState* play);

// Wait for switch
// Raise
// Wait to lower
// Lower

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
    Color_RGBA8 primColor = { 255, 255, 255, 255 };
    Color_RGBA8 envColor = { 255, 255, 255, 255 };

    Vec3f pos = this->dyna.actor.world.pos;
    Vec3f velocity = { 0.0f, 1.0f, 0.0f };
    Vec3f accel = { 0.0f, 0.0f, 0.0f };
    s16 scale = 10;
    s16 scaleStep = 10;
    s16 life = 40;

    EffectSsDust_Spawn(play, 0, &pos, &velocity, &accel, &primColor, &envColor, scale, scaleStep, life, 0);
}

void TreeElevator_SetupWaitForSwitch(TreeElevator* this, PlayState* play) {
    this->actionFunc = TreeElevator_WaitForSwitch;
}

void TreeElevator_WaitForSwitch(TreeElevator* this, PlayState* play) {
    // do nothing
    TreeElevator_SpawnDust(this, play);
}