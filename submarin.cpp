#include "submarin.h"
#include "validate.h"
#include "ps2m3d.h"

EXPORT u8 submarinerDieRelated;
extern CBaddy* BaddyList;

// @NotOk
// fix the address for 3C
CSubmariner::CSubmariner(i16 * a2, i32 a3)
{
	this->InitItem("mariner");
	this->SquirtAngles(this->SquirtPos(a2));
	this->CycleAnim(0, 1);
	this->mFlags |= 0x480u;

	// @FIXME actual address
	this->field_3C = 0x5573D0;

	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));
	this->field_38 = 326;
	this->field_DE = a3;
	this->field_DC = 0;

	if ( submarinerDieRelated )
		this->Die(0);
}

// @Ok
CSubmariner::~CSubmariner(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
}

// @Ok
void Submariner_CreateSubmariner(u32 * a2,u32 * a3)
{
	i16* v2 = reinterpret_cast<i16*>(a2[0]);
	i32 v3 = static_cast<i32>(a2[1]);

	*a3 = reinterpret_cast<u32>(new CSubmariner(v2, v3));
}

// @SMALLTODO
void Submariner_RelocatableModuleClear(void)
{
    printf("Submariner_RelocatableModuleClear(void)");
}

// @Ok
void CSubmariner::AI(void){
	if (submarinerDieRelated){
		this->Die(0);
	}
	else{
		M3d_BuildTransform(this);
	}
}


void validate_CSubmariner(void){
	VALIDATE_SIZE(CSubmariner, 0x324);
}
