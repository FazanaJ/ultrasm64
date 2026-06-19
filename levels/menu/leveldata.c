#include <PR/ultratypes.h>
#include <PR/gbi.h>

#include "macros.h"
#include "surface_terrains.h"
#include "types.h"

#ifdef VERSION_EU
#include "text_strings.h"
#endif
#include "make_const_nonconst.h"

// 0x07000000 - 0x07000018
static const Lights1 lights_menu_save_button = gdSPDefLights1(
    0x3f, 0x3f, 0x3f,
    0xff, 0xff, 0xff, 0x28, 0x28, 0x28
);

// 0x07000018 - 0x07000818
ALIGNED8 static const Texture texture_menu_stone[] = {
#include "levels/menu/main_menu_seg7.00018.rgba16.inc.c"
};

// 0x07000818 - 0x07001018
ALIGNED8 static const Texture texture_menu_dark_stone[] = {
#include "levels/menu/main_menu_seg7.00818.rgba16.inc.c"
};

// 0x07001018 - 0x07002018
ALIGNED8 static const Texture texture_menu_mario_save[] = {
#include "levels/menu/main_menu_seg7.01018.rgba16.inc.c"
};

// 0x07002018 - 0x07003018
ALIGNED8 static const Texture texture_menu_mario_new[] = {
#include "levels/menu/main_menu_seg7.02018.rgba16.inc.c"
};

// 0x07003018 - 0x07003118
static const Vtx vertex_menu_save_button_borders[] = {
    {{{  -163,   -122,      0}, 0, {     0,    990}, {0x00, 0xb6, 0x66, 0xff}}},
    {{{   163,   -122,      0}, 0, {   990,    990}, {0x00, 0xb6, 0x66, 0xff}}},
    {{{  -122,    -81,     30}, 0, {    96,    820}, {0x00, 0xb6, 0x66, 0xff}}},
    {{{   122,    -81,     30}, 0, {   862,    820}, {0x00, 0xb6, 0x66, 0xff}}},
    {{{  -163,   -122,      0}, 0, {     0,    990}, {0xb6, 0x00, 0x66, 0xff}}},
    {{{  -122,    -81,     30}, 0, {    96,    820}, {0xb6, 0x00, 0x66, 0xff}}},
    {{{  -163,    122,      0}, 0, {     0,      0}, {0xb6, 0x00, 0x66, 0xff}}},
    {{{  -122,     81,     30}, 0, {    96,    138}, {0xb6, 0x00, 0x66, 0xff}}},
    {{{  -122,     81,     30}, 0, {    96,    138}, {0x00, 0x4a, 0x66, 0xff}}},
    {{{   122,     81,     30}, 0, {   862,    138}, {0x00, 0x4a, 0x66, 0xff}}},
    {{{   163,    122,      0}, 0, {   990,      0}, {0x00, 0x4a, 0x66, 0xff}}},
    {{{  -163,    122,      0}, 0, {     0,      0}, {0x00, 0x4a, 0x66, 0xff}}},
    {{{   122,     81,     30}, 0, {   862,    138}, {0x4a, 0x00, 0x66, 0xff}}},
    {{{   122,    -81,     30}, 0, {   862,    820}, {0x4a, 0x00, 0x66, 0xff}}},
    {{{   163,   -122,      0}, 0, {   990,    990}, {0x4a, 0x00, 0x66, 0xff}}},
    {{{   163,    122,      0}, 0, {   990,      0}, {0x4a, 0x00, 0x66, 0xff}}},
};

// 0x07003118 - 0x07003158
static const Vtx vertex_menu_save_button_front[] = {
    {{{   122,     81,     30}, 0, {  2012,      0}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  -122,     81,     30}, 0, {     0,      0}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{   122,    -81,     30}, 0, {  2012,    990}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{  -122,    -81,     30}, 0, {     0,    990}, {0x00, 0x00, 0x7f, 0xff}}},
};

// 0x07003158 - 0x070031A0
static const Gfx dl_tex_block_menu_save_button_base[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPEndDisplayList(),
};

// 0x070031A0 - 0x07003218
static const Gfx dl_vertex_menu_save_button_borders[] = {
    gsSPLight(&lights_menu_save_button.l, 1),
    gsSPLight(&lights_menu_save_button.a, 2),
    gsSPVertex(vertex_menu_save_button_borders, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  1,  3,  2, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  5,  7,  6, 0x0),
    gsSP2Triangles( 8,  9, 10, 0x0, 11,  8, 10, 0x0),
    gsSP2Triangles(12, 13, 14, 0x0, 15, 12, 14, 0x0),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 6, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (64 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPEndDisplayList(),
};

// 0x07003218 - 0x07003258
static const Gfx dl_vertex_menu_save_button_front[] = {
    gsSPVertex(vertex_menu_save_button_front, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  1,  3,  2, 0x0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

// 0x07003258 - 0x07003298
static const Vtx vertex_menu_save_button_back[] = {
    {{{   163,   -122,      0}, 0, {     0,    990}, {0x00, 0x00, 0x81, 0xff}}},
    {{{  -163,   -122,      0}, 0, {   990,    990}, {0x00, 0x00, 0x81, 0xff}}},
    {{{   163,    122,      0}, 0, {     0,      0}, {0x00, 0x00, 0x81, 0xff}}},
    {{{  -163,    122,      0}, 0, {   990,      0}, {0x00, 0x00, 0x81, 0xff}}},
};

// 0x07003298 - 0x070032E0
static const Gfx dl_tex_block_menu_save_button_back[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPEndDisplayList(),
};

// 0x070032E0 - 0x07003330
static const Gfx dl_vertex_menu_save_button_back[] = {
    gsSPLight(&lights_menu_save_button.l, 1),
    gsSPLight(&lights_menu_save_button.a, 2),
    gsSPVertex(vertex_menu_save_button_back, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  1,  3,  2, 0x0),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

// 0x07003330 - 0x07003380
const Gfx dl_menu_mario_save_button_base[] = {
    gsSPDisplayList(dl_tex_block_menu_save_button_base),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_stone),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(dl_vertex_menu_save_button_borders),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_mario_save),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 64 * 32 - 1, CALC_DXT(64, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(dl_vertex_menu_save_button_front),
    gsSPEndDisplayList(),
};

// 0x07003380 - 0x070033D0
const Gfx dl_menu_mario_new_button_base[] = {
    gsSPDisplayList(dl_tex_block_menu_save_button_base),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_stone),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(dl_vertex_menu_save_button_borders),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_mario_new),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 64 * 32 - 1, CALC_DXT(64, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(dl_vertex_menu_save_button_front),
    gsSPEndDisplayList(),
};

// 0x070033D0 - 0x07003400
const Gfx dl_menu_save_button_back[] = {
    gsSPDisplayList(dl_tex_block_menu_save_button_back),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_dark_stone),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(dl_vertex_menu_save_button_back),
    gsSPEndDisplayList(),
};

// 0x07003400 - 0x07003450
const Gfx dl_menu_save_button_fade_back[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsSPLight(&lights_menu_save_button.l, 1),
    gsSPLight(&lights_menu_save_button.a, 2),
    gsSPVertex(vertex_menu_save_button_back, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  1,  3,  2, 0x0),
    gsDPPipeSync(),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

// 0x07003450 - 0x07003468
static const Lights1 lights_menu_main_button = gdSPDefLights1(
    0x3f, 0x3f, 0x3f,
    0xff, 0xff, 0xff, 0x28, 0x28, 0x28
);

// 0x07003468 - 0x07003468
ALIGNED8 static const Texture texture_menu_erase[] = {
#include "levels/menu/main_menu_seg7.03468.rgba16.inc.c"
};

// 0x07003C68 - 0x07003C68
ALIGNED8 static const Texture texture_menu_copy[] = {
#include "levels/menu/main_menu_seg7.03C68.rgba16.inc.c"
};

// 0x07004468 - 0x07004468
ALIGNED8 static const Texture texture_menu_file[] = {
#include "levels/menu/main_menu_seg7.04468.rgba16.inc.c"
};

// 0x07004C68 - 0x07004C68
ALIGNED8 static const Texture texture_menu_score[] = {
#include "levels/menu/main_menu_seg7.04C68.rgba16.inc.c"
};

// 0x07005468 - 0x07005468
ALIGNED8 static const Texture texture_menu_sound[] = {
#include "levels/menu/main_menu_seg7.05468.rgba16.inc.c"
};

// 0x07005C68 - 0x07005C88
static const Vtx vertex_menu_main_button[] = {
    {{{ -163,  -122,      0}, 0, {   0,    0}, {0xff, 0xff, 0xff, 0xff}}},
    {{{  163,  -122,      0}, 0, { 990,    0}, {0xff, 0xff, 0xff, 0xff}}},
    {{{ -163,   122,      0}, 0, {   0,  990}, {0xff, 0xff, 0xff, 0xff}}},
    {{{  163,   122,      0}, 0, { 990,  990}, {0xff, 0xff, 0xff, 0xff}}},
};

// 0x07005C88 - 0x07005CC0
static const Gfx dl_vertex_menu_main_button[] = {
    gsSPLight(&lights_menu_main_button.l, 1),
    gsSPLight(&lights_menu_main_button.a, 2),
    gsSPVertex(vertex_menu_main_button, 4, 0),
    gsSP2Triangles(0, 3, 1, 0x0,  0, 2, 3, 0x0),
    gsSPEndDisplayList(),
};

// 0x07006150 - 0x07006198
static const Gfx dl_tex_block_menu_main_button[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB),
    gsSPClearGeometryMode(G_SHADING_SMOOTH),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPEndDisplayList(),
};

// 0x07006198 - 0x070061C8
static const Gfx dl_menu_main_button[] = {
    gsSPDisplayList(dl_vertex_menu_main_button),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

// 0x070061C8 - 0x070061F8
const Gfx dl_menu_erase_button[] = {
    gsSPDisplayList(dl_tex_block_menu_main_button),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_erase),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(dl_menu_main_button),
    gsSPEndDisplayList(),
};

// 0x070061F8 - 0x07006228
const Gfx dl_menu_copy_button[] = {
    gsSPDisplayList(dl_tex_block_menu_main_button),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_copy),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(dl_menu_main_button),
    gsSPEndDisplayList(),
};

Lights1 yeah_f3dlite_material_lights = gdSPDefLights1(
	0x7F, 0x0, 0x5,
	0xFF, 0x0, 0x15, 0x49, 0x49, 0x49);

Lights1 yeah_f3dlite_material_002_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 yeah_f3dlite_material_004_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 yeah_f3dlite_material_005_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 yeah_f3dlite_material_006_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 yeah_f3dlite_material_007_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 yeah_f3dlite_material_008_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 yeah_f3dlite_material_009_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 yeah_f3dlite_material_010_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Lights1 yeah_f3dlite_material_011_lights = gdSPDefLights1(
	0x7F, 0x7F, 0x7F,
	0xFF, 0xFF, 0xFF, 0x49, 0x49, 0x49);

