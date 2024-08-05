#include "mj.h"
#include "validate.h"
#include "ps2m3d.h"

extern u8 submarinerDieRelated;

// @SMALLTODO
CMJ::~CMJ(void)
{
    printf("CMJ::~CMJ(void)");
}

// @SMALLTODO
void MJ_RelocatableModuleClear(void)
{
    printf("MJ_RelocatableModuleClear(void)");
}

// @Ok
void CMJ::AI(void) 
{
	if (this->pMessage){
		this->CleanUpMessages(1, 0);
	}

	if(this->field_44 & 1){
		this->field_44 &= 0xFFFE;
		this->CycleAnim(1 - this->field_12A, 1);
	}

	M3d_BuildTransform(this);
}

// @NotOk
// globals
CMJ::CMJ(int* a2, __int16 a3)
{
	this->InitItem("mj");

	this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));

	this->CycleAnim(0, 1);
	this->mFlags |= 0x480;
	this->field_3C = 0x0054D830;

	this->AttachTo(reinterpret_cast<CBody**>(0x56E990));
	this->field_38 = 303;

	this->field_DE = a3;
	this->field_DC = 0;

	if (submarinerDieRelated)
		this->Die(0);
}

// @Ok
void MJ_CreateMJ(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CMJ(v2, v3));
}

void validate_CMJ(void){
	VALIDATE_SIZE(CMJ, 0x324);
}
