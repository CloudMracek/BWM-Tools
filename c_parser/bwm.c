#include "bwm.h"

int bwm_get_face_count(unsigned char *data) {
	
	int final = 0;
	final |= ( data[0] << 24 );
	final |= ( data[1] << 16 );
	final |= ( data[2] <<  8 );
	final |= ( data[3]       );
	return final;
}

int bwm_get_vertex_count(unsigned char *data) {

	int start = 1*4;	
	int final = 0;
	final |= ( data[start+0] << 24 );
	final |= ( data[start+1] << 16 );
	final |= ( data[start+2] <<  8 );
	final |= ( data[start+3]       );
	return final;
}

VECTOR bwm_get_vertex(unsigned char *data, int i) {
	int start = 2*4+(i*12);
	int x,y,z = 0;
	
	x |= ( data[start+0] << 24 );
	x |= ( data[start+1] << 16 );
	x |= ( data[start+2] <<  8 );
	x |= ( data[start+3]       );
	
	y |= ( data[start+4] << 24 );
	y |= ( data[start+5] << 16 );
	y |= ( data[start+6] <<  8 );
	y |= ( data[start+7]       );

	z |= ( data[start+8] << 24 );
	z |= ( data[start+9] << 16 );
	z |= ( data[start+10] <<  8 );
	z |= ( data[start+11]       );

	VECTOR final = {x,y,z};
	return final;
}

int bwm_get_vertex_index_count(unsigned char *data) {
	int start = ((2+bwm_get_vertex_count(data)*3)*4);
    int final = 0;
	final |= ( data[start+0] << 24 );
	final |= ( data[start+1] << 16 );
	final |= ( data[start+2] <<  8 );
	final |= ( data[start+3]       );
	return final;
}

BWM_FACE bwm_get_face_vertex_indices(unsigned char *data, int i) {
    int start = ((3+bwm_get_vertex_count(data)*3)*4) + i*16;
    int v0,v1,v2,v3 = 0;

	v0 |= ( data[start+0] << 24 );
	v0 |= ( data[start+1] << 16 );
	v0 |= ( data[start+2] <<  8 );
	v0 |= ( data[start+3]       );

    v1 |= ( data[start+4] << 24 );
	v1 |= ( data[start+5] << 16 );
	v1 |= ( data[start+6] <<  8 );
	v1 |= ( data[start+7]       );

    v2 |= ( data[start+8] << 24 );
	v2 |= ( data[start+9] << 16 );
	v2 |= ( data[start+10] <<  8 );
	v2 |= ( data[start+11]       );

    v3 |= ( data[start+12] << 24 );
	v3 |= ( data[start+13] << 16 );
	v3 |= ( data[start+14] <<  8 );
	v3 |= ( data[start+15]       );

	BWM_FACE final = {v0,v1,v2,v3};
    return final;
}

int bwm_get_uv_count(unsigned char *data) {
	int start = ((3+bwm_get_vertex_count(data)*3)*4 + bwm_get_vertex_index_count(data)*16);
    int final = 0;
	final |= ( data[start+0] << 24 );
	final |= ( data[start+1] << 16 );
	final |= ( data[start+2] <<  8 );
	final |= ( data[start+3]       );
	return final;
}

VECTOR bwm_get_uv(unsigned char *data, int i) {
	int start = ((4+bwm_get_vertex_count(data)*3)*4 + bwm_get_vertex_index_count(data)*16) + i*8;
	int u,v = 0;
	
	u |= ( data[start+0] << 24 );
	u |= ( data[start+1] << 16 );
	u |= ( data[start+2] <<  8 );
	u |= ( data[start+3]       );
	
	v |= ( data[start+4] << 24 );
	v |= ( data[start+5] << 16 );
	v |= ( data[start+6] <<  8 );
	v |= ( data[start+7]       );

	VECTOR final = {u,v,0};
	return final;
}

int bwm_get_uv_index_count(unsigned char *data) {
	int start = ((4+bwm_get_vertex_count(data)*3)*4 + bwm_get_vertex_index_count(data)*16) + bwm_get_uv_count(data)*8;
    int final = 0;
	final |= ( data[start+0] << 24 );
	final |= ( data[start+1] << 16 );
	final |= ( data[start+2] <<  8 );
	final |= ( data[start+3]       );
	return final;
}

