#pragma once

#ifndef BWM_H
#define BWM_H

#include "psxgte.h"

typedef const uint32_t *BWM_Model;

typedef struct {
    int v0,v1,v2,v3;
} BWM_FACE;

// Returns the face count of the model
int bwm_get_face_count(BWM_Model *data);

// Returns the vertex count of the model
int bwm_get_vertex_count(BWM_Model *data);
// Returns a vertex with the index of 'i'
VECTOR bwm_get_vertex(BWM_Model *data, int i);

// Returns the vertex indice count (In number of faces so it does the same thing as bwm_get_face_count)
int bwm_get_vertex_index_count(BWM_Model *data);
// Returns a BWM_FACE which contains 4 vertex indicies for the indexed quad.
BWM_FACE bwm_get_face_vertex_indices(BWM_Model *data, int i);

// Returns the uv count of the model
int bwm_get_uv_count(BWM_Model *data);
// Returns a uv with the index of 'i'
VECTOR bwm_get_uv(BWM_Model *data, int i);

// Returns the uv index count of the model
int bwm_get_uv_index_count(BWM_Model *data);
// Returns a BWM_FACE which contains 4 uv indicies for the indexed quad.
BWM_FACE bwm_get_face_uv_indices(BWM_Model *data, int i);

// Returns the normal count of the model
int bwm_get_normal_count(BWM_Model *data);
// Returns a normal with the index of 'i'
VECTOR bwm_get_normal(BWM_Model *data, int i);

// Returns the normal index count of the model
int bwm_get_normal_index_count(BWM_Model *data);
// Returns a BWM_FACE which contains 4 normal indicies for the indexed quad.
BWM_FACE bwm_get_face_normal_indices(BWM_Model *data, int i);

#endif

