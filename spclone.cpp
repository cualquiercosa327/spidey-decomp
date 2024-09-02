#include "spclone.h"
#include "validate.h"

extern CBaddy* BaddyList;
extern u8 submarinerDieRelated;

// @MEDIUMTODO
void CSpClone::AI(void)
{
    printf("CSpClone::AI(void)");
}

// @Ok
// @Matching
CSpClone::CSpClone(i16 * a2,i32 a3)
{
	this->InitItem("spidey");
	this->field_194 &= 0xFFFFFFDF;
	this->field_194 |= 0x40u;
	this->field_194 &= 0xFFFFFBFF;
	this->field_194 |= 0x800u;

	i16 *v5 = this->SquirtAngles(this->SquirtPos(a2));

	this->ShadowOn();
	this->field_D0 = 48;
	this->field_21E = 100;
	this->field_32C = 2;
	this->field_330 = 2;

	this->RunAnim(0xCAu, 0, -1);
	this->mFlags |= 0x480u;

	// @FIXME figure this shit
	this->field_3C = 0x555920;

	this->AttachTo(reinterpret_cast<CBody**>(&BaddyList));

	this->field_38 = 327;
	this->field_31C.bothFlags = 1;
	this->field_DE = a3;
	this->field_DC = 0;
	this->field_348 = reinterpret_cast<i32>(v5);

	if ( submarinerDieRelated )
		this->Die(0);
}

// @MEDIUMTODO
void CSpClone::DoMGSShadow(void)
{
    printf("CSpClone::DoMGSShadow(void)");
}

// @SMALLTODO
void CSpClone::GetNewCommandBlock(u32)
{
    printf("CSpClone::GetNewCommandBlock(u32)");
}

// @SMALLTODO
void CSpClone::KillCommandBlockByID(i32)
{
    printf("CSpClone::KillCommandBlockByID(i32)");
}

// @MEDIUMTODO
void CSpClone::SynthesizeAnalogueInput(void)
{
    printf("CSpClone::SynthesizeAnalogueInput(void)");
}

// @Ok
CSpClone::~CSpClone(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));

	delete this->field_338;

	this->KillAllCommandBlocks();
}

// @Ok
// @Matching
void SpClone_CreateSpClone(u32 * a2,u32 * a3)
{
	i16* v2 = reinterpret_cast<i16*>(a2[0]);
	i32 v3 = static_cast<i32>(a2[1]);

	*a3 = reinterpret_cast<u32>(new CSpClone(v2, v3));
}

// @SMALLTODO
void SpClone_RelocatableModuleClear(void)
{
    printf("SpClone_RelocatableModuleClear(void)");
}

// @Ok
void CSpClone::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @BIGTODO
void CSpClone::DoPhysics(void)
{}

// @BIGTODO
INLINE int* CSpClone::KillCommandBlock(int*)
{
	return (int*)0x02062024;
}

// @NotOk
// Revisit
void CSpClone::KillAllCommandBlocks(void)
{
	for (int* cur = reinterpret_cast<int*>(this->field_34C); cur; cur = this->KillCommandBlock(cur));
	this->field_34C = 0;
}

void validate_CSpClone(void){
	VALIDATE_SIZE(CSpClone, 0x350);

	VALIDATE(CSpClone, field_328, 0x328);
	VALIDATE(CSpClone, field_32C, 0x32C);
	VALIDATE(CSpClone, field_330, 0x330);
	VALIDATE(CSpClone, field_334, 0x334);
	VALIDATE(CSpClone, field_338, 0x338);

	VALIDATE(CSpClone, field_348, 0x348);

	VALIDATE(CSpClone, field_34C, 0x34C);
}
