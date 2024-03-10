#include "ps2funcs.h"
#include "validate.h"

static __int16 gRotMatrix[3][3];
static int vertexRegister[3];
static VECTOR translationVector;
static VECTOR gGeneralLongVector;

static int gRtpsRelatedNoClue;
static int gRtpsRelatedNoClue2;
static int gRtpsRelatedNoClue3;


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