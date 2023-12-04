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
#define LENGTH_MY_DUNGEON_ROOM_0_HEADER00_OBJECTLIST 3
#define LENGTH_MY_DUNGEON_ROOM_0_HEADER00_ACTORLIST 3
SceneCmd my_dungeon_room_0_header00[] = {
    SCENE_CMD_ECHO_SETTINGS(0x00),
    SCENE_CMD_ROOM_BEHAVIOR(0x00, 0x00, false, false),
    SCENE_CMD_SKYBOX_DISABLES(true, true),
    SCENE_CMD_TIME_SETTINGS(0xFF, 0xFF, 0),
    SCENE_CMD_ROOM_SHAPE(&my_dungeon_room_0_shapeHeader),
    SCENE_CMD_OBJECT_LIST(LENGTH_MY_DUNGEON_ROOM_0_HEADER00_OBJECTLIST, my_dungeon_room_0_header00_objectList),
    SCENE_CMD_ACTOR_LIST(LENGTH_MY_DUNGEON_ROOM_0_HEADER00_ACTORLIST, my_dungeon_room_0_header00_actorList),
    SCENE_CMD_END(),
};

s16 my_dungeon_room_0_header00_objectList[LENGTH_MY_DUNGEON_ROOM_0_HEADER00_OBJECTLIST] = {
    OBJECT_BDOOR,
    OBJECT_TREE_ELEVATOR,
    OBJECT_BOX,
};

