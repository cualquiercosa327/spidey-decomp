#include "thug.h"
#include "validate.h"
#include "trig.h"
#include "m3dutils.h"
#include "message.h"
#include "ps2lowsfx.h"
#include "utils.h"

// @Ok
void CThug::SetParamByIndex(i32 Index, i32 Param)
{
	switch ( Index )
	{
		case 1:
			this->field_374 = Param;
			break;
		case 2:
			this->field_370 = Param;
			break;
		case 3:
			this->field_378 = Param;
			break;
		case 4:
			this->field_37C = Param;
			break;
		case 5:
			this->field_380 = Param;
			break;
		case 6:
			this->field_384 = Param;
			break;
		case 7:
			this->field_388 = Param;
			break;
		case 8:
			this->field_38C = Param;
			break;
		case 9:
			this->field_1FC = Param;
			break;
		case 10:
			this->field_394 = Param;
			break;
		case 11:
			if (Param)
				this->field_218 |= 0x800;
			else
				this->field_218 &= 0xFFFFF7FF;
			break;
		case 12:
			this->field_218 |= 0x8000;
			break;
		default:
			print_if_false(0, "Unknown index in C_SET_PARAMETER_BY_INDEX"); 
			break;
	}
}

// @Ok
void CThug::SetHitDirectionFlag(CVector* pVector)
{
	CSVector v4;
	v4.vx = 0;
	v4.vy = 0;
	v4.vz = 0;

	Utils_CalcAim(&v4, &(this->mPos + (*pVector * 300)), &this->mPos);

	i32 v3 = v4.vy - this->mAngles.vy;
	if (v3 < -2048)
	{
		v3 += 4096;
	}
	else
	{
		if (v3 > 2048)
			v3 -= 4096;
	}

	if (v3 < -455)
	{
		this->field_218 |= 0x20000;
	}
	else
	{
		if (v3 > 455)
			this->field_218 |= 0x10000;
	}
}

// @NotOk
// Globals
// also a little out of order with the v6 | 1 thing :(
CThug::CThug(int *a2, int a3)
{
	__int16 *v5 = this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2)));

	this->field_3B8 = Trig_GetLevelId();

	this->ShadowOn();
	this->field_D0 = 50;
	this->field_3B0 = *dword_5FCCF4;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E990));

	int v6 = this->field_2A8;
	this->field_1F4 = a3;
	this->field_DE = a3;

	__int16 v7 = this->field_38;
	this->field_230 = 0;
	this->field_216 = 32;
	this->field_2A8 = v6 | 1;

	this->field_DC = v7 != 304 ? 150 : 96;
	this->field_D8 = 64;
	this->field_380 = v7 != 304 ? 400 : 300;
	this->field_31C.bothFlags = 0;


	this->field_370 = 3500;
	this->field_374 = 400;
	this->field_378 = 2047;
	this->field_37C = 100;
	this->field_384 = 1500;
	this->field_388 = 10;
	this->field_38C = 10;

	this->field_1FC = 10;
	this->field_394 = 2000;
	this->ParseScript(reinterpret_cast<unsigned __int16*>(v5));
	this->field_212 = 60;
}

// @Ok
void Thug_CreateTHug(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CThug(v2, v3));
}

// @Ok
void __inline CThugPing::SetPosition(void)
{
	CSuper* v2 = reinterpret_cast<CSuper*>(Mem_RecoverPointer(&this->field_70));

	if (!v2)
		this->Die();
	else
		M3dUtils_GetDynamicHookPosition(
				reinterpret_cast<VECTOR*>(&this->mPos),
				v2,
				&this->field_78);
}

// @Ok
void CThugPing::Move(void)
{
	this->SetPosition();
	Bit_ReduceRGB(&this->mCodeBGR, 7);

	if ((this->mCodeBGR & 0xFFFFFF) == 0)
		this->Die();
}

static CThug* gGlobalThug;
static unsigned char gAttackFlagRelated;

// @Ok
void CThug::ClearAttackFlags(void)
{

	if ( gGlobalThug == this )
	{
		gGlobalThug = 0;
	}
	else if (this->field_3BC & 2)
	{
		gAttackFlagRelated &= ~this->field_3BD;
	}

	this->field_3BC = 0;
	this->field_3BD = 0;
}

static i32 gThugTypeRelatedFirstFirst;
static i32 gThugTypeRelatedFirstSecond;
static u8 gThugTypeRelatedFirstThird;

static i32 gThugTypeRelatedSecondFirst;
static i32 gThugTypeRelatedSecondSecond;
static u8 gThugTypeRelatedSecondThird;

