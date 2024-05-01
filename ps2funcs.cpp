#include "ps2funcs.h"
#include "validate.h"

EXPORT __int16 gRotMatrix[3][3];

EXPORT int vertexRegister[4];

EXPORT VECTOR translationVector;
EXPORT VECTOR gGeneralLongVector;

EXPORT int gRtpsRelatedNoClue;
EXPORT int gRtpsRelatedNoClue2;
EXPORT int gRtpsRelatedNoClue3;

static unsigned char stubGte = 1;

void validate_MATRIX(void){
	VALIDATE_SIZE(MATRIX, 0x20);
	VALIDATE(MATRIX, m, 0x0);
	VALIDATE(MATRIX, t, 0x14);
}

void gte_SetRotMatrix(MATRIX* a1){

	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			gRotMatrix[i][j] = a1->m[i][j];
		}
	}
}

void gte_ldv0(const SVECTOR* a1){
	vertexRegister[0] = a1->vx;
	vertexRegister[1] = a1->vy;
	vertexRegister[2] = a1->vz;
}

void __inline FixedXForm(__int16 matrix[3][3], const VECTOR* a, VECTOR *r){

	int x = a->vx;
	int y = a->vy;
	int z = a->vz;

	r->vx = (x * matrix[0][0] + y * matrix[0][1] + z * matrix[0][2]) >> 12;
	r->vy = (x * matrix[1][0] + y * matrix[1][1] + z * matrix[1][2]) >> 12;
	r->vz = (x * matrix[2][0] + y * matrix[2][1] + z * matrix[2][2]) >> 12;
	r->pad = (long)r;
}

void gte_rtv0tr(void){

	FixedXForm(gRotMatrix, (VECTOR*)&vertexRegister[0], &gGeneralLongVector);

	gGeneralLongVector.vx += translationVector.vx >> 12;
	gGeneralLongVector.vy += translationVector.vy >> 12;
	gGeneralLongVector.vz += translationVector.vz >> 12;
}

void gte_stlvnl(VECTOR *a1)
{
  a1->vx = gGeneralLongVector.vx;
  a1->vy = gGeneralLongVector.vy;
  a1->vz = gGeneralLongVector.vz;
}

void gte_rtps(void){

	FixedXForm(gRotMatrix, (VECTOR*)&vertexRegister[0], &gGeneralLongVector);
	gGeneralLongVector.vz = translationVector.vz + gGeneralLongVector.vy;
	

	if (gGeneralLongVector.vz == 0){
		gGeneralLongVector.vx = 0x8000;
		gGeneralLongVector.vy = 0x8000;
	}
	else{
		gGeneralLongVector.vx = gRtpsRelatedNoClue2 / 2
                          + (gGeneralLongVector.vx + translationVector.vx) * gRtpsRelatedNoClue / gGeneralLongVector.vz;
		gGeneralLongVector.vy = gRtpsRelatedNoClue3 / 2
							  + (translationVector.vy
							   + ((vertexRegister[0] * gRotMatrix[1][0]
								 + vertexRegister[1] * gRotMatrix[1][1]
								 + vertexRegister[2] * gRotMatrix[1][2]) >> 12))
							  * gRtpsRelatedNoClue
							  / gGeneralLongVector.vz;
	}

}


void gte_rtpt(void){
	if ( !stubGte )
		stubbed_printf("stubbed out: gte_rtpt()");
}

EXPORT VECTOR gFtwOp12;
EXPORT VECTOR gWtfOP12;
EXPORT VECTOR gOp12Result;


void gte_op12(void)
{
  gGeneralLongVector.vz = (gFtwOp12.vy * gWtfOP12.vx - gWtfOP12.vy * gFtwOp12.vx) >> 12;
  gGeneralLongVector.vx = (gWtfOP12.vy * gFtwOp12.vz - gWtfOP12.vz * gFtwOp12.vy) >> 12;
  gGeneralLongVector.vy = (gWtfOP12.vz * gFtwOp12.vx - gFtwOp12.vz * gWtfOP12.vx) >> 12;
  gOp12Result = gGeneralLongVector;
}


void gte_ldlvl(VECTOR *a1)
{
  gOp12Result = *a1;
}