ActorEntry my_dungeon_room_0_header00_actorList[LENGTH_MY_DUNGEON_ROOM_0_HEADER00_ACTORLIST] = {
    // Dungeon Switches
    {
        /* Actor ID   */ ACTOR_OBJ_SWITCH,
        /* Position   */ { 237, -112, -18 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0803
    },

    // Custom Actor
    {
        /* Actor ID   */ ACTOR_TREE_ELEVATOR,
        /* Position   */ { -100, -112, -70 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0008
    },

    // Treasure Chest
    {
        /* Actor ID   */ ACTOR_EN_BOX,
        /* Position   */ { 102, -117, -547 },
        /* Rotation   */ { DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000), DEG_TO_BINANG(0.000) },
        /* Parameters */ 0x0BC3
    },
};

RoomShapeNormal my_dungeon_room_0_shapeHeader = {
    ROOM_SHAPE_TYPE_NORMAL,
    ARRAY_COUNT(my_dungeon_room_0_shapeDListEntry),
    my_dungeon_room_0_shapeDListEntry,
    my_dungeon_room_0_shapeDListEntry + ARRAY_COUNT(my_dungeon_room_0_shapeDListEntry)
};

RoomShapeDListsEntry my_dungeon_room_0_shapeDListEntry[1] = {
    { my_dungeon_room_0_entry_0_opaque, NULL },
};

Gfx my_dungeon_room_0_entry_0_opaque[] = {
	gsSPDisplayList(my_dungeon_dl_Floor_mesh_layer_Opaque),
	gsSPDisplayList(my_dungeon_dl_Floor_004_mesh_layer_Opaque),
	gsSPEndDisplayList(),
};

u64 my_dungeon_dl_men_room_0Tex_00B538_ci8_ci8[] = {
	0x0000010202000304, 0x050607080903090a, 0x000b0a0a0c0c0d00, 0x020d000d0d0e0f10, 0x09000900000c0009, 0x0209000911090a0a, 0x120013020d020d0d, 0x0000000107000002, 
	0x0d0000020d0c0d09, 0x00000011140c0c0c, 0x0c020a090102000a, 0x000900020000000a, 0x02020a020d0d1516, 0x1109000a0a171212, 0x0a02090200090202, 0x0009000909050a0a, 
	0x02000900050a0c18, 0x15150d130014190a, 0x0d0d020202151509, 0x090a15030906001a, 0x00000209020d0b17, 0x130d0a0015020f0f, 0x09000a0202090915, 0x09020204031b0902, 
	0x0002020209000012, 0x020d130002050209, 0x0a0002000909091c, 0x06000909061b1109, 0x0202020902020d0d, 0x0a000d0207060902, 0x02020d001d061509, 0x09000c0a0a0a0900, 
	0x090109050909020a, 0x0c0c0a1e1f111509, 0x1515000013131313, 0x0c0a0a0a18130c0a, 0x020202080909020a, 0x0a0a162021222202, 0x090d0d0d0a0a0c0a, 0x0c0002130d0a0a18, 
	0x0404231f04030505, 0x242526262728040d, 0x0c0000000a180a0c, 0x0a0d0a0a0d00020f, 0x27231f29221f2a25, 0x2b2c2d2e212f160d, 0x0d0f0000000a0c12, 0x17120a001a000911, 
	0x22272227161e1627, 0x3031323334350302, 0x0d00000d0b0c0a12, 0x0c0a000902020811, 0x2525361f041f1f1f, 0x1f3738041f030715, 0x02000a0a0a000909, 0x05091505020d061f, 
	0x393a341f041f2727, 0x04033b3909070509, 0x05090200093c2416, 0x24050507051e3d07, 0x271f223e043e1605, 0x0209091607110303, 0x09150909163f2f40, 0x1f16061f21272739, 
	0x2727271c1f1f0609, 0x09060609111b1b41, 0x1f05050505071f3f, 0x291107422f222525, 0x23222f43163e1616, 0x05151f11070f0900, 0x00061e0709061e23, 0x23441b4546472c47, 
	0x48494a4b2f1f4c2e, 0x2703034407000a0c, 0x0a0d091502091502, 0x061104234a4d4e4f, 0x425039225122521b, 0x0d02130a0c0c170c, 0x00000a0902020909, 0x0306031553545556, 
	0x0a13442122571f39, 0x191a0d0a0d0a0a0a, 0x0a0d0c0d0a020903, 0x1502020311585916, 0x00022f40375a365b, 0x5c58150f02130a13, 0x0d0d00000a130539, 0x0309020002150202, 
	0x00025d1f565e5f60, 0x61573803090a0d0d, 0x0c0a09000d091c15, 0x0909070606030607, 0x0711303662634e36, 0x5a3538030202020a, 0x0c00090609060664, 0x11163e3865523a03, 
	0x0a13116667661f39, 0x034c1f0715000a0c, 0x0a0a0c07060f1438, 0x683822693263381f, 0x02090303396a0703, 0x07020403000a120a, 0x0b120c0000091b6b, 0x6c6c486d6e6f4504, 
	0x1106031509070606, 0x00020009000a0d0a, 0x12120a0009022933, 0x70716e726e60273b, 0x0307030611153903, 0x0f0202090a0d0c0b, 0x1212120c09052b73, 0x74747175762e5621, 
	0x2203060203440909, 0x0309020209070a0c, 0x1a0c0a0c02162216, 0x2e726c462e407333, 0x1102070908000d0a, 0x0909090509150200, 0x0d000d0239110306, 0x2270636330774930, 
	0x390d0a020f000d0d, 0x091e030307090915, 0x1544110915440311, 0x786d5e6d4d346069, 0x410d0c0a00020903, 0x051f04231f1f0505, 0x1e03150900161e79, 0x32327a4e51305e5e, 
	0x0d0a0c170c0a0c0d, 0x0527212f4c1f3e1e, 0x15090909004a3860, 0x60327b49432f3628, 0x0d0a020009130a0d, 0x06257c2e2f3f2516, 0x1e0315090f344e32, 0x2b2c5f5f34450400, 
	0x0209090509097d02, 0x432c522f73252b24, 0x1f16090a00111104, 0x2734451f1f270300, 0x15051e1e167e3941, 0x77617f7c48802521, 0x21160507000d0009, 0x810404391b09020d, 
	0x09061f3a643a3923, 0x41824073307c782f, 0x251e0603090d0006, 0x8361042303021302, 0x031144031b440322, 0x4041457373695248, 0x2b1e030302020c12, 0x042739000d0f0009, 
	0x0606060715034747, 0x3448842b162f361c, 0x03051e05150a120c, 0x120c121212130a00, 0x031e03030327732b, 0x782e7c2705058439, 0x05070316090c0c0a, 0x130a0c0c0c0b0c0a, 
	0x0909110505252e2c, 0x7877252203222739, 0x03051e000a0a1309, 0x0009020a0c0c0a0d, 0x02021303272f1f36, 0x2c7385772286231e, 0x030309020d090005, 0x44060d0c0a0c0b0a, 
	0x0c0b0c1827432236, 0x304e634537871f03, 0x05020a0a03000002, 0x02000a0b0c130c0c, 0x0b0c0b0011224378, 0x345e5e8889641b04, 0x090a0c0c0309000a, 0x0d0d0a130a0a0d0c, 
	0x120c00090d1f8445, 0x838a8b3908080d13, 0x02130a0d02020a02, 0x00000c0a0d0c0a0c, 0x0000090a00078c41, 0x8d58034409020a0a, 0x00130d0200090200, 0x020a0d02000d130a, 
	0x05020a0000382f3b, 0x648e6a3a03020d09, 0x0d0d0208041f1e2a, 0x090515051103031e, 0x220309001e27254a, 0x4d8f2e1f090a0202, 0x06061b3e4d6c6c20, 0x2b212424252b2525, 
	0x221f06073f777a5f, 0x4d79220909020209, 0x093a1f234b726d32, 0x323090862248257c, 0x220609041e217a7a, 0x7060160715071509, 0x052f5d5130717171, 0x7270884562252e2b, 
	0x04090d0616063b03, 0x911f2a0905050515, 0x09161e0487327271, 0x719232933e162f4a, 0x0315000904110307, 0x0909160504163905, 0x0616090915303636, 0x512e362b27222727, 
	0x220900020309090a, 0x0005211604041606, 0x0516030609030339, 0x03090d0703272547, 0x11090a0215050907, 0x05253f273e1f0416, 0x061f1f1e0703090f, 0x090d0002153f4b36, 
	0x22150209091e2a24, 0x20253f2221221f1f, 0x1f06391f03150200, 0x020200090321474b, 0x110d020906404073, 0x274377252f40273e, 0x2703000703070505, 0x02000915051f2f36, 
	0x0900000804515469, 0x485a2d609485253f, 0x1e05000509091e03, 0x0315050503081f22, 0x0709150309394723, 0x2e6669466260213e, 0x1f1e0d0205112716, 0x1e053e0303070808, 
	0x0303070404112722, 0x271f519545414122, 0x2c16020304392704, 0x030616031f110609, 0x030603060a06221c, 0x160466283796414c, 0x0302090d1f1f1f06, 0x0703031b27110709, 
	0x03110311091e2222, 0x5756675a55456723, 0x0509090c0c090404, 0x0503111c16030309, 0x3903390609057740, 0x835a974a5236221f, 0x05090a0a12120603, 0x0304161c1f040303, 
	0x1e03160909161f22, 0x1f1f57981f1f2316, 0x2a09000c0c0d0603, 0x031b030509054403, 0x0303030909031f22, 0x2322381c1f1f0403, 0x0902000c0c0a0909, 0x0703030606030306, 
	
};

u64 my_dungeon_dl_men_room_0Tex_00B538_ci8_pal_rgba16[] = {
	0x31473205394759c5, 0x6a855985520551c7, 0x5245418720c50883, 0x10852907630b4205, 0x41895a4508432107, 0x31494a0572050001, 0x18c7320b21475a85, 0x6b07528571c57245, 
	0xc24792c782c772c5, 0x82059ac7cac78285, 0x7bcb7b877145ab05, 0xbbc9ab4d9b098b09, 0xb38de40fd491bc0b, 0x9b4d938f934b82cd, 0x72c962476a897249, 0x81456ac582459285, 
	0x93076acb828b82c9, 0x5a078b4dabcd9b89, 0xb3cbbc0d9bcbab8b, 0x8b85b3cfbc51c44d, 0x624d8b0babcb5a8b, 0x8c0d93d383477b0d, 0x528b6b0f934dac19, 0x7b136b0bc451c40f, 
	0xab8f73499bcfac93, 0x5ac993cd838b838f, 0x93d7bc0f62499bcd, 0xbc93dd55ccd9bc4f, 0xbc97fddddd99ab09, 0xfe5feddfbc4d930b, 0xb3c9ab89c391dc57, 0xbb073a87824bab8d, 
	0xdb89834f8bcb9c11, 0x8b4b9b8d824d8b0f, 0xab9172d172cf51c9, 0x830f720972cd9351, 0xab0f628bf5599bd3, 0x9b91bc8d6b4f844d, 0x6b89000000000000
};

u64 my_dungeon_dl_men_room_8Tex_005D30_rgba16_ci8[] = {
	0x0000000000000102, 0x0304000000000000, 0x0000000000040502, 0x0603040000000000, 0x0000000004030708, 0x090a030400000000, 0x0000000403070b00, 0x00090c0304000000, 
	0x00000403070b0000, 0x00000d0c03040000, 0x000403070b000000, 0x0000000d0c030400, 0x0403070b00000000, 0x000000000d0c0304, 0x03070b0000000000, 0x00000000000d0a03, 
	0x030e000000000000, 0x0000000000000f10, 0x07030e0000000000, 0x0000000000040307, 0x0b07030e00000000, 0x000000000403070b, 0x001112030e000000, 0x0000001303070b00, 
	0x00000b07030e0000, 0x00000414150b0000, 0x0000000b07030e00, 0x000103070b000000, 0x000000000b07030e, 0x0415070b00000000, 0x00000000000b0703, 0x030a0b0000000000, 
	0x0000000000000403, 0x160e170000000000, 0x0000000000000307, 0x0a030e1700000000, 0x000000000003070b, 0x0007030e17000000, 0x0000000003070b00, 0x000b07030e170000, 
	0x00000003070b0000, 0x00000b07030e1700, 0x000003070b000000, 0x0000000b07030e17, 0x0003070b00000000, 0x000000000b07030e, 0x03070b0000000000, 0x0000000000000703, 
	0x030e171800000000, 0x0000000000000403, 0x07030e1718000000, 0x0000000000040307, 0x0007030e17180000, 0x000000000403070b, 0x000007030e171800, 0x0000000403070b00, 
	0x00000007030e1718, 0x0000040312110000, 0x0000000007030e17, 0x180403070b000000, 0x000000000007030e, 0x0403070b00000000, 0x0000000000000703, 0x03070b0000000000, 
	0x0000000000000403, 0x030e170000000000, 0x0000000000040307, 0x07030e1700000000, 0x000000000403070b, 0x0b07030e17000000, 0x0000000403070b00, 0x000b07030e170000, 
	0x00000403070b0000, 0x00000b07030e1700, 0x000403070b000000, 0x0000000b07030e17, 0x0403070b00000000, 0x000000000b07030e, 0x03070b0000000000, 0x00000000000b0703, 
	0x030e171800000000, 0x0000000000110403, 0x07030e1718000000, 0x0000000011040307, 0x0115030e17180000, 0x000000110403070b, 0x000107030e171800, 0x0000110403070b00, 
	0x00000b07030e1718, 0x00110403070b0000, 0x0000000b07030e17, 0x180403070b000000, 0x000000000b07030e, 0x0403070b00000000, 0x00000000000b0703, 0x03070b0000000000, 
	0x0000000000000403, 0x030e171800000000, 0x0000000000040307, 0x07030e1700000000, 0x000000000403070b, 0x0b07030e17000000, 0x0000000403070b00, 0x000b07030e170000, 
	0x00000403070b0000, 0x00000b07030e1700, 0x000403070d000000, 0x0000000b07030e17, 0x0403070b11000000, 0x000000000b07030e, 0x03070b0000000000, 0x00000000000b0703, 
	0x150b000000000000, 0x0000000000001112, 0x1919191919191919, 0x1919191919191919, 0x1a1a1a1a1a1a1a1a, 0x1a1a1a1a1a1a1a1a, 0x1b1b1a1a1a1a1a1c, 0x1d1e1a1a1a1a1a1a, 
	0x1a1a1a1a1a1a1a1f, 0x20211a1a1a1a1b22, 0x221b1a1a1a1a1a23, 0x241e1a1a1a1a1a1a, 0x1a1a1a1a1a1a1a1a, 0x1a1a1a1a1a1a1a1a, 0x2525252525252525, 0x2525252525252525, 
	
};

u64 my_dungeon_dl_men_room_8Tex_005D30_rgba16_pal_rgba16[] = {
	0x000018c66b596b5b, 0x29085295739d4211, 0x210818844a531082, 0x73dd294aad6a4a52, 0x8c630800294b4a50, 0x631952d584214210, 0x10847a534949494b, 0x5253731b5213398d, 
	0x6ad79421514b1887, 0x290b284300000000
};

Vtx my_dungeon_dl_Floor_mesh_layer_Opaque_vtx_cull[8] = {
	{{ {-899, -121, 321}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-899, 233, 321}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-899, 233, -960}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-899, -121, -960}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {719, -121, 321}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {719, 233, 321}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {719, 233, -960}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {719, -121, -960}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx my_dungeon_dl_Floor_mesh_layer_Opaque_vtx_0[20] = {
	{{ {577, -120, 300}, 0, {3375, 1992}, {255, 255, 255, 255} }},
	{{ {719, -120, 300}, 0, {4083, 1992}, {255, 255, 255, 255} }},
	{{ {719, -120, -475}, 0, {4083, -1874}, {255, 255, 255, 255} }},
	{{ {293, -120, -475}, 0, {1958, -1874}, {255, 255, 255, 255} }},
	{{ {517, -120, 300}, 0, {3075, 1992}, {255, 255, 255, 255} }},
	{{ {293, -120, 300}, 0, {1958, 1992}, {255, 255, 255, 255} }},
	{{ {-132, -120, 300}, 0, {-163, 1992}, {255, 255, 255, 255} }},
	{{ {-132, -120, -475}, 0, {-163, -1874}, {255, 255, 255, 255} }},
	{{ {200, -121, -960}, 0, {1491, -4232}, {255, 255, 255, 255} }},
	{{ {-38, -121, -960}, 0, {304, -4232}, {255, 255, 255, 255} }},
	{{ {-357, -120, 300}, 0, {-1285, 1992}, {255, 255, 255, 255} }},
	{{ {-557, -120, -68}, 0, {-2282, 155}, {255, 255, 255, 255} }},
	{{ {-557, -120, -475}, 0, {-2282, -1874}, {255, 255, 255, 255} }},
	{{ {-557, -120, 52}, 0, {-2282, 753}, {255, 255, 255, 255} }},
	{{ {-577, -120, -68}, 0, {-2382, 155}, {255, 255, 255, 255} }},
	{{ {-577, -120, 52}, 0, {-2382, 753}, {255, 255, 255, 255} }},
	{{ {-417, -120, 300}, 0, {-1584, 1992}, {255, 255, 255, 255} }},
	{{ {-557, -120, 300}, 0, {-2282, 1992}, {255, 255, 255, 255} }},
	{{ {-417, -120, 321}, 0, {-1584, 2099}, {255, 255, 255, 255} }},
	{{ {-357, -120, 321}, 0, {-1285, 2099}, {255, 255, 255, 255} }},
};

Gfx my_dungeon_dl_Floor_mesh_layer_Opaque_tri_0[] = {
	gsSPVertex(my_dungeon_dl_Floor_mesh_layer_Opaque_vtx_0 + 0, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 4, 0, 0, 3, 5, 4, 0),
	gsSP2Triangles(6, 5, 3, 0, 6, 3, 7, 0),
	gsSP2Triangles(7, 3, 8, 0, 7, 8, 9, 0),
	gsSP2Triangles(10, 6, 7, 0, 10, 7, 11, 0),
	gsSP2Triangles(7, 12, 11, 0, 11, 13, 10, 0),
	gsSP2Triangles(13, 11, 14, 0, 13, 14, 15, 0),
	gsSP2Triangles(13, 16, 10, 0, 13, 17, 16, 0),
	gsSP2Triangles(10, 16, 18, 0, 10, 18, 19, 0),
	gsSPEndDisplayList(),
};

Vtx my_dungeon_dl_Floor_mesh_layer_Opaque_vtx_1[98] = {
	{{ {-577, 40, -68}, 0, {1221, 145}, {6, 6, 6, 255} }},
	{{ {-899, 40, -68}, 0, {-582, 145}, {0, 0, 0, 255} }},
	{{ {-899, -120, -68}, 0, {-582, 1939}, {0, 0, 0, 255} }},
	{{ {-577, 40, 52}, 0, {1221, 145}, {0, 0, 0, 255} }},
	{{ {-577, -120, 52}, 0, {1221, 1939}, {255, 255, 255, 255} }},
	{{ {-899, -120, 52}, 0, {-582, 1939}, {0, 0, 0, 255} }},
	{{ {-899, 40, 52}, 0, {-582, 145}, {2, 2, 2, 255} }},
	{{ {-577, 40, 52}, 0, {1221, 145}, {40, 40, 40, 255} }},
	{{ {-577, -120, -68}, 0, {1221, 1939}, {255, 255, 255, 255} }},
	{{ {-577, 40, -68}, 0, {1221, 145}, {0, 0, 0, 255} }},
	{{ {-417, -120, 300}, 0, {-3207, 4221}, {255, 255, 255, 255} }},
	{{ {-557, -120, 300}, 0, {-4001, 4221}, {255, 255, 255, 255} }},
	{{ {-557, 233, 300}, 0, {-4001, -346}, {255, 255, 255, 255} }},
	{{ {-417, -20, 300}, 0, {-3207, 2927}, {255, 255, 255, 255} }},
	{{ {-357, -20, 300}, 0, {-2866, 2927}, {255, 255, 255, 255} }},
	{{ {-132, -120, 300}, 0, {-1591, 4221}, {255, 255, 255, 255} }},
	{{ {-132, 233, 300}, 0, {-1591, -346}, {255, 255, 255, 255} }},
	{{ {-357, -120, 300}, 0, {-2866, 4221}, {255, 255, 255, 255} }},
	{{ {-357, -120, 321}, 0, {-2866, 4221}, {255, 255, 255, 255} }},
	{{ {-357, -20, 321}, 0, {-2866, 2927}, {255, 255, 255, 255} }},
	{{ {-417, -20, 321}, 0, {-3207, 2927}, {255, 255, 255, 255} }},
	{{ {-417, -120, 321}, 0, {-3207, 4221}, {255, 255, 255, 255} }},
	{{ {719, -120, 300}, 0, {-2166, 4221}, {255, 255, 255, 255} }},
	{{ {719, 233, -475}, 0, {2230, -346}, {255, 255, 255, 255} }},
	{{ {719, -120, -475}, 0, {2230, 4221}, {255, 255, 255, 255} }},
	{{ {719, 233, 300}, 0, {-2166, -346}, {255, 255, 255, 255} }},
	{{ {293, 233, 300}, 0, {-4581, -346}, {255, 255, 255, 255} }},
	{{ {577, -20, 300}, 0, {-2971, 2927}, {255, 255, 255, 255} }},
	{{ {577, -120, 300}, 0, {-2971, 4221}, {255, 255, 255, 255} }},
	{{ {517, -20, 300}, 0, {-3311, 2927}, {255, 255, 255, 255} }},
	{{ {517, -120, 300}, 0, {-3311, 4221}, {255, 255, 255, 255} }},
	{{ {293, -120, 300}, 0, {-4581, 4221}, {255, 255, 255, 255} }},
	{{ {-557, -120, -68}, 0, {-77, 4221}, {255, 255, 255, 255} }},
	{{ {-557, -120, -475}, 0, {2230, 4221}, {255, 255, 255, 255} }},
	{{ {-557, 233, -475}, 0, {2230, -346}, {255, 255, 255, 255} }},
	{{ {-557, 40, -68}, 0, {-77, 2151}, {255, 255, 255, 255} }},
	{{ {-557, 233, 300}, 0, {-2166, -346}, {255, 255, 255, 255} }},
	{{ {-557, 40, 52}, 0, {-757, 2151}, {255, 255, 255, 255} }},
	{{ {-557, -120, 52}, 0, {-757, 4221}, {255, 255, 255, 255} }},
	{{ {-557, -120, 300}, 0, {-2166, 4221}, {255, 255, 255, 255} }},
	{{ {-132, -120, -475}, 0, {-1591, 4221}, {255, 255, 255, 255} }},
	{{ {-132, 233, -475}, 0, {-1591, -346}, {255, 255, 255, 255} }},
	{{ {-557, 233, -475}, 0, {-4001, -346}, {255, 255, 255, 255} }},
	{{ {-557, -120, -475}, 0, {-4001, 4221}, {255, 255, 255, 255} }},
	{{ {719, -120, -475}, 0, {3236, 4221}, {255, 255, 255, 255} }},
	{{ {719, 233, -475}, 0, {3236, -346}, {255, 255, 255, 255} }},
	{{ {293, 233, -475}, 0, {821, -346}, {255, 255, 255, 255} }},
	{{ {293, -120, -475}, 0, {821, 4221}, {255, 255, 255, 255} }},
	{{ {293, 233, -475}, 0, {821, -1857}, {255, 255, 255, 255} }},
	{{ {-132, 233, -475}, 0, {-1591, -1857}, {255, 255, 255, 255} }},
	{{ {-38, 76, -960}, 0, {-1060, -8135}, {255, 255, 255, 255} }},
	{{ {200, 76, -960}, 0, {290, -8135}, {255, 255, 255, 255} }},
	{{ {200, -121, -960}, 0, {290, 4238}, {255, 255, 255, 255} }},
	{{ {200, 76, -960}, 0, {290, 1684}, {255, 255, 255, 255} }},
	{{ {-38, 76, -960}, 0, {-1060, 1684}, {255, 255, 255, 255} }},
	{{ {-38, -121, -960}, 0, {-1060, 4238}, {255, 255, 255, 255} }},
	{{ {293, -120, -475}, 0, {2230, 4221}, {255, 255, 255, 255} }},
	{{ {293, 233, -475}, 0, {2230, -346}, {255, 255, 255, 255} }},
	{{ {200, 76, -960}, 0, {4981, 1684}, {255, 255, 255, 255} }},
	{{ {200, -121, -960}, 0, {4981, 4238}, {255, 255, 255, 255} }},
	{{ {-132, 233, -475}, 0, {2230, -346}, {255, 255, 255, 255} }},
	{{ {-132, -120, -475}, 0, {2230, 4221}, {255, 255, 255, 255} }},
	{{ {-38, -121, -960}, 0, {4981, 4238}, {255, 255, 255, 255} }},
	{{ {-38, 76, -960}, 0, {4981, 1684}, {255, 255, 255, 255} }},
	{{ {517, -120, 300}, 0, {-2166, 4221}, {255, 255, 255, 255} }},
	{{ {517, -20, 300}, 0, {-2166, 2927}, {255, 255, 255, 255} }},
	{{ {517, -20, 320}, 0, {-2279, 2927}, {255, 255, 255, 255} }},
	{{ {517, -120, 320}, 0, {-2279, 4221}, {255, 255, 255, 255} }},
	{{ {577, -20, 300}, 0, {-2166, 2927}, {255, 255, 255, 255} }},
	{{ {577, -120, 300}, 0, {-2166, 4221}, {255, 255, 255, 255} }},
	{{ {577, -120, 320}, 0, {-2279, 4221}, {255, 255, 255, 255} }},
	{{ {577, -20, 320}, 0, {-2279, 2927}, {255, 255, 255, 255} }},
	{{ {517, -20, 300}, 0, {2091, 8172}, {255, 255, 255, 255} }},
	{{ {577, -20, 300}, 0, {2431, 8172}, {255, 255, 255, 255} }},
	{{ {577, -20, 320}, 0, {2431, 8431}, {255, 255, 255, 255} }},
	{{ {517, -20, 320}, 0, {2091, 8431}, {255, 255, 255, 255} }},
	{{ {577, -120, 300}, 0, {2431, 8172}, {255, 255, 255, 255} }},
	{{ {517, -120, 300}, 0, {2091, 8172}, {255, 255, 255, 255} }},
	{{ {517, -120, 320}, 0, {2091, 8431}, {255, 255, 255, 255} }},
	{{ {577, -120, 320}, 0, {2431, 8431}, {255, 255, 255, 255} }},
	{{ {-557, 40, -68}, 0, {1333, 257}, {255, 255, 255, 255} }},
	{{ {-557, 40, 52}, 0, {1333, 1602}, {255, 255, 255, 255} }},
	{{ {-577, 40, 52}, 0, {1221, 1602}, {40, 40, 40, 255} }},
	{{ {-577, 40, -68}, 0, {1221, 257}, {6, 6, 6, 255} }},
	{{ {-899, 40, 52}, 0, {-582, 1602}, {2, 2, 2, 255} }},
	{{ {-899, 40, -68}, 0, {-582, 257}, {0, 0, 0, 255} }},
	{{ {-557, -120, -68}, 0, {1333, 1939}, {255, 255, 255, 255} }},
	{{ {-557, 40, -68}, 0, {1333, 145}, {241, 241, 241, 255} }},
	{{ {-577, 40, -68}, 0, {1221, 145}, {0, 0, 0, 255} }},
	{{ {-577, -120, -68}, 0, {1221, 1939}, {255, 255, 255, 255} }},
	{{ {-557, 40, 52}, 0, {1333, 145}, {241, 241, 241, 255} }},
	{{ {-557, -120, 52}, 0, {1333, 1939}, {255, 255, 255, 255} }},
	{{ {-577, -120, 52}, 0, {1221, 1939}, {255, 255, 255, 255} }},
	{{ {-577, 40, 52}, 0, {1221, 145}, {7, 7, 7, 255} }},
	{{ {-899, -120, -68}, 0, {937, 1939}, {0, 0, 0, 255} }},
	{{ {-899, 40, -68}, 0, {937, 145}, {0, 0, 0, 255} }},
	{{ {-899, 40, 52}, 0, {265, 145}, {2, 2, 2, 255} }},
	{{ {-899, -120, 52}, 0, {265, 1939}, {0, 0, 0, 255} }},
};

Gfx my_dungeon_dl_Floor_mesh_layer_Opaque_tri_1[] = {
	gsSPVertex(my_dungeon_dl_Floor_mesh_layer_Opaque_vtx_1 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 5, 0, 8, 9, 2, 0),
	gsSP2Triangles(10, 11, 12, 0, 13, 10, 12, 0),
	gsSP2Triangles(12, 14, 13, 0, 12, 15, 14, 0),
	gsSP2Triangles(12, 16, 15, 0, 15, 17, 14, 0),
	gsSP2Triangles(14, 17, 18, 0, 14, 18, 19, 0),
	gsSP2Triangles(13, 14, 19, 0, 13, 19, 20, 0),
	gsSP2Triangles(10, 13, 20, 0, 10, 20, 21, 0),
	gsSP2Triangles(22, 23, 24, 0, 22, 25, 23, 0),
	gsSP2Triangles(26, 25, 22, 0, 26, 22, 27, 0),
	gsSP2Triangles(22, 28, 27, 0, 26, 27, 29, 0),
	gsSP2Triangles(29, 30, 26, 0, 30, 31, 26, 0),
	gsSPVertex(my_dungeon_dl_Floor_mesh_layer_Opaque_vtx_1 + 32, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(2, 4, 3, 0, 4, 5, 3, 0),
	gsSP2Triangles(4, 6, 5, 0, 4, 7, 6, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 22, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 26, 27, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 30, 31, 0),
	gsSPVertex(my_dungeon_dl_Floor_mesh_layer_Opaque_vtx_1 + 64, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 14, 15, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 18, 19, 0),
	gsSP2Triangles(19, 18, 20, 0, 19, 20, 21, 0),
	gsSP2Triangles(22, 23, 24, 0, 22, 24, 25, 0),
	gsSP2Triangles(26, 27, 28, 0, 26, 28, 29, 0),
	gsSPVertex(my_dungeon_dl_Floor_mesh_layer_Opaque_vtx_1 + 94, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx my_dungeon_dl_Floor_mesh_layer_Opaque_vtx_2[4] = {
	{{ {-132, -120, 300}, 0, {-6993, 4221}, {255, 255, 255, 255} }},
	{{ {-132, 233, 300}, 0, {-6993, -346}, {255, 255, 255, 255} }},
	{{ {293, 233, 300}, 0, {-4581, -346}, {255, 255, 255, 255} }},
	{{ {293, -120, 300}, 0, {-4581, 4221}, {255, 255, 255, 255} }},
};

Gfx my_dungeon_dl_Floor_mesh_layer_Opaque_tri_2[] = {
	gsSPVertex(my_dungeon_dl_Floor_mesh_layer_Opaque_vtx_2 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx my_dungeon_dl_Floor_mesh_layer_Opaque_vtx_3[4] = {
	{{ {-577, -120, 52}, 0, {419, 1799}, {255, 255, 255, 255} }},
	{{ {-577, -120, -68}, 0, {419, -891}, {255, 255, 255, 255} }},
	{{ {-899, -120, -68}, 0, {-6787, -891}, {0, 0, 0, 255} }},
	{{ {-899, -120, 52}, 0, {-6787, 1799}, {0, 0, 0, 255} }},
};

Gfx my_dungeon_dl_Floor_mesh_layer_Opaque_tri_3[] = {
	gsSPVertex(my_dungeon_dl_Floor_mesh_layer_Opaque_vtx_3 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Vtx my_dungeon_dl_Floor_004_mesh_layer_Opaque_vtx_cull[8] = {
	{{ {-132, -120, 299}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-132, 233, 299}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-132, 233, 299}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-132, -120, 299}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {293, -120, 299}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {293, 233, 299}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {293, 233, 299}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {293, -120, 299}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx my_dungeon_dl_Floor_004_mesh_layer_Opaque_vtx_0[4] = {
	{{ {-132, -120, 299}, 0, {-3405, 1972}, {255, 255, 255, 255} }},
	{{ {-132, 233, 299}, 0, {-3405, -108}, {255, 255, 255, 255} }},
	{{ {293, 233, 299}, 0, {3885, -108}, {255, 255, 255, 255} }},
	{{ {293, -120, 299}, 0, {3885, 1972}, {255, 255, 255, 255} }},
};

Gfx my_dungeon_dl_Floor_004_mesh_layer_Opaque_tri_0[] = {
	gsSPVertex(my_dungeon_dl_Floor_004_mesh_layer_Opaque_vtx_0 + 0, 4, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSPEndDisplayList(),
};

Gfx mat_my_dungeon_dl_wall_stone_layerOpaque[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
	gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_SHADING_SMOOTH),
	gsSPSetOtherMode(G_SETOTHERMODE_H, 4, 20, G_AD_NOISE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_2CYCLE | G_PM_NPRIMITIVE),
	gsSPSetOtherMode(G_SETOTHERMODE_L, 0, 32, G_AC_NONE | G_ZS_PIXEL | G_RM_FOG_SHADE_A | G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, my_dungeon_dl_men_room_0Tex_00B538_ci8_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 152),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, my_dungeon_dl_men_room_0Tex_00B538_ci8_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPEndDisplayList(),
};

Gfx mat_my_dungeon_dl_wall_stone_climbable_layerOpaque[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, 1, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
	gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_SHADING_SMOOTH),
	gsSPSetOtherMode(G_SETOTHERMODE_H, 4, 20, G_AD_NOISE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_2CYCLE | G_PM_NPRIMITIVE),
	gsSPSetOtherMode(G_SETOTHERMODE_L, 0, 32, G_AC_NONE | G_ZS_PIXEL | G_RM_FOG_SHADE_A | G_RM_AA_ZB_OPA_SURF2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, my_dungeon_dl_men_room_0Tex_00B538_ci8_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 152),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, my_dungeon_dl_men_room_0Tex_00B538_ci8_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 1023, 512),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 4, 0, 0, 0, G_TX_WRAP | G_TX_MIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 252),
	gsSPEndDisplayList(),
};

Gfx mat_my_dungeon_dl_metal_vines_layerOpaque[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, COMBINED),
	gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_SHADING_SMOOTH),
	gsSPSetOtherMode(G_SETOTHERMODE_H, 4, 20, G_AD_NOISE | G_CD_MAGICSQ | G_CK_NONE | G_TC_FILT | G_TF_BILERP | G_TT_RGBA16 | G_TL_TILE | G_TD_CLAMP | G_TP_PERSP | G_CYC_2CYCLE | G_PM_NPRIMITIVE),
	gsSPSetOtherMode(G_SETOTHERMODE_L, 0, 32, G_AC_NONE | G_ZS_PIXEL | G_RM_FOG_SHADE_A | G_RM_AA_ZB_TEX_EDGE2),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetPrimColor(0, 0, 255, 255, 255, 255),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, my_dungeon_dl_men_room_8Tex_005D30_rgba16_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 37),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 1, my_dungeon_dl_men_room_8Tex_005D30_rgba16_ci8),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 511, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_8b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 4, 0),
	gsDPSetTileSize(0, 0, 0, 60, 252),
	gsSPEndDisplayList(),
};

