#ifndef GD_DRAW_OBJECTS_H
#define GD_DRAW_OBJECTS_H

#include <PR/ultratypes.h>

#include "gd_types.h"
#include "macros.h"

// TODO: make this an enum without causing bss reordering
enum GdColours
{
    COLOUR_BLACK,
    COLOUR_WHITE,
    COLOUR_RED,
    COLOUR_GREEN,
    COLOUR_BLUE,
    COLOUR_GRAY,
    COLOUR_DARK_GRAY,
    COLOUR_DARK_BLUE,
    COLOUR_YELLOW,
    COLOUR_PINK,
    COLOUR_BLACK2 // same as COLOUR_BLACK
};

// data
extern struct ObjCamera *gViewUpdateCamera;

// bss
extern struct ObjGroup *gGdLightGroup;  // ObjGroup* of ObjLights

// functions
void draw_light(struct ObjLight *light);
void draw_material(struct ObjMaterial *mtl);
struct GdColour *gd_get_colour(s32 idx);
void draw_face(struct ObjFace *face);
void draw_label(struct ObjLabel *label);
void draw_net(struct ObjNet *self);
void draw_gadget(struct ObjGadget *gdgt);
void draw_camera(struct ObjCamera *cam);
void world_pos_to_screen_coords(struct GdVec3f *pos, struct ObjCamera *cam, struct ObjView *view);
void draw_nothing(UNUSED struct GdObj *nop);
void draw_particle(struct GdObj *obj);
void draw_bone(struct GdObj *obj);
void draw_joint(struct GdObj *obj);
void draw_group(struct ObjGroup *grp);
void draw_plane(struct GdObj *obj);
void apply_obj_draw_fn(struct GdObj *obj);
void create_gddl_for_shapes(struct ObjGroup *grp);
void map_face_materials(struct ObjGroup *faces, struct ObjGroup *mtls);
void map_vertices(struct ObjGroup *facegrp, struct ObjGroup *vtxgrp);
void update_view(struct ObjView *view);

#endif // GD_DRAW_OBJECTS_H
