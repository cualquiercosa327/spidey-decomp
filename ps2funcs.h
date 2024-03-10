#pragma once

#include "export.h"


struct MATRIX{
	__int16 m[3][3];
	int t[3];
};

typedef struct {		/* long word type 3D vector */
	long	vx, vy;
	long	vz, pad;
} VECTOR;
	
typedef struct {		/* short word type 3D vector */	
	short	vx, vy;
	short	vz, pad;
} SVECTOR;
	       
typedef struct {		/* color type vector */	
  unsigned char	r, g, b, cd;
} CVECTOR;
	       
typedef struct {		/* 2D short vector */
	short vx, vy;
} DVECTOR;


void validate_MATRIX(void);
EXPORT void gte_SetRotMatrix(MATRIX*);
EXPORT void gte_ldv0(const SVECTOR* a1);
EXPORT void gte_rtv0tr(void);
EXPORT void gte_stlvnl(VECTOR *a1);
EXPORT void gte_rtps(void);
EXPORT void gte_rtpt(void);
EXPORT void gte_op12(void);
EXPORT void gte_ldlvl(VECTOR *a1);
EXPORT void gte_sqr0(void);
EXPORT void gte_rtv0(void);
EXPORT void gte_stlvnl0(int *a1);
EXPORT void gte_stlvnl2(int *a1);
EXPORT void gte_gpf0(void);
EXPORT void gte_stlzc(int *a1);
EXPORT void gte_stsv(SVECTOR *a1);
