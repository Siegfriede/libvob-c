

#ifndef VOB_COORDS_H
#define VOB_COORDS_H

/** @nopython */

#include <stdbool.h>

// we just need the prototypes
#include "vob/api.h"
//struct vob_scene;
//#define Scene struct vob_scene



enum VOB_COORDINATE_SYSTEM_TYPE {
	CS_ROOT = 1,
	CS_BOX,
	CS_TRANS,
	CS_ORTHO,
};

struct vob_coordinate_system {
	enum VOB_COORDINATE_SYSTEM_TYPE type;
};
//typedef struct vob_coordinate_system Coordsys;


struct vob_coordinate_system_root {
	Coordsys base;
	float w,h;
};
typedef struct vob_coordinate_system_root RootCS;


struct vob_coordinate_system_box {
	Coordsys base;
	Coordsys *parent;
	float x, y, w, h;
};
typedef struct vob_coordinate_system_box BoxCS;

struct vob_coordinate_system_translate {
	Coordsys base;
	Coordsys *parent;
	float x, y, z;
};
typedef struct vob_coordinate_system_translate TransCS;

struct vob_coordinate_system_ortho {
	Coordsys base;
	Coordsys *parent;
	float x, y, z, sx, sy;
};
typedef struct vob_coordinate_system_ortho OrthoCS;



RootCS *vob_coords_root(Scene *vs);

Coordsys *vob_coords_box(Scene *vs, Coordsys *into, float x, float y, float w, float h);

Coordsys *vob_coords_trans(Scene *vs, Coordsys *into, 
			   float x, float y, float z);

Coordsys *vob_coords_ortho(Scene *vs, Coordsys *into, 
			   float x, float y, float z, 
			   float sx, float sy);

bool vob_coords_is_inside(Coordsys *cs, float x, float y);

float vob_coords_w(Coordsys *cs);
float vob_coords_h(Coordsys *cs);

void vob_coords_dump(Coordsys *cs);


void vob_coords_info(Coordsys *into, 
		float *x, float *y, float *z, 
		float *w, float *h,
		float *sx, float *sy);


#endif
