#include "cop.h"
#include "validate.h"
#include "ps2lowsfx.h"
#include "mem.h"
#include "utils.h"
#include "spidey.h"

extern CVector gGlobalNormal;
extern CPlayer *MechList;

// @Ok
void CCop::LookForPlayer(void)
{
	CVector v5;
	v5.vx = 0;
	v5.vy = 0;
	v5.vz = 0;

	switch (this->dumbAssPad)
	{
		case 0:
			this->Neutralize();
			this->CycleAnim(this->field_298.Bytes[0], 1);
			this->dumbAssPad++;
			this->field_21D = Rnd(64);
			this->field_1F8 = 0;
			break;
		case 1:
			CVector *mPos;

			if (this->field_1F8 < 64)
				mPos = &MechList->mPos;
			else
				mPos = &this->mPos;

			this->GetWaypointNearTarget(mPos, 409600, this->field_21D, &v5);
			this->field_21D++;
			if ( !this->PathCheck(&this->mPos, &v5, 0, 55)
				&& (this->AddPointToPath(&v5, 0)
				|| this->AddPointToPath(&this->mPos, 0)
				&& this->AddPointToPath(&v5, 0)) )
			{
				this->field_31C.bothFlags = 24;
				this->dumbAssPad = 0;
			}
			else
			{
				if ( this->field_1F8++ > 128 )
				{
					this->field_324 = 0;
					this->field_31C.bothFlags = 2;
					this->dumbAssPad = 0;
				}
			}
			break;
		default:
			print_if_false(0, "Unknown substate!");
			break;
	}
}

// @SMALLTODO
void CCopBulletTracer::Move(void)
{
	printf("void CCopBulletTracer::Move(void)");
}

// @SMALLTODO
void CCopBulletTracer::SetWidth(void)
{
	printf("void CCopBulletTracer::SetWidth(void)");
}

// @SMALLTODO
CCopBulletTracer::CCopBulletTracer(CVector*, CVector*, CSuper*, SLineInfo*, u8, u8, u8)
{
	printf("CCopBulletTracer::CCopBulletTracer(CVector*, CVector*, CSuper*, SLineInfo*, u8, u8, u8)");
}

// @Ok
CCopBulletTracer::~CCopBulletTracer(void)
{
	if (this->field_3C)
		delete this->field_3C;

	if (this->field_40)
		delete this->field_40;

	this->field_3C = 0;
	this->field_40 = 0;
}

// @Ok
CCopPing::CCopPing(CSuper* pHost, SHook* pHook)
	: CSimpleAnim(&gGlobalNormal, 10, 0, 1, 0, -1)
{
	this->field_78.Part.vx = 0;
	this->field_78.Part.vy = 0;
	this->field_78.Part.vz = 0;

	print_if_false(pHost != 0, "NULL pHost");
	print_if_false(pHook != 0, "NULL pHook");

	this->field_78 = *pHook;
	this->field_70 = Mem_MakeHandle(pHost);

	this->SetFrame(1);
	this->SetTint(128, 128, 128);
	this->field_58 = Rnd(1024);

	if (Rnd(2))
		this->field_58 *= -1;

	this->mScale = 400;
	this->SetPosition();
}

// @NotOk
// globals
CCop::CCop(int* a2, int a3)
{
	i16 *v5 = this->SquirtAngles(reinterpret_cast<i16*>(this->SquirtPos(a2)));
	this->ShadowOn();
	this->field_D0 = 50;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));


	this->field_230 = 0;
	this->field_1F4 = a3;
	this->field_DE = a3;

	__int16 v6 = this->field_38;
	this->field_216 = 32;
	this->field_D8 = 64;
	this->field_31C.bothFlags = 0;
	this->field_DC = v6 != 306 ? 150 : 96;

	this->field_2A8 |= 1;

	this->field_370 = v6 != 306 ? 400 : 300;
	this->field_340 = *dword_5FCCF4;
	this->field_360 = 3500;
	this->field_364 = 400;
	this->field_368 = 2047;
	this->field_36C = 100;
	this->field_374 = 10;
	this->field_1FC = 10;
	this->field_37C = 2000;

	this->ParseScript(reinterpret_cast<unsigned __int16*>(v5));
	this->field_212 = 60;
}

// @Ok
void Cop_CreateCop(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CCop(v2, v3));
}

// @Ok
void CCop::Victorious(void)
{
	SFX_PlayPos(0x8024, &this->mPos, 0);
}

// @Ok
void __inline CCopPing::SetPosition(void)
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
void CCopPing::Move(void)
{
	this->SetPosition();
	Bit_ReduceRGB(&this->mCodeBGR, 7);

	if ((this->mCodeBGR & 0xFFFFFF) == 0)
		this->Die();
}

static CCop* gCopGlobal;
static unsigned char gAttackFlagsRelated;

// @NotOk
// globals
void CCop::ClearAttackFlags(void)
{
	if (gCopGlobal == this)
	{
		gCopGlobal = NULL;
	}
	else if((this->field_390 & 2))
	{
		gAttackFlagsRelated &= ~this->field_391;
	}

	this->field_390 = 0;
	this->field_391 = 0;
}

void validate_CCop(void){
	VALIDATE_SIZE(CCop, 0x394);

	VALIDATE(CCop, field_324, 0x324);

	VALIDATE(CCop, field_340, 0x340);
	VALIDATE(CCop, field_360, 0x360);
	VALIDATE(CCop, field_364, 0x364);
	VALIDATE(CCop, field_368, 0x368);
	VALIDATE(CCop, field_36C, 0x36C);
	VALIDATE(CCop, field_370, 0x370);
	VALIDATE(CCop, field_374, 0x374);

	VALIDATE(CCop, field_37C, 0x37C);

	VALIDATE(CCop, field_390, 0x390);
	VALIDATE(CCop, field_391, 0x391);
}

void validate_CCopPing(void)
{
	VALIDATE_SIZE(CCopPing, 0x80);

	VALIDATE(CCopPing, field_70, 0x70);
	VALIDATE(CCopPing, field_78, 0x78);
}

void validate_CCopBulletTracer(void)
{
	VALIDATE_SIZE(CCopBulletTracer, 0x48);

	VALIDATE(CCopBulletTracer, field_3C, 0x3C);
	VALIDATE(CCopBulletTracer, field_40, 0x40);
}
