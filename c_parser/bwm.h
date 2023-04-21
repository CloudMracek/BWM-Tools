#pragma once

#ifndef BWM_H
#define BWM_H

#include "psxgte.h"

typedef struct {
    int v0,v1,v2,v3;
} BWM_FACE;

int bwm_get_face_count(unsigned char *data);

int bwm_get_vertex_count(unsigned char *data);
VECTOR bwm_get_vertex(unsigned char *data, int i);

int bwm_get_vertex_index_count(unsigned char *data);
BWM_FACE bwm_get_face_vertex_indices(unsigned char *data, int i);

int bwm_get_uv_count(unsigned char *data);
VECTOR bwm_get_uv(unsigned char *data, int i);

int bwm_get_uv_index_count(unsigned char *data);
BWM_FACE bwm_get_face_uv_indices(unsigned char *data, int i);

int bwm_get_normal_count(unsigned char *data);
VECTOR bwm_get_normal(unsigned char *data, int i);

int bwm_get_normal_index_count(unsigned char *data);
BWM_FACE bwm_get_face_normal_indices(unsigned char *data, int i);

#endif

