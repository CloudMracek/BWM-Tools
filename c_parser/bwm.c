#include "bwm.h"

int bwm_get_face_count(BWM_Model *data) {
	return data[0];
}

int bwm_get_vertex_count(BWM_Model *data) {
	return data[1];
}

VECTOR bwm_get_vertex(BWM_Model *data, int i) {
	int start = 2+(i*3);
	VECTOR final = {data[start],data[start+1],data[start+2]};
	return final;
}

int bwm_get_vertex_index_count(BWM_Model *data) {
	int start = 2+bwm_get_vertex_count(data)*3;
	return data[start];
}

BWM_FACE bwm_get_face_vertex_indices(BWM_Model *data, int i) {
    int start = 3+bwm_get_vertex_count(data)*3 + i*4;
	BWM_FACE final = {data[start],data[start+1],data[start+2],data[start+3]};
    return final;
}

int bwm_get_uv_count(BWM_Model *data) {
	int start = 3+bwm_get_vertex_count(data)*3 + bwm_get_vertex_index_count(data)*4;
    return data[start];
}

VECTOR bwm_get_uv(BWM_Model *data, int i) {
	int start = 4+bwm_get_vertex_count(data)*3 + bwm_get_vertex_index_count(data)*4 + i*2;
	VECTOR final = {data[start],data[start+1],0};
	return final;
}

int bwm_get_uv_index_count(BWM_Model *data) {
	int start = 4+bwm_get_vertex_count(data)*3 + bwm_get_vertex_index_count(data)*4 + bwm_get_uv_count(data)*2;
	return data[start];
}

BWM_FACE bwm_get_face_uv_indices(BWM_Model *data, int i) {
    int start = 5+bwm_get_vertex_count(data)*3 + bwm_get_vertex_index_count(data)*4 + bwm_get_uv_count(data)*2 + i*4;
	BWM_FACE final = {data[start],data[start+1],data[start+2], data[start+3]};
    return final;
}

int bwm_get_normal_count(BWM_Model *data) {
	int start = 5+bwm_get_vertex_count(data)*3 + bwm_get_vertex_index_count(data)*4 + bwm_get_uv_count(data)*2 + bwm_get_uv_index_count(data)*4;
    return data[start];
}

VECTOR bwm_get_normal(BWM_Model *data, int i) {
	int start = 6+bwm_get_vertex_count(data)*3 + bwm_get_vertex_index_count(data)*4 + bwm_get_uv_count(data)*2 + bwm_get_uv_index_count(data)*4 + i*3;
	VECTOR final = {data[start],data[start+1],data[start+2]};
	return final;
}

int bwm_get_normal_index_count(BWM_Model *data) {
	int start = 6+bwm_get_vertex_count(data)*3 + bwm_get_vertex_index_count(data)*4 + bwm_get_uv_count(data)*2 + bwm_get_uv_index_count(data)*4 + bwm_get_normal_count(data)*3;
    return data[start];
}

BWM_FACE bwm_get_face_normal_indices(BWM_Model *data, int i) {
	int start = 7+bwm_get_vertex_count(data)*3 + bwm_get_vertex_index_count(data)*4 + bwm_get_uv_count(data)*2 + bwm_get_uv_index_count(data)*4 + bwm_get_normal_count(data)*3 + i*4;
	BWM_FACE final = {data[start],data[start+1],data[start+2],data[start+3]};
    return final;
}