Gfx my_dungeon_dl_Floor_mesh_layer_Opaque[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(my_dungeon_dl_Floor_mesh_layer_Opaque_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_my_dungeon_dl_floor_mat_layerOpaque),
	gsSPDisplayList(my_dungeon_dl_Floor_mesh_layer_Opaque_tri_0),
	gsSPDisplayList(mat_my_dungeon_dl_wall_stone_layerOpaque),
	gsSPDisplayList(my_dungeon_dl_Floor_mesh_layer_Opaque_tri_1),
	gsSPDisplayList(mat_my_dungeon_dl_wall_stone_climbable_layerOpaque),
	gsSPDisplayList(my_dungeon_dl_Floor_mesh_layer_Opaque_tri_2),
	gsSPDisplayList(mat_my_dungeon_dl_floor_2_layerOpaque),
	gsSPDisplayList(my_dungeon_dl_Floor_mesh_layer_Opaque_tri_3),
	gsSPEndDisplayList(),
};

Gfx my_dungeon_dl_Floor_004_mesh_layer_Opaque[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(my_dungeon_dl_Floor_004_mesh_layer_Opaque_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_my_dungeon_dl_metal_vines_layerOpaque),
	gsSPDisplayList(my_dungeon_dl_Floor_004_mesh_layer_Opaque_tri_0),
	gsSPEndDisplayList(),
};

