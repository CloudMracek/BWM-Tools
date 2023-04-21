#pragma once

#ifndef BWM_H
#define BWM_H

#include "psxgte.h"

typedef struct {
    int v0,v1,v2,v3;
} BWM_FACE;

int bwm_get_face_count(uint32_t *data);

int bwm_get_vertex_count(uint32_t *data);
VECTOR bwm_get_vertex(uint32_t *data, int i);

int bwm_get_vertex_index_count(uint32_t *data);
BWM_FACE bwm_get_face_vertex_indices(uint32_t *data, int i);

int bwm_get_uv_count(uint32_t *data);
VECTOR bwm_get_uv(uint32_t *data, int i);

int bwm_get_uv_index_count(uint32_t *data);
BWM_FACE bwm_get_face_uv_indices(uint32_t *data, int i);

int bwm_get_normal_count(uint32_t *data);
VECTOR bwm_get_normal(uint32_t *data, int i);

int bwm_get_normal_index_count(uint32_t *data);
BWM_FACE bwm_get_face_normal_indices(uint32_t *data, int i);

#endif