void gte_sqr0(void)
{
  gGeneralLongVector.vx = gOp12Result.vx * gOp12Result.vx;
  gGeneralLongVector.vy = gOp12Result.vy * gOp12Result.vy;
  gGeneralLongVector.vz = gOp12Result.vz * gOp12Result.vz;
}



void gte_rtv0(void)
{
	FixedXForm(gRotMatrix, (VECTOR*)&vertexRegister[0], &gGeneralLongVector);

	gOp12Result = gGeneralLongVector;
}

void gte_stlvnl0(int *a1)
{
  *a1 = gGeneralLongVector.vx;
}

void gte_stlvnl2(int *a1)
{
  *a1 = gGeneralLongVector.vz;
}

EXPORT int gScalar;
void gte_gpf0()
{
  gGeneralLongVector.vx = gOp12Result.vx * gScalar;
  gGeneralLongVector.vy = gScalar * gOp12Result.vy;
  gGeneralLongVector.vz = gScalar * gOp12Result.vz;
}

EXPORT int lzc;

// Stupid function, can be extremely simplified
void gte_stlzc(int *a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // eax

  v1 = lzc;
  print_if_false(lzc != 0, "lzc not zero");
  if ( v1 < 0 )
  {
    v2 = 0;
    do
    {
      v1 *= 2;
      ++v2;
    }
    while ( v1 < 0 );
    *a1 = v2;
  }
  else
  {
	v3 = 0;
    do
    {
      v1 *= 2;
      ++v3;
    }
    while ( v1 >= 0 );
    *a1 = v3;
  }
}


void gte_stsv(SVECTOR *a1)
{
  a1->vx = (short)gOp12Result.vx;
  a1->vy = (short)gOp12Result.vy;
  a1->vz = (short)gOp12Result.vz;
}


// Revisit, maybe with validator???
void gte_mvmva(int _sf, int mx, int a3, int cv, int lm)
{
  VECTOR *v7; // eax

  print_if_false(!(_sf!=0 && _sf!=1), "sf!=0 && sf!=1");
  print_if_false(mx == 0, "MX!=0");
  print_if_false(!a3 || a3 == 3, "bad v");
  print_if_false(cv == 3, "cv!=3");
  print_if_false(lm == 0, "lm!=0");
  v7 = (VECTOR *)vertexRegister;

  if ( a3 )
    v7 = &gOp12Result;

  gGeneralLongVector.vx = v7->vz * gRotMatrix[0][2] + v7->vy * gRotMatrix[0][1] + v7->vx * gRotMatrix[0][0];
  gGeneralLongVector.vy = v7->vz * gRotMatrix[1][1] + v7->vy * gRotMatrix[0][1] + v7->vx * gRotMatrix[0][2];
  gGeneralLongVector.vz = v7->vz * gRotMatrix[2][1] + v7->vy * gRotMatrix[2][0] + v7->vx * gRotMatrix[1][2];
  if ( _sf == 1 )
  {
    gGeneralLongVector.vx = gGeneralLongVector.vx >> 12;
    gGeneralLongVector.vy = gGeneralLongVector.vy >> 12;
    gGeneralLongVector.vz = gGeneralLongVector.vz >> 12;
  }

  gOp12Result.vz = gGeneralLongVector.vz;
  gOp12Result.vx = gGeneralLongVector.vx;
  gOp12Result.vy = gGeneralLongVector.vy;
  gOp12Result.pad = gGeneralLongVector.pad;
}


void gte_stsxy(int *a1)
{
  *a1 = (gGeneralLongVector.vx & 0xFFFF) | (gGeneralLongVector.vy << 16);
}

void gte_lddp(int a1)
{
  gScalar = a1;
}


void gte_ldsvrtrow0(const SVECTOR *a1)
{
  gRotMatrix[0][0] = a1->vx;
  gRotMatrix[0][1] = a1->vy;
  gRotMatrix[0][2] = a1->vz;
}

void gte_ldopv1(VECTOR *a1)
{
  gWtfOP12 = *a1;
}

void gte_ldopv2(VECTOR *a1)
{
  gFtwOp12 = *a1;
}


// Garbage revisit
// vertex register is not vector, i added one to it so it doesn't crash, it's trash
void gte_ldlv0(const VECTOR *a1)
{
  *(VECTOR *)vertexRegister = *a1;
}