BWM_FACE bwm_get_face_uv_indices(unsigned char *data, int i) {
    int start = ((5+bwm_get_vertex_count(data)*3)*4 + bwm_get_vertex_index_count(data)*16) + bwm_get_uv_count(data)*8 + i*16;
    int v0,v1,v2,v3 = 0;

	v0 |= ( data[start+0] << 24 );
	v0 |= ( data[start+1] << 16 );
	v0 |= ( data[start+2] <<  8 );
	v0 |= ( data[start+3]       );

    v1 |= ( data[start+4] << 24 );
	v1 |= ( data[start+5] << 16 );
	v1 |= ( data[start+6] <<  8 );
	v1 |= ( data[start+7]       );

    v2 |= ( data[start+8] << 24 );
	v2 |= ( data[start+9] << 16 );
	v2 |= ( data[start+10] <<  8 );
	v2 |= ( data[start+11]       );

    v3 |= ( data[start+12] << 24 );
	v3 |= ( data[start+13] << 16 );
	v3 |= ( data[start+14] <<  8 );
	v3 |= ( data[start+15]       );

	BWM_FACE final = {v0,v1,v2,v3};
    return final;
}

int bwm_get_normal_count(unsigned char *data) {
	int start = ((5+bwm_get_vertex_count(data)*3)*4 + bwm_get_vertex_index_count(data)*16) + bwm_get_uv_count(data)*8 + bwm_get_uv_index_count(data)*16;
    int final = 0;
	final |= ( data[start+0] << 24 );
	final |= ( data[start+1] << 16 );
	final |= ( data[start+2] <<  8 );
	final |= ( data[start+3]       );
	return final;
}

VECTOR bwm_get_normal(unsigned char *data, int i) {
	int start = ((6+bwm_get_vertex_count(data)*3)*4 + bwm_get_vertex_index_count(data)*16) + bwm_get_uv_count(data)*8 + bwm_get_uv_index_count(data)*16 + i*12;
	int x,y,z = 0;
	
	x |= ( data[start+0] << 24 );
	x |= ( data[start+1] << 16 );
	x |= ( data[start+2] <<  8 );
	x |= ( data[start+3]       );
	
	y |= ( data[start+4] << 24 );
	y |= ( data[start+5] << 16 );
	y |= ( data[start+6] <<  8 );
	y |= ( data[start+7]       );

	z |= ( data[start+8] << 24 );
	z |= ( data[start+9] << 16 );
	z |= ( data[start+10] <<  8 );
	z |= ( data[start+11]       );

	VECTOR final = {x,y,z};
	return final;
}

int bwm_get_normal_index_count(unsigned char *data) {
	int start = ((6+bwm_get_vertex_count(data)*3)*4 + bwm_get_vertex_index_count(data)*16) + bwm_get_uv_count(data)*8 + bwm_get_uv_index_count(data)*16 + bwm_get_normal_count(data)*12;
    int final = 0;
	final |= ( data[start+0] << 24 );
	final |= ( data[start+1] << 16 );
	final |= ( data[start+2] <<  8 );
	final |= ( data[start+3]       );
	return final;
}

BWM_FACE bwm_get_face_normal_indices(unsigned char *data, int i) {
    int start = ((7+bwm_get_vertex_count(data)*3)*4 + bwm_get_vertex_index_count(data)*16) + bwm_get_uv_count(data)*8 + bwm_get_uv_index_count(data)*16 + bwm_get_normal_count(data)*12 + i*16;
    int v0,v1,v2,v3 = 0;

	v0 |= ( data[start+0] << 24 );
	v0 |= ( data[start+1] << 16 );
	v0 |= ( data[start+2] <<  8 );
	v0 |= ( data[start+3]       );

    v1 |= ( data[start+4] << 24 );
	v1 |= ( data[start+5] << 16 );
	v1 |= ( data[start+6] <<  8 );
	v1 |= ( data[start+7]       );

    v2 |= ( data[start+8] << 24 );
	v2 |= ( data[start+9] << 16 );
	v2 |= ( data[start+10] <<  8 );
	v2 |= ( data[start+11]       );

    v3 |= ( data[start+12] << 24 );
	v3 |= ( data[start+13] << 16 );
	v3 |= ( data[start+14] <<  8 );
	v3 |= ( data[start+15]       );

	BWM_FACE final = {v0,v1,v2,v3};
    return final;
}