Gfx yeah_tex4_ci4_aligner[] = {gsSPEndDisplayList()};
u8 yeah_tex4_ci4[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 
	0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x10, 0x00, 
	0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 
	0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x10, 
	0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x10, 
	0x01, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 
	0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x10, 0x01, 0x00, 0x00, 0x00, 
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 
	0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
	0x01, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
	0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx yeah_tex4_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 yeah_tex4_pal_rgba16[] = {
	0xff, 0xff, 0x52, 0x0b, 
};

Gfx yeah_tex2_ci4_aligner[] = {gsSPEndDisplayList()};
u8 yeah_tex2_ci4[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x11, 0x11, 0x10, 0x00, 0x01, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 
	0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx yeah_tex2_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 yeah_tex2_pal_rgba16[] = {
	0xff, 0xff, 0x52, 0x0b, 
};

Gfx yeah_mario_ci4_i8_aligner[] = {gsSPEndDisplayList()};
u8 yeah_mario_ci4_i8[] = {
	0x32, 0x20, 0x20, 0x31, 0x26, 0x45, 0x32, 0x24, 
	0x39, 0x3a, 0x34, 0x3d, 0x21, 0x29, 0x1b, 0x1c, 
	0x1f, 0x22, 0x1c, 0x15, 0x18, 0x0e, 0x0f, 0x15, 
	0x20, 0x32, 0x1e, 0x22, 0x30, 0x22, 0x46, 0x2e, 
	0x24, 0x3d, 0x3d, 0x32, 0x3f, 0x1e, 0x29, 0x1c, 
	0x1d, 0x1f, 0x22, 0x1b, 0x14, 0x18, 0x0d, 0x13, 
	0x16, 0x24, 0x30, 0x1d, 0x26, 0x30, 0x25, 0x4b, 
	0x2a, 0x25, 0x3b, 0x3c, 0x32, 0x3c, 0x1f, 0x27, 
	0x25, 0x1b, 0x20, 0x1c, 0x21, 0x21, 0x22, 0x22, 
	0x35, 0x36, 0x27, 0x25, 0x48, 0x30, 0x1d, 0x19, 
	0x26, 0x27, 0x1e, 0x1c, 0x17, 0x0f, 0x12, 0x13, 
	0x1e, 0x23, 0x1c, 0x1f, 0x1d, 0x21, 0x23, 0x22, 
	0x22, 0x38, 0x36, 0x26, 0x26, 0x46, 0x2b, 0x1e, 
	0x1b, 0x2a, 0x26, 0x1f, 0x1e, 0x17, 0x0e, 0x16, 
	0x15, 0x1e, 0x21, 0x1e, 0x20, 0x1c, 0x22, 0x21, 
	0x22, 0x24, 0x38, 0x34, 0x23, 0x2e, 0x45, 0x25, 
	0x45, 0x39, 0x4e, 0x35, 0x20, 0x43, 0x39, 0x25, 
	0x55, 0x61, 0x5a, 0x47, 0x51, 0x36, 0x1b, 0x1d, 
	0x21, 0x23, 0x1d, 0x16, 0x18, 0x12, 0x13, 0x16, 
	0x2e, 0x45, 0x3c, 0x4f, 0x2c, 0x21, 0x48, 0x37, 
	0x28, 0x5f, 0x67, 0x5c, 0x44, 0x58, 0x30, 0x1c, 
	0x1f, 0x24, 0x24, 0x1e, 0x16, 0x17, 0x11, 0x16, 
	0x18, 0x35, 0x47, 0x3d, 0x4d, 0x2c, 0x22, 0x47, 
	0x31, 0x29, 0x5d, 0x63, 0x57, 0x40, 0x53, 0x28, 
	0x44, 0x45, 0x48, 0x4b, 0x2d, 0x53, 0x4d, 0x27, 
	0x50, 0x44, 0x54, 0x58, 0x4c, 0x3d, 0x45, 0x46, 
	0x30, 0x14, 0x13, 0x10, 0x0c, 0x0c, 0x13, 0x16, 
	0x3d, 0x46, 0x4a, 0x53, 0x4a, 0x3c, 0x5b, 0x56, 
	0x2d, 0x62, 0x43, 0x64, 0x5e, 0x5a, 0x40, 0x53, 
	0x4e, 0x32, 0x17, 0x16, 0x13, 0x0e, 0x0c, 0x17, 
	0x19, 0x46, 0x49, 0x49, 0x51, 0x3e, 0x3c, 0x51, 
	0x48, 0x28, 0x59, 0x3d, 0x5a, 0x4c, 0x4f, 0x32, 
	0x42, 0x47, 0x4a, 0x4e, 0x4c, 0x3d, 0x49, 0x3b, 
	0x54, 0x48, 0x55, 0x4d, 0x48, 0x53, 0x49, 0x43, 
	0x44, 0x28, 0x15, 0x0f, 0x10, 0x0c, 0x16, 0x1d, 
	0x40, 0x4b, 0x55, 0x56, 0x5f, 0x66, 0x46, 0x63, 
	0x46, 0x79, 0x53, 0x74, 0x5b, 0x66, 0x6c, 0x5e, 
	0x54, 0x59, 0x2f, 0x19, 0x15, 0x13, 0x0d, 0x1d, 
	0x24, 0x48, 0x51, 0x51, 0x51, 0x51, 0x52, 0x34, 
	0x53, 0x33, 0x5f, 0x41, 0x58, 0x41, 0x4e, 0x53, 
	0x2e, 0x40, 0x21, 0x4b, 0x50, 0x3f, 0x4e, 0x50, 
	0x53, 0x56, 0x52, 0x34, 0x47, 0x53, 0x37, 0x1f, 
	0x41, 0x34, 0x18, 0x13, 0x0e, 0x0a, 0x13, 0x20, 
	0x4a, 0x41, 0x53, 0x37, 0x77, 0x7e, 0x66, 0x83, 
	0x7c, 0x91, 0x91, 0x8c, 0x4e, 0x7c, 0x87, 0x50, 
	0x37, 0x70, 0x51, 0x23, 0x1e, 0x14, 0x0b, 0x1e, 
	0x32, 0x55, 0x45, 0x45, 0x37, 0x5a, 0x59, 0x41, 
	0x59, 0x49, 0x58, 0x57, 0x50, 0x2e, 0x4b, 0x53, 
	0x25, 0x20, 0x18, 0x43, 0x4f, 0x3c, 0x47, 0x4d, 
	0x53, 0x3f, 0x49, 0x4d, 0x45, 0x50, 0x46, 0x43, 
	0x49, 0x26, 0x15, 0x11, 0x11, 0x0d, 0x1a, 0x30, 
	0x57, 0x3c, 0x36, 0x3a, 0x97, 0xa9, 0x86, 0xaf, 
	0xbb, 0xd2, 0x85, 0xb3, 0xb3, 0xb4, 0xbc, 0xac, 
	0xa1, 0xa6, 0x46, 0x2d, 0x23, 0x1f, 0x18, 0x30, 
	0x49, 0x6f, 0x39, 0x32, 0x34, 0x67, 0x60, 0x46, 
	0x59, 0x52, 0x5c, 0x3c, 0x4c, 0x47, 0x4c, 0x4a, 
	0x1e, 0x15, 0x17, 0x36, 0x1d, 0x1a, 0x21, 0x3a, 
	0x35, 0x26, 0x1f, 0x27, 0x31, 0x2f, 0x2e, 0x37, 
	0x2c, 0x19, 0x13, 0x12, 0x10, 0x0f, 0x1d, 0x39, 
	0x69, 0x51, 0x3e, 0x4f, 0x90, 0x43, 0x33, 0x3e, 
	0x51, 0x51, 0x3c, 0x39, 0x3e, 0x4e, 0x4a, 0x4c, 
	0x50, 0x46, 0x31, 0x33, 0x33, 0x32, 0x32, 0x39, 
	0x4b, 0x78, 0x4d, 0x38, 0x42, 0x59, 0x2e, 0x28, 
	0x36, 0x47, 0x38, 0x25, 0x23, 0x24, 0x33, 0x25, 
	0x10, 0x13, 0x15, 0x17, 0x18, 0x17, 0x1a, 0x19, 
	0x1b, 0x1c, 0x1c, 0x1c, 0x1b, 0x1f, 0x1d, 0x1f, 
	0x1c, 0x1b, 0x1b, 0x19, 0x17, 0x15, 0x2e, 0x2a, 
	0x36, 0x3a, 0x37, 0x38, 0x38, 0x37, 0x38, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x38, 0x39, 0x36, 0x43, 0x48, 0x42, 0x3a, 0x2f, 
	0x29, 0x25, 0x24, 0x20, 0x1e, 0x1b, 0x1a, 0x1a, 
	0x0e, 0x10, 0x11, 0x13, 0x15, 0x18, 0x17, 0x1b, 
	0x1a, 0x1c, 0x1c, 0x1f, 0x1e, 0x20, 0x21, 0x26, 
	0x24, 0x25, 0x26, 0x27, 0x2a, 0x36, 0x38, 0x38, 
	0x38, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x36, 0x36, 0x33, 0x35, 0x3a, 0x44, 0x4b, 
	0x3e, 0x34, 0x2b, 0x23, 0x1e, 0x1b, 0x18, 0x16, 
	0x0b, 0x0b, 0x0f, 0x0f, 0x12, 0x14, 0x14, 0x18, 
	0x1a, 0x1b, 0x1e, 0x20, 0x22, 0x26, 0x24, 0x2b, 
	0x2d, 0x2e, 0x33, 0x38, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x36, 0x35, 0x35, 0x32, 0x30, 0x2d, 0x31, 
	0x40, 0x42, 0x34, 0x2d, 0x23, 0x1c, 0x16, 0x16, 
	0x0a, 0x0a, 0x0c, 0x11, 0x12, 0x11, 0x11, 0x18, 
	0x1a, 0x1f, 0x27, 0x30, 0x34, 0x31, 0x32, 0x31, 
	0x37, 0x38, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x36, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x36, 0x35, 0x35, 0x35, 0x34, 0x31, 0x2f, 0x2b, 
	0x29, 0x30, 0x40, 0x3f, 0x32, 0x25, 0x19, 0x13, 
	0x0b, 0x0f, 0x14, 0x15, 0x16, 0x1a, 0x1c, 0x1f, 
	0x28, 0x37, 0x43, 0x4e, 0x3d, 0x39, 0x38, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x38, 0x39, 0x3a, 0x3c, 
	0x3f, 0x40, 0x3f, 0x3d, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x36, 0x35, 0x35, 0x34, 0x34, 0x33, 0x30, 0x2e, 
	0x2a, 0x28, 0x28, 0x3d, 0x4c, 0x3f, 0x2b, 0x20, 
	0x0f, 0x15, 0x1b, 0x19, 0x1a, 0x23, 0x2b, 0x35, 
	0x46, 0x4a, 0x41, 0x38, 0x38, 0x37, 0x37, 0x37, 
	0x37, 0x39, 0x3d, 0x42, 0x49, 0x4f, 0x51, 0x56, 
	0x54, 0x4f, 0x45, 0x3c, 0x36, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x36, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x36, 0x37, 
	0x36, 0x35, 0x34, 0x33, 0x32, 0x32, 0x31, 0x2f, 
	0x2c, 0x2b, 0x27, 0x26, 0x2d, 0x45, 0x44, 0x34, 
	0x2a, 0x2b, 0x3b, 0x32, 0x2f, 0x68, 0x91, 0x8a, 
	0x5d, 0x3e, 0x37, 0x37, 0x37, 0x36, 0x37, 0x3c, 
	0x43, 0x4d, 0x59, 0x6a, 0x7c, 0x7e, 0x76, 0x6a, 
	0x5e, 0x4f, 0x42, 0x39, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x38, 0x37, 0x37, 0x38, 0x3a, 0x3e, 
	0x48, 0x5e, 0x69, 0x62, 0x5c, 0x53, 0x41, 0x3b, 
	0x34, 0x33, 0x32, 0x31, 0x31, 0x30, 0x2f, 0x2e, 
	0x2c, 0x2b, 0x28, 0x26, 0x25, 0x24, 0x56, 0x5f, 
	0x36, 0x36, 0x5b, 0x5a, 0x7a, 0xa6, 0xbe, 0x8d, 
	0x42, 0x37, 0x37, 0x37, 0x37, 0x3d, 0x44, 0x50, 
	0x5f, 0x79, 0x9a, 0xb6, 0xa4, 0x96, 0x80, 0x6b, 
	0x59, 0x49, 0x3e, 0x37, 0x37, 0x37, 0x37, 0x36, 
	0x38, 0x3a, 0x4e, 0x76, 0x78, 0xb2, 0xd4, 0xe3, 
	0xed, 0xf6, 0xfa, 0xf6, 0xef, 0xe6, 0xdd, 0x9d, 
	0xa1, 0x7c, 0x4d, 0x34, 0x2f, 0x2f, 0x2e, 0x2c, 
	0x2b, 0x2a, 0x28, 0x27, 0x25, 0x24, 0x24, 0x50, 
	0x52, 0x41, 0x79, 0x70, 0xba, 0x96, 0x52, 0x38, 
	0x37, 0x37, 0x37, 0x37, 0x39, 0x47, 0x59, 0x6f, 
	0x8a, 0x9e, 0xb7, 0xb3, 0x93, 0x79, 0x61, 0x55, 
	0x49, 0x41, 0x3a, 0x37, 0x37, 0x38, 0x41, 0x62, 
	0x88, 0xc1, 0xee, 0xf7, 0x61, 0x6c, 0xf4, 0xfd, 
	0xfd, 0xfd, 0xfd, 0xfa, 0xf4, 0xf1, 0xd7, 0x43, 
	0x92, 0xdb, 0xd1, 0x9f, 0x7a, 0x52, 0x2e, 0x2b, 
	0x29, 0x28, 0x27, 0x26, 0x25, 0x23, 0x22, 0x22, 
	0x6f, 0x9a, 0xaa, 0xad, 0x80, 0x3d, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x38, 0x40, 0x50, 0x60, 0x6e, 
	0x82, 0x8b, 0x8c, 0x8e, 0x83, 0x65, 0x55, 0x49, 
	0x41, 0x3a, 0x37, 0x37, 0x38, 0x76, 0xda, 0xf6, 
	0xfd, 0xfd, 0xfd, 0xda, 0x3a, 0x38, 0x95, 0xfa, 
	0xfc, 0xfd, 0xfd, 0xf6, 0xe8, 0xee, 0x8f, 0x33, 
	0x4e, 0xd0, 0xd8, 0x97, 0x6d, 0xc0, 0x47, 0x2b, 
	0x2a, 0x28, 0x28, 0x27, 0x24, 0x23, 0x22, 0x21, 
	0xaf, 0x96, 0x62, 0x4e, 0x39, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x3b, 0x44, 0x50, 0x57, 0x5d, 
	0x60, 0x60, 0x5f, 0x5d, 0x67, 0x5c, 0x50, 0x46, 
	0x3d, 0x37, 0x37, 0x37, 0x3b, 0xd1, 0xfd, 0xfd, 
	0xfd, 0xfd, 0xfc, 0x81, 0x37, 0x36, 0x3f, 0xb9, 
	0xfb, 0xfb, 0xf4, 0xce, 0xf5, 0xd2, 0x44, 0x32, 
	0x32, 0x92, 0xd8, 0xd2, 0x42, 0xa9, 0x78, 0x2c, 
	0x2a, 0x29, 0x28, 0x26, 0x23, 0x22, 0x20, 0x20, 
	0x49, 0x44, 0x39, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x3c, 0x41, 0x46, 0x49, 0x48, 
	0x47, 0x45, 0x43, 0x42, 0x48, 0x4f, 0x4b, 0x41, 
	0x39, 0x37, 0x37, 0x38, 0x5b, 0xf4, 0xfd, 0xfe, 
	0xfe, 0xfe, 0xec, 0x43, 0x37, 0x38, 0x38, 0x4a, 
	0xd6, 0xed, 0xab, 0xf4, 0xf4, 0x85, 0x33, 0x31, 
	0x31, 0x4a, 0xcc, 0xd3, 0x4a, 0x82, 0xb1, 0x33, 
	0x2b, 0x29, 0x28, 0x26, 0x23, 0x22, 0x20, 0x1f, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x39, 0x39, 0x3b, 0x3b, 
	0x39, 0x38, 0x38, 0x38, 0x38, 0x3b, 0x3e, 0x3c, 
	0x37, 0x37, 0x2b, 0x38, 0xa8, 0xfc, 0xfe, 0xfe, 
	0xfe, 0xfd, 0xa9, 0x38, 0x39, 0x39, 0x54, 0x6b, 
	0x85, 0x78, 0xd6, 0xf7, 0xd5, 0x40, 0x32, 0x31, 
	0x30, 0x31, 0x8c, 0xd4, 0x44, 0x59, 0xa9, 0x5b, 
	0x2e, 0x2b, 0x27, 0x24, 0x22, 0x21, 0x20, 0x1d, 
	0x37, 0x37, 0x37, 0x37, 0x36, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x38, 
	0x37, 0x37, 0x22, 0x39, 0xde, 0xfd, 0xfe, 0xfe, 
	0xfe, 0xf9, 0x5a, 0x38, 0x4f, 0x95, 0xa9, 0x98, 
	0x54, 0x3b, 0x86, 0x9e, 0x81, 0x35, 0x33, 0x31, 
	0x31, 0x31, 0x54, 0xb3, 0x36, 0x48, 0x71, 0x5d, 
	0x48, 0x2f, 0x28, 0x24, 0x22, 0x21, 0x1b, 0x0b, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x36, 0x36, 0x28, 0x54, 0xf9, 0xfd, 0xfe, 0xfd, 
	0xfd, 0xd1, 0x39, 0x3e, 0x98, 0xbe, 0x79, 0x3a, 
	0x0a, 0x27, 0x77, 0x77, 0x5d, 0x38, 0x32, 0x32, 
	0x30, 0x32, 0x7c, 0x9b, 0x51, 0x2c, 0x29, 0x28, 
	0x44, 0x3f, 0x28, 0x22, 0x20, 0x1b, 0x08, 0x12, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x35, 0x2f, 0x16, 0xdd, 0xfd, 0xfe, 0xfd, 
	0xfb, 0x78, 0x38, 0x78, 0x9f, 0x78, 0x09, 0x02, 
	0x02, 0x02, 0x22, 0x78, 0x6d, 0x47, 0x33, 0x43, 
	0x30, 0x4d, 0xb2, 0x8c, 0x69, 0x07, 0x03, 0x01, 
	0x14, 0x43, 0x2b, 0x22, 0x1f, 0x0c, 0x08, 0x1b, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x36, 0x36, 0x32, 0x09, 0x7d, 0xfd, 0xfe, 0xfd, 
	0xd7, 0x3c, 0x37, 0x84, 0x9a, 0x28, 0x02, 0x07, 
	0x55, 0x0b, 0x04, 0x55, 0x73, 0x57, 0x69, 0xb7, 
	0x37, 0x60, 0x9c, 0x84, 0x53, 0x04, 0x18, 0x3a, 
	0x06, 0x37, 0x2f, 0x20, 0x14, 0x04, 0x16, 0x1e, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x39, 
	0x40, 0x44, 0x34, 0x12, 0x17, 0xe4, 0xfd, 0xfb, 
	0x76, 0x38, 0x38, 0x8e, 0x98, 0x1f, 0x01, 0x39, 
	0xf7, 0xa0, 0x03, 0x28, 0x74, 0x61, 0xd3, 0xe6, 
	0x56, 0x62, 0x8e, 0x7b, 0x43, 0x04, 0x7d, 0xbc, 
	0x23, 0x29, 0x32, 0x1c, 0x07, 0x09, 0x1d, 0x1d, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x36, 0x37, 0x37, 0x36, 0x37, 0x37, 0x38, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x36, 0x40, 
	0x52, 0x62, 0x5d, 0x17, 0x04, 0x85, 0xfc, 0xc4, 
	0x3d, 0x38, 0x37, 0x85, 0x94, 0x2d, 0x03, 0x5f, 
	0xd1, 0x5d, 0x02, 0x26, 0x70, 0x5f, 0xe6, 0xf2, 
	0x86, 0x61, 0x88, 0x77, 0x49, 0x03, 0x40, 0x63, 
	0x09, 0x2d, 0x2e, 0x0c, 0x04, 0x16, 0x1d, 0x1c, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x38, 0x34, 0x2e, 
	0x2d, 0x33, 0x37, 0x37, 0x38, 0x37, 0x38, 0x37, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x3b, 0x4f, 
	0x6f, 0x8e, 0x91, 0x42, 0x14, 0x18, 0xe2, 0x6f, 
	0x39, 0x38, 0x37, 0x47, 0x79, 0x29, 0x04, 0x03, 
	0x09, 0x03, 0x03, 0x3a, 0x5d, 0x27, 0xcf, 0xf8, 
	0xb0, 0x67, 0x91, 0x89, 0x6a, 0x17, 0x06, 0x04, 
	0x09, 0x39, 0x1e, 0x04, 0x0c, 0x1d, 0x1d, 0x1d, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x36, 0x25, 0x1e, 
	0x1e, 0x1f, 0x22, 0x26, 0x29, 0x48, 0xa1, 0x53, 
	0x38, 0x37, 0x37, 0x37, 0x37, 0x37, 0x44, 0x5d, 
	0x90, 0xc4, 0xa1, 0x4c, 0x3e, 0x17, 0x52, 0x3d, 
	0x38, 0x37, 0x1b, 0x0b, 0x36, 0x1d, 0x3d, 0x05, 
	0x04, 0x04, 0x1f, 0x63, 0x1f, 0x05, 0x2b, 0xba, 
	0xc1, 0xba, 0xbd, 0xbd, 0xbc, 0xb2, 0xa5, 0x98, 
	0x89, 0x81, 0x54, 0x2c, 0x23, 0x1f, 0x1e, 0x21, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x31, 0x1f, 0x1d, 
	0x1d, 0x1d, 0x1e, 0x21, 0x32, 0xb2, 0xde, 0xca, 
	0x65, 0x39, 0x37, 0x36, 0x37, 0x3a, 0x4b, 0x66, 
	0x8e, 0xa4, 0x87, 0x56, 0x22, 0x35, 0x2c, 0x37, 
	0x37, 0x36, 0x2e, 0x27, 0x20, 0x46, 0x4f, 0x3c, 
	0x2f, 0x35, 0x69, 0x4e, 0x25, 0x9e, 0xc0, 0xcb, 
	0xcb, 0xcb, 0xcb, 0xc9, 0xc9, 0xc8, 0xc6, 0xc5, 
	0xc0, 0xba, 0xb4, 0xab, 0x9f, 0x8c, 0x77, 0x67, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x24, 0x1d, 0x1d, 
	0x1d, 0x1e, 0x24, 0x2e, 0x8e, 0xde, 0xde, 0xde, 
	0xd5, 0x9b, 0x6d, 0x4f, 0x3d, 0x3e, 0x52, 0x67, 
	0x72, 0x5d, 0x43, 0x39, 0x32, 0x37, 0x38, 0x36, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x38, 0x37, 0x38, 
	0x54, 0x9f, 0x86, 0x40, 0xbd, 0xd2, 0xd3, 0xd4, 
	0xd2, 0xd2, 0xd0, 0xcf, 0xcd, 0xcb, 0xc9, 0xc6, 
	0xc2, 0xbf, 0xba, 0xb4, 0xae, 0xa8, 0x9f, 0x98, 
	0x37, 0x37, 0x37, 0x37, 0x37, 0x1f, 0x1b, 0x1c, 
	0x1c, 0x1d, 0x25, 0x4a, 0xd9, 0xde, 0xdc, 0xdc, 
	0xdd, 0xdd, 0xdc, 0xd6, 0xc6, 0xb1, 0x9f, 0x7f, 
	0x4f, 0x42, 0x47, 0x38, 0x37, 0x37, 0x37, 0x37, 
	0x37, 0x37, 0x37, 0x38, 0x37, 0x37, 0x37, 0x3c, 
	0xa9, 0xc8, 0xa7, 0xce, 0xd6, 0xd8, 0xd7, 0xd5, 
	0xd4, 0xd3, 0xd1, 0xcf, 0xce, 0xcd, 0xca, 0xc6, 
	0xc2, 0xbf, 0xbc, 0xb8, 0xb3, 0xad, 0xa6, 0x9f, 
	0x37, 0x37, 0x37, 0x38, 0x37, 0x30, 0x1c, 0x1b, 
	0x1b, 0x1b, 0x1d, 0x3e, 0xd9, 0xda, 0xda, 0xda, 
	0xdb, 0xdb, 0xdb, 0xdb, 0xdb, 0xdc, 0xdd, 0xdc, 
	0xc7, 0x76, 0x40, 0x38, 0x37, 0x37, 0x38, 0x38, 
	0x37, 0x3a, 0x3d, 0x41, 0x43, 0x3d, 0x38, 0x40, 
	0xba, 0xd4, 0xd8, 0xda, 0xdb, 0xd9, 0xd9, 0xd8, 
	0xd6, 0xd5, 0xd3, 0xd1, 0xd0, 0xce, 0xcb, 0xc7, 
	0xc4, 0xc0, 0xbc, 0xb9, 0xb5, 0xb0, 0xac, 0xa6, 
	0x37, 0x36, 0x38, 0x3a, 0x38, 0x38, 0x31, 0x1c, 
	0x1a, 0x1b, 0x1d, 0x3e, 0xd5, 0xd7, 0xd7, 0xd8, 
	0xd8, 0xd8, 0xd8, 0xd9, 0xd8, 0xcf, 0xab, 0x67, 
	0x3f, 0x38, 0x39, 0x3e, 0x49, 0x56, 0x63, 0x6a, 
	0x66, 0x58, 0x4c, 0x54, 0x64, 0x79, 0x7a, 0x31, 
	0x37, 0xd5, 0xdd, 0xdc, 0xdb, 0xdc, 0xdd, 0xdc, 
	0xdc, 0xd9, 0xd6, 0xd3, 0xd1, 0xcf, 0xcc, 0xc8, 
	0xc4, 0xc0, 0xbd, 0xb9, 0xb5, 0xb2, 0xae, 0xaa, 
	0x36, 0x37, 0x50, 0xd3, 0x7f, 0x3f, 0x38, 0x30, 
	0x1b, 0x1b, 0x3e, 0x9c, 0xd0, 0xd3, 0xd5, 0xd5, 
	0xd4, 0xd5, 0xd3, 0xb7, 0x78, 0x43, 0x39, 0x43, 
	0x50, 0x5b, 0x5b, 0x54, 0x54, 0x5d, 0x6f, 0x85, 
	0xa5, 0xc3, 0xdd, 0xe3, 0x9f, 0x39, 0x04, 0x02, 
	0x3a, 0xd5, 0xdc, 0xda, 0xda, 0xde, 0xe3, 0xe8, 
	0xe6, 0xdf, 0xd9, 0xd4, 0xd2, 0xcf, 0xcb, 0xc7, 
	0xc3, 0xbf, 0xbb, 0xb7, 0xb2, 0xaf, 0xab, 0xa8, 
	0x36, 0x47, 0xd1, 0xe1, 0xd4, 0xc3, 0x7d, 0x3e, 
	0x39, 0x7f, 0xad, 0xb4, 0xba, 0xc1, 0xc6, 0xc5, 
	0x95, 0x85, 0x5d, 0x3a, 0x36, 0x37, 0x47, 0x5f, 
	0x79, 0x93, 0xa9, 0xbe, 0xcb, 0xd0, 0xd3, 0xd5, 
	0xd4, 0xc7, 0x6f, 0x17, 0x03, 0x02, 0x01, 0x02, 
	0x61, 0xd9, 0xda, 0xda, 0xdb, 0xe1, 0xe8, 0xf0, 
	0xea, 0xe1, 0xd7, 0xd1, 0xcd, 0xc9, 0xc5, 0xc1, 
	0xbd, 0xb9, 0xb5, 0xb1, 0xad, 0xaa, 0xa5, 0x9f, 
	0x3a, 0xa2, 0xd0, 0xd2, 0xcf, 0xcb, 0xc8, 0xb8, 
	0x84, 0xa2, 0xa6, 0xaa, 0xad, 0xb1, 0x99, 0x4e, 
	0x38, 0x35, 0x3e, 0x59, 0x8a, 0xb4, 0xc9, 0xcf, 
	0xd0, 0xcf, 0xce, 0xce, 0xcd, 0xcd, 0xcc, 0xcb, 
	0x60, 0x09, 0x02, 0x01, 0x01, 0x01, 0x01, 0x05, 
	0xa5, 0xd9, 0xd8, 0xd7, 0xd8, 0xdb, 0xe0, 0xe3, 
	0xe0, 0xda, 0xd3, 0xcc, 0xc7, 0xc3, 0xbf, 0xbc, 
	0xb7, 0xb4, 0xb0, 0xac, 0xa8, 0xa4, 0x9e, 0x97, 
	0x66, 0x8f, 0xa5, 0xb0, 0xb5, 0xb8, 0xbb, 0xbc, 
	0xbc, 0xa9, 0xa5, 0xa8, 0xa1, 0x71, 0x3f, 0x4f, 
	0x73, 0xa0, 0xbb, 0xc4, 0xc8, 0xca, 0xcc, 0xcc, 
	0xcc, 0xcb, 0xcb, 0xca, 0xc9, 0xc8, 0xc7, 0xc6, 
	0xbe, 0x1b, 0x01, 0x01, 0x01, 0x01, 0x01, 0x17, 
	0xc9, 0xd5, 0xd4, 0xd3, 0xd3, 0xd3, 0xd4, 0xd4, 
	0xd2, 0xd0, 0xcc, 0xc6, 0xc2, 0xbe, 0xba, 0xb6, 
	0xb3, 0xae, 0xaa, 0xa6, 0xa3, 0x9e, 0x97, 0x8e, 
	0x22, 0x44, 0x6e, 0x83, 0x88, 0x8c, 0x8f, 0x92, 
	0x93, 0x9b, 0xa7, 0xa5, 0x7e, 0x8b, 0xab, 0xb4, 
	0xb8, 0xbc, 0xbf, 0xc2, 0xc3, 0xc3, 0xc4, 0xba, 
	0xae, 0xba, 0xc5, 0xc5, 0xc5, 0xc4, 0xc2, 0xbd, 
	0x3f, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x3a, 
	0xce, 0xd0, 0xd0, 0xcf, 0xce, 0xcd, 0xcc, 0xcb, 
	0xc9, 0xc7, 0xc3, 0xbf, 0xbc, 0xb8, 0xb4, 0xb1, 
	0xac, 0xa8, 0xa4, 0xa0, 0x9c, 0x95, 0x8d, 0x85, 
	0x51, 0x2f, 0x47, 0x40, 0x3f, 0x45, 0x42, 0x3e, 
	0x4e, 0x68, 0xa8, 0xa8, 0xa8, 0xab, 0xae, 0xb3, 
	0xb6, 0xb9, 0xbb, 0xbb, 0xbc, 0xbb, 0xbc, 0x90, 
	0x27, 0x2f, 0x89, 0xb7, 0xbe, 0xbf, 0xba, 0x4e, 
	0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x4a, 
	0xcb, 0xcc, 0xcb, 0xca, 0xc9, 0xc9, 0xc8, 0xc7, 
	0xc5, 0xc2, 0xbd, 0xb9, 0xb6, 0xb1, 0xaf, 0xaa, 
	0xa6, 0xa2, 0x9f, 0x9b, 0x95, 0x8c, 0x84, 0x7d, 
	0x66, 0x65, 0x65, 0x4e, 0x28, 0x66, 0x69, 0x40, 
	0x95, 0x7a, 0x9a, 0xa6, 0xa8, 0xaa, 0xac, 0xb0, 
	0xb2, 0xb2, 0xb3, 0xb3, 0xb4, 0xb4, 0xb5, 0xb5, 
	0x8c, 0x24, 0x16, 0x2b, 0x73, 0xa3, 0x55, 0x03, 
	0x02, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x20, 
	0xbb, 0xc0, 0xc1, 0xc1, 0xc2, 0xc2, 0xc1, 0xc1, 
	0xbe, 0xba, 0xb6, 0xb2, 0xae, 0xaa, 0xa6, 0xa3, 
	0x9e, 0x99, 0x96, 0x92, 0x8d, 0x85, 0x7c, 0x74, 
	0x55, 0x61, 0x68, 0x69, 0x4e, 0x72, 0x7f, 0x54, 
	0xaf, 0x9a, 0x70, 0x9c, 0xa2, 0xa7, 0xa9, 0xa9, 
	0xaa, 0xaa, 0xaa, 0xaa, 0xab, 0xac, 0xad, 0xad, 
	0xad, 0x89, 0x26, 0x17, 0x1d, 0x45, 0x04, 0x02, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x0b, 
	0x8e, 0xb1, 0xb1, 0xb3, 0xb3, 0xb3, 0xb3, 0xb2, 
	0xae, 0xaa, 0xa6, 0xa2, 0x9e, 0x9a, 0x96, 0x92, 
	0x8e, 0x8a, 0x87, 0x85, 0x83, 0x7e, 0x75, 0x6d, 
	0x44, 0x51, 0x45, 0x5d, 0x64, 0x46, 0x5f, 0x68, 
	0x93, 0xa4, 0xa7, 0x8a, 0x96, 0x9b, 0x9d, 0x9e, 
	0x9d, 0x9d, 0x9d, 0x9e, 0x9f, 0xa0, 0xa1, 0xa1, 
	0xa2, 0xa3, 0x85, 0x29, 0x0f, 0x03, 0x02, 0x02, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 
	0x38, 0xa0, 0xa2, 0xa2, 0xa2, 0xa1, 0xa1, 0xa0, 
	0x9d, 0x99, 0x95, 0x91, 0x8e, 0x8a, 0x85, 0x81, 
	0x7e, 0x7b, 0x79, 0x77, 0x75, 0x73, 0x6e, 0x66, 
	0x2c, 0x3b, 0x1c, 0x4f, 0x59, 0x52, 0x62, 0x65, 
	0x7a, 0x90, 0x99, 0x7e, 0x8a, 0x8e, 0x91, 0x93, 
	0x94, 0x92, 0x92, 0x91, 0x91, 0x92, 0x92, 0x93, 
	0x94, 0x94, 0x95, 0x51, 0x04, 0x02, 0x02, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 
	0x08, 0x61, 0x90, 0x90, 0x90, 0x90, 0x8f, 0x8d, 
	0x8a, 0x87, 0x84, 0x81, 0x7c, 0x78, 0x74, 0x72, 
	0x6f, 0x6d, 0x6b, 0x6a, 0x67, 0x65, 0x63, 0x5e, 
	0x20, 0x16, 0x1a, 0x42, 0x41, 0x27, 0x3d, 0x59, 
	0x62, 0x4c, 0x5a, 0x5e, 0x68, 0x7f, 0x83, 0x87, 
	0x8a, 0x89, 0x88, 0x87, 0x86, 0x85, 0x85, 0x86, 
	0x86, 0x86, 0x69, 0x0b, 0x02, 0x02, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x02, 0x05, 0x36, 0x77, 0x7f, 0x7e, 0x7c, 0x7b, 
	0x78, 0x75, 0x72, 0x70, 0x6c, 0x69, 0x67, 0x65, 
	0x63, 0x60, 0x5e, 0x5b, 0x59, 0x57, 0x56, 0x54, 
	0x1a, 0x15, 0x15, 0x25, 0x19, 0x19, 0x1d, 0x26, 
	0x24, 0x24, 0x27, 0x2e, 0x23, 0x38, 0x5f, 0x78, 
	0x7d, 0x7f, 0x7e, 0x7d, 0x7d, 0x7c, 0x7b, 0x79, 
	0x79, 0x5e, 0x0c, 0x02, 0x02, 0x01, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
	0x01, 0x02, 0x02, 0x17, 0x55, 0x6c, 0x6a, 0x67, 
	0x65, 0x63, 0x61, 0x60, 0x5f, 0x5e, 0x5d, 0x5b, 
	0x59, 0x58, 0x56, 0x55, 0x53, 0x52, 0x52, 0x4d, 
	0x0e, 0x12, 0x15, 0x14, 0x18, 0x17, 0x19, 0x1b, 
	0x1c, 0x1f, 0x21, 0x21, 0x22, 0x24, 0x1f, 0x39, 
	0x65, 0x72, 0x73, 0x73, 0x72, 0x72, 0x71, 0x70, 
	0x5c, 0x11, 0x02, 0x01, 0x02, 0x02, 0x02, 0x01, 
	0x02, 0x01, 0x02, 0x01, 0x02, 0x01, 0x01, 0x01, 
	0x01, 0x01, 0x01, 0x02, 0x08, 0x39, 0x53, 0x55, 
	0x56, 0x57, 0x57, 0x58, 0x58, 0x59, 0x58, 0x56, 
	0x54, 0x54, 0x4c, 0x44, 0x3a, 0x32, 0x22, 0x19, 
	0x0d, 0x10, 0x10, 0x12, 0x15, 0x16, 0x16, 0x19, 
	0x1a, 0x19, 0x1c, 0x20, 0x1f, 0x22, 0x1c, 0x1c, 
	0x1a, 0x3f, 0x63, 0x68, 0x68, 0x68, 0x67, 0x67, 
	0x58, 0x49, 0x41, 0x35, 0x31, 0x2e, 0x26, 0x23, 
	0x20, 0x18, 0x15, 0x12, 0x0c, 0x07, 0x06, 0x03, 
	0x02, 0x02, 0x02, 0x01, 0x02, 0x04, 0x08, 0x0e, 
	0x17, 0x26, 0x2a, 0x2d, 0x30, 0x33, 0x34, 0x37, 
	0x2c, 0x20, 0x1b, 0x1a, 0x1c, 0x1d, 0x1e, 0x1d, 
	0x0a, 0x0b, 0x0e, 0x0e, 0x10, 0x18, 0x14, 0x16, 
	0x15, 0x15, 0x18, 0x17, 0x16, 0x19, 0x17, 0x17, 
	0x15, 0x12, 0x14, 0x39, 0x5b, 0x5f, 0x5e, 0x5e, 
	0x5e, 0x5f, 0x5e, 0x5e, 0x5e, 0x5f, 0x5e, 0x5f, 
	0x5e, 0x5f, 0x5e, 0x5d, 0x5c, 0x5a, 0x57, 0x50, 
	0x4a, 0x38, 0x21, 0x0c, 0x0c, 0x09, 0x08, 0x14, 
	0x31, 0x24, 0x13, 0x12, 0x12, 0x15, 0x1a, 0x1f, 
	0x1b, 0x1d, 0x1c, 0x20, 0x1d, 0x1e, 0x17, 0x1a, 
	0x08, 0x09, 0x09, 0x0a, 0x0e, 0x0d, 0x0c, 0x10, 
	0x0f, 0x10, 0x11, 0x11, 0x0f, 0x0c, 0x0e, 0x0c, 
	0x0e, 0x09, 0x0a, 0x05, 0x16, 0x35, 0x4c, 0x56, 
	0x58, 0x57, 0x57, 0x57, 0x57, 0x56, 0x56, 0x56, 
	0x56, 0x56, 0x57, 0x57, 0x58, 0x5c, 0x5f, 0x62, 
	0x64, 0x68, 0x68, 0x34, 0x1d, 0x1d, 0x1c, 0x1e, 
	0x4c, 0x7f, 0x26, 0x11, 0x14, 0x14, 0x17, 0x13, 
	0x13, 0x19, 0x16, 0x17, 0x16, 0x13, 0x10, 0x0c, 
	0x09, 0x09, 0x0b, 0x0f, 0x12, 0x10, 0x10, 0x15, 
	0x13, 0x13, 0x15, 0x13, 0x13, 0x0f, 0x11, 0x0f, 
	0x0d, 0x0c, 0x0c, 0x06, 0x04, 0x05, 0x0f, 0x23, 
	0x3e, 0x50, 0x55, 0x55, 0x55, 0x54, 0x54, 0x55, 
	0x54, 0x54, 0x54, 0x54, 0x53, 0x56, 0x56, 0x5f, 
	0x63, 0x6a, 0x65, 0x2e, 0x24, 0x23, 0x24, 0x25, 
	0x48, 0x8c, 0x32, 0x20, 0x1d, 0x1b, 0x19, 0x14, 
	0x15, 0x19, 0x17, 0x18, 0x18, 0x15, 0x11, 0x0f, 
	0x0c, 0x0e, 0x12, 0x12, 0x14, 0x14, 0x15, 0x15, 
	0x15, 0x19, 0x17, 0x19, 0x14, 0x14, 0x12, 0x0f, 
	0x0e, 0x0d, 0x0b, 0x0a, 0x08, 0x04, 0x13, 0x0d, 
	0x0f, 0x1a, 0x30, 0x49, 0x52, 0x53, 0x53, 0x53, 
	0x52, 0x52, 0x52, 0x52, 0x52, 0x53, 0x46, 0x3c, 
	0x5e, 0x6c, 0x64, 0x25, 0x23, 0x24, 0x25, 0x25, 
	0x43, 0x62, 0x21, 0x25, 0x21, 0x1c, 0x19, 0x19, 
	0x16, 0x16, 0x16, 0x1a, 0x18, 0x17, 0x15, 0x15, 
	0x0e, 0x13, 0x15, 0x16, 0x15, 0x1a, 0x17, 0x19, 
	0x1b, 0x18, 0x19, 0x17, 0x16, 0x17, 0x14, 0x14, 
	0x14, 0x0f, 0x0c, 0x0b, 0x09, 0x05, 0x11, 0x10, 
	0x10, 0x18, 0x1d, 0x21, 0x30, 0x4e, 0x51, 0x52, 
	0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x51, 0x48, 
	0x5f, 0x70, 0x53, 0x23, 0x23, 0x24, 0x25, 0x25, 
	0x37, 0x57, 0x3b, 0x25, 0x23, 0x1e, 0x18, 0x1e, 
	0x17, 0x1d, 0x19, 0x19, 0x19, 0x18, 0x14, 0x17, 
	0x24, 0x22, 0x2d, 0x23, 0x1b, 0x32, 0x3b, 0x2d, 
	0x22, 0x2b, 0x1f, 0x38, 0x37, 0x28, 0x17, 0x18, 
	0x15, 0x11, 0x11, 0x0b, 0x0a, 0x08, 0x0f, 0x11, 
	0x1a, 0x38, 0x34, 0x50, 0x31, 0x2b, 0x45, 0x50, 
	0x52, 0x52, 0x52, 0x52, 0x52, 0x52, 0x53, 0x56, 
	0x66, 0x75, 0x64, 0x52, 0x4e, 0x4f, 0x6b, 0x82, 
	0x92, 0x79, 0x4d, 0x38, 0x44, 0x28, 0x1f, 0x38, 
	0x3c, 0x26, 0x24, 0x2a, 0x24, 0x39, 0x38, 0x1f, 
	0x2c, 0x2b, 0x3f, 0x35, 0x3d, 0x44, 0x41, 0x45, 
	0x46, 0x37, 0x22, 0x47, 0x2d, 0x45, 0x1b, 0x17, 
	0x16, 0x12, 0x0f, 0x0c, 0x0a, 0x08, 0x0f, 0x14, 
	0x33, 0x38, 0x3f, 0x62, 0x55, 0x54, 0x54, 0x3e, 
	0x41, 0x43, 0x3b, 0x4a, 0x50, 0x50, 0x52, 0x56, 
	0x65, 0x79, 0x98, 0xa4, 0xa5, 0xa2, 0x9d, 0x96, 
	0x8d, 0x5c, 0x36, 0x44, 0x53, 0x44, 0x37, 0x4c, 
	0x3d, 0x48, 0x41, 0x31, 0x2d, 0x3a, 0x35, 0x3f, 
	0x3a, 0x26, 0x3f, 0x30, 0x48, 0x45, 0x3a, 0x45, 
	0x51, 0x42, 0x25, 0x51, 0x39, 0x35, 0x1b, 0x18, 
	0x16, 0x14, 0x13, 0x0f, 0x0c, 0x09, 0x0f, 0x11, 
	0x2b, 0x3b, 0x29, 0x54, 0x40, 0x67, 0x69, 0x49, 
	0x5b, 0x64, 0x52, 0x28, 0x55, 0x4a, 0x33, 0x45, 
	0x61, 0x71, 0x7f, 0x81, 0x7e, 0x7c, 0x6d, 0x54, 
	0x3c, 0x37, 0x46, 0x34, 0x4f, 0x3a, 0x44, 0x4b, 
	0x31, 0x4d, 0x4f, 0x3b, 0x2f, 0x49, 0x44, 0x2a, 
	0x37, 0x42, 0x43, 0x3f, 0x4c, 0x4b, 0x52, 0x53, 
	0x52, 0x3f, 0x3c, 0x50, 0x41, 0x44, 0x20, 0x19, 
	0x18, 0x15, 0x13, 0x10, 0x0c, 0x0a, 0x10, 0x13, 
	0x21, 0x3b, 0x45, 0x51, 0x48, 0x60, 0x67, 0x73, 
	0x75, 0x7a, 0x5b, 0x52, 0x7c, 0x6e, 0x5b, 0x22, 
	0x20, 0x24, 0x26, 0x26, 0x24, 0x1f, 0x12, 0x13, 
	0x17, 0x2b, 0x4f, 0x50, 0x4f, 0x45, 0x4c, 0x51, 
	0x52, 0x53, 0x51, 0x3f, 0x3b, 0x48, 0x4b, 0x3c, 
	0x3f, 0x32, 0x27, 0x44, 0x38, 0x4e, 0x44, 0x29, 
	0x4d, 0x53, 0x4b, 0x53, 0x26, 0x3d, 0x1c, 0x19, 
	0x1a, 0x1e, 0x1a, 0x12, 0x13, 0x0b, 0x11, 0x15, 
	0x2d, 0x41, 0x2e, 0x30, 0x4a, 0x37, 0x5f, 0x4c, 
	0x35, 0x6e, 0x74, 0x67, 0x7a, 0x3a, 0x5c, 0x25, 
	0x22, 0x23, 0x2a, 0x22, 0x17, 0x1b, 0x10, 0x1a, 
	0x1f, 0x43, 0x4f, 0x33, 0x36, 0x48, 0x31, 0x58, 
	0x38, 0x2c, 0x52, 0x54, 0x49, 0x49, 0x29, 0x39, 
	0x1b, 0x1a, 0x1a, 0x1d, 0x1d, 0x28, 0x23, 0x20, 
	0x26, 0x24, 0x21, 0x25, 0x2e, 0x24, 0x1c, 0x1b, 
	0x24, 0x25, 0x19, 0x1b, 0x17, 0x0e, 0x12, 0x15, 
	0x17, 0x1b, 0x1a, 0x1a, 0x1f, 0x20, 0x2b, 0x24, 
	0x25, 0x2b, 0x2a, 0x28, 0x2f, 0x39, 0x2c, 0x25, 
	0x25, 0x34, 0x31, 0x25, 0x26, 0x1e, 0x11, 0x19, 
	0x1c, 0x1e, 0x1c, 0x1c, 0x1c, 0x1e, 0x20, 0x2a, 
	0x21, 0x22, 0x25, 0x24, 0x20, 0x29, 0x2c, 0x20, 
	0x42, 0x27, 0x4b, 0x29, 0x22, 0x2f, 0x27, 0x27, 
	0x52, 0x5b, 0x4a, 0x34, 0x54, 0x35, 0x1c, 0x1b, 
	0x26, 0x23, 0x21, 0x1a, 0x18, 0x12, 0x12, 0x14, 
	0x2a, 0x3d, 0x2d, 0x49, 0x24, 0x22, 0x2f, 0x27, 
	0x28, 0x5c, 0x60, 0x50, 0x35, 0x5e, 0x36, 0x21, 
	0x21, 0x2e, 0x27, 0x27, 0x21, 0x1d, 0x11, 0x19, 
	0x17, 0x31, 0x40, 0x31, 0x46, 0x25, 0x21, 0x31, 
	0x24, 0x2a, 0x5a, 0x58, 0x48, 0x37, 0x52, 0x29, 
	0x46, 0x42, 0x48, 0x43, 0x24, 0x4f, 0x49, 0x24, 
	0x52, 0x52, 0x60, 0x53, 0x4e, 0x3a, 0x2f, 0x34, 
	0x25, 0x19, 0x16, 0x12, 0x0f, 0x0d, 0x13, 0x16, 
	0x36, 0x44, 0x44, 0x4a, 0x3a, 0x29, 0x50, 0x46, 
	0x26, 0x59, 0x4c, 0x60, 0x52, 0x53, 0x36, 0x34, 
	0x36, 0x24, 0x1a, 0x18, 0x12, 0x11, 0x0d, 0x17, 
	0x18, 0x3e, 0x46, 0x46, 0x4d, 0x35, 0x2e, 0x51, 
	0x40, 0x26, 0x5b, 0x4e, 0x5f, 0x4c, 0x4f, 0x2a, 
	0x42, 0x46, 0x4c, 0x4d, 0x3d, 0x4a, 0x4e, 0x31, 
	0x53, 0x46, 0x4a, 0x58, 0x4c, 0x4c, 0x4d, 0x48, 
	0x40, 0x1d, 0x13, 0x10, 0x10, 0x0a, 0x15, 0x17, 
	0x3a, 0x43, 0x48, 0x4b, 0x4a, 0x46, 0x46, 0x51, 
	0x2f, 0x5c, 0x3a, 0x50, 0x4e, 0x4f, 0x49, 0x4d, 
	0x48, 0x3f, 0x1a, 0x12, 0x0f, 0x0e, 0x09, 0x17, 
	0x19, 0x3f, 0x41, 0x46, 0x4d, 0x44, 0x49, 0x42, 
	0x51, 0x2b, 0x5f, 0x38, 0x53, 0x47, 0x50, 0x49, 
	0x36, 0x45, 0x31, 0x4c, 0x51, 0x35, 0x46, 0x4b, 
	0x53, 0x52, 0x57, 0x30, 0x47, 0x58, 0x3b, 0x28, 
	0x42, 0x32, 0x13, 0x12, 0x0d, 0x0a, 0x10, 0x1b, 
	0x3b, 0x39, 0x44, 0x35, 0x4e, 0x52, 0x33, 0x4b, 
	0x43, 0x5b, 0x51, 0x58, 0x2c, 0x4a, 0x56, 0x37, 
	0x28, 0x45, 0x2f, 0x13, 0x13, 0x0d, 0x0a, 0x13, 
	0x22, 0x3a, 0x3e, 0x3e, 0x39, 0x4d, 0x51, 0x2e, 
	0x50, 0x3f, 0x58, 0x52, 0x53, 0x2d, 0x4b, 0x54, 
	0x2a, 0x30, 0x1a, 0x49, 0x54, 0x4f, 0x56, 0x50, 
	0x59, 0x4f, 0x56, 0x4e, 0x4b, 0x4d, 0x3e, 0x2f, 
	0x42, 0x2b, 0x13, 0x11, 0x0e, 0x09, 0x11, 0x1e, 
	0x38, 0x29, 0x2d, 0x1d, 0x4e, 0x55, 0x4f, 0x55, 
	0x4e, 0x5e, 0x4b, 0x55, 0x4b, 0x50, 0x4c, 0x3b, 
	0x31, 0x44, 0x27, 0x12, 0x0f, 0x0c, 0x08, 0x14, 
	0x20, 0x3a, 0x27, 0x2a, 0x24, 0x4f, 0x55, 0x4e, 
	0x57, 0x4b, 0x5b, 0x4d, 0x52, 0x46, 0x4f, 0x4c, 
	
};

Gfx yeah_tex1_ci4_aligner[] = {gsSPEndDisplayList()};
u8 yeah_tex1_ci4[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x10, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 
	0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 
	0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x11, 0x11, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx yeah_tex1_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 yeah_tex1_pal_rgba16[] = {
	0xff, 0xff, 0x52, 0x0b, 
};

Gfx yeah_tex10_ci4_aligner[] = {gsSPEndDisplayList()};
u8 yeah_tex10_ci4[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x10, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x11, 
	0x10, 0x00, 0x00, 0x11, 0x11, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 
	0x01, 0x11, 0x11, 0x01, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
	0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
	0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
	0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x01, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx yeah_tex10_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 yeah_tex10_pal_rgba16[] = {
	0xff, 0xff, 0x52, 0x0b, 
};

Gfx yeah_tex7_ci4_aligner[] = {gsSPEndDisplayList()};
u8 yeah_tex7_ci4[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x11, 
	0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x00, 
	0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x10, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 
	0x01, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 
	0x00, 0x00, 0x11, 0x11, 0x11, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 
	0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
	0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x11, 0x11, 
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x11, 0x11, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx yeah_tex7_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 yeah_tex7_pal_rgba16[] = {
	0xff, 0xff, 0x52, 0x0b, 
};

Gfx yeah_tex_ci4_aligner[] = {gsSPEndDisplayList()};
u8 yeah_tex_ci4[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x11, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x10, 
	0x00, 0x01, 0x11, 0x11, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 
	0x11, 0x11, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 
	0x01, 0x10, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x10, 
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 
	0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 
	0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 
	0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 
	0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x11, 
	0x10, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x01, 0x11, 
	0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x10, 0x00, 0x11, 0x00, 
	0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x01, 0x11, 0x11, 0x11, 
	0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	
};

Gfx yeah_tex_pal_rgba16_aligner[] = {gsSPEndDisplayList()};
u8 yeah_tex_pal_rgba16[] = {
	0xff, 0xff, 0x52, 0x0b, 
};

Vtx yeah_Plane_mesh_vtx_cull[8] = {
	{{ {-856, -86, -821}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-856, -86, 813}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-856, 421, 813}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-856, 421, -821}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {891, -86, -821}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {891, -86, 813}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {891, 421, 813}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {891, 421, -821}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx yeah_Plane_mesh_vtx_0[171] = {
	{{ {206, 0, -117}, 0, {3807, -552}, {33, 0, 133, 255} }},
	{{ {470, -86, -46}, 0, {6275, 256}, {33, 0, 133, 255} }},
	{{ {206, -86, -117}, 0, {3807, 256}, {33, 0, 133, 255} }},
	{{ {470, 0, -46}, 0, {6275, -552}, {33, 0, 133, 255} }},
	{{ {256, 0, -393}, 0, {2554, -552}, {125, 0, 20, 255} }},
	{{ {240, -86, -289}, 0, {1574, 256}, {125, 0, 22, 255} }},
	{{ {256, -86, -393}, 0, {2554, 256}, {125, 0, 20, 255} }},
	{{ {240, 0, -289}, 0, {1574, -552}, {125, 0, 22, 255} }},
	{{ {206, 0, -117}, 0, {-40, -552}, {125, 0, 24, 255} }},
	{{ {206, -86, -117}, 0, {-40, 256}, {125, 0, 24, 255} }},
	{{ {524, 0, -218}, 0, {910, -552}, {134, 0, 219, 255} }},
	{{ {470, -86, -46}, 0, {-705, 256}, {135, 0, 218, 255} }},
	{{ {470, 0, -46}, 0, {-705, -552}, {135, 0, 218, 255} }},
	{{ {524, -86, -218}, 0, {910, 256}, {134, 0, 219, 255} }},
	{{ {579, 0, -411}, 0, {2720, -552}, {134, 0, 221, 255} }},
	{{ {579, -86, -411}, 0, {2720, 256}, {134, 0, 221, 255} }},
	{{ {413, 0, -458}, 0, {5745, -552}, {221, 0, 122, 255} }},
	{{ {579, -86, -411}, 0, {7302, 256}, {221, 0, 122, 255} }},
	{{ {579, 0, -411}, 0, {7302, -552}, {221, 0, 122, 255} }},
	{{ {413, -86, -458}, 0, {5745, 256}, {221, 0, 122, 255} }},
	{{ {333, -52, -371}, 0, {4995, -2838}, {0, 127, 0, 255} }},
	{{ {375, -52, -469}, 0, {5384, -3752}, {0, 127, 0, 255} }},
	{{ {362, -52, -472}, 0, {5264, -3786}, {0, 127, 0, 255} }},
	{{ {346, -52, -368}, 0, {5116, -2804}, {0, 127, 0, 255} }},
	{{ {256, -9, -393}, 0, {4274, -471}, {221, 0, 122, 255} }},
	{{ {269, 0, -390}, 0, {4394, -552}, {221, 0, 122, 255} }},
	{{ {256, 0, -393}, 0, {4274, -552}, {221, 0, 122, 255} }},
	{{ {269, -9, -390}, 0, {4394, -471}, {221, 0, 122, 255} }},
	{{ {269, -17, -390}, 0, {4394, -390}, {221, 0, 122, 255} }},
	{{ {256, -86, -393}, 0, {4274, 256}, {221, 0, 122, 255} }},
	{{ {282, -26, -386}, 0, {4514, -309}, {221, 0, 122, 255} }},
	{{ {295, -34, -382}, 0, {4634, -229}, {221, 0, 122, 255} }},
	{{ {308, -43, -379}, 0, {4755, -148}, {221, 0, 122, 255} }},
	{{ {295, -34, -382}, 0, {4634, -229}, {221, 0, 122, 255} }},
	{{ {256, -86, -393}, 0, {4274, 256}, {221, 0, 122, 255} }},
	{{ {320, -52, -375}, 0, {4875, -67}, {221, 0, 122, 255} }},
	{{ {333, -60, -371}, 0, {4995, 14}, {221, 0, 122, 255} }},
	{{ {346, -69, -368}, 0, {5116, 94}, {221, 0, 122, 255} }},
	{{ {359, -77, -364}, 0, {5236, 175}, {221, 0, 122, 255} }},
	{{ {372, -86, -360}, 0, {5356, 256}, {221, 0, 122, 255} }},
	{{ {372, -77, -360}, 0, {5356, 175}, {221, 0, 122, 255} }},
	{{ {384, -86, -357}, 0, {5477, 256}, {221, 0, 122, 255} }},
	{{ {384, -77, -357}, 0, {5477, 175}, {221, 0, 122, 255} }},
	{{ {359, -69, -364}, 0, {5236, 94}, {221, 0, 122, 255} }},
	{{ {372, -69, -360}, 0, {5356, 94}, {221, 0, 122, 255} }},
	{{ {346, -60, -368}, 0, {5116, 14}, {221, 0, 122, 255} }},
	{{ {359, -60, -364}, 0, {5236, 14}, {221, 0, 122, 255} }},
	{{ {333, -52, -371}, 0, {4995, -67}, {221, 0, 122, 255} }},
	{{ {346, -52, -368}, 0, {5116, -67}, {221, 0, 122, 255} }},
	{{ {320, -43, -375}, 0, {4875, -148}, {221, 0, 122, 255} }},
	{{ {333, -43, -371}, 0, {4995, -148}, {221, 0, 122, 255} }},
	{{ {320, -34, -375}, 0, {4875, -229}, {221, 0, 122, 255} }},
	{{ {308, -34, -379}, 0, {4755, -229}, {221, 0, 122, 255} }},
	{{ {295, -26, -382}, 0, {4634, -309}, {221, 0, 122, 255} }},
	{{ {308, -26, -379}, 0, {4755, -309}, {221, 0, 122, 255} }},
	{{ {282, -26, -386}, 0, {4514, -309}, {221, 0, 122, 255} }},
	{{ {295, -17, -382}, 0, {4634, -390}, {221, 0, 122, 255} }},
	{{ {282, -17, -386}, 0, {4514, -390}, {221, 0, 122, 255} }},
	{{ {269, -17, -390}, 0, {4394, -390}, {221, 0, 122, 255} }},
	{{ {269, -9, -390}, 0, {4394, -471}, {221, 0, 122, 255} }},
	{{ {282, -9, -386}, 0, {4514, -471}, {221, 0, 122, 255} }},
	{{ {320, -43, -375}, 0, {2384, -148}, {122, 0, 35, 255} }},
	{{ {349, -34, -476}, 0, {3332, -229}, {122, 0, 35, 255} }},
	{{ {320, -34, -375}, 0, {2384, -229}, {122, 0, 35, 255} }},
	{{ {320, -43, -375}, 0, {2384, -148}, {122, 0, 35, 255} }},
	{{ {349, -43, -476}, 0, {3332, -148}, {122, 0, 35, 255} }},
	{{ {349, -34, -476}, 0, {3332, -229}, {122, 0, 35, 255} }},
	{{ {295, -17, -382}, 0, {2452, -390}, {122, 0, 35, 255} }},
	{{ {323, -26, -483}, 0, {3400, -309}, {122, 0, 35, 255} }},
	{{ {323, -17, -483}, 0, {3400, -390}, {122, 0, 35, 255} }},
	{{ {295, -26, -382}, 0, {2452, -309}, {122, 0, 35, 255} }},
	{{ {372, -77, -360}, 0, {2247, 175}, {122, 0, 35, 255} }},
	{{ {400, -69, -462}, 0, {3195, 94}, {122, 0, 35, 255} }},
	{{ {372, -69, -360}, 0, {2247, 94}, {122, 0, 35, 255} }},
	{{ {400, -77, -462}, 0, {3195, 175}, {122, 0, 35, 255} }},
	{{ {333, -43, -371}, 0, {4995, -2838}, {0, 127, 0, 255} }},
	{{ {349, -43, -476}, 0, {5143, -3820}, {0, 127, 0, 255} }},
	{{ {320, -43, -375}, 0, {4875, -2872}, {0, 127, 0, 255} }},
	{{ {362, -43, -472}, 0, {5264, -3786}, {0, 127, 0, 255} }},
	{{ {372, -77, -360}, 0, {5356, -2736}, {0, 127, 0, 255} }},
	{{ {413, -77, -458}, 0, {5745, -3650}, {0, 127, 0, 255} }},
	{{ {400, -77, -462}, 0, {5625, -3684}, {0, 127, 0, 255} }},
	{{ {384, -77, -357}, 0, {5477, -2702}, {0, 127, 0, 255} }},
	{{ {346, -60, -368}, 0, {2315, 14}, {122, 0, 35, 255} }},
	{{ {375, -52, -469}, 0, {3263, -67}, {122, 0, 35, 255} }},
	{{ {346, -52, -368}, 0, {2315, -67}, {122, 0, 35, 255} }},
	{{ {375, -60, -469}, 0, {3263, 14}, {122, 0, 35, 255} }},
	{{ {308, -26, -379}, 0, {4755, -2906}, {0, 127, 0, 255} }},
	{{ {323, -26, -483}, 0, {4903, -3888}, {0, 127, 0, 255} }},
	{{ {295, -26, -382}, 0, {4634, -2940}, {0, 127, 0, 255} }},
	{{ {336, -26, -480}, 0, {5023, -3854}, {0, 127, 0, 255} }},
	{{ {384, -77, -357}, 0, {2213, 175}, {122, 0, 35, 255} }},
	{{ {413, -86, -458}, 0, {3161, 256}, {122, 0, 35, 255} }},
	{{ {413, -77, -458}, 0, {3161, 175}, {122, 0, 35, 255} }},
	{{ {384, -86, -357}, 0, {2213, 256}, {122, 0, 35, 255} }},
	{{ {333, -52, -371}, 0, {2350, -67}, {122, 0, 35, 255} }},
	{{ {362, -43, -472}, 0, {3297, -148}, {122, 0, 35, 255} }},
	{{ {333, -43, -371}, 0, {2350, -148}, {122, 0, 35, 255} }},
	{{ {362, -52, -472}, 0, {3297, -67}, {122, 0, 35, 255} }},
	{{ {269, -9, -390}, 0, {4394, -3008}, {0, 127, 0, 255} }},
	{{ {310, -9, -487}, 0, {4783, -3922}, {0, 127, 0, 255} }},
	{{ {298, -9, -491}, 0, {4662, -3956}, {0, 127, 0, 255} }},
	{{ {282, -9, -386}, 0, {4514, -2974}, {0, 127, 0, 255} }},
	{{ {346, -60, -368}, 0, {5116, -2804}, {0, 127, 0, 255} }},
	{{ {387, -60, -465}, 0, {5504, -3718}, {0, 127, 0, 255} }},
	{{ {375, -60, -469}, 0, {5384, -3752}, {0, 127, 0, 255} }},
	{{ {359, -60, -364}, 0, {5236, -2770}, {0, 127, 0, 255} }},
	{{ {308, -26, -379}, 0, {2418, -309}, {122, 0, 35, 255} }},
	{{ {336, -34, -480}, 0, {3366, -229}, {122, 0, 35, 255} }},
	{{ {336, -26, -480}, 0, {3366, -309}, {122, 0, 35, 255} }},
	{{ {308, -34, -379}, 0, {2418, -229}, {122, 0, 35, 255} }},
	{{ {359, -60, -364}, 0, {2281, 14}, {122, 0, 35, 255} }},
	{{ {387, -69, -465}, 0, {3229, 94}, {122, 0, 35, 255} }},
	{{ {387, -60, -465}, 0, {3229, 14}, {122, 0, 35, 255} }},
	{{ {359, -69, -364}, 0, {2281, 94}, {122, 0, 35, 255} }},
	{{ {282, -9, -386}, 0, {2486, -471}, {122, 0, 35, 255} }},
	{{ {310, -17, -487}, 0, {3434, -390}, {122, 0, 35, 255} }},
	{{ {310, -9, -487}, 0, {3434, -471}, {122, 0, 35, 255} }},
	{{ {282, -17, -386}, 0, {2486, -390}, {122, 0, 35, 255} }},
	{{ {308, -34, -379}, 0, {4755, -2906}, {0, 127, 0, 255} }},
	{{ {349, -34, -476}, 0, {5143, -3820}, {0, 127, 0, 255} }},
	{{ {336, -34, -480}, 0, {5023, -3854}, {0, 127, 0, 255} }},
	{{ {320, -34, -375}, 0, {4875, -2872}, {0, 127, 0, 255} }},
	{{ {295, -17, -382}, 0, {4634, -2940}, {0, 127, 0, 255} }},
	{{ {310, -17, -487}, 0, {4783, -3922}, {0, 127, 0, 255} }},
	{{ {282, -17, -386}, 0, {4514, -2974}, {0, 127, 0, 255} }},
	{{ {323, -17, -483}, 0, {4903, -3888}, {0, 127, 0, 255} }},
	{{ {269, 0, -390}, 0, {2520, -552}, {122, 0, 35, 255} }},
	{{ {298, -9, -491}, 0, {3468, -471}, {122, 0, 35, 255} }},
	{{ {298, 0, -491}, 0, {3468, -552}, {122, 0, 35, 255} }},
	{{ {269, -9, -390}, 0, {2520, -471}, {122, 0, 35, 255} }},
	{{ {359, -69, -364}, 0, {5236, -2770}, {0, 127, 0, 255} }},
	{{ {400, -69, -462}, 0, {5625, -3684}, {0, 127, 0, 255} }},
	{{ {387, -69, -465}, 0, {5504, -3718}, {0, 127, 0, 255} }},
	{{ {372, -69, -360}, 0, {5356, -2736}, {0, 127, 0, 255} }},
	{{ {206, -86, -117}, 0, {3807, -449}, {0, 127, 0, 255} }},
	{{ {470, -86, -46}, 0, {6275, 217}, {0, 127, 0, 255} }},
	{{ {524, -86, -218}, 0, {6786, -1398}, {0, 127, 0, 255} }},
	{{ {240, -86, -289}, 0, {4119, -2062}, {0, 127, 0, 255} }},
	{{ {384, -86, -357}, 0, {5477, -2702}, {0, 127, 0, 255} }},
	{{ {579, -86, -411}, 0, {7302, -3209}, {0, 127, 0, 255} }},
	{{ {413, -86, -458}, 0, {5745, -3650}, {0, 127, 0, 255} }},
	{{ {372, -86, -360}, 0, {5356, -2736}, {0, 127, 0, 255} }},
	{{ {256, -86, -393}, 0, {4274, -3042}, {0, 127, 0, 255} }},
	{{ {269, 0, -390}, 0, {4394, -3008}, {0, 127, 0, 255} }},
	{{ {298, 0, -491}, 0, {4662, -3956}, {0, 127, 0, 255} }},
	{{ {285, 0, -494}, 0, {4542, -3990}, {0, 127, 0, 255} }},
	{{ {256, 0, -393}, 0, {4274, -3042}, {0, 127, 0, 255} }},
	{{ {298, 0, -491}, 0, {4662, -552}, {221, 0, 122, 255} }},
	{{ {298, -9, -491}, 0, {4662, -471}, {221, 0, 122, 255} }},
	{{ {310, -9, -487}, 0, {4783, -471}, {221, 0, 122, 255} }},
	{{ {413, 0, -458}, 0, {5745, -552}, {221, 0, 122, 255} }},
	{{ {323, -17, -483}, 0, {4903, -390}, {221, 0, 122, 255} }},
	{{ {310, -17, -487}, 0, {4783, -390}, {221, 0, 122, 255} }},
	{{ {336, -26, -480}, 0, {5023, -309}, {221, 0, 122, 255} }},
	{{ {323, -26, -483}, 0, {4903, -309}, {221, 0, 122, 255} }},
	{{ {349, -34, -476}, 0, {5143, -229}, {221, 0, 122, 255} }},
	{{ {336, -34, -480}, 0, {5023, -229}, {221, 0, 122, 255} }},
	{{ {362, -43, -472}, 0, {5264, -148}, {221, 0, 122, 255} }},
	{{ {349, -34, -476}, 0, {5143, -229}, {221, 0, 122, 255} }},
	{{ {349, -43, -476}, 0, {5143, -148}, {221, 0, 122, 255} }},
	{{ {362, -43, -472}, 0, {5264, -148}, {221, 0, 122, 255} }},
	{{ {375, -52, -469}, 0, {5384, -67}, {221, 0, 122, 255} }},
	{{ {413, 0, -458}, 0, {5745, -552}, {221, 0, 122, 255} }},
	{{ {362, -52, -472}, 0, {5264, -67}, {221, 0, 122, 255} }},
	{{ {387, -60, -465}, 0, {5504, 14}, {221, 0, 122, 255} }},
	{{ {375, -60, -469}, 0, {5384, 14}, {221, 0, 122, 255} }},
	{{ {400, -69, -462}, 0, {5625, 94}, {221, 0, 122, 255} }},
	{{ {387, -69, -465}, 0, {5504, 94}, {221, 0, 122, 255} }},
	{{ {413, -77, -458}, 0, {5745, 175}, {221, 0, 122, 255} }},
	{{ {400, -77, -462}, 0, {5625, 175}, {221, 0, 122, 255} }},
};

Gfx yeah_Plane_mesh_tri_0[] = {
	gsSPVertex(yeah_Plane_mesh_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 5, 7, 0, 8, 9, 5, 0),
	gsSP2Triangles(10, 11, 12, 0, 10, 13, 11, 0),
	gsSP2Triangles(14, 13, 10, 0, 14, 15, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 19, 17, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 23, 21, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 27, 25, 0),
	gsSP2Triangles(27, 24, 28, 0, 24, 29, 28, 0),
	gsSP2Triangles(30, 28, 29, 0, 31, 30, 29, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_0 + 32, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(4, 3, 2, 0, 2, 5, 4, 0),
	gsSP2Triangles(2, 6, 5, 0, 2, 7, 6, 0),
	gsSP2Triangles(7, 8, 6, 0, 9, 8, 7, 0),
	gsSP2Triangles(9, 10, 8, 0, 8, 11, 6, 0),
	gsSP2Triangles(8, 12, 11, 0, 6, 11, 5, 0),
	gsSP2Triangles(11, 13, 5, 0, 11, 14, 13, 0),
	gsSP2Triangles(5, 13, 4, 0, 13, 15, 4, 0),
	gsSP2Triangles(13, 16, 15, 0, 4, 15, 3, 0),
	gsSP2Triangles(15, 17, 3, 0, 15, 18, 17, 0),
	gsSP2Triangles(3, 17, 0, 0, 0, 17, 19, 0),
	gsSP2Triangles(0, 19, 20, 0, 0, 20, 1, 0),
	gsSP2Triangles(20, 21, 1, 0, 20, 22, 21, 0),
	gsSP2Triangles(1, 21, 23, 0, 23, 21, 24, 0),
	gsSP2Triangles(23, 24, 25, 0, 23, 25, 26, 0),
	gsSP2Triangles(25, 27, 26, 0, 25, 28, 27, 0),
	gsSP1Triangle(29, 30, 31, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_0 + 64, 31, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(3, 6, 4, 0, 7, 8, 9, 0),
	gsSP2Triangles(7, 10, 8, 0, 11, 12, 13, 0),
	gsSP2Triangles(11, 14, 12, 0, 15, 16, 17, 0),
	gsSP2Triangles(15, 18, 16, 0, 19, 20, 21, 0),
	gsSP2Triangles(19, 22, 20, 0, 23, 24, 25, 0),
	gsSP2Triangles(23, 26, 24, 0, 27, 28, 29, 0),
	gsSP1Triangle(27, 30, 28, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_0 + 95, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 11, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 17, 18, 0, 16, 19, 17, 0),
	gsSP2Triangles(20, 21, 22, 0, 20, 23, 21, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 27, 25, 0),
	gsSP2Triangles(28, 29, 30, 0, 28, 31, 29, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_0 + 127, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(11, 10, 12, 0, 10, 13, 12, 0),
	gsSP2Triangles(13, 14, 12, 0, 12, 15, 11, 0),
	gsSP2Triangles(16, 11, 15, 0, 17, 18, 19, 0),
	gsSP2Triangles(17, 19, 20, 0, 21, 22, 23, 0),
	gsSP2Triangles(24, 21, 23, 0, 24, 23, 25, 0),
	gsSP2Triangles(23, 26, 25, 0, 24, 25, 27, 0),
	gsSP2Triangles(25, 28, 27, 0, 24, 27, 29, 0),
	gsSP2Triangles(27, 30, 29, 0, 29, 31, 24, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_0 + 159, 12, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 4, 0),
	gsSP2Triangles(2, 5, 3, 0, 3, 6, 4, 0),
	gsSP2Triangles(3, 7, 6, 0, 6, 8, 4, 0),
	gsSP2Triangles(6, 9, 8, 0, 10, 4, 8, 0),
	gsSP1Triangle(11, 10, 8, 0),
	gsSPEndDisplayList(),
};

Vtx yeah_Plane_mesh_vtx_1[54] = {
	{{ {559, 99, 584}, 0, {-6613, -1477}, {196, 221, 150, 255} }},
	{{ {553, 111, 579}, 0, {-6558, -1592}, {211, 186, 160, 255} }},
	{{ {645, 111, 462}, 0, {-5470, -1592}, {164, 183, 208, 255} }},
	{{ {652, 99, 467}, 0, {-5513, -1477}, {149, 219, 199, 255} }},
	{{ {708, 99, 288}, 0, {-3830, -1477}, {135, 220, 242, 255} }},
	{{ {700, 111, 285}, 0, {-3803, -1592}, {151, 186, 246, 255} }},
	{{ {694, 99, 120}, 0, {-2255, -1477}, {135, 221, 14, 255} }},
	{{ {687, 111, 119}, 0, {-2244, -1592}, {149, 189, 13, 255} }},
	{{ {645, 99, -188}, 0, {627, -1477}, {134, 222, 1, 255} }},
	{{ {638, 111, -186}, 0, {607, -1592}, {147, 191, 3, 255} }},
	{{ {665, 111, -392}, 0, {2541, -1592}, {151, 186, 16, 255} }},
	{{ {673, 99, -396}, 0, {2580, -1477}, {137, 221, 26, 255} }},
	{{ {562, 111, -570}, 0, {4209, -1592}, {196, 183, 84, 255} }},
	{{ {568, 99, -576}, 0, {4265, -1477}, {181, 220, 96, 255} }},
	{{ {-575, 111, -581}, 0, {4315, -1592}, {94, 189, 52, 255} }},
	{{ {-586, 99, -436}, 0, {2952, -1477}, {120, 225, 29, 255} }},
	{{ {-580, 99, -587}, 0, {4372, -1477}, {102, 223, 68, 255} }},
	{{ {-581, 111, -431}, 0, {2909, -1592}, {108, 197, 31, 255} }},
	{{ {-661, 99, -286}, 0, {1553, -1477}, {115, 225, 45, 255} }},
	{{ {-655, 111, -283}, 0, {1524, -1592}, {104, 194, 40, 255} }},
	{{ {-704, 99, -131}, 0, {97, -1477}, {123, 226, 252, 255} }},
	{{ {-698, 111, -130}, 0, {83, -1592}, {112, 197, 248, 255} }},
	{{ {-619, 99, 102}, 0, {-2094, -1477}, {124, 227, 4, 255} }},
	{{ {-613, 111, 102}, 0, {-2086, -1592}, {115, 203, 1, 255} }},
	{{ {-680, 111, 263}, 0, {-3598, -1592}, {112, 204, 30, 255} }},
	{{ {-686, 99, 265}, 0, {-3622, -1477}, {121, 229, 27, 255} }},
	{{ {-694, 111, 466}, 0, {-5499, -1592}, {104, 189, 226, 255} }},
	{{ {-700, 99, 470}, 0, {-5543, -1477}, {116, 223, 215, 255} }},
	{{ {-561, 111, 617}, 0, {-6916, -1592}, {53, 187, 164, 255} }},
	{{ {-566, 99, 623}, 0, {-6974, -1477}, {64, 221, 152, 255} }},
	{{ {-438, 99, -658}, 0, {-2235, -1477}, {17, 224, 122, 255} }},
	{{ {-575, 111, -581}, 0, {-3517, -1592}, {94, 189, 52, 255} }},
	{{ {-580, 99, -587}, 0, {-3566, -1477}, {102, 223, 68, 255} }},
	{{ {-434, 111, -651}, 0, {-2199, -1592}, {8, 192, 109, 255} }},
	{{ {-209, 99, -608}, 0, {-86, -1477}, {248, 226, 123, 255} }},
	{{ {-207, 111, -601}, 0, {-72, -1592}, {251, 198, 113, 255} }},
	{{ {37, 111, -627}, 0, {2219, -1592}, {13, 197, 112, 255} }},
	{{ {38, 99, -633}, 0, {2229, -1477}, {15, 225, 122, 255} }},
	{{ {237, 111, -655}, 0, {4095, -1592}, {252, 193, 110, 255} }},
	{{ {240, 99, -662}, 0, {4124, -1477}, {248, 224, 123, 255} }},
	{{ {562, 111, -570}, 0, {7141, -1592}, {196, 183, 84, 255} }},
	{{ {568, 99, -576}, 0, {7201, -1477}, {181, 220, 96, 255} }},
	{{ {-561, 111, 617}, 0, {-3391, -1592}, {53, 187, 164, 255} }},
	{{ {-486, 99, 642}, 0, {-2683, -1477}, {20, 223, 135, 255} }},
	{{ {-566, 99, 623}, 0, {-3439, -1477}, {64, 221, 152, 255} }},
	{{ {-481, 111, 636}, 0, {-2643, -1592}, {16, 193, 147, 255} }},
	{{ {-255, 99, 660}, 0, {-517, -1477}, {250, 226, 133, 255} }},
	{{ {-253, 111, 653}, 0, {-499, -1592}, {249, 197, 144, 255} }},
	{{ {-29, 99, 619}, 0, {1595, -1477}, {243, 226, 133, 255} }},
	{{ {-30, 111, 612}, 0, {1591, -1592}, {244, 199, 143, 255} }},
	{{ {273, 111, 604}, 0, {4432, -1592}, {250, 198, 143, 255} }},
	{{ {277, 99, 610}, 0, {4465, -1477}, {248, 226, 133, 255} }},
	{{ {553, 111, 579}, 0, {7053, -1592}, {211, 186, 160, 255} }},
	{{ {559, 99, 584}, 0, {7113, -1477}, {196, 221, 150, 255} }},
};

Gfx yeah_Plane_mesh_tri_1[] = {
	gsSPVertex(yeah_Plane_mesh_vtx_1 + 0, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(2, 4, 3, 0, 2, 5, 4, 0),
	gsSP2Triangles(5, 6, 4, 0, 5, 7, 6, 0),
	gsSP2Triangles(7, 8, 6, 0, 7, 9, 8, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(11, 10, 12, 0, 11, 12, 13, 0),
	gsSP2Triangles(14, 15, 16, 0, 14, 17, 15, 0),
	gsSP2Triangles(17, 18, 15, 0, 17, 19, 18, 0),
	gsSP2Triangles(19, 20, 18, 0, 19, 21, 20, 0),
	gsSP2Triangles(21, 22, 20, 0, 21, 23, 22, 0),
	gsSP2Triangles(22, 23, 24, 0, 22, 24, 25, 0),
	gsSP2Triangles(25, 24, 26, 0, 25, 26, 27, 0),
	gsSP2Triangles(27, 26, 28, 0, 27, 28, 29, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_1 + 30, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
	gsSP2Triangles(6, 5, 4, 0, 6, 4, 7, 0),
	gsSP2Triangles(8, 6, 7, 0, 8, 7, 9, 0),
	gsSP2Triangles(10, 8, 9, 0, 10, 9, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(15, 16, 13, 0, 15, 17, 16, 0),
	gsSP2Triangles(17, 18, 16, 0, 17, 19, 18, 0),
	gsSP2Triangles(18, 19, 20, 0, 18, 20, 21, 0),
	gsSP2Triangles(21, 20, 22, 0, 21, 22, 23, 0),
	gsSPEndDisplayList(),
};

Vtx yeah_Plane_mesh_vtx_2[42] = {
	{{ {92, -4, 79}, 0, {2735, 1382}, {231, 124, 4, 255} }},
	{{ {39, -4, 85}, 0, {2237, 1439}, {27, 124, 249, 255} }},
	{{ {45, -4, 136}, 0, {2297, 1916}, {28, 124, 0, 255} }},
	{{ {74, -4, 5}, 0, {2563, 692}, {233, 124, 14, 255} }},
	{{ {8, -4, 14}, 0, {1947, 777}, {17, 125, 239, 255} }},
	{{ {-1, -4, -53}, 0, {1864, 152}, {244, 125, 20, 255} }},
	{{ {-37, -4, -6}, 0, {1520, 587}, {15, 122, 225, 255} }},
	{{ {-119, -4, -106}, 0, {753, -347}, {17, 123, 29, 255} }},
	{{ {-136, -4, -56}, 0, {596, 119}, {37, 120, 237, 255} }},
	{{ {-195, 28, -79}, 0, {43, -96}, {53, 114, 238, 255} }},
	{{ {-187, 28, -134}, 0, {113, -612}, {28, 120, 29, 255} }},
	{{ {-263, 45, -106}, 0, {-591, -351}, {48, 116, 236, 255} }},
	{{ {-250, 44, -171}, 0, {-474, -955}, {18, 124, 23, 255} }},
	{{ {-302, 60, -167}, 0, {-962, -921}, {52, 116, 250, 255} }},
	{{ {-282, 59, -225}, 0, {-770, -1465}, {8, 123, 30, 255} }},
	{{ {-326, 66, -220}, 0, {-1186, -1419}, {45, 118, 5, 255} }},
	{{ {-273, 80, -296}, 0, {-687, -2135}, {240, 126, 11, 255} }},
	{{ {-338, 78, -304}, 0, {-1301, -2202}, {36, 122, 7, 255} }},
	{{ {-336, 78, -339}, 0, {-1276, -2539}, {35, 122, 6, 255} }},
	{{ {-250, 80, -334}, 0, {-475, -2484}, {242, 126, 243, 255} }},
	{{ {-320, 78, -390}, 0, {-1126, -3010}, {31, 123, 8, 255} }},
	{{ {-196, 80, -394}, 0, {29, -3053}, {235, 125, 251, 255} }},
	{{ {-211, 80, -355}, 0, {-104, -2685}, {239, 125, 239, 255} }},
	{{ {-311, 78, -439}, 0, {-1044, -3475}, {34, 121, 16, 255} }},
	{{ {-286, 78, -464}, 0, {-813, -3709}, {14, 123, 30, 255} }},
	{{ {-230, 79, -469}, 0, {-289, -3756}, {247, 124, 26, 255} }},
	{{ {-197, 80, -445}, 0, {27, -3524}, {234, 125, 9, 255} }},
	{{ {99, -4, 143}, 0, {2796, 1982}, {228, 124, 253, 255} }},
	{{ {41, -4, 196}, 0, {2257, 2483}, {25, 124, 6, 255} }},
	{{ {81, -4, 206}, 0, {2629, 2572}, {231, 124, 248, 255} }},
	{{ {59, -4, 271}, 0, {2420, 3186}, {231, 124, 246, 255} }},
	{{ {14, -4, 270}, 0, {2004, 3173}, {24, 124, 10, 255} }},
	{{ {23, -4, 351}, 0, {2086, 3939}, {237, 126, 255, 255} }},
	{{ {59, -4, 271}, 0, {2420, 3186}, {231, 124, 246, 255} }},
	{{ {14, -4, 270}, 0, {2004, 3173}, {24, 124, 10, 255} }},
	{{ {-28, -4, 358}, 0, {1605, 4001}, {33, 123, 2, 255} }},
	{{ {-15, -4, 419}, 0, {1730, 4578}, {26, 124, 0, 255} }},
	{{ {39, -4, 426}, 0, {2234, 4637}, {228, 124, 255, 255} }},
	{{ {28, -4, 476}, 0, {2131, 5112}, {230, 124, 247, 255} }},
	{{ {-24, -4, 468}, 0, {1649, 5030}, {24, 124, 8, 255} }},
	{{ {-8, -4, 560}, 0, {1797, 5896}, {247, 122, 223, 255} }},
	{{ {-60, -4, 542}, 0, {1311, 5729}, {27, 123, 239, 255} }},
};

Gfx yeah_Plane_mesh_tri_2[] = {
	gsSPVertex(yeah_Plane_mesh_vtx_2 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(3, 4, 1, 0, 3, 5, 4, 0),
	gsSP2Triangles(6, 4, 5, 0, 5, 7, 6, 0),
	gsSP2Triangles(7, 8, 6, 0, 9, 8, 7, 0),
	gsSP2Triangles(9, 7, 10, 0, 11, 9, 10, 0),
	gsSP2Triangles(12, 11, 10, 0, 13, 11, 12, 0),
	gsSP2Triangles(13, 12, 14, 0, 15, 13, 14, 0),
	gsSP2Triangles(15, 14, 16, 0, 17, 15, 16, 0),
	gsSP2Triangles(18, 17, 16, 0, 18, 16, 19, 0),
	gsSP2Triangles(20, 18, 19, 0, 19, 21, 20, 0),
	gsSP2Triangles(22, 21, 19, 0, 23, 20, 21, 0),
	gsSP2Triangles(24, 23, 21, 0, 25, 24, 21, 0),
	gsSP2Triangles(26, 25, 21, 0, 27, 0, 2, 0),
	gsSP2Triangles(28, 27, 2, 0, 29, 27, 28, 0),
	gsSP2Triangles(30, 29, 28, 0, 30, 28, 31, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_2 + 32, 10, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
	gsSP2Triangles(3, 4, 0, 0, 5, 0, 4, 0),
	gsSP2Triangles(6, 5, 4, 0, 7, 6, 4, 0),
	gsSP2Triangles(8, 6, 7, 0, 9, 8, 7, 0),
	gsSPEndDisplayList(),
};

Vtx yeah_Plane_mesh_vtx_3[148] = {
	{{ {559, 0, 584}, 0, {14242, 12265}, {0, 127, 0, 255} }},
	{{ {652, 0, 467}, 0, {15989, 10065}, {0, 127, 0, 255} }},
	{{ {277, 0, 610}, 0, {8945, 12755}, {0, 127, 0, 255} }},
	{{ {89, 0, 206}, 0, {5432, 5174}, {231, 124, 248, 255} }},
	{{ {708, 0, 288}, 0, {17034, 6698}, {0, 127, 0, 255} }},
	{{ {108, 0, 142}, 0, {5776, 3961}, {234, 125, 255, 255} }},
	{{ {470, 0, -46}, 0, {12566, 449}, {0, 127, 0, 255} }},
	{{ {694, 0, 120}, 0, {16782, 3548}, {0, 127, 0, 255} }},
	{{ {645, 0, -188}, 0, {15864, -2214}, {0, 127, 0, 255} }},
	{{ {524, 0, -218}, 0, {13588, -2781}, {0, 127, 0, 255} }},
	{{ {579, 0, -411}, 0, {14620, -6402}, {0, 127, 0, 255} }},
	{{ {673, 0, -396}, 0, {16371, -6120}, {0, 127, 0, 255} }},
	{{ {568, 0, -576}, 0, {14419, -9491}, {0, 127, 0, 255} }},
	{{ {413, 0, -458}, 0, {11506, -7283}, {0, 127, 0, 255} }},
	{{ {240, 0, -662}, 0, {8264, -11102}, {0, 127, 0, 255} }},
	{{ {285, 0, -494}, 0, {9100, -7965}, {0, 127, 0, 255} }},
	{{ {115, 0, -466}, 0, {5917, -7443}, {0, 127, 0, 255} }},
	{{ {64, 0, -512}, 0, {4952, -8306}, {0, 127, 0, 255} }},
	{{ {38, 0, -633}, 0, {4474, -10570}, {0, 127, 0, 255} }},
	{{ {-35, 0, -540}, 0, {3095, -8825}, {0, 127, 0, 255} }},
	{{ {-123, 0, -542}, 0, {1451, -8857}, {0, 127, 0, 255} }},
	{{ {-209, 0, -608}, 0, {-157, -10092}, {0, 127, 0, 255} }},
	{{ {-182, 0, -538}, 0, {339, -8783}, {0, 127, 0, 255} }},
	{{ {-366, 0, -539}, 0, {-3099, -8802}, {0, 127, 0, 255} }},
	{{ {-377, 0, -567}, 0, {-3310, -9323}, {0, 127, 0, 255} }},
	{{ {-438, 0, -658}, 0, {-4454, -11036}, {0, 127, 0, 255} }},
	{{ {-406, 0, -588}, 0, {-3853, -9723}, {0, 127, 0, 255} }},
	{{ {-456, 0, -588}, 0, {-4798, -9717}, {0, 127, 0, 255} }},
	{{ {-580, 0, -587}, 0, {-7116, -9706}, {0, 127, 0, 255} }},
	{{ {-488, 0, -554}, 0, {-5401, -9079}, {0, 127, 0, 255} }},
	{{ {-586, 0, -436}, 0, {-7231, -6864}, {0, 127, 0, 255} }},
	{{ {-475, 0, -505}, 0, {-5144, -8159}, {0, 127, 0, 255} }},
	{{ {-428, 0, -481}, 0, {-4260, -7718}, {0, 127, 0, 255} }},
	{{ {-475, 0, -505}, 0, {-5144, -8159}, {0, 127, 0, 255} }},
	{{ {-586, 0, -436}, 0, {-7231, -6864}, {0, 127, 0, 255} }},
	{{ {-380, 0, -383}, 0, {-3362, -5885}, {0, 127, 0, 255} }},
	{{ {-376, 0, -306}, 0, {-3295, -4425}, {0, 127, 0, 255} }},
	{{ {-661, 0, -286}, 0, {-8649, -4067}, {0, 127, 0, 255} }},
	{{ {-351, 0, -217}, 0, {-2831, -2757}, {0, 127, 0, 255} }},
	{{ {-704, 0, -131}, 0, {-9453, -1155}, {0, 127, 0, 255} }},
	{{ {-317, 0, -153}, 0, {-2184, -1563}, {0, 127, 0, 255} }},
	{{ {-619, 0, 102}, 0, {-7844, 3227}, {0, 127, 0, 255} }},
	{{ {-271, 0, -103}, 0, {-1331, -629}, {0, 127, 0, 255} }},
	{{ {-197, 0, -73}, 0, {62, -69}, {0, 127, 0, 255} }},
	{{ {-36, 0, 355}, 0, {3083, 7968}, {21, 125, 3, 255} }},
	{{ {-686, 0, 265}, 0, {-9110, 6283}, {0, 127, 0, 255} }},
	{{ {-486, 0, 642}, 0, {-5351, 13349}, {0, 127, 0, 255} }},
	{{ {-700, 0, 470}, 0, {-9373, 10124}, {0, 127, 0, 255} }},
	{{ {-566, 0, 623}, 0, {-6863, 12988}, {0, 127, 0, 255} }},
	{{ {-255, 0, 660}, 0, {-1019, 13680}, {0, 127, 0, 255} }},
	{{ {-70, 0, 545}, 0, {2445, 11529}, {9, 127, 253, 255} }},
	{{ {-29, 0, 619}, 0, {3206, 12906}, {0, 127, 0, 255} }},
	{{ {-3, 0, 568}, 0, {3709, 11963}, {251, 126, 245, 255} }},
	{{ {277, 0, 610}, 0, {8945, 12755}, {0, 127, 0, 255} }},
	{{ {36, 0, 477}, 0, {4436, 10253}, {232, 125, 249, 255} }},
	{{ {48, 0, 424}, 0, {4653, 9257}, {235, 125, 0, 255} }},
	{{ {67, 0, 272}, 0, {5010, 6411}, {232, 124, 247, 255} }},
	{{ {89, 0, 206}, 0, {5432, 5174}, {231, 124, 248, 255} }},
	{{ {32, 0, 351}, 0, {4359, 7879}, {227, 124, 252, 255} }},
	{{ {-138, 0, -50}, 0, {1161, 360}, {28, 121, 230, 255} }},
	{{ {8, 0, 265}, 0, {3900, 6271}, {26, 124, 11, 255} }},
	{{ {-40, 0, -1}, 0, {3007, 1294}, {14, 123, 226, 255} }},
	{{ {34, 0, 193}, 0, {4398, 4918}, {30, 123, 6, 255} }},
	{{ {38, 0, 134}, 0, {4474, 3821}, {31, 123, 255, 255} }},
	{{ {38, 0, 134}, 0, {4474, 3821}, {31, 123, 255, 255} }},
	{{ {32, 0, 85}, 0, {4359, 2902}, {32, 122, 246, 255} }},
	{{ {-40, 0, -1}, 0, {3007, 1294}, {14, 123, 226, 255} }},
	{{ {3, 0, 18}, 0, {3811, 1651}, {26, 121, 229, 255} }},
	{{ {-207, 0, -305}, 0, {-133, -4409}, {0, 127, 0, 255} }},
	{{ {-232, 0, -291}, 0, {-598, -4148}, {0, 127, 0, 255} }},
	{{ {-239, 0, -252}, 0, {-734, -3421}, {0, 127, 0, 255} }},
	{{ {-140, 0, -274}, 0, {1135, -3832}, {0, 127, 0, 255} }},
	{{ {-224, 0, -189}, 0, {-450, -2235}, {0, 127, 0, 255} }},
	{{ {-109, 0, -236}, 0, {1719, -3126}, {0, 127, 0, 255} }},
	{{ {-183, 0, -143}, 0, {324, -1376}, {0, 127, 0, 255} }},
	{{ {-115, 0, -115}, 0, {1597, -847}, {3, 124, 26, 255} }},
	{{ {-59, 0, -222}, 0, {2642, -2861}, {0, 127, 0, 255} }},
	{{ {4, 0, -61}, 0, {3836, 158}, {245, 125, 18, 255} }},
	{{ {22, 0, -227}, 0, {4162, -2952}, {0, 127, 0, 255} }},
	{{ {206, 0, -117}, 0, {7629, -881}, {0, 127, 0, 255} }},
	{{ {82, 0, -1}, 0, {5291, 1281}, {242, 126, 10, 255} }},
	{{ {101, 0, 76}, 0, {5648, 2723}, {233, 125, 4, 255} }},
	{{ {470, 0, -46}, 0, {12566, 449}, {0, 127, 0, 255} }},
	{{ {108, 0, 142}, 0, {5776, 3961}, {234, 125, 255, 255} }},
	{{ {106, 0, -260}, 0, {5740, -3574}, {0, 127, 0, 255} }},
	{{ {240, 0, -289}, 0, {8253, -4109}, {0, 127, 0, 255} }},
	{{ {155, 0, -310}, 0, {6658, -4506}, {0, 127, 0, 255} }},
	{{ {256, 0, -393}, 0, {8563, -6069}, {0, 127, 0, 255} }},
	{{ {153, 0, -392}, 0, {6619, -6042}, {0, 127, 0, 255} }},
	{{ {285, 0, -494}, 0, {9100, -7965}, {0, 127, 0, 255} }},
	{{ {115, 0, -466}, 0, {5917, -7443}, {0, 127, 0, 255} }},
	{{ {106, 83, -260}, 0, {5740, -3574}, {0, 127, 0, 255} }},
	{{ {155, 83, -310}, 0, {6658, -4506}, {0, 127, 0, 255} }},
	{{ {153, 83, -392}, 0, {6619, -6042}, {0, 127, 0, 255} }},
	{{ {22, 83, -227}, 0, {4162, -2952}, {0, 127, 0, 255} }},
	{{ {115, 83, -466}, 0, {5917, -7443}, {0, 127, 0, 255} }},
	{{ {115, 83, -466}, 0, {5917, -7443}, {0, 127, 0, 255} }},
	{{ {64, 83, -512}, 0, {4952, -8306}, {0, 127, 0, 255} }},
	{{ {22, 83, -227}, 0, {4162, -2952}, {0, 127, 0, 255} }},
	{{ {-140, 83, -274}, 0, {1135, -3832}, {0, 127, 0, 255} }},
	{{ {-35, 83, -540}, 0, {3095, -8825}, {0, 127, 0, 255} }},
	{{ {-188, 83, -395}, 0, {238, -6096}, {239, 126, 253, 255} }},
	{{ {-188, 83, -450}, 0, {234, -7141}, {245, 126, 6, 255} }},
	{{ {-123, 83, -542}, 0, {1451, -8857}, {0, 127, 0, 255} }},
	{{ {-182, 83, -538}, 0, {339, -8783}, {0, 127, 0, 255} }},
	{{ {-227, 83, -479}, 0, {-503, -7682}, {251, 126, 16, 255} }},
	{{ {-293, 83, -519}, 0, {-1740, -8435}, {0, 127, 0, 255} }},
	{{ {-289, 83, -474}, 0, {-1662, -7577}, {8, 125, 20, 255} }},
	{{ {-355, 83, -464}, 0, {-2906, -7396}, {0, 127, 0, 255} }},
	{{ {-317, 83, -445}, 0, {-2194, -7038}, {23, 124, 13, 255} }},
	{{ {-326, 83, -393}, 0, {-2365, -6072}, {35, 122, 8, 255} }},
	{{ {-380, 83, -383}, 0, {-3362, -5885}, {0, 127, 0, 255} }},
	{{ {-343, 83, -343}, 0, {-2668, -5122}, {32, 123, 7, 255} }},
	{{ {-376, 83, -306}, 0, {-3295, -4425}, {0, 127, 10, 255} }},
	{{ {-345, 83, -305}, 0, {-2720, -4414}, {32, 123, 9, 255} }},
	{{ {-351, 67, -217}, 0, {-2831, -2757}, {238, 124, 20, 255} }},
	{{ {-333, 71, -219}, 0, {-2485, -2809}, {21, 125, 11, 255} }},
	{{ {-308, 64, -165}, 0, {-2024, -1785}, {46, 118, 245, 255} }},
	{{ {-317, 67, -153}, 0, {-2184, -1563}, {34, 122, 252, 255} }},
	{{ {-271, 51, -103}, 0, {-1331, -629}, {28, 123, 10, 255} }},
	{{ {-267, 49, -101}, 0, {-1250, -597}, {54, 112, 232, 255} }},
	{{ {-203, 83, -351}, 0, {-56, -5282}, {244, 126, 247, 255} }},
	{{ {-207, 83, -305}, 0, {-133, -4409}, {0, 127, 0, 255} }},
	{{ {-244, 83, -329}, 0, {-812, -4872}, {240, 125, 237, 255} }},
	{{ {-232, 83, -291}, 0, {-598, -4148}, {253, 126, 18, 255} }},
	{{ {-264, 83, -296}, 0, {-1198, -4238}, {235, 125, 12, 255} }},
	{{ {-239, 67, -252}, 0, {-734, -3421}, {4, 121, 38, 255} }},
	{{ {-273, 61, -229}, 0, {-1356, -2982}, {244, 121, 37, 255} }},
	{{ {-273, 61, -229}, 0, {-1356, -2982}, {244, 121, 37, 255} }},
	{{ {-224, 51, -189}, 0, {-450, -2235}, {1, 120, 41, 255} }},
	{{ {-239, 67, -252}, 0, {-734, -3421}, {4, 121, 38, 255} }},
	{{ {-244, 47, -178}, 0, {-809, -2036}, {252, 119, 44, 255} }},
	{{ {-183, 32, -143}, 0, {324, -1376}, {12, 115, 53, 255} }},
	{{ {-59, 83, -222}, 0, {2642, -2861}, {0, 127, 0, 255} }},
	{{ {22, 83, -227}, 0, {4162, -2952}, {0, 127, 0, 255} }},
	{{ {-140, 83, -274}, 0, {1135, -3832}, {0, 127, 0, 255} }},
	{{ {-109, 83, -236}, 0, {1719, -3126}, {0, 127, 0, 255} }},
	{{ {-293, 0, -519}, 0, {-1740, -8435}, {0, 127, 0, 255} }},
	{{ {-182, 0, -538}, 0, {339, -8783}, {0, 127, 0, 255} }},
	{{ {-366, 0, -539}, 0, {-3099, -8802}, {0, 127, 0, 255} }},
	{{ {-377, 0, -506}, 0, {-3306, -8191}, {0, 127, 0, 255} }},
	{{ {-355, 0, -464}, 0, {-2906, -7396}, {0, 127, 0, 255} }},
	{{ {-428, 0, -481}, 0, {-4260, -7718}, {0, 127, 0, 255} }},
	{{ {-380, 0, -383}, 0, {-3362, -5885}, {0, 127, 0, 255} }},
	{{ {-70, 0, 545}, 0, {2445, 11529}, {9, 127, 253, 255} }},
	{{ {-31, 0, 463}, 0, {3185, 9998}, {29, 123, 9, 255} }},
	{{ {-36, 0, 355}, 0, {3083, 7968}, {21, 125, 3, 255} }},
	{{ {-22, 0, 418}, 0, {3339, 9143}, {33, 123, 254, 255} }},
};

Gfx yeah_Plane_mesh_tri_3[] = {
	gsSPVertex(yeah_Plane_mesh_vtx_3 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 1, 3, 0),
	gsSP2Triangles(1, 4, 3, 0, 4, 5, 3, 0),
	gsSP2Triangles(4, 6, 5, 0, 4, 7, 6, 0),
	gsSP2Triangles(7, 8, 6, 0, 8, 9, 6, 0),
	gsSP2Triangles(9, 8, 10, 0, 8, 11, 10, 0),
	gsSP2Triangles(11, 12, 10, 0, 13, 10, 12, 0),
	gsSP2Triangles(12, 14, 13, 0, 13, 14, 15, 0),
	gsSP2Triangles(15, 14, 16, 0, 14, 17, 16, 0),
	gsSP2Triangles(14, 18, 17, 0, 17, 18, 19, 0),
	gsSP2Triangles(19, 18, 20, 0, 18, 21, 20, 0),
	gsSP2Triangles(22, 20, 21, 0, 23, 22, 21, 0),
	gsSP2Triangles(24, 23, 21, 0, 21, 25, 24, 0),
	gsSP2Triangles(25, 26, 24, 0, 26, 25, 27, 0),
	gsSP2Triangles(25, 28, 27, 0, 28, 29, 27, 0),
	gsSP2Triangles(29, 28, 30, 0, 31, 29, 30, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_3 + 32, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 2, 3, 0, 0),
	gsSP2Triangles(3, 2, 4, 0, 2, 5, 4, 0),
	gsSP2Triangles(4, 5, 6, 0, 5, 7, 6, 0),
	gsSP2Triangles(6, 7, 8, 0, 7, 9, 8, 0),
	gsSP2Triangles(10, 8, 9, 0, 11, 10, 9, 0),
	gsSP2Triangles(11, 9, 12, 0, 9, 13, 12, 0),
	gsSP2Triangles(13, 14, 12, 0, 13, 15, 14, 0),
	gsSP2Triangles(15, 16, 14, 0, 14, 17, 12, 0),
	gsSP2Triangles(17, 18, 12, 0, 17, 19, 18, 0),
	gsSP2Triangles(20, 18, 19, 0, 19, 21, 20, 0),
	gsSP2Triangles(20, 21, 22, 0, 22, 21, 23, 0),
	gsSP2Triangles(23, 21, 24, 0, 21, 25, 24, 0),
	gsSP2Triangles(24, 26, 23, 0, 27, 11, 12, 0),
	gsSP2Triangles(12, 28, 27, 0, 29, 27, 28, 0),
	gsSP2Triangles(29, 28, 30, 0, 30, 31, 29, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_3 + 64, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(4, 5, 6, 0, 7, 4, 6, 0),
	gsSP2Triangles(6, 8, 7, 0, 9, 7, 8, 0),
	gsSP2Triangles(8, 10, 9, 0, 10, 11, 9, 0),
	gsSP2Triangles(12, 9, 11, 0, 11, 13, 12, 0),
	gsSP2Triangles(14, 12, 13, 0, 15, 14, 13, 0),
	gsSP2Triangles(16, 15, 13, 0, 17, 15, 16, 0),
	gsSP2Triangles(18, 15, 17, 0, 18, 17, 19, 0),
	gsSP2Triangles(15, 20, 14, 0, 15, 21, 20, 0),
	gsSP2Triangles(21, 22, 20, 0, 22, 21, 23, 0),
	gsSP2Triangles(22, 23, 24, 0, 23, 25, 24, 0),
	gsSP2Triangles(26, 24, 25, 0, 27, 28, 29, 0),
	gsSP2Triangles(29, 30, 27, 0, 29, 31, 30, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_3 + 96, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 1, 0),
	gsSP2Triangles(1, 4, 3, 0, 5, 3, 4, 0),
	gsSP2Triangles(4, 6, 5, 0, 4, 7, 6, 0),
	gsSP2Triangles(7, 8, 6, 0, 8, 9, 6, 0),
	gsSP2Triangles(8, 10, 9, 0, 10, 11, 9, 0),
	gsSP2Triangles(10, 12, 11, 0, 11, 12, 13, 0),
	gsSP2Triangles(14, 13, 12, 0, 12, 15, 14, 0),
	gsSP2Triangles(16, 14, 15, 0, 15, 17, 16, 0),
	gsSP2Triangles(17, 18, 16, 0, 17, 19, 18, 0),
	gsSP2Triangles(19, 20, 18, 0, 19, 21, 20, 0),
	gsSP2Triangles(19, 22, 21, 0, 22, 23, 21, 0),
	gsSP2Triangles(23, 24, 21, 0, 25, 3, 5, 0),
	gsSP2Triangles(26, 3, 25, 0, 25, 27, 26, 0),
	gsSP2Triangles(28, 26, 27, 0, 27, 29, 28, 0),
	gsSP2Triangles(29, 30, 28, 0, 29, 31, 30, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_3 + 128, 20, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(3, 4, 1, 0, 5, 6, 7, 0),
	gsSP2Triangles(7, 8, 5, 0, 9, 10, 11, 0),
	gsSP2Triangles(9, 11, 12, 0, 13, 9, 12, 0),
	gsSP2Triangles(13, 12, 14, 0, 15, 13, 14, 0),
	gsSP2Triangles(16, 17, 18, 0, 17, 19, 18, 0),
	gsSPEndDisplayList(),
};

Vtx yeah_Plane_mesh_vtx_4[86] = {
	{{ {-263, 45, -106}, 0, {-591, -351}, {48, 116, 236, 255} }},
	{{ {-197, 32, -73}, 0, {23, -43}, {57, 105, 212, 255} }},
	{{ {-195, 28, -79}, 0, {43, -96}, {53, 114, 238, 255} }},
	{{ {-267, 49, -101}, 0, {-633, -307}, {54, 112, 232, 255} }},
	{{ {-302, 60, -167}, 0, {-962, -921}, {52, 116, 250, 255} }},
	{{ {-308, 64, -165}, 0, {-1020, -900}, {46, 118, 245, 255} }},
	{{ {-326, 66, -220}, 0, {-1186, -1419}, {45, 118, 5, 255} }},
	{{ {-333, 71, -219}, 0, {-1250, -1413}, {21, 125, 11, 255} }},
	{{ {-338, 78, -304}, 0, {-1301, -2202}, {36, 122, 7, 255} }},
	{{ {-345, 83, -305}, 0, {-1368, -2215}, {32, 123, 9, 255} }},
	{{ {-336, 78, -339}, 0, {-1276, -2539}, {35, 122, 6, 255} }},
	{{ {-343, 83, -343}, 0, {-1342, -2569}, {32, 123, 7, 255} }},
	{{ {-320, 78, -390}, 0, {-1126, -3010}, {31, 123, 8, 255} }},
	{{ {-326, 83, -393}, 0, {-1190, -3044}, {35, 122, 8, 255} }},
	{{ {-311, 78, -439}, 0, {-1044, -3475}, {34, 121, 16, 255} }},
	{{ {-317, 83, -445}, 0, {-1105, -3527}, {23, 124, 13, 255} }},
	{{ {-286, 78, -464}, 0, {-813, -3709}, {14, 123, 30, 255} }},
	{{ {-289, 83, -474}, 0, {-839, -3797}, {8, 125, 20, 255} }},
	{{ {-230, 79, -469}, 0, {-289, -3756}, {247, 124, 26, 255} }},
	{{ {-227, 83, -479}, 0, {-260, -3849}, {251, 126, 16, 255} }},
	{{ {-197, 80, -445}, 0, {27, -3524}, {234, 125, 9, 255} }},
	{{ {-188, 83, -450}, 0, {109, -3578}, {245, 126, 6, 255} }},
	{{ {-188, 83, -395}, 0, {111, -3056}, {239, 126, 253, 255} }},
	{{ {-196, 80, -394}, 0, {29, -3053}, {235, 125, 251, 255} }},
	{{ {-203, 83, -351}, 0, {-36, -2649}, {244, 126, 247, 255} }},
	{{ {-211, 80, -355}, 0, {-104, -2685}, {239, 125, 239, 255} }},
	{{ {-244, 83, -329}, 0, {-414, -2444}, {240, 125, 237, 255} }},
	{{ {-250, 80, -334}, 0, {-475, -2484}, {242, 126, 243, 255} }},
	{{ {-264, 83, -296}, 0, {-607, -2127}, {235, 125, 12, 255} }},
	{{ {-273, 80, -296}, 0, {-687, -2135}, {240, 126, 11, 255} }},
	{{ {-273, 61, -229}, 0, {-686, -1499}, {244, 121, 37, 255} }},
	{{ {-282, 59, -225}, 0, {-770, -1465}, {8, 123, 30, 255} }},
	{{ {-244, 47, -178}, 0, {-412, -1026}, {252, 119, 44, 255} }},
	{{ {-273, 61, -229}, 0, {-686, -1499}, {244, 121, 37, 255} }},
	{{ {-282, 59, -225}, 0, {-770, -1465}, {8, 123, 30, 255} }},
	{{ {-250, 44, -171}, 0, {-474, -955}, {18, 124, 23, 255} }},
	{{ {-183, 32, -143}, 0, {154, -696}, {12, 115, 53, 255} }},
	{{ {-187, 28, -134}, 0, {113, -612}, {28, 120, 29, 255} }},
	{{ {-115, 0, -115}, 0, {791, -432}, {3, 124, 26, 255} }},
	{{ {-119, -4, -106}, 0, {753, -347}, {17, 123, 29, 255} }},
	{{ {-1, -4, -53}, 0, {1864, 152}, {244, 125, 20, 255} }},
	{{ {4, 0, -61}, 0, {1910, 71}, {245, 125, 18, 255} }},
	{{ {74, -4, 5}, 0, {2563, 692}, {233, 124, 14, 255} }},
	{{ {82, 0, -1}, 0, {2638, 633}, {242, 126, 10, 255} }},
	{{ {101, 0, 76}, 0, {2816, 1354}, {233, 125, 4, 255} }},
	{{ {92, -4, 79}, 0, {2735, 1382}, {231, 124, 4, 255} }},
	{{ {108, 0, 142}, 0, {2880, 1973}, {234, 125, 255, 255} }},
	{{ {99, -4, 143}, 0, {2796, 1982}, {228, 124, 253, 255} }},
	{{ {89, 0, 206}, 0, {2708, 2579}, {231, 124, 248, 255} }},
	{{ {81, -4, 206}, 0, {2629, 2572}, {231, 124, 248, 255} }},
	{{ {67, 0, 272}, 0, {2497, 3198}, {232, 124, 247, 255} }},
	{{ {59, -4, 271}, 0, {2420, 3186}, {231, 124, 246, 255} }},
	{{ {32, 0, 351}, 0, {2172, 3932}, {227, 124, 252, 255} }},
	{{ {23, -4, 351}, 0, {2086, 3939}, {237, 126, 255, 255} }},
	{{ {39, -4, 426}, 0, {2234, 4637}, {228, 124, 255, 255} }},
	{{ {48, 0, 424}, 0, {2319, 4621}, {235, 125, 0, 255} }},
	{{ {36, 0, 477}, 0, {2210, 5118}, {232, 125, 249, 255} }},
	{{ {28, -4, 476}, 0, {2131, 5112}, {230, 124, 247, 255} }},
	{{ {-8, -4, 560}, 0, {1797, 5896}, {247, 122, 223, 255} }},
	{{ {-3, 0, 568}, 0, {1846, 5974}, {251, 126, 245, 255} }},
	{{ {-60, -4, 542}, 0, {1311, 5729}, {27, 123, 239, 255} }},
	{{ {-70, 0, 545}, 0, {1215, 5757}, {9, 127, 253, 255} }},
	{{ {-31, 0, 463}, 0, {1585, 4991}, {29, 123, 9, 255} }},
	{{ {-24, -4, 468}, 0, {1649, 5030}, {24, 124, 8, 255} }},
	{{ {-15, -4, 419}, 0, {1730, 4578}, {26, 124, 0, 255} }},
	{{ {-31, 0, 463}, 0, {1585, 4991}, {29, 123, 9, 255} }},
	{{ {-24, -4, 468}, 0, {1649, 5030}, {24, 124, 8, 255} }},
	{{ {-22, 0, 418}, 0, {1661, 4563}, {33, 123, 254, 255} }},
	{{ {-28, -4, 358}, 0, {1605, 4001}, {33, 123, 2, 255} }},
	{{ {-36, 0, 355}, 0, {1534, 3976}, {21, 125, 3, 255} }},
	{{ {14, -4, 270}, 0, {2004, 3173}, {24, 124, 10, 255} }},
	{{ {8, 0, 265}, 0, {1942, 3128}, {26, 124, 11, 255} }},
	{{ {41, -4, 196}, 0, {2257, 2483}, {25, 124, 6, 255} }},
	{{ {34, 0, 193}, 0, {2191, 2451}, {30, 123, 6, 255} }},
	{{ {45, -4, 136}, 0, {2297, 1916}, {28, 124, 0, 255} }},
	{{ {38, 0, 134}, 0, {2229, 1902}, {31, 123, 255, 255} }},
	{{ {39, -4, 85}, 0, {2237, 1439}, {27, 124, 249, 255} }},
	{{ {32, 0, 85}, 0, {2172, 1443}, {32, 122, 246, 255} }},
	{{ {8, -4, 14}, 0, {1947, 777}, {17, 125, 239, 255} }},
	{{ {3, 0, 18}, 0, {1897, 818}, {26, 121, 229, 255} }},
	{{ {-37, -4, -6}, 0, {1520, 587}, {15, 122, 225, 255} }},
	{{ {-40, 0, -1}, 0, {1495, 639}, {14, 123, 226, 255} }},
	{{ {-138, 0, -50}, 0, {573, 172}, {28, 121, 230, 255} }},
	{{ {-136, -4, -56}, 0, {596, 119}, {37, 120, 237, 255} }},
	{{ {-195, 28, -79}, 0, {43, -96}, {53, 114, 238, 255} }},
	{{ {-197, 32, -73}, 0, {23, -43}, {57, 105, 212, 255} }},
};

Gfx yeah_Plane_mesh_tri_4[] = {
	gsSPVertex(yeah_Plane_mesh_vtx_4 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
	gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
	gsSP2Triangles(8, 7, 6, 0, 8, 9, 7, 0),
	gsSP2Triangles(10, 9, 8, 0, 10, 11, 9, 0),
	gsSP2Triangles(12, 11, 10, 0, 12, 13, 11, 0),
	gsSP2Triangles(14, 13, 12, 0, 14, 15, 13, 0),
	gsSP2Triangles(16, 15, 14, 0, 16, 17, 15, 0),
	gsSP2Triangles(18, 17, 16, 0, 18, 19, 17, 0),
	gsSP2Triangles(20, 19, 18, 0, 20, 21, 19, 0),
	gsSP2Triangles(22, 21, 20, 0, 22, 20, 23, 0),
	gsSP2Triangles(24, 22, 23, 0, 24, 23, 25, 0),
	gsSP2Triangles(26, 24, 25, 0, 26, 25, 27, 0),
	gsSP2Triangles(28, 26, 27, 0, 28, 27, 29, 0),
	gsSP2Triangles(30, 28, 29, 0, 30, 29, 31, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_4 + 32, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
	gsSP2Triangles(6, 4, 5, 0, 6, 5, 7, 0),
	gsSP2Triangles(8, 6, 7, 0, 8, 9, 6, 0),
	gsSP2Triangles(10, 9, 8, 0, 10, 11, 9, 0),
	gsSP2Triangles(12, 11, 10, 0, 12, 10, 13, 0),
	gsSP2Triangles(14, 12, 13, 0, 14, 13, 15, 0),
	gsSP2Triangles(16, 14, 15, 0, 16, 15, 17, 0),
	gsSP2Triangles(18, 16, 17, 0, 18, 17, 19, 0),
	gsSP2Triangles(20, 18, 19, 0, 20, 19, 21, 0),
	gsSP2Triangles(22, 20, 21, 0, 22, 23, 20, 0),
	gsSP2Triangles(24, 23, 22, 0, 24, 22, 25, 0),
	gsSP2Triangles(26, 24, 25, 0, 26, 27, 24, 0),
	gsSP2Triangles(28, 27, 26, 0, 28, 29, 27, 0),
	gsSP2Triangles(30, 29, 28, 0, 30, 28, 31, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_4 + 64, 22, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
	gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
	gsSP2Triangles(8, 7, 6, 0, 8, 9, 7, 0),
	gsSP2Triangles(10, 9, 8, 0, 10, 11, 9, 0),
	gsSP2Triangles(12, 11, 10, 0, 12, 13, 11, 0),
	gsSP2Triangles(14, 13, 12, 0, 14, 15, 13, 0),
	gsSP2Triangles(16, 15, 14, 0, 16, 17, 15, 0),
	gsSP2Triangles(18, 17, 16, 0, 18, 16, 19, 0),
	gsSP2Triangles(20, 18, 19, 0, 20, 21, 18, 0),
	gsSPEndDisplayList(),
};

Vtx yeah_Plane_mesh_vtx_5[78] = {
	{{ {-183, 0, -143}, 0, {154, -552}, {49, 0, 139, 255} }},
	{{ {-183, 32, -143}, 0, {154, -847}, {49, 0, 139, 255} }},
	{{ {-115, 0, -115}, 0, {791, -552}, {49, 0, 139, 255} }},
	{{ {-197, 32, -73}, 0, {23, -847}, {210, 0, 118, 255} }},
	{{ {-197, 0, -73}, 0, {23, -552}, {210, 0, 118, 255} }},
	{{ {-138, 0, -50}, 0, {573, -552}, {210, 0, 118, 255} }},
	{{ {-183, 0, -143}, 0, {154, -552}, {100, 241, 180, 255} }},
	{{ {-183, 16, -145}, 0, {159, -702}, {121, 0, 219, 255} }},
	{{ {-183, 32, -143}, 0, {154, -847}, {101, 14, 181, 255} }},
	{{ {-197, 32, -73}, 0, {23, -847}, {132, 0, 230, 255} }},
	{{ {-196, 16, -77}, 0, {30, -702}, {132, 0, 230, 255} }},
	{{ {-197, 0, -73}, 0, {23, -552}, {132, 0, 230, 255} }},
	{{ {-380, 0, -383}, 0, {2462, -552}, {130, 11, 240, 255} }},
	{{ {-352, 41, -462}, 0, {3198, -938}, {149, 0, 188, 255} }},
	{{ {-355, 0, -464}, 0, {3218, -552}, {149, 11, 188, 255} }},
	{{ {-376, 41, -382}, 0, {2453, -938}, {130, 0, 241, 255} }},
	{{ {-376, 0, -306}, 0, {1732, -552}, {131, 10, 20, 255} }},
	{{ {-373, 41, -306}, 0, {1734, -938}, {131, 0, 20, 255} }},
	{{ {-348, 33, -218}, 0, {912, -865}, {138, 0, 47, 255} }},
	{{ {-351, 0, -217}, 0, {898, -552}, {139, 12, 47, 255} }},
	{{ {-314, 33, -155}, 0, {323, -865}, {152, 255, 73, 255} }},
	{{ {-317, 0, -153}, 0, {301, -552}, {154, 13, 74, 255} }},
	{{ {-270, 25, -106}, 0, {-137, -790}, {183, 255, 104, 255} }},
	{{ {-271, 0, -103}, 0, {-166, -552}, {185, 18, 104, 255} }},
	{{ {-207, 0, -305}, 0, {-74, -552}, {6, 0, 127, 255} }},
	{{ {-231, 41, -291}, 0, {-296, -938}, {103, 0, 75, 255} }},
	{{ {-232, 0, -291}, 0, {-307, -552}, {104, 253, 73, 255} }},
	{{ {-207, 41, -305}, 0, {-66, -938}, {5, 0, 127, 255} }},
	{{ {-140, 0, -274}, 0, {560, -552}, {179, 1, 101, 255} }},
	{{ {-140, 41, -274}, 0, {559, -938}, {179, 0, 101, 255} }},
	{{ {-352, 41, -462}, 0, {-1433, -938}, {149, 0, 188, 255} }},
	{{ {-293, 0, -519}, 0, {-878, -552}, {201, 11, 142, 255} }},
	{{ {-355, 0, -464}, 0, {-1461, -552}, {149, 11, 188, 255} }},
	{{ {-291, 41, -516}, 0, {-858, -938}, {201, 0, 141, 255} }},
	{{ {-182, 0, -538}, 0, {162, -552}, {241, 10, 130, 255} }},
	{{ {-182, 41, -535}, 0, {166, -938}, {241, 0, 130, 255} }},
	{{ {-123, 41, -539}, 0, {714, -938}, {253, 0, 129, 255} }},
	{{ {-123, 0, -542}, 0, {717, -552}, {253, 10, 129, 255} }},
	{{ {-37, 41, -537}, 0, {1524, -938}, {18, 0, 130, 255} }},
	{{ {-35, 0, -540}, 0, {1539, -552}, {19, 11, 131, 255} }},
	{{ {61, 41, -510}, 0, {2439, -938}, {60, 0, 144, 255} }},
	{{ {64, 0, -512}, 0, {2468, -552}, {61, 12, 145, 255} }},
	{{ {111, 41, -464}, 0, {2915, -938}, {101, 0, 179, 255} }},
	{{ {115, 0, -466}, 0, {2951, -552}, {100, 13, 179, 255} }},
	{{ {-196, 16, -77}, 0, {30, -702}, {207, 1, 117, 255} }},
	{{ {-271, 0, -103}, 0, {-673, -552}, {185, 18, 104, 255} }},
	{{ {-197, 0, -73}, 0, {23, -552}, {210, 27, 115, 255} }},
	{{ {-270, 25, -106}, 0, {-656, -790}, {183, 255, 104, 255} }},
	{{ {102, 41, -261}, 0, {2828, -938}, {69, 0, 107, 255} }},
	{{ {22, 0, -227}, 0, {2073, -552}, {28, 6, 124, 255} }},
	{{ {106, 0, -260}, 0, {2862, -552}, {71, 8, 105, 255} }},
	{{ {19, 41, -228}, 0, {2050, -938}, {27, 0, 124, 255} }},
	{{ {-59, 0, -222}, 0, {1313, -552}, {243, 4, 126, 255} }},
	{{ {-61, 41, -224}, 0, {1301, -938}, {242, 0, 126, 255} }},
	{{ {-109, 0, -236}, 0, {851, -552}, {187, 2, 107, 255} }},
	{{ {-109, 41, -237}, 0, {846, -938}, {186, 0, 106, 255} }},
	{{ {-224, 0, -189}, 0, {637, -552}, {111, 246, 196, 255} }},
	{{ {-183, 16, -145}, 0, {231, -702}, {121, 0, 219, 255} }},
	{{ {-183, 0, -143}, 0, {207, -552}, {100, 241, 180, 255} }},
	{{ {-223, 25, -191}, 0, {655, -790}, {113, 1, 198, 255} }},
	{{ {-239, 0, -252}, 0, {1230, -552}, {127, 251, 252, 255} }},
	{{ {-238, 33, -253}, 0, {1239, -865}, {127, 0, 254, 255} }},
	{{ {-232, 0, -291}, 0, {1593, -552}, {104, 253, 73, 255} }},
	{{ {-238, 33, -253}, 0, {1239, -865}, {127, 0, 254, 255} }},
	{{ {-239, 0, -252}, 0, {1230, -552}, {127, 251, 252, 255} }},
	{{ {-231, 41, -291}, 0, {1597, -938}, {103, 0, 75, 255} }},
	{{ {-109, 41, -237}, 0, {1094, -938}, {186, 0, 106, 255} }},
	{{ {-140, 0, -274}, 0, {1435, -552}, {179, 1, 101, 255} }},
	{{ {-109, 0, -236}, 0, {1083, -552}, {187, 2, 107, 255} }},
	{{ {-140, 41, -274}, 0, {1441, -938}, {179, 0, 101, 255} }},
	{{ {115, 0, -466}, 0, {3241, -552}, {100, 13, 179, 255} }},
	{{ {148, 41, -391}, 0, {2530, -938}, {123, 0, 225, 255} }},
	{{ {153, 0, -392}, 0, {2541, -552}, {122, 14, 225, 255} }},
	{{ {111, 41, -464}, 0, {3221, -938}, {101, 0, 179, 255} }},
	{{ {155, 0, -310}, 0, {1772, -552}, {118, 13, 45, 255} }},
	{{ {150, 41, -310}, 0, {1773, -938}, {118, 0, 48, 255} }},
	{{ {106, 0, -260}, 0, {1306, -552}, {71, 8, 105, 255} }},
	{{ {102, 41, -261}, 0, {1314, -938}, {69, 0, 107, 255} }},
};

Gfx yeah_Plane_mesh_tri_5[] = {
	gsSPVertex(yeah_Plane_mesh_vtx_5 + 0, 30, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 4, 5, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(16, 15, 12, 0, 16, 17, 15, 0),
	gsSP2Triangles(18, 17, 16, 0, 18, 16, 19, 0),
	gsSP2Triangles(20, 18, 19, 0, 20, 19, 21, 0),
	gsSP2Triangles(22, 20, 21, 0, 22, 21, 23, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 27, 25, 0),
	gsSP2Triangles(28, 27, 24, 0, 28, 29, 27, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_5 + 30, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(3, 4, 1, 0, 3, 5, 4, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 6, 7, 0),
	gsSP2Triangles(7, 6, 8, 0, 7, 8, 9, 0),
	gsSP2Triangles(9, 8, 10, 0, 9, 10, 11, 0),
	gsSP2Triangles(11, 10, 12, 0, 11, 12, 13, 0),
	gsSP2Triangles(14, 15, 16, 0, 14, 17, 15, 0),
	gsSP2Triangles(18, 19, 20, 0, 18, 21, 19, 0),
	gsSP2Triangles(21, 22, 19, 0, 21, 23, 22, 0),
	gsSP2Triangles(23, 24, 22, 0, 23, 25, 24, 0),
	gsSP2Triangles(26, 27, 28, 0, 26, 29, 27, 0),
	gsSP2Triangles(30, 29, 26, 0, 30, 31, 29, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_5 + 62, 16, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 11, 9, 0),
	gsSP2Triangles(9, 12, 10, 0, 9, 13, 12, 0),
	gsSP2Triangles(13, 14, 12, 0, 13, 15, 14, 0),
	gsSPEndDisplayList(),
};

Vtx yeah_Plane_mesh_vtx_6[67] = {
	{{ {-109, 41, -237}, 0, {1094, -938}, {186, 0, 106, 255} }},
	{{ {-140, 83, -274}, 0, {1435, -1326}, {179, 255, 101, 255} }},
	{{ {-140, 41, -274}, 0, {1441, -938}, {179, 0, 101, 255} }},
	{{ {-109, 83, -236}, 0, {1083, -1326}, {187, 254, 107, 255} }},
	{{ {-61, 41, -224}, 0, {1301, -938}, {242, 0, 126, 255} }},
	{{ {-109, 83, -236}, 0, {851, -1326}, {187, 254, 107, 255} }},
	{{ {-109, 41, -237}, 0, {846, -938}, {186, 0, 106, 255} }},
	{{ {-59, 83, -222}, 0, {1313, -1326}, {243, 252, 126, 255} }},
	{{ {19, 41, -228}, 0, {2050, -938}, {27, 0, 124, 255} }},
	{{ {22, 83, -227}, 0, {2073, -1326}, {28, 250, 124, 255} }},
	{{ {102, 41, -261}, 0, {2828, -938}, {69, 0, 107, 255} }},
	{{ {106, 83, -260}, 0, {2862, -1326}, {71, 248, 105, 255} }},
	{{ {-271, 51, -103}, 0, {-166, -1025}, {178, 239, 99, 255} }},
	{{ {-314, 33, -155}, 0, {323, -865}, {152, 255, 73, 255} }},
	{{ {-270, 25, -106}, 0, {-137, -790}, {183, 255, 104, 255} }},
	{{ {-317, 67, -153}, 0, {301, -1176}, {152, 243, 71, 255} }},
	{{ {-351, 67, -217}, 0, {898, -1176}, {138, 244, 46, 255} }},
	{{ {-348, 33, -218}, 0, {912, -865}, {138, 0, 47, 255} }},
	{{ {-373, 41, -306}, 0, {1734, -938}, {131, 0, 20, 255} }},
	{{ {-376, 83, -306}, 0, {1732, -1326}, {131, 246, 18, 255} }},
	{{ {-376, 41, -382}, 0, {2453, -938}, {130, 0, 241, 255} }},
	{{ {-380, 83, -383}, 0, {2462, -1326}, {130, 245, 240, 255} }},
	{{ {-352, 41, -462}, 0, {3198, -938}, {149, 0, 188, 255} }},
	{{ {-355, 83, -464}, 0, {3218, -1326}, {149, 245, 188, 255} }},
	{{ {-223, 25, -191}, 0, {655, -790}, {113, 1, 198, 255} }},
	{{ {-183, 32, -143}, 0, {207, -847}, {101, 14, 181, 255} }},
	{{ {-183, 16, -145}, 0, {231, -702}, {121, 0, 219, 255} }},
	{{ {-224, 51, -189}, 0, {637, -1025}, {115, 9, 203, 255} }},
	{{ {-238, 33, -253}, 0, {1239, -865}, {127, 0, 254, 255} }},
	{{ {-239, 67, -252}, 0, {1230, -1176}, {127, 5, 3, 255} }},
	{{ {-231, 41, -291}, 0, {1597, -938}, {103, 0, 75, 255} }},
	{{ {-232, 83, -291}, 0, {1593, -1326}, {98, 2, 80, 255} }},
	{{ {-267, 49, -101}, 0, {-633, -1015}, {205, 238, 115, 255} }},
	{{ {-271, 51, -103}, 0, {-673, -1025}, {178, 239, 99, 255} }},
	{{ {-270, 25, -106}, 0, {-656, -790}, {183, 255, 104, 255} }},
	{{ {-197, 32, -73}, 0, {23, -847}, {206, 230, 114, 255} }},
	{{ {-196, 16, -77}, 0, {30, -702}, {207, 1, 117, 255} }},
	{{ {150, 41, -310}, 0, {1773, -938}, {118, 0, 48, 255} }},
	{{ {106, 83, -260}, 0, {1306, -1326}, {71, 248, 105, 255} }},
	{{ {102, 41, -261}, 0, {1314, -938}, {69, 0, 107, 255} }},
	{{ {155, 83, -310}, 0, {1772, -1326}, {118, 243, 45, 255} }},
	{{ {148, 41, -391}, 0, {2530, -938}, {123, 0, 225, 255} }},
	{{ {153, 83, -392}, 0, {2541, -1326}, {123, 242, 225, 255} }},
	{{ {115, 83, -466}, 0, {3241, -1326}, {100, 243, 179, 255} }},
	{{ {111, 41, -464}, 0, {3221, -938}, {101, 0, 179, 255} }},
	{{ {-140, 83, -274}, 0, {560, -1326}, {179, 255, 101, 255} }},
	{{ {-207, 41, -305}, 0, {-66, -938}, {5, 0, 127, 255} }},
	{{ {-140, 41, -274}, 0, {559, -938}, {179, 0, 101, 255} }},
	{{ {-207, 83, -305}, 0, {-74, -1326}, {6, 0, 127, 255} }},
	{{ {-231, 41, -291}, 0, {-296, -938}, {103, 0, 75, 255} }},
	{{ {-232, 83, -291}, 0, {-307, -1326}, {98, 2, 80, 255} }},
	{{ {64, 83, -512}, 0, {2468, -1326}, {61, 244, 145, 255} }},
	{{ {115, 83, -466}, 0, {2951, -1326}, {100, 243, 179, 255} }},
	{{ {111, 41, -464}, 0, {2915, -938}, {101, 0, 179, 255} }},
	{{ {61, 41, -510}, 0, {2439, -938}, {60, 0, 144, 255} }},
	{{ {-35, 83, -540}, 0, {1539, -1326}, {19, 245, 131, 255} }},
	{{ {-37, 41, -537}, 0, {1524, -938}, {18, 0, 130, 255} }},
	{{ {-123, 83, -542}, 0, {717, -1326}, {253, 246, 129, 255} }},
	{{ {-123, 41, -539}, 0, {714, -938}, {253, 0, 129, 255} }},
	{{ {-182, 83, -538}, 0, {162, -1326}, {241, 246, 130, 255} }},
	{{ {-182, 41, -535}, 0, {166, -938}, {241, 0, 130, 255} }},
	{{ {-291, 41, -516}, 0, {-858, -938}, {201, 0, 141, 255} }},
	{{ {-293, 83, -519}, 0, {-878, -1326}, {201, 245, 142, 255} }},
	{{ {-352, 41, -462}, 0, {-1433, -938}, {149, 0, 188, 255} }},
	{{ {-352, 41, -462}, 0, {-1433, -938}, {149, 0, 188, 255} }},
	{{ {-355, 83, -464}, 0, {-1461, -1326}, {149, 245, 188, 255} }},
	{{ {-293, 83, -519}, 0, {-878, -1326}, {201, 245, 142, 255} }},
};

Gfx yeah_Plane_mesh_tri_6[] = {
	gsSPVertex(yeah_Plane_mesh_vtx_6 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
	gsSP2Triangles(8, 7, 4, 0, 8, 9, 7, 0),
	gsSP2Triangles(10, 9, 8, 0, 10, 11, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(13, 15, 16, 0, 13, 16, 17, 0),
	gsSP2Triangles(16, 18, 17, 0, 16, 19, 18, 0),
	gsSP2Triangles(19, 20, 18, 0, 19, 21, 20, 0),
	gsSP2Triangles(21, 22, 20, 0, 21, 23, 22, 0),
	gsSP2Triangles(24, 25, 26, 0, 24, 27, 25, 0),
	gsSP2Triangles(28, 27, 24, 0, 28, 29, 27, 0),
	gsSP2Triangles(30, 29, 28, 0, 30, 31, 29, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_6 + 32, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 0, 2, 0),
	gsSP2Triangles(2, 4, 3, 0, 5, 6, 7, 0),
	gsSP2Triangles(5, 8, 6, 0, 9, 8, 5, 0),
	gsSP2Triangles(9, 10, 8, 0, 11, 10, 9, 0),
	gsSP2Triangles(11, 9, 12, 0, 13, 14, 15, 0),
	gsSP2Triangles(13, 16, 14, 0, 16, 17, 14, 0),
	gsSP2Triangles(16, 18, 17, 0, 19, 20, 21, 0),
	gsSP2Triangles(19, 21, 22, 0, 23, 19, 22, 0),
	gsSP2Triangles(23, 22, 24, 0, 25, 23, 24, 0),
	gsSP2Triangles(25, 24, 26, 0, 27, 25, 26, 0),
	gsSP2Triangles(27, 26, 28, 0, 29, 27, 28, 0),
	gsSP2Triangles(29, 30, 27, 0, 31, 30, 29, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_6 + 64, 3, 0),
	gsSP1Triangle(0, 1, 2, 0),
	gsSPEndDisplayList(),
};

Vtx yeah_Plane_mesh_vtx_7[56] = {
	{{ {568, 99, -576}, 0, {7201, -1477}, {181, 220, 96, 255} }},
	{{ {240, 0, -662}, 0, {4124, -552}, {249, 0, 127, 255} }},
	{{ {568, 0, -576}, 0, {7201, -552}, {179, 0, 101, 255} }},
	{{ {240, 99, -662}, 0, {4124, -1477}, {248, 224, 123, 255} }},
	{{ {38, 0, -633}, 0, {2229, -552}, {15, 0, 126, 255} }},
	{{ {38, 99, -633}, 0, {2229, -1477}, {15, 225, 122, 255} }},
	{{ {-209, 0, -608}, 0, {-86, -552}, {249, 0, 127, 255} }},
	{{ {-209, 99, -608}, 0, {-86, -1477}, {248, 226, 123, 255} }},
	{{ {-438, 0, -658}, 0, {-2235, -552}, {16, 0, 126, 255} }},
	{{ {-438, 99, -658}, 0, {-2235, -1477}, {17, 224, 122, 255} }},
	{{ {-580, 0, -587}, 0, {-3566, -552}, {57, 0, 114, 255} }},
	{{ {-580, 99, -587}, 0, {-3566, -1477}, {102, 223, 68, 255} }},
	{{ {559, 99, 584}, 0, {-6613, -1477}, {196, 221, 150, 255} }},
	{{ {652, 0, 467}, 0, {-5513, -552}, {144, 0, 197, 255} }},
	{{ {559, 0, 584}, 0, {-6613, -552}, {196, 0, 144, 255} }},
	{{ {652, 99, 467}, 0, {-5513, -1477}, {149, 219, 199, 255} }},
	{{ {708, 0, 288}, 0, {-3830, -552}, {130, 0, 242, 255} }},
	{{ {708, 99, 288}, 0, {-3830, -1477}, {135, 220, 242, 255} }},
	{{ {694, 0, 120}, 0, {-2255, -552}, {130, 0, 15, 255} }},
	{{ {694, 99, 120}, 0, {-2255, -1477}, {135, 221, 14, 255} }},
	{{ {645, 0, -188}, 0, {627, -552}, {129, 0, 2, 255} }},
	{{ {645, 99, -188}, 0, {627, -1477}, {134, 222, 1, 255} }},
	{{ {673, 0, -396}, 0, {2580, -552}, {131, 0, 25, 255} }},
	{{ {673, 99, -396}, 0, {2580, -1477}, {137, 221, 26, 255} }},
	{{ {568, 0, -576}, 0, {4265, -552}, {179, 0, 101, 255} }},
	{{ {568, 99, -576}, 0, {4265, -1477}, {181, 220, 96, 255} }},
	{{ {-700, 0, 470}, 0, {-5543, -552}, {120, 0, 215, 255} }},
	{{ {-566, 99, 623}, 0, {-6974, -1477}, {64, 221, 152, 255} }},
	{{ {-566, 0, 623}, 0, {-6974, -552}, {66, 0, 147, 255} }},
	{{ {-700, 99, 470}, 0, {-5543, -1477}, {116, 223, 215, 255} }},
	{{ {-686, 0, 265}, 0, {-3622, -552}, {124, 0, 29, 255} }},
	{{ {-686, 99, 265}, 0, {-3622, -1477}, {121, 229, 27, 255} }},
	{{ {-619, 99, 102}, 0, {-2094, -1477}, {124, 227, 4, 255} }},
	{{ {-686, 99, 265}, 0, {-3622, -1477}, {121, 229, 27, 255} }},
	{{ {-686, 0, 265}, 0, {-3622, -552}, {124, 0, 29, 255} }},
	{{ {-619, 0, 102}, 0, {-2094, -552}, {127, 0, 3, 255} }},
	{{ {-704, 0, -131}, 0, {97, -552}, {127, 0, 251, 255} }},
	{{ {-704, 99, -131}, 0, {97, -1477}, {123, 226, 252, 255} }},
	{{ {-661, 99, -286}, 0, {1553, -1477}, {115, 225, 45, 255} }},
	{{ {-661, 0, -286}, 0, {1553, -552}, {118, 0, 46, 255} }},
	{{ {-586, 0, -436}, 0, {2952, -552}, {123, 0, 32, 255} }},
	{{ {-586, 99, -436}, 0, {2952, -1477}, {120, 225, 29, 255} }},
	{{ {-580, 0, -587}, 0, {4372, -552}, {127, 0, 5, 255} }},
	{{ {-580, 99, -587}, 0, {4372, -1477}, {102, 223, 68, 255} }},
	{{ {-566, 99, 623}, 0, {-3439, -1477}, {64, 221, 152, 255} }},
	{{ {-486, 0, 642}, 0, {-2683, -552}, {20, 0, 131, 255} }},
	{{ {-566, 0, 623}, 0, {-3439, -552}, {66, 0, 147, 255} }},
	{{ {-486, 99, 642}, 0, {-2683, -1477}, {20, 223, 135, 255} }},
	{{ {-255, 0, 660}, 0, {-517, -552}, {249, 0, 129, 255} }},
	{{ {-255, 99, 660}, 0, {-517, -1477}, {250, 226, 133, 255} }},
	{{ {-29, 0, 619}, 0, {1595, -552}, {243, 0, 130, 255} }},
	{{ {-29, 99, 619}, 0, {1595, -1477}, {243, 226, 133, 255} }},
	{{ {277, 0, 610}, 0, {4465, -552}, {248, 0, 129, 255} }},
	{{ {277, 99, 610}, 0, {4465, -1477}, {248, 226, 133, 255} }},
	{{ {559, 0, 584}, 0, {7113, -552}, {196, 0, 144, 255} }},
	{{ {559, 99, 584}, 0, {7113, -1477}, {196, 221, 150, 255} }},
};

Gfx yeah_Plane_mesh_tri_7[] = {
	gsSPVertex(yeah_Plane_mesh_vtx_7 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(3, 4, 1, 0, 3, 5, 4, 0),
	gsSP2Triangles(5, 6, 4, 0, 5, 7, 6, 0),
	gsSP2Triangles(7, 8, 6, 0, 7, 9, 8, 0),
	gsSP2Triangles(9, 10, 8, 0, 9, 11, 10, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(15, 16, 13, 0, 15, 17, 16, 0),
	gsSP2Triangles(17, 18, 16, 0, 17, 19, 18, 0),
	gsSP2Triangles(19, 20, 18, 0, 19, 21, 20, 0),
	gsSP2Triangles(21, 22, 20, 0, 21, 23, 22, 0),
	gsSP2Triangles(23, 24, 22, 0, 23, 25, 24, 0),
	gsSP2Triangles(26, 27, 28, 0, 26, 29, 27, 0),
	gsSP2Triangles(30, 29, 26, 0, 30, 31, 29, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_7 + 32, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 0, 3, 0, 4, 5, 0, 0),
	gsSP2Triangles(6, 5, 4, 0, 6, 4, 7, 0),
	gsSP2Triangles(8, 6, 7, 0, 8, 9, 6, 0),
	gsSP2Triangles(10, 9, 8, 0, 10, 11, 9, 0),
	gsSP2Triangles(12, 13, 14, 0, 12, 15, 13, 0),
	gsSP2Triangles(15, 16, 13, 0, 15, 17, 16, 0),
	gsSP2Triangles(17, 18, 16, 0, 17, 19, 18, 0),
	gsSP2Triangles(19, 20, 18, 0, 19, 21, 20, 0),
	gsSP2Triangles(21, 22, 20, 0, 21, 23, 22, 0),
	gsSPEndDisplayList(),
};

Vtx yeah_Plane_mesh_vtx_8[50] = {
	{{ {37, 111, -627}, 0, {2219, -5231}, {3, 124, 29, 255} }},
	{{ {-224, 128, -673}, 0, {-229, -5663}, {252, 103, 74, 255} }},
	{{ {-207, 111, -601}, 0, {-72, -4995}, {255, 124, 29, 255} }},
	{{ {49, 128, -701}, 0, {2329, -5927}, {9, 102, 75, 255} }},
	{{ {237, 111, -655}, 0, {4095, -5495}, {0, 124, 27, 255} }},
	{{ {272, 128, -732}, 0, {4422, -6221}, {253, 101, 77, 255} }},
	{{ {562, 111, -570}, 0, {7141, -4697}, {244, 125, 18, 255} }},
	{{ {635, 128, -637}, 0, {7822, -5331}, {213, 103, 60, 255} }},
	{{ {750, 128, -439}, 0, {8900, -3469}, {182, 103, 12, 255} }},
	{{ {665, 111, -392}, 0, {8107, -3029}, {233, 125, 3, 255} }},
	{{ {720, 128, -209}, 0, {8620, -1312}, {187, 107, 1, 255} }},
	{{ {638, 111, -186}, 0, {7856, -1096}, {231, 124, 1, 255} }},
	{{ {687, 111, 119}, 0, {8310, 1756}, {231, 125, 3, 255} }},
	{{ {774, 128, 131}, 0, {9127, 1871}, {185, 105, 9, 255} }},
	{{ {700, 111, 285}, 0, {8435, 3315}, {233, 125, 254, 255} }},
	{{ {789, 128, 316}, 0, {9266, 3611}, {184, 105, 249, 255} }},
	{{ {645, 111, 462}, 0, {7918, 4981}, {237, 125, 246, 255} }},
	{{ {727, 128, 515}, 0, {8689, 5471}, {194, 106, 224, 255} }},
	{{ {624, 128, 644}, 0, {7724, 6685}, {223, 102, 187, 255} }},
	{{ {553, 111, 579}, 0, {7053, 6070}, {247, 125, 234, 255} }},
	{{ {312, 128, 673}, 0, {4798, 6956}, {252, 101, 179, 255} }},
	{{ {273, 111, 604}, 0, {4432, 6312}, {255, 124, 227, 255} }},
	{{ {-26, 128, 682}, 0, {1628, 7039}, {248, 102, 181, 255} }},
	{{ {-30, 111, 612}, 0, {1591, 6387}, {253, 123, 226, 255} }},
	{{ {-253, 111, 653}, 0, {-499, 6770}, {254, 124, 227, 255} }},
	{{ {-275, 128, 728}, 0, {-705, 7467}, {251, 100, 178, 255} }},
	{{ {-481, 111, 636}, 0, {-2643, 6606}, {4, 124, 229, 255} }},
	{{ {-530, 128, 708}, 0, {-3097, 7284}, {11, 103, 182, 255} }},
	{{ {-561, 111, 617}, 0, {-3391, 6427}, {11, 125, 235, 255} }},
	{{ {-619, 128, 687}, 0, {-3933, 7085}, {38, 103, 191, 255} }},
	{{ {-767, 128, 518}, 0, {-5319, 5503}, {75, 100, 234, 255} }},
	{{ {-694, 111, 466}, 0, {-4634, 5010}, {25, 124, 251, 255} }},
	{{ {-751, 128, 292}, 0, {-5174, 3381}, {81, 95, 20, 255} }},
	{{ {-767, 128, 518}, 0, {-5319, 5503}, {75, 100, 234, 255} }},
	{{ {-694, 111, 466}, 0, {-4634, 5010}, {25, 124, 251, 255} }},
	{{ {-680, 111, 263}, 0, {-4503, 3109}, {33, 122, 10, 255} }},
	{{ {-677, 128, 112}, 0, {-4475, 1694}, {72, 105, 2, 255} }},
	{{ {-613, 111, 102}, 0, {-3877, 1597}, {32, 123, 0, 255} }},
	{{ {-698, 111, -130}, 0, {-4673, -572}, {29, 124, 253, 255} }},
	{{ {-771, 128, -146}, 0, {-5363, -726}, {82, 97, 251, 255} }},
	{{ {-655, 111, -283}, 0, {-4275, -2013}, {26, 124, 10, 255} }},
	{{ {-724, 128, -318}, 0, {-4919, -2335}, {71, 102, 27, 255} }},
	{{ {-581, 111, -431}, 0, {-3574, -3397}, {27, 124, 9, 255} }},
	{{ {-641, 128, -482}, 0, {-4136, -3880}, {70, 104, 18, 255} }},
	{{ {-575, 111, -581}, 0, {-3517, -4803}, {24, 124, 10, 255} }},
	{{ {-634, 128, -650}, 0, {-4073, -5449}, {70, 99, 40, 255} }},
	{{ {-477, 128, -728}, 0, {-2602, -6184}, {7, 99, 79, 255} }},
	{{ {-434, 111, -651}, 0, {-2199, -5462}, {0, 124, 27, 255} }},
	{{ {-224, 128, -673}, 0, {-229, -5663}, {252, 103, 74, 255} }},
	{{ {-207, 111, -601}, 0, {-72, -4995}, {255, 124, 29, 255} }},
};

Gfx yeah_Plane_mesh_tri_8[] = {
	gsSPVertex(yeah_Plane_mesh_vtx_8 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
	gsSP2Triangles(6, 5, 4, 0, 6, 7, 5, 0),
	gsSP2Triangles(8, 7, 6, 0, 8, 6, 9, 0),
	gsSP2Triangles(10, 8, 9, 0, 10, 9, 11, 0),
	gsSP2Triangles(12, 10, 11, 0, 12, 13, 10, 0),
	gsSP2Triangles(14, 13, 12, 0, 14, 15, 13, 0),
	gsSP2Triangles(16, 15, 14, 0, 16, 17, 15, 0),
	gsSP2Triangles(18, 17, 16, 0, 18, 16, 19, 0),
	gsSP2Triangles(20, 18, 19, 0, 20, 19, 21, 0),
	gsSP2Triangles(22, 20, 21, 0, 22, 21, 23, 0),
	gsSP2Triangles(24, 22, 23, 0, 24, 25, 22, 0),
	gsSP2Triangles(26, 25, 24, 0, 26, 27, 25, 0),
	gsSP2Triangles(28, 27, 26, 0, 28, 29, 27, 0),
	gsSP2Triangles(30, 29, 28, 0, 30, 28, 31, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_8 + 32, 18, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(4, 0, 3, 0, 4, 3, 5, 0),
	gsSP2Triangles(6, 4, 5, 0, 6, 7, 4, 0),
	gsSP2Triangles(8, 7, 6, 0, 8, 9, 7, 0),
	gsSP2Triangles(10, 9, 8, 0, 10, 11, 9, 0),
	gsSP2Triangles(12, 11, 10, 0, 12, 13, 11, 0),
	gsSP2Triangles(14, 13, 12, 0, 14, 12, 15, 0),
	gsSP2Triangles(16, 14, 15, 0, 16, 15, 17, 0),
	gsSPEndDisplayList(),
};

Vtx yeah_Plane_mesh_vtx_9[56] = {
	{{ {707, 275, 720}, 0, {-7884, -3134}, {203, 75, 168, 255} }},
	{{ {727, 128, 515}, 0, {-5959, -1750}, {194, 106, 224, 255} }},
	{{ {624, 128, 644}, 0, {-7174, -1750}, {223, 102, 187, 255} }},
	{{ {822, 275, 575}, 0, {-6524, -3134}, {167, 77, 208, 255} }},
	{{ {891, 275, 353}, 0, {-4441, -3134}, {154, 74, 243, 255} }},
	{{ {789, 128, 316}, 0, {-4099, -1750}, {184, 105, 249, 255} }},
	{{ {874, 275, 145}, 0, {-2493, -3134}, {151, 70, 12, 255} }},
	{{ {774, 128, 131}, 0, {-2360, -1750}, {185, 105, 9, 255} }},
	{{ {814, 275, -235}, 0, {1072, -3134}, {149, 68, 0, 255} }},
	{{ {720, 128, -209}, 0, {823, -1750}, {187, 107, 1, 255} }},
	{{ {750, 128, -439}, 0, {2981, -1750}, {182, 103, 12, 255} }},
	{{ {847, 275, -493}, 0, {3488, -3134}, {156, 75, 23, 255} }},
	{{ {635, 128, -637}, 0, {4842, -1750}, {213, 103, 60, 255} }},
	{{ {718, 275, -715}, 0, {5573, -3134}, {193, 77, 79, 255} }},
	{{ {-619, 128, 687}, 0, {-3933, -1750}, {38, 103, 191, 255} }},
	{{ {-685, 275, 768}, 0, {-4557, -3134}, {55, 73, 168, 255} }},
	{{ {-586, 275, 791}, 0, {-3622, -3134}, {18, 67, 150, 255} }},
	{{ {-530, 128, 708}, 0, {-3097, -1750}, {11, 103, 182, 255} }},
	{{ {-300, 275, 813}, 0, {-942, -3134}, {252, 63, 146, 255} }},
	{{ {-275, 128, 728}, 0, {-705, -1750}, {251, 100, 178, 255} }},
	{{ {-21, 275, 762}, 0, {1671, -3134}, {244, 61, 145, 255} }},
	{{ {-26, 128, 682}, 0, {1628, -1750}, {248, 102, 181, 255} }},
	{{ {312, 128, 673}, 0, {4798, -1750}, {252, 101, 179, 255} }},
	{{ {357, 275, 752}, 0, {5221, -3134}, {249, 62, 145, 255} }},
	{{ {624, 128, 644}, 0, {7724, -1750}, {223, 102, 187, 255} }},
	{{ {707, 275, 720}, 0, {8498, -3134}, {203, 75, 168, 255} }},
	{{ {635, 128, -637}, 0, {7822, -1750}, {213, 103, 60, 255} }},
	{{ {718, 275, -715}, 0, {8607, -3134}, {193, 77, 79, 255} }},
	{{ {312, 275, -821}, 0, {4800, -3134}, {247, 67, 107, 255} }},
	{{ {272, 128, -732}, 0, {4422, -1750}, {253, 101, 77, 255} }},
	{{ {62, 275, -786}, 0, {2455, -3134}, {14, 62, 110, 255} }},
	{{ {49, 128, -701}, 0, {2329, -1750}, {9, 102, 75, 255} }},
	{{ {49, 128, -701}, 0, {2329, -1750}, {9, 102, 75, 255} }},
	{{ {62, 275, -786}, 0, {2455, -3134}, {14, 62, 110, 255} }},
	{{ {-243, 275, -755}, 0, {-409, -3134}, {248, 61, 111, 255} }},
	{{ {-224, 128, -673}, 0, {-229, -1750}, {252, 103, 74, 255} }},
	{{ {-477, 128, -728}, 0, {-2602, -1750}, {7, 99, 79, 255} }},
	{{ {-527, 275, -817}, 0, {-3067, -3134}, {17, 69, 105, 255} }},
	{{ {-634, 128, -650}, 0, {-4073, -1750}, {70, 99, 40, 255} }},
	{{ {-702, 275, -729}, 0, {-4714, -3134}, {85, 72, 60, 255} }},
	{{ {-851, 275, 579}, 0, {-6560, -3134}, {98, 71, 219, 255} }},
	{{ {-685, 275, 768}, 0, {-8331, -3134}, {55, 73, 168, 255} }},
	{{ {-619, 128, 687}, 0, {-7573, -1750}, {38, 103, 191, 255} }},
	{{ {-767, 128, 518}, 0, {-5992, -1750}, {75, 100, 234, 255} }},
	{{ {-834, 275, 325}, 0, {-4184, -3134}, {111, 57, 23, 255} }},
	{{ {-751, 128, 292}, 0, {-3870, -1750}, {81, 95, 20, 255} }},
	{{ {-750, 275, 124}, 0, {-2294, -3134}, {114, 56, 5, 255} }},
	{{ {-677, 128, 112}, 0, {-2182, -1750}, {72, 105, 2, 255} }},
	{{ {-771, 128, -146}, 0, {238, -1750}, {82, 97, 251, 255} }},
	{{ {-856, 275, -165}, 0, {417, -3134}, {110, 63, 254, 255} }},
	{{ {-724, 128, -318}, 0, {1846, -1750}, {71, 102, 27, 255} }},
	{{ {-803, 275, -357}, 0, {2218, -3134}, {102, 65, 40, 255} }},
	{{ {-641, 128, -482}, 0, {3391, -1750}, {70, 104, 18, 255} }},
	{{ {-710, 275, -542}, 0, {3948, -3134}, {109, 61, 24, 255} }},
	{{ {-634, 128, -650}, 0, {4961, -1750}, {70, 99, 40, 255} }},
	{{ {-702, 275, -729}, 0, {5706, -3134}, {85, 72, 60, 255} }},
};

Gfx yeah_Plane_mesh_tri_9[] = {
	gsSPVertex(yeah_Plane_mesh_vtx_9 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(1, 3, 4, 0, 1, 4, 5, 0),
	gsSP2Triangles(5, 4, 6, 0, 5, 6, 7, 0),
	gsSP2Triangles(7, 6, 8, 0, 7, 8, 9, 0),
	gsSP2Triangles(8, 10, 9, 0, 8, 11, 10, 0),
	gsSP2Triangles(11, 12, 10, 0, 11, 13, 12, 0),
	gsSP2Triangles(14, 15, 16, 0, 14, 16, 17, 0),
	gsSP2Triangles(17, 16, 18, 0, 17, 18, 19, 0),
	gsSP2Triangles(19, 18, 20, 0, 19, 20, 21, 0),
	gsSP2Triangles(20, 22, 21, 0, 20, 23, 22, 0),
	gsSP2Triangles(23, 24, 22, 0, 23, 25, 24, 0),
	gsSP2Triangles(26, 27, 28, 0, 26, 28, 29, 0),
	gsSP2Triangles(29, 28, 30, 0, 29, 30, 31, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_9 + 32, 24, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(2, 4, 3, 0, 2, 5, 4, 0),
	gsSP2Triangles(5, 6, 4, 0, 5, 7, 6, 0),
	gsSP2Triangles(8, 9, 10, 0, 8, 10, 11, 0),
	gsSP2Triangles(12, 8, 11, 0, 12, 11, 13, 0),
	gsSP2Triangles(14, 12, 13, 0, 14, 13, 15, 0),
	gsSP2Triangles(16, 14, 15, 0, 16, 17, 14, 0),
	gsSP2Triangles(18, 17, 16, 0, 18, 19, 17, 0),
	gsSP2Triangles(20, 19, 18, 0, 20, 21, 19, 0),
	gsSP2Triangles(22, 21, 20, 0, 22, 23, 21, 0),
	gsSPEndDisplayList(),
};

Vtx yeah_Plane_mesh_vtx_10[148] = {
	{{ {-366, 0, -539}, 0, {3920, -552}, {127, 0, 252, 255} }},
	{{ {-377, 118, -506}, 0, {3615, -1657}, {99, 253, 80, 255} }},
	{{ {-377, 0, -506}, 0, {3615, -552}, {96, 0, 84, 255} }},
	{{ {-366, 118, -539}, 0, {3920, -1657}, {127, 1, 254, 255} }},
	{{ {-377, 0, -567}, 0, {4181, -552}, {100, 0, 178, 255} }},
	{{ {-377, 118, -567}, 0, {4181, -1657}, {101, 252, 179, 255} }},
	{{ {-381, 162, -579}, 0, {4296, -2070}, {86, 246, 163, 255} }},
	{{ {-408, 162, -591}, 0, {4406, -2070}, {18, 247, 131, 255} }},
	{{ {-365, 162, -548}, 0, {4007, -2070}, {126, 252, 241, 255} }},
	{{ {-383, 162, -494}, 0, {3502, -2070}, {88, 247, 92, 255} }},
	{{ {-362, 221, -535}, 0, {3882, -2620}, {127, 247, 2, 255} }},
	{{ {-387, 221, -586}, 0, {4359, -2620}, {79, 252, 156, 255} }},
	{{ {-428, 118, -481}, 0, {3378, -1657}, {0, 248, 127, 255} }},
	{{ {-428, 0, -481}, 0, {-2138, -552}, {0, 0, 127, 255} }},
	{{ {-475, 118, -505}, 0, {-2580, -1657}, {158, 250, 80, 255} }},
	{{ {-475, 0, -505}, 0, {-2580, -552}, {158, 0, 81, 255} }},
	{{ {-428, 118, -481}, 0, {-2138, -1657}, {0, 248, 127, 255} }},
	{{ {-377, 0, -506}, 0, {-1661, -552}, {96, 0, 84, 255} }},
	{{ {-377, 118, -506}, 0, {-1661, -1657}, {99, 253, 80, 255} }},
	{{ {-433, 162, -478}, 0, {-2194, -2070}, {242, 246, 126, 255} }},
	{{ {-383, 162, -494}, 0, {-1725, -2070}, {88, 247, 92, 255} }},
	{{ {-385, 221, -488}, 0, {-1741, -2620}, {80, 247, 99, 255} }},
	{{ {-362, 221, -535}, 0, {-1520, -2620}, {127, 247, 2, 255} }},
	{{ {-434, 221, -474}, 0, {-2201, -2620}, {225, 8, 123, 255} }},
	{{ {-383, 271, -484}, 0, {-1722, -3089}, {65, 8, 109, 255} }},
	{{ {-358, 271, -529}, 0, {-1488, -3089}, {126, 246, 14, 255} }},
	{{ {-430, 271, -483}, 0, {-2161, -3089}, {213, 22, 117, 255} }},
	{{ {-387, 321, -494}, 0, {-1755, -3557}, {53, 22, 113, 255} }},
	{{ {-355, 321, -528}, 0, {-1454, -3557}, {123, 8, 30, 255} }},
	{{ {-437, 321, -494}, 0, {-2228, -3557}, {213, 6, 119, 255} }},
	{{ {-399, 371, -496}, 0, {-1872, -4026}, {54, 6, 115, 255} }},
	{{ {-364, 371, -532}, 0, {-1541, -4026}, {117, 22, 43, 255} }},
	{{ {-437, 321, -494}, 0, {-2228, -3557}, {213, 6, 119, 255} }},
	{{ {-399, 371, -496}, 0, {-1872, -4026}, {54, 6, 115, 255} }},
	{{ {-435, 371, -491}, 0, {-2206, -4026}, {238, 247, 125, 255} }},
	{{ {-396, 421, -496}, 0, {-1839, -4495}, {74, 244, 102, 255} }},
	{{ {-374, 421, -525}, 0, {-1639, -4495}, {117, 12, 49, 255} }},
	{{ {-423, 421, -485}, 0, {-2100, -4495}, {8, 237, 125, 255} }},
	{{ {-462, 371, -503}, 0, {-2465, -4026}, {169, 247, 92, 255} }},
	{{ {-456, 421, -496}, 0, {-2405, -4495}, {177, 253, 99, 255} }},
	{{ {-478, 371, -534}, 0, {-2607, -4026}, {130, 252, 15, 255} }},
	{{ {-433, 162, -478}, 0, {-2194, -2070}, {242, 246, 126, 255} }},
	{{ {-434, 221, -474}, 0, {-2201, -2620}, {225, 8, 123, 255} }},
	{{ {-478, 162, -503}, 0, {-2610, -2070}, {148, 6, 66, 255} }},
	{{ {-430, 271, -483}, 0, {-2161, -3089}, {213, 22, 117, 255} }},
	{{ {-468, 221, -506}, 0, {-2520, -2620}, {142, 20, 53, 255} }},
	{{ {-466, 271, -519}, 0, {-2498, -3089}, {141, 6, 54, 255} }},
	{{ {-466, 321, -515}, 0, {-2499, -3557}, {154, 247, 76, 255} }},
	{{ {-488, 0, -554}, 0, {4059, -552}, {133, 0, 225, 255} }},
	{{ {-456, 118, -588}, 0, {4378, -1657}, {203, 10, 141, 255} }},
	{{ {-456, 0, -588}, 0, {4378, -552}, {205, 0, 140, 255} }},
	{{ {-488, 118, -554}, 0, {4059, -1657}, {134, 10, 221, 255} }},
	{{ {-475, 118, -505}, 0, {3599, -1657}, {158, 250, 80, 255} }},
	{{ {-475, 0, -505}, 0, {3599, -552}, {158, 0, 81, 255} }},
	{{ {-478, 162, -503}, 0, {3580, -2070}, {148, 6, 66, 255} }},
	{{ {-433, 162, -478}, 0, {3346, -2070}, {242, 246, 126, 255} }},
	{{ {-479, 162, -549}, 0, {4019, -2070}, {139, 23, 213, 255} }},
	{{ {-468, 221, -506}, 0, {3613, -2620}, {142, 20, 53, 255} }},
	{{ {-434, 221, -474}, 0, {3312, -2620}, {225, 8, 123, 255} }},
	{{ {-469, 221, -557}, 0, {4086, -2620}, {136, 5, 213, 255} }},
	{{ {-466, 271, -519}, 0, {3730, -3089}, {141, 6, 54, 255} }},
	{{ {-430, 271, -483}, 0, {3398, -3089}, {213, 22, 117, 255} }},
	{{ {-471, 271, -554}, 0, {4063, -3089}, {131, 247, 238, 255} }},
	{{ {-466, 321, -515}, 0, {3697, -3557}, {154, 247, 76, 255} }},
	{{ {-466, 271, -519}, 0, {3730, -3089}, {141, 6, 54, 255} }},
	{{ {-437, 321, -494}, 0, {3497, -3557}, {213, 6, 119, 255} }},
	{{ {-466, 321, -515}, 0, {3697, -3557}, {154, 247, 76, 255} }},
	{{ {-471, 271, -554}, 0, {4063, -3089}, {131, 247, 238, 255} }},
	{{ {-477, 321, -543}, 0, {3958, -3557}, {129, 247, 4, 255} }},
	{{ {-462, 371, -503}, 0, {3582, -4026}, {169, 247, 92, 255} }},
	{{ {-435, 371, -491}, 0, {3472, -4026}, {238, 247, 125, 255} }},
	{{ {-478, 371, -534}, 0, {3871, -4026}, {130, 252, 15, 255} }},
	{{ {-466, 321, -575}, 0, {4263, -3557}, {156, 252, 178, 255} }},
	{{ {-459, 371, -587}, 0, {4376, -4026}, {168, 247, 165, 255} }},
	{{ {-481, 421, -547}, 0, {3996, -4495}, {129, 251, 252, 255} }},
	{{ {-456, 421, -496}, 0, {3519, -4495}, {177, 253, 99, 255} }},
	{{ {-415, 321, -601}, 0, {4500, -3557}, {2, 247, 129, 255} }},
	{{ {-488, 118, -554}, 0, {4059, -1657}, {134, 10, 221, 255} }},
	{{ {-479, 162, -549}, 0, {4019, -2070}, {139, 23, 213, 255} }},
	{{ {-456, 118, -588}, 0, {4378, -1657}, {203, 10, 141, 255} }},
	{{ {-469, 221, -557}, 0, {4086, -2620}, {136, 5, 213, 255} }},
	{{ {-444, 162, -585}, 0, {4356, -2070}, {203, 7, 141, 255} }},
	{{ {-447, 221, -585}, 0, {4357, -2620}, {180, 247, 155, 255} }},
	{{ {-406, 0, -588}, 0, {-1934, -552}, {39, 0, 135, 255} }},
	{{ {-377, 118, -567}, 0, {-1663, -1657}, {101, 252, 179, 255} }},
	{{ {-377, 0, -567}, 0, {-1663, -552}, {100, 0, 178, 255} }},
	{{ {-406, 118, -588}, 0, {-1934, -1657}, {38, 0, 135, 255} }},
	{{ {-456, 0, -588}, 0, {-2407, -552}, {205, 0, 140, 255} }},
	{{ {-456, 118, -588}, 0, {-2407, -1657}, {203, 10, 141, 255} }},
	{{ {-444, 162, -585}, 0, {-2290, -2070}, {203, 7, 141, 255} }},
	{{ {-479, 162, -549}, 0, {-2622, -2070}, {139, 23, 213, 255} }},
	{{ {-408, 162, -591}, 0, {-1957, -2070}, {18, 247, 131, 255} }},
	{{ {-447, 221, -585}, 0, {-2323, -2620}, {180, 247, 155, 255} }},
	{{ {-469, 221, -557}, 0, {-2523, -2620}, {136, 5, 213, 255} }},
	{{ {-419, 221, -597}, 0, {-2063, -2620}, {252, 249, 129, 255} }},
	{{ {-460, 271, -582}, 0, {-2438, -3089}, {164, 247, 169, 255} }},
	{{ {-447, 221, -585}, 0, {-2323, -2620}, {180, 247, 155, 255} }},
	{{ {-471, 271, -554}, 0, {-2548, -3089}, {131, 247, 238, 255} }},
	{{ {-460, 271, -582}, 0, {-2438, -3089}, {164, 247, 169, 255} }},
	{{ {-419, 221, -597}, 0, {-2063, -2620}, {252, 249, 129, 255} }},
	{{ {-429, 271, -597}, 0, {-2149, -3089}, {241, 252, 130, 255} }},
	{{ {-387, 221, -586}, 0, {-1757, -2620}, {79, 252, 156, 255} }},
	{{ {-375, 271, -579}, 0, {-1644, -3089}, {91, 247, 168, 255} }},
	{{ {-415, 321, -601}, 0, {-2024, -3557}, {2, 247, 129, 255} }},
	{{ {-466, 321, -575}, 0, {-2501, -3557}, {156, 252, 178, 255} }},
	{{ {-362, 221, -535}, 0, {-1520, -2620}, {127, 247, 2, 255} }},
	{{ {-406, 118, -588}, 0, {-1934, -1657}, {38, 0, 135, 255} }},
	{{ {-408, 162, -591}, 0, {-1957, -2070}, {18, 247, 131, 255} }},
	{{ {-377, 118, -567}, 0, {-1663, -1657}, {101, 252, 179, 255} }},
	{{ {-381, 162, -579}, 0, {-1698, -2070}, {86, 246, 163, 255} }},
	{{ {-365, 162, -548}, 0, {-1555, -2070}, {126, 252, 241, 255} }},
	{{ {-362, 221, -535}, 0, {3882, -2620}, {127, 247, 2, 255} }},
	{{ {-358, 271, -529}, 0, {3827, -3089}, {126, 246, 14, 255} }},
	{{ {-385, 221, -488}, 0, {3440, -2620}, {80, 247, 99, 255} }},
	{{ {-375, 271, -579}, 0, {4295, -3089}, {91, 247, 168, 255} }},
	{{ {-368, 321, -577}, 0, {4279, -3557}, {99, 246, 177, 255} }},
	{{ {-415, 321, -601}, 0, {4500, -3557}, {2, 247, 129, 255} }},
	{{ {-355, 321, -528}, 0, {3819, -3557}, {123, 8, 30, 255} }},
	{{ {-365, 371, -579}, 0, {4298, -4026}, {109, 8, 191, 255} }},
	{{ {-409, 371, -604}, 0, {4532, -4026}, {14, 246, 130, 255} }},
	{{ {-364, 371, -532}, 0, {3859, -4026}, {117, 22, 43, 255} }},
	{{ {-375, 421, -576}, 0, {4265, -4495}, {114, 26, 206, 255} }},
	{{ {-409, 421, -608}, 0, {4566, -4495}, {23, 255, 131, 255} }},
	{{ {-374, 421, -525}, 0, {3792, -4495}, {117, 12, 49, 255} }},
	{{ {-399, 371, -496}, 0, {3523, -4026}, {54, 6, 115, 255} }},
	{{ {-383, 271, -484}, 0, {3410, -3089}, {65, 8, 109, 255} }},
	{{ {-387, 321, -494}, 0, {3500, -3557}, {53, 22, 113, 255} }},
	{{ {-460, 271, -582}, 0, {4323, -3089}, {164, 247, 169, 255} }},
	{{ {-466, 321, -575}, 0, {4263, -3557}, {156, 252, 178, 255} }},
	{{ {-429, 271, -597}, 0, {4465, -3089}, {241, 252, 130, 255} }},
	{{ {-477, 321, -543}, 0, {3958, -3557}, {129, 247, 4, 255} }},
	{{ {-471, 271, -554}, 0, {4063, -3089}, {131, 247, 238, 255} }},
	{{ {-415, 321, -601}, 0, {-2024, -3557}, {2, 247, 129, 255} }},
	{{ {-409, 371, -604}, 0, {-1969, -4026}, {14, 246, 130, 255} }},
	{{ {-368, 321, -577}, 0, {-1582, -3557}, {99, 246, 177, 255} }},
	{{ {-459, 371, -587}, 0, {-2437, -4026}, {168, 247, 165, 255} }},
	{{ {-458, 421, -594}, 0, {-2421, -4495}, {177, 248, 157, 255} }},
	{{ {-481, 421, -547}, 0, {-2642, -4495}, {129, 251, 252, 255} }},
	{{ {-409, 421, -608}, 0, {-1961, -4495}, {23, 255, 131, 255} }},
	{{ {-365, 371, -579}, 0, {-1553, -4026}, {109, 8, 191, 255} }},
	{{ {-423, 421, -485}, 0, {-2100, -3904}, {0, 127, 0, 255} }},
	{{ {-396, 421, -496}, 0, {-1839, -4010}, {0, 127, 0, 255} }},
	{{ {-456, 421, -496}, 0, {-2405, -4007}, {0, 127, 0, 255} }},
	{{ {-374, 421, -525}, 0, {-1639, -4281}, {0, 127, 0, 255} }},
	{{ {-481, 421, -547}, 0, {-2642, -4485}, {0, 127, 0, 255} }},
	{{ {-458, 421, -594}, 0, {-2421, -4926}, {0, 127, 0, 255} }},
	{{ {-375, 421, -576}, 0, {-1642, -4753}, {0, 127, 0, 255} }},
	{{ {-409, 421, -608}, 0, {-1961, -5055}, {0, 127, 0, 255} }},
};

Gfx yeah_Plane_mesh_tri_10[] = {
	gsSPVertex(yeah_Plane_mesh_vtx_10 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 3, 0, 0, 4, 5, 3, 0),
	gsSP2Triangles(5, 6, 3, 0, 5, 7, 6, 0),
	gsSP2Triangles(3, 6, 8, 0, 3, 8, 1, 0),
	gsSP2Triangles(1, 8, 9, 0, 8, 10, 9, 0),
	gsSP2Triangles(8, 11, 10, 0, 1, 9, 12, 0),
	gsSP2Triangles(13, 14, 15, 0, 13, 16, 14, 0),
	gsSP2Triangles(17, 16, 13, 0, 17, 18, 16, 0),
	gsSP2Triangles(16, 19, 14, 0, 16, 20, 19, 0),
	gsSP2Triangles(20, 21, 19, 0, 20, 22, 21, 0),
	gsSP2Triangles(19, 21, 23, 0, 21, 24, 23, 0),
	gsSP2Triangles(21, 25, 24, 0, 23, 24, 26, 0),
	gsSP2Triangles(24, 27, 26, 0, 24, 28, 27, 0),
	gsSP2Triangles(26, 27, 29, 0, 27, 30, 29, 0),
	gsSP1Triangle(27, 31, 30, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_10 + 32, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 1, 3, 2, 0),
	gsSP2Triangles(1, 4, 3, 0, 2, 3, 5, 0),
	gsSP2Triangles(2, 5, 6, 0, 6, 5, 7, 0),
	gsSP2Triangles(6, 7, 8, 0, 9, 10, 11, 0),
	gsSP2Triangles(10, 12, 13, 0, 12, 0, 14, 0),
	gsSP2Triangles(0, 2, 15, 0, 16, 17, 18, 0),
	gsSP2Triangles(16, 19, 17, 0, 16, 20, 19, 0),
	gsSP2Triangles(16, 21, 20, 0, 20, 22, 19, 0),
	gsSP2Triangles(20, 23, 22, 0, 19, 22, 24, 0),
	gsSP2Triangles(22, 25, 24, 0, 22, 26, 25, 0),
	gsSP2Triangles(24, 25, 27, 0, 25, 28, 27, 0),
	gsSP2Triangles(25, 29, 28, 0, 27, 28, 30, 0),
	gsSP1Triangle(28, 31, 30, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_10 + 64, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
	gsSP2Triangles(2, 5, 4, 0, 2, 6, 5, 0),
	gsSP2Triangles(4, 5, 7, 0, 4, 7, 8, 0),
	gsSP2Triangles(8, 7, 9, 0, 7, 10, 9, 0),
	gsSP2Triangles(7, 11, 10, 0, 8, 9, 12, 0),
	gsSP2Triangles(13, 14, 15, 0, 14, 16, 17, 0),
	gsSP2Triangles(16, 3, 18, 0, 19, 20, 21, 0),
	gsSP2Triangles(19, 22, 20, 0, 23, 22, 19, 0),
	gsSP2Triangles(23, 24, 22, 0, 24, 25, 22, 0),
	gsSP2Triangles(24, 26, 25, 0, 22, 25, 27, 0),
	gsSP2Triangles(25, 28, 27, 0, 25, 29, 28, 0),
	gsSP2Triangles(27, 28, 30, 0, 28, 31, 30, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_10 + 96, 31, 0),
	gsSP2Triangles(0, 1, 2, 0, 3, 2, 4, 0),
	gsSP2Triangles(3, 4, 5, 0, 5, 4, 6, 0),
	gsSP2Triangles(4, 7, 6, 0, 4, 8, 7, 0),
	gsSP2Triangles(5, 6, 9, 0, 10, 11, 12, 0),
	gsSP2Triangles(11, 3, 13, 0, 13, 3, 5, 0),
	gsSP2Triangles(13, 5, 14, 0, 15, 16, 17, 0),
	gsSP2Triangles(15, 18, 16, 0, 18, 19, 16, 0),
	gsSP2Triangles(18, 20, 19, 0, 16, 19, 21, 0),
	gsSP2Triangles(19, 22, 21, 0, 19, 23, 22, 0),
	gsSP2Triangles(21, 22, 24, 0, 22, 25, 24, 0),
	gsSP2Triangles(22, 26, 25, 0, 24, 25, 27, 0),
	gsSP2Triangles(24, 27, 28, 0, 16, 21, 29, 0),
	gsSP1Triangle(21, 24, 30, 0),
	gsSPVertex(yeah_Plane_mesh_vtx_10 + 127, 21, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(4, 3, 0, 0, 5, 6, 7, 0),
	gsSP2Triangles(5, 8, 6, 0, 8, 9, 6, 0),
	gsSP2Triangles(8, 10, 9, 0, 6, 9, 11, 0),
	gsSP2Triangles(6, 11, 12, 0, 13, 14, 15, 0),
	gsSP2Triangles(14, 16, 15, 0, 17, 15, 16, 0),
	gsSP2Triangles(18, 17, 16, 0, 16, 19, 18, 0),
	gsSP1Triangle(19, 20, 18, 0),
	gsSPEndDisplayList(),
};

Gfx mat_yeah_f3dlite_material[] = {
	gsSPSetLights1(yeah_f3dlite_material_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yeah_f3dlite_material[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_yeah_f3dlite_material_002[] = {
	gsSPSetLights1(yeah_f3dlite_material_002_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, yeah_tex4_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 1),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, yeah_tex4_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yeah_f3dlite_material_002[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_yeah_f3dlite_material_004[] = {
	gsSPSetLights1(yeah_f3dlite_material_004_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, yeah_tex2_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 1),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, yeah_tex2_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yeah_f3dlite_material_004[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_yeah_f3dlite_material_005[] = {
	gsSPSetLights1(yeah_f3dlite_material_005_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 1, yeah_mario_ci4_i8),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 2047, 256),
	gsDPSetTile(G_IM_FMT_I, G_IM_SIZ_8b, 8, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0, G_TX_WRAP | G_TX_NOMIRROR, 6, 0),
	gsDPSetTileSize(0, 0, 0, 252, 252),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yeah_f3dlite_material_005[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx mat_yeah_f3dlite_material_006[] = {
	gsSPSetLights1(yeah_f3dlite_material_006_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, yeah_tex1_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 1),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, yeah_tex1_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yeah_f3dlite_material_006[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_yeah_f3dlite_material_007[] = {
	gsSPSetLights1(yeah_f3dlite_material_007_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, yeah_tex10_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 1),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, yeah_tex10_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yeah_f3dlite_material_007[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_yeah_f3dlite_material_008[] = {
	gsSPSetLights1(yeah_f3dlite_material_008_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, yeah_tex7_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 1),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, yeah_tex7_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yeah_f3dlite_material_008[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_yeah_f3dlite_material_009[] = {
	gsSPSetLights1(yeah_f3dlite_material_009_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, yeah_tex10_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 1),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, yeah_tex10_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yeah_f3dlite_material_009[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_yeah_f3dlite_material_010[] = {
	gsSPSetLights1(yeah_f3dlite_material_010_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, yeah_tex_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 1),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, yeah_tex_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yeah_f3dlite_material_010[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_yeah_f3dlite_material_011[] = {
	gsSPSetLights1(yeah_f3dlite_material_011_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT, TEXEL0, 0, SHADE, 0, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsDPSetTextureLUT(G_TT_RGBA16),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, yeah_tex1_pal_rgba16),
	gsDPSetTile(0, 0, 0, 256, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadTLUTCmd(5, 1),
	gsDPSetTextureImage(G_IM_FMT_CI, G_IM_SIZ_16b, 1, yeah_tex1_ci4),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_16b, 0, 0, 7, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 0, 0),
	gsDPLoadBlock(7, 0, 0, 255, 1024),
	gsDPSetTile(G_IM_FMT_CI, G_IM_SIZ_4b, 2, 0, 0, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, 0),
	gsDPSetTileSize(0, 0, 0, 124, 124),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yeah_f3dlite_material_011[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsDPSetTextureLUT(G_TT_NONE),
	gsSPEndDisplayList(),
};

Gfx mat_yeah_f3dlite_material_012[] = {
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yeah_f3dlite_material_012[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Lights1 yeah_f3dlite_material_001_lights = gdSPDefLights1(
	0x3D, 0x66, 0x7F,
	0x80, 0xCE, 0xFF, 0x49, 0x49, 0x49);

Vtx yeah_Icosphere_mesh_vtx_cull[8] = {
	{{ {-1252, 148, -1316}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-1252, 148, 1316}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-1252, 1464, 1316}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {-1252, 1464, -1316}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {1252, 148, -1316}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {1252, 148, 1316}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {1252, 1464, 1316}, 0, {0, 0}, {0, 0, 0, 0} }},
	{{ {1252, 1464, -1316}, 0, {0, 0}, {0, 0, 0, 0} }},
};

Vtx yeah_Icosphere_mesh_vtx_0[42] = {
	{{ {692, 1268, 0}, 0, {403, 605}, {189, 148, 0, 255} }},
	{{ {0, 1464, 0}, 0, {449, 524}, {0, 129, 0, 255} }},
	{{ {214, 1268, -658}, 0, {496, 605}, {235, 148, 64, 255} }},
	{{ {906, 840, -658}, 0, {449, 686}, {169, 189, 63, 255} }},
	{{ {364, 737, -1120}, 0, {543, 686}, {221, 199, 108, 255} }},
	{{ {774, 148, -1065}, 0, {496, 766}, {182, 228, 99, 255} }},
	{{ {0, 148, -1316}, 0, {589, 766}, {2, 228, 124, 255} }},
	{{ {-346, 840, -1065}, 0, {636, 686}, {33, 189, 103, 255} }},
	{{ {214, 1268, -658}, 0, {589, 605}, {235, 148, 64, 255} }},
	{{ {-560, 1268, -407}, 0, {682, 605}, {54, 148, 39, 255} }},
	{{ {0, 1464, 0}, 0, {636, 524}, {0, 129, 0, 255} }},
	{{ {-952, 737, -692}, 0, {729, 686}, {92, 199, 67, 255} }},
	{{ {-774, 148, -1065}, 0, {682, 766}, {71, 228, 101, 255} }},
	{{ {-1252, 148, -407}, 0, {775, 766}, {118, 228, 36, 255} }},
	{{ {-1120, 840, 0}, 0, {822, 686}, {108, 189, 0, 255} }},
	{{ {-560, 1268, -407}, 0, {775, 605}, {54, 148, 39, 255} }},
	{{ {-560, 1268, 407}, 0, {868, 605}, {54, 148, 217, 255} }},
	{{ {0, 1464, 0}, 0, {822, 524}, {0, 129, 0, 255} }},
	{{ {-952, 737, 692}, 0, {915, 686}, {92, 199, 189, 255} }},
	{{ {-1252, 148, 407}, 0, {868, 766}, {118, 228, 220, 255} }},
	{{ {-774, 148, 1065}, 0, {961, 766}, {71, 228, 155, 255} }},
	{{ {1177, 737, 0}, 0, {356, 686}, {142, 199, 0, 255} }},
	{{ {1252, 148, -407}, 0, {403, 766}, {139, 228, 40, 255} }},
	{{ {1252, 148, 407}, 0, {310, 766}, {139, 228, 216, 255} }},
	{{ {906, 840, 658}, 0, {263, 686}, {169, 189, 193, 255} }},
	{{ {774, 148, 1065}, 0, {217, 766}, {182, 228, 157, 255} }},
	{{ {364, 737, 1120}, 0, {170, 686}, {221, 199, 148, 255} }},
	{{ {0, 148, 1316}, 0, {124, 766}, {2, 228, 132, 255} }},
	{{ {-346, 840, 1065}, 0, {77, 686}, {33, 189, 153, 255} }},
	{{ {-774, 148, 1065}, 0, {31, 766}, {71, 228, 155, 255} }},
	{{ {-952, 737, 692}, 0, {-16, 686}, {92, 199, 189, 255} }},
	{{ {-560, 1268, 407}, 0, {31, 605}, {54, 148, 217, 255} }},
	{{ {-560, 1268, 407}, 0, {31, 605}, {54, 148, 217, 255} }},
	{{ {214, 1268, 658}, 0, {124, 605}, {235, 148, 192, 255} }},
	{{ {-346, 840, 1065}, 0, {77, 686}, {33, 189, 153, 255} }},
	{{ {0, 1464, 0}, 0, {77, 524}, {0, 129, 0, 255} }},
	{{ {364, 737, 1120}, 0, {170, 686}, {221, 199, 148, 255} }},
	{{ {214, 1268, 658}, 0, {217, 605}, {235, 148, 192, 255} }},
	{{ {906, 840, 658}, 0, {263, 686}, {169, 189, 193, 255} }},
	{{ {692, 1268, 0}, 0, {310, 605}, {189, 148, 0, 255} }},
	{{ {0, 1464, 0}, 0, {263, 524}, {0, 129, 0, 255} }},
	{{ {1177, 737, 0}, 0, {356, 686}, {142, 199, 0, 255} }},
};

Gfx yeah_Icosphere_mesh_tri_0[] = {
	gsSPVertex(yeah_Icosphere_mesh_vtx_0 + 0, 32, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 2, 3, 0),
	gsSP2Triangles(3, 2, 4, 0, 5, 3, 4, 0),
	gsSP2Triangles(5, 4, 6, 0, 6, 4, 7, 0),
	gsSP2Triangles(4, 8, 7, 0, 8, 9, 7, 0),
	gsSP2Triangles(8, 10, 9, 0, 7, 9, 11, 0),
	gsSP2Triangles(12, 7, 11, 0, 12, 11, 13, 0),
	gsSP2Triangles(13, 11, 14, 0, 11, 15, 14, 0),
	gsSP2Triangles(15, 16, 14, 0, 15, 17, 16, 0),
	gsSP2Triangles(14, 16, 18, 0, 19, 14, 18, 0),
	gsSP2Triangles(19, 18, 20, 0, 13, 14, 19, 0),
	gsSP2Triangles(6, 7, 12, 0, 21, 0, 3, 0),
	gsSP2Triangles(22, 21, 3, 0, 22, 3, 5, 0),
	gsSP2Triangles(23, 21, 22, 0, 23, 24, 21, 0),
	gsSP2Triangles(25, 24, 23, 0, 25, 26, 24, 0),
	gsSP2Triangles(27, 26, 25, 0, 27, 28, 26, 0),
	gsSP2Triangles(29, 28, 27, 0, 29, 30, 28, 0),
	gsSP1Triangle(30, 31, 28, 0),
	gsSPVertex(yeah_Icosphere_mesh_vtx_0 + 32, 10, 0),
	gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
	gsSP2Triangles(2, 1, 4, 0, 4, 5, 6, 0),
	gsSP2Triangles(5, 7, 6, 0, 5, 8, 7, 0),
	gsSP1Triangle(6, 7, 9, 0),
	gsSPEndDisplayList(),
};

Gfx mat_yeah_f3dlite_material_001[] = {
	gsSPSetLights1(yeah_f3dlite_material_001_lights),
	gsDPPipeSync(),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsDPSetAlphaDither(G_AD_NOISE),
	gsSPTexture(65535, 65535, 0, 0, 1),
	gsSPEndDisplayList(),
};

Gfx mat_revert_yeah_f3dlite_material_001[] = {
	gsDPPipeSync(),
	gsDPSetAlphaDither(G_AD_DISABLE),
	gsSPEndDisplayList(),
};

Gfx yeah_Icosphere_mesh[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(yeah_Icosphere_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_yeah_f3dlite_material_001),
	gsSPDisplayList(yeah_Icosphere_mesh_tri_0),
	gsSPDisplayList(mat_revert_yeah_f3dlite_material_001),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};



Gfx dl_menu_file_button[] = {
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(yeah_Plane_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_yeah_f3dlite_material),
	gsSPDisplayList(yeah_Plane_mesh_tri_0),
	gsSPDisplayList(mat_revert_yeah_f3dlite_material),
	gsSPDisplayList(mat_yeah_f3dlite_material_002),
	gsSPDisplayList(yeah_Plane_mesh_tri_1),
	gsSPDisplayList(mat_revert_yeah_f3dlite_material_002),
	gsSPDisplayList(mat_yeah_f3dlite_material_004),
	gsSPDisplayList(yeah_Plane_mesh_tri_2),
	gsSPDisplayList(mat_revert_yeah_f3dlite_material_004),
	gsSPDisplayList(mat_yeah_f3dlite_material_005),
	gsSPDisplayList(yeah_Plane_mesh_tri_3),
	gsSPDisplayList(mat_revert_yeah_f3dlite_material_005),
	gsSPDisplayList(mat_yeah_f3dlite_material_006),
	gsSPDisplayList(yeah_Plane_mesh_tri_4),
	gsSPDisplayList(mat_revert_yeah_f3dlite_material_006),
	gsSPDisplayList(mat_yeah_f3dlite_material_007),
	gsSPDisplayList(yeah_Plane_mesh_tri_5),
	gsSPDisplayList(mat_revert_yeah_f3dlite_material_007),
	gsSPDisplayList(mat_yeah_f3dlite_material_008),
	gsSPDisplayList(yeah_Plane_mesh_tri_6),
	gsSPDisplayList(mat_revert_yeah_f3dlite_material_008),
	gsSPDisplayList(mat_yeah_f3dlite_material_009),
	gsSPDisplayList(yeah_Plane_mesh_tri_7),
	gsSPDisplayList(mat_revert_yeah_f3dlite_material_009),
	gsSPDisplayList(mat_yeah_f3dlite_material_010),
	gsSPDisplayList(yeah_Plane_mesh_tri_8),
	gsSPDisplayList(mat_revert_yeah_f3dlite_material_010),
	gsSPDisplayList(mat_yeah_f3dlite_material_011),
	gsSPDisplayList(yeah_Plane_mesh_tri_9),
	gsSPDisplayList(mat_revert_yeah_f3dlite_material_011),
	gsSPDisplayList(mat_yeah_f3dlite_material_012),
	gsSPDisplayList(yeah_Plane_mesh_tri_10),
	gsSPDisplayList(mat_revert_yeah_f3dlite_material_012),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPClearGeometryMode(G_LIGHTING),
	gsSPVertex(yeah_Icosphere_mesh_vtx_cull + 0, 8, 0),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPCullDisplayList(0, 7),
	gsSPDisplayList(mat_yeah_f3dlite_material_001),
	gsSPDisplayList(yeah_Icosphere_mesh_tri_0),
	gsSPDisplayList(mat_revert_yeah_f3dlite_material_001),
	gsDPPipeSync(),
	gsSPSetGeometryMode(G_LIGHTING),
	gsSPClearGeometryMode(G_TEXTURE_GEN),
	gsDPSetCombineLERP(0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT, 0, 0, 0, SHADE, 0, 0, 0, ENVIRONMENT),
	gsSPTexture(65535, 65535, 0, 0, 0),
	gsSPEndDisplayList(),
};



// 0x07006258 - 0x07006288
const Gfx dl_menu_score_button[] = {
    gsSPDisplayList(dl_tex_block_menu_main_button),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_score),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(dl_menu_main_button),
    gsSPEndDisplayList(),
};

// 0x07006288 - 0x070062B8
const Gfx dl_menu_sound_button[] = {
    gsSPDisplayList(dl_tex_block_menu_main_button),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_sound),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(dl_menu_main_button),
    gsSPEndDisplayList(),
};

// 0x070062B8 - 0x070062E8
const Gfx dl_menu_generic_button[] = {
    gsSPDisplayList(dl_tex_block_menu_main_button),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_stone),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPDisplayList(dl_menu_main_button),
    gsSPEndDisplayList(),
};

// 0x070062E8 - 0x07006328
static const Vtx vertex_menu_hand[] = {
    {{{     0,      0,      0}, 0, {     0,   1984}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{    32,      0,      0}, 0, {  1984,   1984}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{    32,     32,      0}, 0, {  1984,      0}, {0x00, 0x00, 0x7f, 0xff}}},
    {{{     0,     32,      0}, 0, {     0,      0}, {0x00, 0x00, 0x7f, 0xff}}},
};

// 0x07006328 - 0x07006B28
ALIGNED8 static const Texture texture_menu_idle_hand[] = {
#include "levels/menu/main_menu_seg7.06328.rgba16.inc.c"
};

// 0x07006B28 - 0x07007328
ALIGNED8 static const Texture texture_menu_grabbing_hand[] = {
#include "levels/menu/main_menu_seg7.06B28.rgba16.inc.c"
};

// 0x07007328 - 0x070073A0
static const Gfx dl_menu_hand[] = {
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetRenderMode(G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPVertex(vertex_menu_hand, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSPTexture(0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPEndDisplayList(),
};

// 0x070073A0 - 0x070073B8
const Gfx dl_menu_idle_hand[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_idle_hand),
    gsSPBranchList(dl_menu_hand),
};

// 0x070073B8 - 0x070073D0
const Gfx dl_menu_grabbing_hand[] = {
    gsDPPipeSync(),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_grabbing_hand),
    gsSPBranchList(dl_menu_hand),
};

// 0x070073D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_hu[] = {
#include "levels/menu/main_menu_seg7.073D0.rgba16.inc.c"
};

// 0x070075D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_small_a[] = {
#include "levels/menu/main_menu_seg7.075D0.rgba16.inc.c"
};

// 0x070077D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_i[] = {
#include "levels/menu/main_menu_seg7.077D0.rgba16.inc.c"
};

// 0x070079D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_ru[] = {
#include "levels/menu/main_menu_seg7.079D0.rgba16.inc.c"
};

// 0x07007BD0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_se[] = {
#include "levels/menu/main_menu_seg7.07BD0.rgba16.inc.c"
};

// 0x07007DD0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_re[] = {
#include "levels/menu/main_menu_seg7.07DD0.rgba16.inc.c"
};

// 0x07007FD0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_ku[] = {
#include "levels/menu/main_menu_seg7.07FD0.rgba16.inc.c"
};

// 0x070081D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_to[] = {
#include "levels/menu/main_menu_seg7.081D0.rgba16.inc.c"
};

// 0x070083D0
ALIGNED8 static const Texture texture_menu_hud_char_hiragana_wo[] = {
#include "levels/menu/main_menu_seg7.083D0.rgba16.inc.c"
};

// 0x070085D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_ko[] = {
#include "levels/menu/main_menu_seg7.085D0.rgba16.inc.c"
};

// 0x070087D0
ALIGNED8 static const Texture texture_menu_hud_char_kana_handakuten_pi[] = {
#include "levels/menu/main_menu_seg7.087D0.rgba16.inc.c"
};

// 0x070089D0
ALIGNED8 static const Texture texture_menu_hud_char_choonpu[] = {
#include "levels/menu/main_menu_seg7.089D0.rgba16.inc.c"
};

// 0x07008BD0
ALIGNED8 static const Texture texture_menu_hud_char_hiragana_su[] = {
#include "levels/menu/main_menu_seg7.08BD0.rgba16.inc.c"
};

// 0x07008DD0
ALIGNED8 static const Texture texture_menu_hud_char_hiragana_ru[] = {
#include "levels/menu/main_menu_seg7.08DD0.rgba16.inc.c"
};

// 0x07008FD0
ALIGNED8 static const Texture texture_menu_hud_char_hiragana_ke[] = {
#include "levels/menu/main_menu_seg7.08FD0.rgba16.inc.c"
};

// 0x070091D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_ma[] = {
#include "levels/menu/main_menu_seg7.091D0.rgba16.inc.c"
};

// 0x070093D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_ri[] = {
#include "levels/menu/main_menu_seg7.093D0.rgba16.inc.c"
};

// 0x070095D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_o[] = {
#include "levels/menu/main_menu_seg7.095D0.rgba16.inc.c"
};

// 0x070097D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_su[] = {
#include "levels/menu/main_menu_seg7.097D0.rgba16.inc.c"
};

// 0x070099D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_a[] = {
#include "levels/menu/main_menu_seg7.099D0.rgba16.inc.c"
};

// 0x07009BD0
ALIGNED8 static const Texture texture_menu_hud_char_hiragana_mi[] = {
#include "levels/menu/main_menu_seg7.09BD0.rgba16.inc.c"
};

// 0x07009DD0
ALIGNED8 static const Texture texture_menu_hud_char_hira_dakuten_do[] = {
#include "levels/menu/main_menu_seg7.09DD0.rgba16.inc.c"
};

// 0x07009FD0
ALIGNED8 static const Texture texture_menu_hud_char_hiragana_no[] = {
#include "levels/menu/main_menu_seg7.09FD0.rgba16.inc.c"
};

// 0x0700A1D0
ALIGNED8 static const Texture texture_menu_hud_char_question[] = {
#include "levels/menu/main_menu_seg7.0A1D0.rgba16.inc.c"
};

// 0x0700A3D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_sa[] = {
#include "levels/menu/main_menu_seg7.0A3D0.rgba16.inc.c"
};

// 0x0700A5D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_u[] = {
#include "levels/menu/main_menu_seg7.0A5D0.rgba16.inc.c"
};

// 0x0700A7D0
ALIGNED8 static const Texture texture_menu_hud_char_katakana_n[] = {
#include "levels/menu/main_menu_seg7.0A7D0.rgba16.inc.c"
};

// 0x0700A9D0
ALIGNED8 static const Texture texture_menu_hud_char_kana_dakuten_do[] = {
#include "levels/menu/main_menu_seg7.0A9D0.rgba16.inc.c"
};

// Menu HUD print table, only used in JP
// 0x0700ABD0
const Texture *const menu_hud_lut[] = {
    texture_menu_hud_char_katakana_hu, texture_menu_hud_char_katakana_small_a,         texture_menu_hud_char_katakana_i, texture_menu_hud_char_katakana_ru,
    texture_menu_hud_char_katakana_se,      texture_menu_hud_char_katakana_re,        texture_menu_hud_char_katakana_ku, texture_menu_hud_char_katakana_to,
    texture_menu_hud_char_hiragana_wo,      texture_menu_hud_char_katakana_ko, texture_menu_hud_char_kana_handakuten_pi, texture_menu_hud_char_choonpu,
    texture_menu_hud_char_hiragana_su,      texture_menu_hud_char_hiragana_ru,        texture_menu_hud_char_hiragana_ke, texture_menu_hud_char_katakana_ma,
    texture_menu_hud_char_katakana_ri,       texture_menu_hud_char_katakana_o,        texture_menu_hud_char_katakana_su, texture_menu_hud_char_katakana_a,
    texture_menu_hud_char_hiragana_mi,  texture_menu_hud_char_hira_dakuten_do,        texture_menu_hud_char_hiragana_no, texture_menu_hud_char_question,
    texture_menu_hud_char_katakana_sa,       texture_menu_hud_char_katakana_u,         texture_menu_hud_char_katakana_n, texture_menu_hud_char_kana_dakuten_do,
};

#if defined(VERSION_JP) || defined(VERSION_SH)
UNUSED static const u64 menu_unused_0 = 0;

// 0x0700AC48
ALIGNED8 static const Texture texture_menu_font_char_jp_0[] = {
#include "levels/menu/main_menu_seg7.0AC48.ia8.inc.c"
};

// 0x0700AC88
ALIGNED8 static const Texture texture_menu_font_char_jp_1[] = {
#include "levels/menu/main_menu_seg7.0AC88.ia8.inc.c"
};

// 0x0700ACC8
ALIGNED8 static const Texture texture_menu_font_char_jp_2[] = {
#include "levels/menu/main_menu_seg7.0ACC8.ia8.inc.c"
};

// 0x0700AD08
ALIGNED8 static const Texture texture_menu_font_char_jp_3[] = {
#include "levels/menu/main_menu_seg7.0AD08.ia8.inc.c"
};

// 0x0700AD48
ALIGNED8 static const Texture texture_menu_font_char_jp_4[] = {
#include "levels/menu/main_menu_seg7.0AD48.ia8.inc.c"
};

// 0x0700AD88
ALIGNED8 static const Texture texture_menu_font_char_jp_5[] = {
#include "levels/menu/main_menu_seg7.0AD88.ia8.inc.c"
};

// 0x0700ADC8
ALIGNED8 static const Texture texture_menu_font_char_jp_6[] = {
#include "levels/menu/main_menu_seg7.0ADC8.ia8.inc.c"
};

// 0x0700AE08
ALIGNED8 static const Texture texture_menu_font_char_jp_7[] = {
#include "levels/menu/main_menu_seg7.0AE08.ia8.inc.c"
};

// 0x0700AE48
ALIGNED8 static const Texture texture_menu_font_char_jp_8[] = {
#include "levels/menu/main_menu_seg7.0AE48.ia8.inc.c"
};

// 0x0700AE88
ALIGNED8 static const Texture texture_menu_font_char_jp_9[] = {
#include "levels/menu/main_menu_seg7.0AE88.ia8.inc.c"
};

// 0x0700AEC8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_a[] = {
#include "levels/menu/main_menu_seg7.0AEC8.ia8.inc.c"
};

// 0x0700AF08
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_i[] = {
#include "levels/menu/main_menu_seg7.0AF08.ia8.inc.c"
};

// 0x0700AF48
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_u[] = {
#include "levels/menu/main_menu_seg7.0AF48.ia8.inc.c"
};

// 0x0700AF88
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_c[] = {
#include "levels/menu/main_menu_seg7.0AF88.ia8.inc.c"
};

// 0x0700AFC8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_o[] = {
#include "levels/menu/main_menu_seg7.0AFC8.ia8.inc.c"
};

// 0x0700B008
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ka[] = {
#include "levels/menu/main_menu_seg7.0B008.ia8.inc.c"
};

// 0x0700B048
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ki[] = {
#include "levels/menu/main_menu_seg7.0B048.ia8.inc.c"
};

// 0x0700B088
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ku[] = {
#include "levels/menu/main_menu_seg7.0B088.ia8.inc.c"
};

// 0x0700B0C8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ke[] = {
#include "levels/menu/main_menu_seg7.0B0C8.ia8.inc.c"
};

// 0x0700B108
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ko[] = {
#include "levels/menu/main_menu_seg7.0B108.ia8.inc.c"
};

// 0x0700B148
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_sa[] = {
#include "levels/menu/main_menu_seg7.0B148.ia8.inc.c"
};

// 0x0700B188
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_shi[] = {
#include "levels/menu/main_menu_seg7.0B188.ia8.inc.c"
};

// 0x0700B1C8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_su[] = {
#include "levels/menu/main_menu_seg7.0B1C8.ia8.inc.c"
};

// 0x0700B208
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_se[] = {
#include "levels/menu/main_menu_seg7.0B208.ia8.inc.c"
};

// 0x0700B248
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_so[] = {
#include "levels/menu/main_menu_seg7.0B248.ia8.inc.c"
};

// 0x0700B288
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ta[] = {
#include "levels/menu/main_menu_seg7.0B288.ia8.inc.c"
};

// 0x0700B2C8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_chi[] = {
#include "levels/menu/main_menu_seg7.0B2C8.ia8.inc.c"
};

// 0x0700B308
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_tsu[] = {
#include "levels/menu/main_menu_seg7.0B308.ia8.inc.c"
};

// 0x0700B348
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_te[] = {
#include "levels/menu/main_menu_seg7.0B348.ia8.inc.c"
};

// 0x0700B388
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_to[] = {
#include "levels/menu/main_menu_seg7.0B388.ia8.inc.c"
};

// 0x0700B3C8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_na[] = {
#include "levels/menu/main_menu_seg7.0B3C8.ia8.inc.c"
};

// 0x0700B408
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ni[] = {
#include "levels/menu/main_menu_seg7.0B408.ia8.inc.c"
};

// 0x0700B448
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_nu[] = {
#include "levels/menu/main_menu_seg7.0B448.ia8.inc.c"
};

// 0x0700B488
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ne[] = {
#include "levels/menu/main_menu_seg7.0B488.ia8.inc.c"
};

// 0x0700B4C8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_no[] = {
#include "levels/menu/main_menu_seg7.0B4C8.ia8.inc.c"
};

// 0x0700B508
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ha[] = {
#include "levels/menu/main_menu_seg7.0B508.ia8.inc.c"
};

// 0x0700B548
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_hi[] = {
#include "levels/menu/main_menu_seg7.0B548.ia8.inc.c"
};

// 0x0700B588
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_hu[] = {
#include "levels/menu/main_menu_seg7.0B588.ia8.inc.c"
};

// 0x0700B5C8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_he[] = {
#include "levels/menu/main_menu_seg7.0B5C8.ia8.inc.c"
};

// 0x0700B608
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ho[] = {
#include "levels/menu/main_menu_seg7.0B608.ia8.inc.c"
};

// 0x0700B648
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ma[] = {
#include "levels/menu/main_menu_seg7.0B648.ia8.inc.c"
};

// 0x0700B688
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_mi[] = {
#include "levels/menu/main_menu_seg7.0B688.ia8.inc.c"
};

// 0x0700B6C8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_mu[] = {
#include "levels/menu/main_menu_seg7.0B6C8.ia8.inc.c"
};

// 0x0700B708
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_me[] = {
#include "levels/menu/main_menu_seg7.0B708.ia8.inc.c"
};

// 0x0700B748
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_mo[] = {
#include "levels/menu/main_menu_seg7.0B748.ia8.inc.c"
};

// 0x0700B788
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ya[] = {
#include "levels/menu/main_menu_seg7.0B788.ia8.inc.c"
};

// 0x0700B7C8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_yu[] = {
#include "levels/menu/main_menu_seg7.0B7C8.ia8.inc.c"
};

// 0x0700B808
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_yo[] = {
#include "levels/menu/main_menu_seg7.0B808.ia8.inc.c"
};

// 0x0700B848
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ra[] = {
#include "levels/menu/main_menu_seg7.0B848.ia8.inc.c"
};

// 0x0700B888
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ri[] = {
#include "levels/menu/main_menu_seg7.0B888.ia8.inc.c"
};

// 0x0700B8C8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ru[] = {
#include "levels/menu/main_menu_seg7.0B8C8.ia8.inc.c"
};

// 0x0700B908
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_re[] = {
#include "levels/menu/main_menu_seg7.0B908.ia8.inc.c"
};

// 0x0700B948
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_ro[] = {
#include "levels/menu/main_menu_seg7.0B948.ia8.inc.c"
};

// 0x0700B988
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_wa[] = {
#include "levels/menu/main_menu_seg7.0B988.ia8.inc.c"
};

// 0x0700B9C8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_wo[] = {
#include "levels/menu/main_menu_seg7.0B9C8.ia8.inc.c"
};

// 0x0700BA08
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_n[] = {
#include "levels/menu/main_menu_seg7.0BA08.ia8.inc.c"
};

// 0x0700BA48
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_small_a[] = {
#include "levels/menu/main_menu_seg7.0BA48.ia8.inc.c"
};

// 0x0700BA88
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_small_i[] = {
#include "levels/menu/main_menu_seg7.0BA88.ia8.inc.c"
};

// 0x0700BAC8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_small_u[] = {
#include "levels/menu/main_menu_seg7.0BAC8.ia8.inc.c"
};

// 0x0700BB08
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_small_e[] = {
#include "levels/menu/main_menu_seg7.0BB08.ia8.inc.c"
};

// 0x0700BB48
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_small_o[] = {
#include "levels/menu/main_menu_seg7.0BB48.ia8.inc.c"
};

// 0x0700BB88
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_small_ka[] = {
#include "levels/menu/main_menu_seg7.0BB88.ia8.inc.c"
};

// 0x0700BBC8
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_small_yu[] = {
#include "levels/menu/main_menu_seg7.0BBC8.ia8.inc.c"
};

// 0x0700BC08
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_small_yo[] = {
#include "levels/menu/main_menu_seg7.0BC08.ia8.inc.c"
};

// 0x0700BC48
ALIGNED8 static const Texture texture_menu_font_char_jp_hiragana_small_tsu[] = {
#include "levels/menu/main_menu_seg7.0BC48.ia8.inc.c"
};

// 0x0700BC88
ALIGNED8 static const Texture texture_menu_font_char_jp_handakuten[] = {
#include "levels/menu/main_menu_seg7.0BC88.ia8.inc.c"
};

// 0x0700BCC8
ALIGNED8 static const Texture texture_menu_font_char_jp_dakuten[] = {
#include "levels/menu/main_menu_seg7.0BCC8.ia8.inc.c"
};

// 0x0700BD08
ALIGNED8 static const Texture texture_menu_font_char_jp_long_vowel[] = {
#include "levels/menu/main_menu_seg7.0BD08.ia8.inc.c"
};

// 0x0700BD48
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_a[] = {
#include "levels/menu/main_menu_seg7.0BD48.ia8.inc.c"
};

// 0x0700BD88
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_i[] = {
#include "levels/menu/main_menu_seg7.0BD88.ia8.inc.c"
};

// 0x0700BDC8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_u[] = {
#include "levels/menu/main_menu_seg7.0BDC8.ia8.inc.c"
};

// 0x0700BE08
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_e[] = {
#include "levels/menu/main_menu_seg7.0BE08.ia8.inc.c"
};

// 0x0700BE48
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_o[] = {
#include "levels/menu/main_menu_seg7.0BE48.ia8.inc.c"
};

// 0x0700BE88
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ka[] = {
#include "levels/menu/main_menu_seg7.0BE88.ia8.inc.c"
};

// 0x0700BEC8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ki[] = {
#include "levels/menu/main_menu_seg7.0BEC8.ia8.inc.c"
};

// 0x0700BF08
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ku[] = {
#include "levels/menu/main_menu_seg7.0BF08.ia8.inc.c"
};

// 0x0700BF48
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ke[] = {
#include "levels/menu/main_menu_seg7.0BF48.ia8.inc.c"
};

// 0x0700BF88
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ko[] = {
#include "levels/menu/main_menu_seg7.0BF88.ia8.inc.c"
};

// 0x0700BFC8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_sa[] = {
#include "levels/menu/main_menu_seg7.0BFC8.ia8.inc.c"
};

// 0x0700C008
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_shi[] = {
#include "levels/menu/main_menu_seg7.0C008.ia8.inc.c"
};

// 0x0700C048
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_su[] = {
#include "levels/menu/main_menu_seg7.0C048.ia8.inc.c"
};

// 0x0700C088
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_se[] = {
#include "levels/menu/main_menu_seg7.0C088.ia8.inc.c"
};

// 0x0700C0C8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_so[] = {
#include "levels/menu/main_menu_seg7.0C0C8.ia8.inc.c"
};

// 0x0700C108
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ta[] = {
#include "levels/menu/main_menu_seg7.0C108.ia8.inc.c"
};

// 0x0700C148
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_chi[] = {
#include "levels/menu/main_menu_seg7.0C148.ia8.inc.c"
};

// 0x0700C188
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_tsu[] = {
#include "levels/menu/main_menu_seg7.0C188.ia8.inc.c"
};

// 0x0700C1C8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_te[] = {
#include "levels/menu/main_menu_seg7.0C1C8.ia8.inc.c"
};

// 0x0700C208
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_to[] = {
#include "levels/menu/main_menu_seg7.0C208.ia8.inc.c"
};

// 0x0700C248
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_na[] = {
#include "levels/menu/main_menu_seg7.0C248.ia8.inc.c"
};

// 0x0700C288
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ni[] = {
#include "levels/menu/main_menu_seg7.0C288.ia8.inc.c"
};

// 0x0700C2C8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_nu[] = {
#include "levels/menu/main_menu_seg7.0C2C8.ia8.inc.c"
};

// 0x0700C308
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ne[] = {
#include "levels/menu/main_menu_seg7.0C308.ia8.inc.c"
};

// 0x0700C348
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_no[] = {
#include "levels/menu/main_menu_seg7.0C348.ia8.inc.c"
};

// 0x0700C388
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ha[] = {
#include "levels/menu/main_menu_seg7.0C388.ia8.inc.c"
};

// 0x0700C3C8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_hi[] = {
#include "levels/menu/main_menu_seg7.0C3C8.ia8.inc.c"
};

// 0x0700C408
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_hu[] = {
#include "levels/menu/main_menu_seg7.0C408.ia8.inc.c"
};

// 0x0700C448
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_he[] = {
#include "levels/menu/main_menu_seg7.0C448.ia8.inc.c"
};

// 0x0700C488
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ho[] = {
#include "levels/menu/main_menu_seg7.0C488.ia8.inc.c"
};

// 0x0700C4C8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ma[] = {
#include "levels/menu/main_menu_seg7.0C4C8.ia8.inc.c"
};

// 0x0700C508
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_mi[] = {
#include "levels/menu/main_menu_seg7.0C508.ia8.inc.c"
};

// 0x0700C548
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_mu[] = {
#include "levels/menu/main_menu_seg7.0C548.ia8.inc.c"
};

// 0x0700C588
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_me[] = {
#include "levels/menu/main_menu_seg7.0C588.ia8.inc.c"
};

// 0x0700C5C8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_mo[] = {
#include "levels/menu/main_menu_seg7.0C5C8.ia8.inc.c"
};

// 0x0700C608
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ya[] = {
#include "levels/menu/main_menu_seg7.0C608.ia8.inc.c"
};

// 0x0700C648
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_yu[] = {
#include "levels/menu/main_menu_seg7.0C648.ia8.inc.c"
};

// 0x0700C688
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_yo[] = {
#include "levels/menu/main_menu_seg7.0C688.ia8.inc.c"
};

// 0x0700C6C8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ra[] = {
#include "levels/menu/main_menu_seg7.0C6C8.ia8.inc.c"
};

// 0x0700C708
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ri[] = {
#include "levels/menu/main_menu_seg7.0C708.ia8.inc.c"
};

// 0x0700C748
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ru[] = {
#include "levels/menu/main_menu_seg7.0C748.ia8.inc.c"
};

// 0x0700C788
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_re[] = {
#include "levels/menu/main_menu_seg7.0C788.ia8.inc.c"
};

// 0x0700C7C8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_ro[] = {
#include "levels/menu/main_menu_seg7.0C7C8.ia8.inc.c"
};

// 0x0700C808
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_wa[] = {
#include "levels/menu/main_menu_seg7.0C808.ia8.inc.c"
};

// 0x0700C848
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_wo[] = {
#include "levels/menu/main_menu_seg7.0C848.ia8.inc.c"
};

// 0x0700C888
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_n[] = {
#include "levels/menu/main_menu_seg7.0C888.ia8.inc.c"
};

// 0x0700C8C8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_small_a[] = {
#include "levels/menu/main_menu_seg7.0C8C8.ia8.inc.c"
};

// 0x0700C908
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_small_i[] = {
#include "levels/menu/main_menu_seg7.0C908.ia8.inc.c"
};

// 0x0700C948
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_small_u[] = {
#include "levels/menu/main_menu_seg7.0C948.ia8.inc.c"
};

// 0x0700C988
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_small_e[] = {
#include "levels/menu/main_menu_seg7.0C988.ia8.inc.c"
};

// 0x0700C9C8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_small_o[] = {
#include "levels/menu/main_menu_seg7.0C9C8.ia8.inc.c"
};

// 0x0700CA08
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_small_ka[] = {
#include "levels/menu/main_menu_seg7.0CA08.ia8.inc.c"
};

// 0x0700CA48
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_small_yu[] = {
#include "levels/menu/main_menu_seg7.0CA48.ia8.inc.c"
};

// 0x0700CA88
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_small_yo[] = {
#include "levels/menu/main_menu_seg7.0CA88.ia8.inc.c"
};

// 0x0700CAC8
ALIGNED8 static const Texture texture_menu_font_char_jp_katakana_small_tsu[] = {
#include "levels/menu/main_menu_seg7.0CAC8.ia8.inc.c"
};

// 0x0700CB08
ALIGNED8 static const Texture texture_menu_font_char_jp_A[] = {
#include "levels/menu/main_menu_seg7.0CB08.ia8.inc.c"
};

// 0x0700CB48
ALIGNED8 static const Texture texture_menu_font_char_jp_B[] = {
#include "levels/menu/main_menu_seg7.0CB48.ia8.inc.c"
};

// 0x0700CB88
ALIGNED8 static const Texture texture_menu_font_char_jp_C[] = {
#include "levels/menu/main_menu_seg7.0CB88.ia8.inc.c"
};

// 0x0700CBC8
ALIGNED8 static const Texture texture_menu_font_char_jp_D[] = {
#include "levels/menu/main_menu_seg7.0CBC8.ia8.inc.c"
};

// 0x0700CC08
ALIGNED8 static const Texture texture_menu_font_char_jp_coin[] = {
#include "levels/menu/main_menu_seg7.0CC08.ia8.inc.c"
};

// 0x0700CC48
ALIGNED8 static const Texture texture_menu_font_char_jp_star_filled[] = {
#include "levels/menu/main_menu_seg7.0CC48.ia8.inc.c"
};

// 0x0700CC88
ALIGNED8 static const Texture texture_menu_font_char_jp_multiply[] = {
#include "levels/menu/main_menu_seg7.0CC88.ia8.inc.c"
};

// 0x0700CCC8
ALIGNED8 static const Texture texture_menu_font_char_jp_exclamation[] = {
#include "levels/menu/main_menu_seg7.0CCC8.ia8.inc.c"
};

#else

// 0x0700AC40
ALIGNED8 static const Texture texture_menu_font_char_0[] = {
#include "levels/menu/main_menu_seg7_us.0AC40.ia8.inc.c"
};

// 0x0700AC80
ALIGNED8 static const Texture texture_menu_font_char_1[] = {
#include "levels/menu/main_menu_seg7_us.0AC80.ia8.inc.c"
};

// 0x0700ACC0
ALIGNED8 static const Texture texture_menu_font_char_2[] = {
#include "levels/menu/main_menu_seg7_us.0ACC0.ia8.inc.c"
};

// 0x0700AD00
ALIGNED8 static const Texture texture_menu_font_char_3[] = {
#include "levels/menu/main_menu_seg7_us.0AD00.ia8.inc.c"
};

// 0x0700AD40
ALIGNED8 static const Texture texture_menu_font_char_4[] = {
#include "levels/menu/main_menu_seg7_us.0AD40.ia8.inc.c"
};

// 0x0700AD80
ALIGNED8 static const Texture texture_menu_font_char_5[] = {
#include "levels/menu/main_menu_seg7_us.0AD80.ia8.inc.c"
};

// 0x0700ADC0
ALIGNED8 static const Texture texture_menu_font_char_6[] = {
#include "levels/menu/main_menu_seg7_us.0ADC0.ia8.inc.c"
};

// 0x0700AE00
ALIGNED8 static const Texture texture_menu_font_char_7[] = {
#include "levels/menu/main_menu_seg7_us.0AE00.ia8.inc.c"
};

// 0x0700AE40
ALIGNED8 static const Texture texture_menu_font_char_8[] = {
#include "levels/menu/main_menu_seg7_us.0AE40.ia8.inc.c"
};

// 0x0700AE80
ALIGNED8 static const Texture texture_menu_font_char_9[] = {
#include "levels/menu/main_menu_seg7_us.0AE80.ia8.inc.c"
};

// 0x0700AEC0
ALIGNED8 static const Texture texture_menu_font_char_A[] = {
#include "levels/menu/main_menu_seg7_us.0AEC0.ia8.inc.c"
};

// 0x0700AF00
ALIGNED8 static const Texture texture_menu_font_char_B[] = {
#include "levels/menu/main_menu_seg7_us.0AF00.ia8.inc.c"
};

// 0x0700AF40
ALIGNED8 static const Texture texture_menu_font_char_C[] = {
#include "levels/menu/main_menu_seg7_us.0AF40.ia8.inc.c"
};

#ifdef VERSION_EU
// 0x0700AF80
ALIGNED8 static const Texture texture_menu_font_char_D[] = {
#include "levels/menu/main_menu_seg7_eu.0AF80.ia8.inc.c"
};

#else

// 0x0700AF80
ALIGNED8 static const Texture texture_menu_font_char_D[] = {
#include "levels/menu/main_menu_seg7_us.0AF80.ia8.inc.c"
};
#endif

// 0x0700AFC0
ALIGNED8 static const Texture texture_menu_font_char_E[] = {
#include "levels/menu/main_menu_seg7_us.0AFC0.ia8.inc.c"
};

// 0x0700B000
ALIGNED8 static const Texture texture_menu_font_char_F[] = {
#include "levels/menu/main_menu_seg7_us.0B000.ia8.inc.c"
};

// 0x0700B040
ALIGNED8 static const Texture texture_menu_font_char_G[] = {
#include "levels/menu/main_menu_seg7_us.0B040.ia8.inc.c"
};

// 0x0700B080
ALIGNED8 static const Texture texture_menu_font_char_H[] = {
#include "levels/menu/main_menu_seg7_us.0B080.ia8.inc.c"
};

// 0x0700B0C0
ALIGNED8 static const Texture texture_menu_font_char_I[] = {
#include "levels/menu/main_menu_seg7_us.0B0C0.ia8.inc.c"
};

// 0x0700B100
ALIGNED8 static const Texture texture_menu_font_char_J[] = {
#include "levels/menu/main_menu_seg7_us.0B100.ia8.inc.c"
};

// 0x0700B140
ALIGNED8 static const Texture texture_menu_font_char_K[] = {
#include "levels/menu/main_menu_seg7_us.0B140.ia8.inc.c"
};

// 0x0700B180
ALIGNED8 static const Texture texture_menu_font_char_L[] = {
#include "levels/menu/main_menu_seg7_us.0B180.ia8.inc.c"
};

// 0x0700B1C0
ALIGNED8 static const Texture texture_menu_font_char_M[] = {
#include "levels/menu/main_menu_seg7_us.0B1C0.ia8.inc.c"
};

// 0x0700B200
ALIGNED8 static const Texture texture_menu_font_char_N[] = {
#include "levels/menu/main_menu_seg7_us.0B200.ia8.inc.c"
};

// 0x0700B240
ALIGNED8 static const Texture texture_menu_font_char_O[] = {
#include "levels/menu/main_menu_seg7_us.0B240.ia8.inc.c"
};

// 0x0700B280
ALIGNED8 static const Texture texture_menu_font_char_P[] = {
#include "levels/menu/main_menu_seg7_us.0B280.ia8.inc.c"
};

// 0x0700B2C0
ALIGNED8 static const Texture texture_menu_font_char_Q[] = {
#include "levels/menu/main_menu_seg7_us.0B2C0.ia8.inc.c"
};

// 0x0700B300
ALIGNED8 static const Texture texture_menu_font_char_R[] = {
#include "levels/menu/main_menu_seg7_us.0B300.ia8.inc.c"
};

// 0x0700B340
ALIGNED8 static const Texture texture_menu_font_char_S[] = {
#include "levels/menu/main_menu_seg7_us.0B340.ia8.inc.c"
};

// 0x0700B380
ALIGNED8 static const Texture texture_menu_font_char_T[] = {
#include "levels/menu/main_menu_seg7_us.0B380.ia8.inc.c"
};

// 0x0700B3C0
ALIGNED8 static const Texture texture_menu_font_char_U[] = {
#include "levels/menu/main_menu_seg7_us.0B3C0.ia8.inc.c"
};

// 0x0700B400
ALIGNED8 static const Texture texture_menu_font_char_V[] = {
#include "levels/menu/main_menu_seg7_us.0B400.ia8.inc.c"
};

// 0x0700B440
ALIGNED8 static const Texture texture_menu_font_char_W[] = {
#include "levels/menu/main_menu_seg7_us.0B440.ia8.inc.c"
};

// 0x0700B480
ALIGNED8 static const Texture texture_menu_font_char_X[] = {
#include "levels/menu/main_menu_seg7_us.0B480.ia8.inc.c"
};

// 0x0700B4C0
ALIGNED8 static const Texture texture_menu_font_char_Y[] = {
#include "levels/menu/main_menu_seg7_us.0B4C0.ia8.inc.c"
};

// 0x0700B500
ALIGNED8 static const Texture texture_menu_font_char_Z[] = {
#include "levels/menu/main_menu_seg7_us.0B500.ia8.inc.c"
};

// 0x0700B540
ALIGNED8 static const Texture texture_menu_font_char_coin[] = {
#include "levels/menu/main_menu_seg7_us.0B540.ia8.inc.c"
};

// 0x0700B580
ALIGNED8 static const Texture texture_menu_font_char_multiply[] = {
#include "levels/menu/main_menu_seg7_us.0B580.ia8.inc.c"
};

// 0x0700B5C0
ALIGNED8 static const Texture texture_menu_font_char_star_filled[] = {
#include "levels/menu/main_menu_seg7_us.0B5C0.ia8.inc.c"
};

// 0x0700B600
ALIGNED8 static const Texture texture_menu_font_char_dash[] = {
#include "levels/menu/main_menu_seg7_us.0B600.ia8.inc.c"
};

#ifdef VERSION_EU
// 0x0700B640
ALIGNED8 static const Texture texture_menu_font_char_comma[] = {
#include "levels/menu/main_menu_seg7_eu.0B640.ia8.inc.c"
};

// 0x0700B680
ALIGNED8 static const Texture texture_menu_font_char_apostrophe[] = {
#include "levels/menu/main_menu_seg7_eu.0B680.ia8.inc.c"
};

#else

// 0x0700B640
ALIGNED8 static const Texture texture_menu_font_char_comma[] = {
#include "levels/menu/main_menu_seg7_us.0B640.ia8.inc.c"
};

// 0x0700B680
ALIGNED8 static const Texture texture_menu_font_char_apostrophe[] = {
#include "levels/menu/main_menu_seg7_us.0B680.ia8.inc.c"
};
#endif

// 0x0700B6C0
ALIGNED8 static const Texture texture_menu_font_char_exclamation[] = {
#include "levels/menu/main_menu_seg7_us.0B6C0.ia8.inc.c"
};

// 0x0700B700
ALIGNED8 static const Texture texture_menu_font_char_question[] = {
#include "levels/menu/main_menu_seg7_us.0B700.ia8.inc.c"
};

// 0x0700B740
ALIGNED8 static const Texture texture_menu_font_char_mface1[] = {
#include "levels/menu/main_menu_seg7_us.0B740.ia8.inc.c"
};

// 0x0700B780
ALIGNED8 static const Texture texture_menu_font_char_mface2[] = {
#include "levels/menu/main_menu_seg7_us.0B780.ia8.inc.c"
};

// 0x0700B7C0
ALIGNED8 static const Texture texture_menu_font_char_period[] = {
#include "levels/menu/main_menu_seg7_us.0B7C0.ia8.inc.c"
};

// 0x0700B800
ALIGNED8 static const Texture texture_menu_font_char_ampersand[] = {
#include "levels/menu/main_menu_seg7_us.0B800.ia8.inc.c"
};
#endif

#ifdef VERSION_EU
// 0x0700B840
ALIGNED8 static const Texture texture_menu_font_char_umlaut[] = {
#include "levels/menu/main_menu_seg7_eu.0B840.ia8.inc.c"
};

// 0x0700B880
ALIGNED8 static const Texture texture_menu_font_char_cedilla_mayus[] = {
#include "levels/menu/main_menu_seg7_eu.0B880.ia8.inc.c"
};

// 0x0700B8C0
ALIGNED8 static const Texture texture_menu_font_char_colon[] = {
#include "levels/menu/main_menu_seg7_eu.0B8C0.ia8.inc.c"
};
#endif

// Menu small font print table
// 0x0700CD08
const Texture *const menu_font_lut[] = {
#if defined(VERSION_JP) || defined(VERSION_SH)
    texture_menu_font_char_jp_0, texture_menu_font_char_jp_1, texture_menu_font_char_jp_2, texture_menu_font_char_jp_3,
    texture_menu_font_char_jp_4, texture_menu_font_char_jp_5, texture_menu_font_char_jp_6, texture_menu_font_char_jp_7,
    texture_menu_font_char_jp_8, texture_menu_font_char_jp_9, texture_menu_font_char_jp_A, texture_menu_font_char_jp_B,
    texture_menu_font_char_jp_C, texture_menu_font_char_jp_D,                   0x0,                      0x0,
                              0x0,                      0x0,                      0x0,                      0x0,
                              0x0,                      0x0,                      0x0,                      0x0,
                              0x0,                      0x0,                      0x0,                      0x0,
                              0x0,                      0x0,                      0x0,                      0x0,
                              0x0,                      0x0,                      0x0,                      0x0,
                              0x0,                      0x0,                      0x0,                      0x0,
                              0x0,                      0x0,                      0x0,                      0x0,
                              0x0,                      0x0,                      0x0,                      0x0,
                              0x0,                      0x0,                      0x0,                      0x0,
                              0x0,                      0x0,                      0x0,                      0x0,
                              0x0,                      0x0,                      0x0,                      0x0,
                              0x0,                      0x0,                      0x0,                      0x0,
    texture_menu_font_char_jp_hiragana_a, texture_menu_font_char_jp_hiragana_i, texture_menu_font_char_jp_hiragana_u, texture_menu_font_char_jp_hiragana_c,
    texture_menu_font_char_jp_hiragana_o, texture_menu_font_char_jp_hiragana_ka, texture_menu_font_char_jp_hiragana_ki, texture_menu_font_char_jp_hiragana_ku,
    texture_menu_font_char_jp_hiragana_ke, texture_menu_font_char_jp_hiragana_ko, texture_menu_font_char_jp_hiragana_sa, texture_menu_font_char_jp_hiragana_shi,
    texture_menu_font_char_jp_hiragana_su, texture_menu_font_char_jp_hiragana_se, texture_menu_font_char_jp_hiragana_so, texture_menu_font_char_jp_hiragana_ta,
    texture_menu_font_char_jp_hiragana_chi, texture_menu_font_char_jp_hiragana_tsu, texture_menu_font_char_jp_hiragana_te, texture_menu_font_char_jp_hiragana_to,
    texture_menu_font_char_jp_hiragana_na, texture_menu_font_char_jp_hiragana_ni, texture_menu_font_char_jp_hiragana_nu, texture_menu_font_char_jp_hiragana_ne,
    texture_menu_font_char_jp_hiragana_no, texture_menu_font_char_jp_hiragana_ha, texture_menu_font_char_jp_hiragana_hi, texture_menu_font_char_jp_hiragana_hu,
    texture_menu_font_char_jp_hiragana_he, texture_menu_font_char_jp_hiragana_ho, texture_menu_font_char_jp_hiragana_ma, texture_menu_font_char_jp_hiragana_mi,
    texture_menu_font_char_jp_hiragana_mu, texture_menu_font_char_jp_hiragana_me, texture_menu_font_char_jp_hiragana_mo, texture_menu_font_char_jp_hiragana_ya,
    texture_menu_font_char_jp_hiragana_yu, texture_menu_font_char_jp_hiragana_yo, texture_menu_font_char_jp_hiragana_ra, texture_menu_font_char_jp_hiragana_ri,
    texture_menu_font_char_jp_hiragana_ru, texture_menu_font_char_jp_hiragana_re, texture_menu_font_char_jp_hiragana_ro, texture_menu_font_char_jp_hiragana_wa,
    texture_menu_font_char_jp_hiragana_wo, texture_menu_font_char_jp_hiragana_n, 0x0,                                0x0,
    texture_menu_font_char_jp_katakana_a, texture_menu_font_char_jp_katakana_i, texture_menu_font_char_jp_katakana_u, texture_menu_font_char_jp_katakana_e,
    texture_menu_font_char_jp_katakana_o, texture_menu_font_char_jp_katakana_ka, texture_menu_font_char_jp_katakana_ki, texture_menu_font_char_jp_katakana_ku,
    texture_menu_font_char_jp_katakana_ke, texture_menu_font_char_jp_katakana_ko, texture_menu_font_char_jp_katakana_sa, texture_menu_font_char_jp_katakana_shi,
    texture_menu_font_char_jp_katakana_su, texture_menu_font_char_jp_katakana_se, texture_menu_font_char_jp_katakana_so, texture_menu_font_char_jp_katakana_ta,
    texture_menu_font_char_jp_katakana_chi, texture_menu_font_char_jp_katakana_tsu, texture_menu_font_char_jp_katakana_te, texture_menu_font_char_jp_katakana_to,
    texture_menu_font_char_jp_katakana_na, texture_menu_font_char_jp_katakana_ni, texture_menu_font_char_jp_katakana_nu, texture_menu_font_char_jp_katakana_ne,
    texture_menu_font_char_jp_katakana_no, texture_menu_font_char_jp_katakana_ha, texture_menu_font_char_jp_katakana_hi, texture_menu_font_char_jp_katakana_hu,
    texture_menu_font_char_jp_katakana_he, texture_menu_font_char_jp_katakana_ho, texture_menu_font_char_jp_katakana_ma, texture_menu_font_char_jp_katakana_mi,
    texture_menu_font_char_jp_katakana_mu, texture_menu_font_char_jp_katakana_me, texture_menu_font_char_jp_katakana_mo, texture_menu_font_char_jp_katakana_ya,
    texture_menu_font_char_jp_katakana_yu, texture_menu_font_char_jp_katakana_yo, texture_menu_font_char_jp_katakana_ra, texture_menu_font_char_jp_katakana_ri,
    texture_menu_font_char_jp_katakana_ru, texture_menu_font_char_jp_katakana_re, texture_menu_font_char_jp_katakana_ro, texture_menu_font_char_jp_katakana_wa,
    texture_menu_font_char_jp_katakana_wo, texture_menu_font_char_jp_katakana_n,                                   0x0, texture_menu_font_char_jp_long_vowel,
    texture_menu_font_char_jp_hiragana_small_e, texture_menu_font_char_jp_hiragana_small_tsu, texture_menu_font_char_jp_hiragana_small_ka, texture_menu_font_char_jp_hiragana_small_yu,
    texture_menu_font_char_jp_hiragana_small_yo, texture_menu_font_char_jp_hiragana_small_a, texture_menu_font_char_jp_hiragana_small_i, texture_menu_font_char_jp_hiragana_small_u,
    texture_menu_font_char_jp_hiragana_small_o,          0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    texture_menu_font_char_jp_katakana_small_e, texture_menu_font_char_jp_katakana_small_tsu, texture_menu_font_char_jp_katakana_small_ka, texture_menu_font_char_jp_katakana_small_yu,
    texture_menu_font_char_jp_katakana_small_yo, texture_menu_font_char_jp_katakana_small_a, texture_menu_font_char_jp_katakana_small_i, texture_menu_font_char_jp_katakana_small_u,
    texture_menu_font_char_jp_katakana_small_o, 0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    texture_menu_font_char_jp_dakuten, texture_menu_font_char_jp_handakuten, texture_menu_font_char_jp_exclamation, 0x0,
    0x0,                      0x0,                      0x0,                      0x0,
    0x0,                      texture_menu_font_char_jp_coin, texture_menu_font_char_jp_star_filled, texture_menu_font_char_jp_multiply,
    0x0,                      0x0,                      0x0,                      0x0,
#else
    texture_menu_font_char_0, texture_menu_font_char_1, texture_menu_font_char_2, texture_menu_font_char_3,
    texture_menu_font_char_4, texture_menu_font_char_5, texture_menu_font_char_6, texture_menu_font_char_7,
    texture_menu_font_char_8, texture_menu_font_char_9, texture_menu_font_char_A, texture_menu_font_char_B,
    texture_menu_font_char_C, texture_menu_font_char_D, texture_menu_font_char_E, texture_menu_font_char_F,
    texture_menu_font_char_G, texture_menu_font_char_H, texture_menu_font_char_I, texture_menu_font_char_J,
    texture_menu_font_char_K, texture_menu_font_char_L, texture_menu_font_char_M, texture_menu_font_char_N,
    texture_menu_font_char_O, texture_menu_font_char_P, texture_menu_font_char_Q, texture_menu_font_char_R,
    texture_menu_font_char_S, texture_menu_font_char_T, texture_menu_font_char_U, texture_menu_font_char_V,
    texture_menu_font_char_W, texture_menu_font_char_X, texture_menu_font_char_Y, texture_menu_font_char_Z,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0, texture_menu_font_char_apostrophe, texture_menu_font_char_period,
    texture_menu_font_char_mface1, texture_menu_font_char_mface2,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0, texture_menu_font_char_comma,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0, texture_menu_font_char_dash,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
#ifdef VERSION_EU
          0x0, texture_menu_font_char_ampersand, texture_menu_font_char_colon,       0x0,
          0x0, texture_menu_font_char_umlaut,       0x0,       0x0,
          0x0, texture_menu_font_char_cedilla_mayus,       0x0,       0x0,
#else
          0x0, texture_menu_font_char_ampersand,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
          0x0,       0x0,       0x0,       0x0,
#endif
          0x0,       0x0, texture_menu_font_char_exclamation,       0x0,
    texture_menu_font_char_question,       0x0,       0x0,       0x0,
          0x0, texture_menu_font_char_coin, texture_menu_font_char_star_filled, texture_menu_font_char_multiply,
          0x0,       0x0,       0x0,       0x0,
#endif
};

// 0x0700D108 - 0x0700D160
const Gfx dl_menu_ia8_text_begin[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetCombineMode(G_CC_FADEA, G_CC_FADEA),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsDPSetRenderMode(G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_IA, G_IM_SIZ_8b, 1, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 3, G_TX_NOLOD, G_TX_CLAMP, 3, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (8 - 1) << G_TEXTURE_IMAGE_FRAC, (8 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPEndDisplayList(),
};

// 0x0700D160 - 0x0700D1A0
const Gfx dl_menu_ia8_text_end[] = {
    gsDPPipeSync(),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetEnvColor(255, 255, 255, 255),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsSPEndDisplayList(),
};

UNUSED static const u64 menu_unused_1 = 0;

#ifdef VERSION_EU

// 0x0700BDA0 - 0x0700CDA0
ALIGNED8 static const Texture texture_menu_course_upper[] = {
#include "levels/menu/main_menu_seg7_eu.0BDA0.rgba16.inc.c"
};

// 0x0700CDA0 - 0x0700DDA0
ALIGNED8 static const Texture texture_menu_niveau_upper[] = {
#include "levels/menu/main_menu_seg7_eu.0CDA0.rgba16.inc.c"
};

// 0x0700DDA0 - 0x0700EDA0
ALIGNED8 static const Texture texture_menu_kurs_upper[] = {
#include "levels/menu/main_menu_seg7_eu.0DDA0.rgba16.inc.c"
};

// 0x0700EDA0 - 0x0700FDA0
ALIGNED8 static const Texture texture_menu_course_lower[] = {
#include "levels/menu/main_menu_seg7_eu.0EDA0.rgba16.inc.c"
};

#else

// 0x0700D1A8 - 0x0700E1A8
ALIGNED8 static const Texture texture_menu_course_upper[] = {
#include "levels/menu/main_menu_seg7.0D1A8.rgba16.inc.c"
};

// 0x0700E1A8 - 0x0700F1A8
ALIGNED8 static const Texture texture_menu_course_lower[] = {
#include "levels/menu/main_menu_seg7.0E1A8.rgba16.inc.c"
};
#endif

// 0x0700F1A8 - 0x0700F1E8
static const Vtx vertex_menu_course_upper[] = {
    {{{   -32,      0,      0}, 0, {     0,   1984}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{    32,      0,      0}, 0, {  4032,   1984}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{    32,     32,      0}, 0, {  4032,      0}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{   -32,     32,      0}, 0, {     0,      0}, {0x00, 0x00, 0x7f, 0x00}}},
};

// 0x0700F1E8 - 0x0700F228
static const Vtx vertex_menu_course_lower[] = {
    {{{   -32,    -32,      0}, 0, {     0,   1984}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{    32,    -32,      0}, 0, {  4032,   1984}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{    32,      0,      0}, 0, {  4032,      0}, {0x00, 0x00, 0x7f, 0x00}}},
    {{{   -32,      0,      0}, 0, {     0,      0}, {0x00, 0x00, 0x7f, 0x00}}},
};

// 0x0700F228 - 0x0700F2F8
const Gfx dl_menu_rgba16_wood_course[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPTexture(0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2),
#ifdef VERSION_EU
    gsSPEndDisplayList(),
};
const Gfx dl_menu_rgba16_wood_course_end[] = {
#else
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_course_upper),
#endif
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 64 * 32 - 1, CALC_DXT(64, G_IM_SIZ_16b_BYTES)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (64 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPVertex(vertex_menu_course_upper, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_course_lower),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 64 * 32 - 1, CALC_DXT(64, G_IM_SIZ_16b_BYTES)),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 16, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (64 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPVertex(vertex_menu_course_lower, 4, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsDPSetRenderMode(G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2),
    gsSPTexture(0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPEndDisplayList(),
};

#ifdef VERSION_EU
// 0x0700FEF0 - 0x0700FF00
const Gfx dl_menu_texture_course_upper[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_course_upper),
    gsSPEndDisplayList(),
};

// 0x0700FF00 - 0x0700FF10
const Gfx dl_menu_texture_niveau_upper[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_niveau_upper),
    gsSPEndDisplayList(),
};

// 0x0700FF10 - 0x0700FF20
const Gfx dl_menu_texture_kurs_upper[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, texture_menu_kurs_upper),
    gsSPEndDisplayList(),
};
#endif

// 0x0700F2F8 - 0x0700F328
const Collision main_menu_seg7_collision[] = {
    COL_INIT(),
    COL_VERTEX_INIT(0x4),
    COL_VERTEX( 8192, -1000, -8192),
    COL_VERTEX(-8192, -1000, -8192),
    COL_VERTEX(-8192, -1000,  8192),
    COL_VERTEX( 8192, -1000,  8192),
    COL_TRI_INIT(SURFACE_DEFAULT, 2),
    COL_TRI(0, 1, 2),
    COL_TRI(0, 2, 3),
    COL_TRI_STOP(),
    COL_END(),
};

#ifdef VERSION_EU

// Duplicate course name tables; the main menu needs all languages loaded at
// once since it switches language, so the copies in segment 19 aren't good
// enough.

#define COURSE_TABLE eu_course_strings_en_table
#include "text/us/define_courses.inc.c"
#undef COURSE_TABLE

#define COURSE_TABLE eu_course_strings_fr_table
#include "text/fr/define_courses.inc.c"
#undef COURSE_TABLE

#define COURSE_TABLE eu_course_strings_de_table
#include "text/de/define_courses.inc.c"
#undef COURSE_TABLE

#endif
