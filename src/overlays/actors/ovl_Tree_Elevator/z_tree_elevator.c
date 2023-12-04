/*
 * File: z_tree_elevator.c
 * Overlay: ovl_Tree_Elevator
 * Description: Switch-controlled elevator that looks like a tree
 */

#include "z_tree_elevator.h"

#define FLAGS (ACTOR_FLAG_4 | ACTOR_FLAG_5)
#include "assets/objects/gameplay_keep/gameplay_keep.h"

void TreeElevator_Init(Actor* thisx, PlayState* play);
void TreeElevator_Destroy(Actor* thisx, PlayState* play);
void TreeElevator_Update(Actor* thisx, PlayState* play);
void TreeElevator_Draw(Actor* thisx, PlayState* play);

const ActorInit Tree_Elevator_InitVars = {
    ACTOR_TREE_ELEVATOR,
    ACTORCAT_BG,
    FLAGS,
    OBJECT_GAMEPLAY_KEEP,
    sizeof(TreeElevator),
    (ActorFunc)TreeElevator_Init,
    (ActorFunc)TreeElevator_Destroy,
    (ActorFunc)TreeElevator_Update,
    (ActorFunc)TreeElevator_Draw
};

void TreeElevator_Init(Actor* thisx, PlayState* play) {

}

void TreeElevator_Destroy(Actor* thisx, PlayState* play) {

}

void TreeElevator_Update(Actor* thisx, PlayState* play) {

}

void TreeElevator_Draw(Actor* thisx, PlayState* play) {
    
}