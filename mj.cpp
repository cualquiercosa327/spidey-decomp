#include "mj.h"
#include "validate.h"
#include "ps2m3d.h"


// @Ok
void CMJ::AI(void){
	if (this->field_290){
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

	this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));

	this->CycleAnim(0, 1);
	this->mFlags |= 0x480;
	this->field_3C = 0x0054D830;

	this->AttachTo(reinterpret_cast<CBody**>(0x56E990));
	this->field_38 = 303;

	this->field_DE = a3;
	this->field_DC = 0;

	if (*submarinerDieRelated)
		this->Die(0);
}

void validate_CMJ(void){
	VALIDATE_SIZE(CMJ, 0x324);
}