// @NotOk
// globals
void CThug::SetThugType(int type)
{
	this->field_38 = type;
	switch (type)
	{
		case 304:
			this->InitItem("thug");
			this->field_21E = 100;

			this->field_294.Int = gThugTypeRelatedFirstFirst;
			this->field_298.Int = gThugTypeRelatedFirstSecond;
			M3dUtils_ReadHooksPacket(this, &gThugTypeRelatedFirstThird);

			break;
		case 312:
			if (Trig_GetLevelId() == 513)
				this->InitItem("henchngt");
			else
				this->InitItem("henchman");

			this->field_294.Int = gThugTypeRelatedSecondFirst;
			this->field_298.Int = gThugTypeRelatedSecondSecond;
			M3dUtils_ReadHooksPacket(this, &gThugTypeRelatedSecondThird);
			break;
		default:
			print_if_false(0, "Unknown thug type!");
	}

}

// @TODO
void CThug::RunToWhereTheActionIs(CVector*)
{}

// @Ok
void CThug::HelpOutBuddy(CMessage *pMessage)
{
	if (this->field_31C.bothFlags == 2 || this->field_31C.bothFlags == 1)
	{
		CItem *pItem = reinterpret_cast<CItem*>(Mem_RecoverPointer(&pMessage->mHandle));

		if (pItem)
			this->RunToWhereTheActionIs(&pItem->mPos);
	}
}

// @Ok
void __inline CThug::PlayHitWallSound(void)
{
	if (!this->field_1F8)
	{
		if (this->field_218 & 0x400)
		{
			SFX_PlayPos(0x802F, &this->mPos, 0);
		}
		else
		{
			SFX_PlayPos(0x802E, &this->mPos, 0);
		}
	}
}

// @Ok
void __inline CThug::StandStill(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->CycleAnim(this->field_38 != 304 ? 15 : 17, 1);
			this->dumbAssPad++;

			break;
		default:
			print_if_false(0, "Unknown substate.");
			break;
	}
}

// @TODO
i32 CThug::ShouldFall(i32, i32)
{
	return 0x09062024;
}

// @Ok
void CThug::DieAfterFlyingAcrossRoom(void)
{
	if (this->ShouldFall(200, 0x5F000))
	{
		this->field_218 &= 0xFFFFFFFD;
		this->field_31C.bothFlags = 22;
	}
	else
	{
		this->SetHeight(1, 100, 600);
		this->PlayHitWallSound();
		this->field_31C.bothFlags = 26;
	}

	this->dumbAssPad = 0;
}

// @Ok
void __inline CThug::RunAppropriateHitAnim(void)
{
	i32 anim;
	if (this->field_218 & 0x10000)
	{
		anim = this->field_38 != 304 ? 38 : 43;
	}
	else if (this->field_218 & 0x20000)
	{
		anim = this->field_38 != 304 ? 37 : 42;
	}
	else
	{
		anim = this->field_38 != 304 ? 18 : 25;
	}

	this->RunAnim(anim, 0, -1);
}

// @Ok
void __inline CThug::StopShooting(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			this->RunAnim(9, 0, -1);
			this->dumbAssPad++;
			break;
		case 1:
			if (this->field_142)
			{
				this->field_31C.bothFlags = 28;
				this->dumbAssPad = 0;
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @TODO
i32 CThug::AddPointToPath(CVector*, i32)
{
	return 0x09062024;
}

// @Ok
i32 CThug::TryAddingCollidePointToPath(CVector* pVector)
{
	if (Utils_CrapDist(*pVector, this->mPos) < 0x64)
		return 0;

	CVector v5 = *pVector - this->mPos;
	v5 >>= 0xC;
	v5 *= 0xE74;
	v5 += this->mPos;
	return this->AddPointToPath(&v5, 0);
}


void validate_CThug(void){

	VALIDATE_SIZE(CThug, 0x3C0);

	VALIDATE(CThug, field_370, 0x370);
	VALIDATE(CThug, field_374, 0x374);
	VALIDATE(CThug, field_378, 0x378);
	VALIDATE(CThug, field_37C, 0x37C);
	VALIDATE(CThug, field_380, 0x380);
	VALIDATE(CThug, field_384, 0x384);
	VALIDATE(CThug, field_388, 0x388);
	VALIDATE(CThug, field_38C, 0x38C);

	VALIDATE(CThug, field_394, 0x394);
	VALIDATE(CThug, field_3B0, 0x3B0);
	VALIDATE(CThug, field_3B8, 0x3B8);

	VALIDATE_SIZE(IntToBytes, 0x4);
}

void validate_CThugPing(void)
{
	VALIDATE_SIZE(CThugPing, 0x80);

	VALIDATE(CThugPing, field_70, 0x70);
	VALIDATE(CThugPing, field_78, 0x78);
}
