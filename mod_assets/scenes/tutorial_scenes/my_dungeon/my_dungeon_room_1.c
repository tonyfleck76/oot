#include "ultra64.h"
#include "z64.h"
#include "macros.h"
#include "my_dungeon_scene.h"
#include "segment_symbols.h"
#include "command_macros_base.h"
#include "z64cutscene_commands.h"
#include "variables.h"

/**
 * Header Child Day (Default)
*/
#define LENGTH_MY_DUNGEON_ROOM_1_HEADER00_OBJECTLIST 3
#define LENGTH_MY_DUNGEON_ROOM_1_HEADER00_ACTORLIST 4
SceneCmd my_dungeon_room_1_header00[] = {
    SCENE_CMD_ECHO_SETTINGS(0x00),
    SCENE_CMD_ROOM_BEHAVIOR(0x00, 0x00, false, false),
    SCENE_CMD_SKYBOX_DISABLES(true, true),
    SCENE_CMD_TIME_SETTINGS(0xFF, 0xFF, 0),
    SCENE_CMD_ROOM_SHAPE(&my_dungeon_room_1_shapeHeader),
    SCENE_CMD_OBJECT_LIST(LENGTH_MY_DUNGEON_ROOM_1_HEADER00_OBJECTLIST, my_dungeon_room_1_header00_objectList),
    SCENE_CMD_ACTOR_LIST(LENGTH_MY_DUNGEON_ROOM_1_HEADER00_ACTORLIST, my_dungeon_room_1_header00_actorList),
    SCENE_CMD_END(),
};

s16 my_dungeon_room_1_header00_objectList[LENGTH_MY_DUNGEON_ROOM_1_HEADER00_OBJECTLIST] = {
    OBJECT_BOX,
    OBJECT_ZF,
    OBJECT_FIREFLY,
};