void gte_stsxy3(int *a1, int *a2, int *a3)
{
  *a1 = (gOp12Result.vx & 0xFFFF) | (gOp12Result.vy << 16);
  *a2 = (gOp12Result.vx & 0xFFFF) | (gOp12Result.vy << 16);
  *a3 = (gOp12Result.vx & 0xFFFF) | (gOp12Result.vy << 16);
  if ( !stubGte )
    stubbed_printf("stubbed out:  gte_stsxy3");
}


void gte_rtir(void){
	FixedXForm(gRotMatrix, &gOp12Result, &gGeneralLongVector);
}

void M3dMaths_SetIdentityRotation(MATRIX *a1)
{
  a1->m[2][2] = 4096;
  a1->m[1][1] = 4096;
  a1->m[0][0] = 4096;

  a1->m[2][1] = 0;
  a1->m[2][0] = 0;
  a1->m[1][2] = 0;

  a1->m[1][0] = 0;
  a1->m[0][2] = 0;
  a1->m[0][1] = 0;
}

// Revisit, with validator
void MulMatrix0(MATRIX *a1, MATRIX *a2, MATRIX *a3)
{
  int v3; // [sp+0h] [-78h]
  int v4; // [sp+4h] [-74h]
  int v5; // [sp+8h] [-70h]
  int v6; // [sp+Ch] [-6Ch]
  int v7; // [sp+10h] [-68h]
  int v8; // [sp+14h] [-64h]
  int v9; // [sp+18h] [-60h]
  int v10; // [sp+1Ch] [-5Ch]
  int v11; // [sp+20h] [-58h]
  int v12; // [sp+24h] [-54h]
  int v13; // [sp+28h] [-50h]
  int v14; // [sp+2Ch] [-4Ch]
  int v15; // [sp+30h] [-48h]
  int v16; // [sp+34h] [-44h]
  int v17; // [sp+38h] [-40h]
  int v18; // [sp+3Ch] [-3Ch]
  int v19; // [sp+40h] [-38h]
  int v20; // [sp+44h] [-34h]

  v12 = a1->m[0][0];
  v13 = a1->m[0][1];
  v14 = a1->m[0][2];
  v15 = a1->m[1][0];
  v16 = a1->m[1][1];
  v17 = a1->m[1][2];
  v18 = a1->m[2][0];
  v19 = a1->m[2][1];
  v20 = a1->m[2][2];
  v3 = a2->m[0][0];
  v4 = a2->m[0][1];
  v5 = a2->m[0][2];
  v6 = a2->m[1][0];
  v7 = a2->m[1][1];
  v8 = a2->m[1][2];
  v9 = a2->m[2][0];
  v10 = a2->m[2][1];
  v11 = a2->m[2][2];
  a3->m[0][0] = (v12 * v3 + v13 * v6 + v14 * v9) >> 12;
  a3->m[0][1] = (v12 * v4 + v13 * v7 + v14 * v10) >> 12;
  a3->m[0][2] = (v12 * v5 + v13 * v8 + v14 * v11) >> 12;
  a3->m[1][0] = (v15 * v3 + v16 * v6 + v17 * v9) >> 12;
  a3->m[1][1] = (v15 * v4 + v16 * v7 + v17 * v10) >> 12;
  a3->m[1][2] = (v15 * v5 + v16 * v8 + v17 * v11) >> 12;
  a3->m[2][0] = (v18 * v3 + v19 * v6 + v20 * v9) >> 12;
  a3->m[2][1] = (v18 * v4 + v19 * v7 + v20 * v10) >> 12;
  a3->m[2][2] = (v18 * v5 + v19 * v8 + v20 * v11) >> 12;
}


void MulMatrix(MATRIX *a1, MATRIX *a2)
{
  //MATRIX v2 = *a1;

	MATRIX v2;
	for (int i = 0; i<3; i++){
		for (int j = 0; j<3; j++){
			v2.m[i][j] = a2->m[i][j];
		}
	}
  MulMatrix0(&v2, a2, a1);
}

void m3d_ZeroTransVector(void)
{
  translationVector.vx = 0;
  translationVector.vy = 0;
  translationVector.vz = 0;
}

void MToQ(MATRIX const & a1, CQuat& a2){
}

void VectorNormal(VECTOR* a1, VECTOR* a2){
}