ActorEntry my_dungeon_room_1_header00_actorList[LENGTH_MY_DUNGEON_ROOM_1_HEADER00_ACTORLIST] = {
    // Treasure Chest
    {
        /* Actor ID   */ ACTOR_EN_BOX,
        /* Position   */ { 649, -120, 881 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x7841
    },

    // Lizalfos
    {
        /* Actor ID   */ ACTOR_EN_ZF,
        /* Position   */ { 653, -120, 818 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x00FE
    },

    // Keese
    {
        /* Actor ID   */ ACTOR_EN_FIREFLY,
        /* Position   */ { 470, 168, 669 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0002
    },

    // Keese
    {
        /* Actor ID   */ ACTOR_EN_FIREFLY,
        /* Position   */ { 834, 168, 669 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0002
    },
};

RoomShapeNormal my_dungeon_room_1_shapeHeader = {
    ROOM_SHAPE_TYPE_NORMAL,
    ARRAY_COUNT(my_dungeon_room_1_shapeDListEntry),
    my_dungeon_room_1_shapeDListEntry,
    my_dungeon_room_1_shapeDListEntry + ARRAY_COUNT(my_dungeon_room_1_shapeDListEntry)
};

RoomShapeDListsEntry my_dungeon_room_1_shapeDListEntry[1] = {
    { my_dungeon_room_1_entry_0_opaque, NULL },
};

Gfx my_dungeon_room_1_entry_0_opaque[] = {
	gsSPDisplayList(my_dungeon_dl_Floor_001_mesh_layer_Opaque),
	gsSPEndDisplayList(),
};

Vtx my_dungeon_dl_Floor_001_mesh_layer_Opaque_vtx_cull[8] = {
	{{ {353, -120, 940}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {353, 481, 940}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {353, 481, 320}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {353, -120, 320}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {953, -120, 940}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {953, 481, 940}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {953, 481, 320}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {953, -120, 320}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx my_dungeon_dl_Floor_001_mesh_layer_Opaque_vtx_0[12] = {
	{{ {429, -120, 864}, 0, {-620, 1470}, {255, 255, 255, 255} }},
	{{ {353, -120, 340}, 0, {-1000, -1143}, {77, 77, 77, 255} }},
	{{ {353, -120, 940}, 0, {-1000, 1850}, {110, 110, 110, 255} }},
	{{ {429, -120, 416}, 0, {-620, -763}, {255, 255, 255, 255} }},
	{{ {877, -120, 864}, 0, {1612, 1470}, {255, 255, 255, 255} }},
	{{ {953, -120, 940}, 0, {1992, 1850}, {77, 77, 77, 255} }},
	{{ {877, -120, 416}, 0, {1612, -763}, {255, 255, 255, 255} }},
	{{ {953, -120, 340}, 0, {1992, -1143}, {126, 126, 126, 255} }},
	{{ {577, -120, 416}, 0, {117, -763}, {255, 255, 255, 255} }},
	{{ {577, -120, 340}, 0, {117, -1143}, {119, 119, 119, 255} }},
	{{ {517, -120, 416}, 0, {-183, -763}, {255, 255, 255, 255} }},
	{{ {517, -120, 340}, 0, {-183, -1143}, {76, 76, 76, 255} }},
};

Gfx my_dungeon_dl_Floor_001_mesh_layer_Opaque_tri_0[] = {
	gsSPVertex(my_dungeon_dl_Floor_001_mesh_layer_Opaque_vtx_0 + 0, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(3, 0, 4, 0, 4, 0, 2, 0),
	gsSP2Triangles(4, 2, 5, 0, 6, 4, 5, 0),
	gsSP2Triangles(6, 5, 7, 0, 8, 6, 7, 0),
	gsSP2Triangles(8, 7, 9, 0, 10, 8, 9, 0),
	gsSP2Triangles(10, 9, 11, 0, 3, 10, 11, 0),
	gsSP2Triangles(3, 11, 1, 0, 10, 3, 4, 0),
	gsSP2Triangles(4, 8, 10, 0, 4, 6, 8, 0),
	gsSPEndDisplayList(),
};

Vtx my_dungeon_dl_Floor_001_mesh_layer_Opaque_vtx_1[53] = {
	{{ {517, -20, 340}, 0, {3169, 1559}, {76, 76, 76, 255} }},
	{{ {517, -120, 340}, 0, {3169, 2231}, {76, 76, 76, 255} }},
	{{ {517, -120, 320}, 0, {3438, 2231}, {197, 197, 197, 255} }},
	{{ {517, -20, 320}, 0, {3438, 1559}, {255, 255, 255, 255} }},
	{{ {353, -120, 340}, 0, {3169, 2231}, {250, 250, 250, 255} }},
	{{ {517, -120, 340}, 0, {5375, 2231}, {208, 208, 208, 255} }},
	{{ {517, -20, 340}, 0, {5375, 1559}, {255, 255, 255, 255} }},
	{{ {353, 233, 340}, 0, {3169, -143}, {77, 77, 77, 255} }},
	{{ {517, 233, 340}, 0, {5375, -143}, {76, 76, 76, 255} }},
	{{ {517, 481, 340}, 0, {5375, -1810}, {3, 3, 3, 255} }},
	{{ {353, 481, 340}, 0, {3169, -1810}, {0, 0, 0, 255} }},
	{{ {353, 481, 940}, 0, {-1543, -1810}, {0, 0, 0, 255} }},
	{{ {577, 481, 340}, 0, {1470, -1810}, {0, 0, 0, 255} }},
	{{ {953, 481, 940}, 0, {-4903, -1810}, {0, 0, 0, 255} }},
	{{ {953, 481, 340}, 0, {6529, -1810}, {0, 0, 0, 255} }},
	{{ {353, 233, 940}, 0, {-4903, -143}, {76, 76, 76, 255} }},
	{{ {353, 481, 340}, 0, {3169, -1810}, {0, 0, 0, 255} }},
	{{ {353, 481, 940}, 0, {-4903, -1810}, {0, 0, 0, 255} }},
	{{ {353, -120, 940}, 0, {-4903, 2231}, {252, 252, 252, 255} }},
	{{ {353, -120, 940}, 0, {-1543, 2231}, {252, 252, 252, 255} }},
	{{ {953, 233, 940}, 0, {6529, -143}, {77, 77, 77, 255} }},
	{{ {953, -120, 940}, 0, {6529, 2231}, {255, 255, 255, 255} }},
	{{ {353, 233, 940}, 0, {-1543, -143}, {76, 76, 76, 255} }},
	{{ {953, 481, 940}, 0, {6529, -1810}, {0, 0, 0, 255} }},
	{{ {577, -120, 340}, 0, {1470, 2231}, {252, 252, 252, 255} }},
	{{ {953, -120, 340}, 0, {6529, 2231}, {255, 255, 255, 255} }},
	{{ {953, 233, 340}, 0, {6529, -143}, {77, 77, 77, 255} }},
	{{ {577, -20, 340}, 0, {1470, 1559}, {255, 255, 255, 255} }},
	{{ {577, 233, 340}, 0, {1470, -143}, {76, 76, 76, 255} }},
	{{ {577, 481, 340}, 0, {1470, -1810}, {0, 0, 0, 255} }},
	{{ {517, -20, 340}, 0, {662, 1559}, {255, 255, 255, 255} }},
	{{ {517, 233, 340}, 0, {662, -143}, {76, 76, 76, 255} }},
	{{ {517, 233, 340}, 0, {662, -143}, {76, 76, 76, 255} }},
	{{ {577, 481, 340}, 0, {1470, -1810}, {0, 0, 0, 255} }},
	{{ {517, 481, 340}, 0, {662, -1810}, {3, 3, 3, 255} }},
	{{ {953, -120, 940}, 0, {-4903, 2231}, {255, 255, 255, 255} }},
	{{ {953, 233, 340}, 0, {3169, -143}, {77, 77, 77, 255} }},
	{{ {953, -120, 340}, 0, {3169, 2231}, {255, 255, 255, 255} }},
	{{ {953, 233, 940}, 0, {-4903, -143}, {77, 77, 77, 255} }},
	{{ {953, 481, 940}, 0, {-4903, -1810}, {0, 0, 0, 255} }},
	{{ {953, 481, 340}, 0, {3169, -1810}, {0, 0, 0, 255} }},
	{{ {517, -120, 340}, 0, {662, 591}, {76, 76, 76, 255} }},
	{{ {577, -120, 340}, 0, {1470, 591}, {119, 119, 119, 255} }},
	{{ {577, -120, 320}, 0, {1470, 457}, {254, 254, 254, 255} }},
	{{ {517, -120, 320}, 0, {662, 457}, {197, 197, 197, 255} }},
	{{ {577, -120, 340}, 0, {3169, 2231}, {119, 119, 119, 255} }},
	{{ {577, -20, 340}, 0, {3169, 1559}, {165, 165, 165, 255} }},
	{{ {577, -20, 320}, 0, {3438, 1559}, {255, 255, 255, 255} }},
	{{ {577, -120, 320}, 0, {3438, 2231}, {254, 254, 254, 255} }},
	{{ {577, -20, 340}, 0, {1470, 591}, {165, 165, 165, 255} }},
	{{ {517, -20, 340}, 0, {662, 591}, {76, 76, 76, 255} }},
	{{ {517, -20, 320}, 0, {662, 457}, {255, 255, 255, 255} }},
	{{ {577, -20, 320}, 0, {1470, 457}, {255, 255, 255, 255} }},
};

Gfx my_dungeon_dl_Floor_001_mesh_layer_Opaque_tri_1[] = {
	gsSPVertex(my_dungeon_dl_Floor_001_mesh_layer_Opaque_vtx_1 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 6, 7, 4, 0),
	gsSP2Triangles(6, 8, 7, 0, 7, 8, 9, 0),
	gsSP2Triangles(7, 9, 10, 0, 11, 10, 9, 0),
	gsSP2Triangles(11, 9, 12, 0, 12, 13, 11, 0),
	gsSP2Triangles(12, 14, 13, 0, 4, 7, 15, 0),
	gsSP2Triangles(15, 7, 16, 0, 15, 16, 17, 0),
	gsSP2Triangles(4, 15, 18, 0, 19, 20, 21, 0),
	gsSP2Triangles(19, 22, 20, 0, 20, 22, 11, 0),
	gsSP2Triangles(20, 11, 23, 0, 24, 25, 26, 0),
	gsSP2Triangles(26, 27, 24, 0, 26, 28, 27, 0),
	gsSP2Triangles(28, 26, 14, 0, 28, 14, 29, 0),
	gsSP2Triangles(30, 27, 28, 0, 30, 28, 31, 0),
	gsSP1Triangle(31, 28, 12, 0),
	gsSPVertex(my_dungeon_dl_Floor_001_mesh_layer_Opaque_vtx_1 + 32, 21, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(3, 6, 4, 0, 4, 6, 7, 0),
	gsSP2Triangles(4, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(9, 11, 12, 0, 13, 14, 15, 0),
	gsSP2Triangles(13, 15, 16, 0, 17, 18, 19, 0),
	gsSP1Triangle(17, 19, 20, 0),
	gsSPEndDisplayList(),
};

Gfx my_dungeon_dl_Floor_001_mesh_layer_Opaque[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(my_dungeon_dl_Floor_001_mesh_layer_Opaque_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_my_dungeon_dl_floor_mat_layerOpaque),
	gsSPDisplayList(my_dungeon_dl_Floor_001_mesh_layer_Opaque_tri_0),
	gsSPDisplayList(mat_my_dungeon_dl_wall_2_layerOpaque),
	gsSPDisplayList(my_dungeon_dl_Floor_001_mesh_layer_Opaque_tri_1),
	gsSPEndDisplayList(),
};

