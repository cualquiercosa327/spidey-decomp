#include "superock.h"
#include "ps2m3d.h"
#include "spidey.h"
#include "trig.h"
#include "ps2lowsfx.h"
#include "utils.h"

#include <cmath>

#include "validate.h"

extern CBaddy* BaddyList;
extern CPlayer* MechList;

// @Ok
i32 CSuperDocOck::Hit(SHitInfo* a2)
{
	if ( this->field_E2 < 0 )
		return 0;
	if ( !this->field_DC )
		return 0;
	if ( this->field_31C.bothFlags != 1024 )
		return 0;

	this->field_218 &= 0xFFFFFF1F;
	this->field_E2 -= a2->field_8;

	if ( this->field_E2 <= 0 )
	{
		this->PlaySingleAnim(0x1Fu, 0, -1);
		this->field_31C.bothFlags = 0x4000;
		this->dumbAssPad = 0;
		return 1;
	}

	if  (a2->field_0 & 8)
	{
		CSVector v9;
		v9.vx = 0;
		v9.vy = 0;
		v9.vz = 0;

		Utils_CalcAim(&v9, &this->mPos, &(this->mPos + (a2->field_C << 12)));

		i32 v7 = v9.vy - this->mAngles.vy;
		if (v7 < -2048)
		{
			v7 += 4096;
		}
		else if (v7 > 2048)
		{
			v7 -= 4096;
		}

		if (abs(v7) >= 0x600)
		{
			this->field_218 |= 0x80;
		}
		else if  (v7 < -256)
		{
			this->field_218 |= 0x20;
		}
		else if  (v7 > 256)
		{
			this->field_218 |= 0x40;
		}
	}

	this->field_31C.bothFlags = 0x2000;
	this->dumbAssPad = 0;
	return 1;
}

// @Ok
// @Test
void CSuperDocOck::DoPhysics(void)
{
	if (!this->field_338)
	{
			if (this->field_218 & 0x100)
			{
				CSVector v8;
				v8.vx = 0;
				v8.vy = 0;
				v8.vz = 0;

				Utils_CalcAim(&v8, &this->mPos, &this->field_240);

				i16 vx = v8.vx;
				v8.vx = 0;
				Utils_TurnTowards(
					this->mAngles,
					&this->csVector1,
					&this->field_8E,
					v8,
					10);
				v8.vx = vx;

				i32 v5 = abs(this->csVector1.vy);
				i32 v6;
				if ( v5 >= 64 )
					v6 = 0;
				else
					v6 = (64 - v5) << 6;
				Utils_GetVecFromMagDir(&this->mAccellorVel, (v6 * (this->field_374 >> 12)) >> 12, &v8);
			}
			else
			{
				this->csVector1.vz = 0;
				this->csVector1.vy = 0;
				this->csVector1.vx = 0;
				this->field_8E.vz = 0;
				this->field_8E.vy = 0;
				this->field_8E.vx = 0;
			}
	}


	i16 v7 = this->csVector1.vy + this->field_8E.vy;

	this->csVector1.vx += this->field_8E.vx;
	this->csVector1.vx -= this->csVector1.vx >> 2;

	this->csVector1.vy = v7 - (v7 >> 2);
	this->csVector1.KillSmall();

	for (i32 i = 0; i < this->field_80; i++)
	{
		this->mPos += this->mAccellorVel;
		this->mAngles += this->csVector1;
	}

	this->mAngles.KillSmall();
}

// @Ok
void CSuperDocOck::PlaySounds(void)
{
	switch (this->field_12A)
	{
		case 1:
			if (!(this->field_364 & 1) && this->field_128 >= 0)
			{
				SFX_PlayPos((Rnd(3) + 230) | 0x8000, &this->mPos, 0);
				this->field_364 |= 1u;
			}
			else if (!(this->field_364 & 2) && this->field_128 >= 20)
			{
				SFX_PlayPos((Rnd(3) + 230) | 0x8000, &this->mPos, 0);
				this->field_364 |= 2u;
			}
			break;
		case 4:
			if (!(this->field_364 & 1) && this->field_128 >= 0)
			{
				SFX_PlayPos((Rnd(3) + 230) | 0x8000, &this->mPos, 0);
				this->field_364 |= 1u;
			}
			break;
		case 6:
			if (!(this->field_364 & 1) && this->field_128 >= 20)
			{
				SFX_PlayPos((Rnd(3) + 230) | 0x8000, &this->mPos, 0);
				this->field_364 |= 1u;
			}
			break;
	}
}

// @Ok
// @Test
// Not sure what they did in the register array asignment when v2 > v3
// sub i16 but then move i32 and assign i16
void CSuperDocOck::HangAndGetBeaten(void)
{
	switch (this->dumbAssPad)
	{
		case 0:
			i16 v5;
			v5 = Rnd(120) + 120;
			print_if_false(1u, "Bad register index");

			this->registerArr[1] = v5;

			this->mCBodyFlags |= 0x10;
			this->field_DC = 100;
			this->dumbAssPad++;

			break;
		case 1:
			print_if_false(1u, "Bad register index");
			i32 v2 = this->registerArr[1];
			i32 v3 = this->field_80;

			if ( v2 > v3 )
			{
				i32 v4;
				v4 = v2 - v3;

				print_if_false(1u, "Bad register index");
				this->registerArr[1] = v4;
			}
			else
			{
				print_if_false(1u, "Bad register index");
				this->registerArr[1] = 0;
				this->mCBodyFlags &= ~0x10u;
				this->field_DC = 0;
				this->field_364 = 0;
				this->RunAnim(0x18u, 0, -1);
				this->dumbAssPad = 0;
				this->field_31C.bothFlags = 2048;
			}
			break;
	}
}

// @Ok
// @Test
void CSuperDocOck::CreateExplosion(i32 a2, i32)
{
	CVector a3;
	a3.vx = 0;
	a3.vy = 0;
	a3.vz = 0;

	Trig_GetPosition(&a3, a2);
	SFX_PlayPos(0x23u, &a3, 0);

	CSVector v7;
	v7.vx = 0;
	v7.vy = 0;
	v7.vz = 0;
	Utils_CalcAim(&v7, &this->mPos, &a3);

	i32 v4 = v7.vy - this->mAngles.vy;
	if (v4 < -2048)
	{
		v4 += 4096;
	}
	else if (v4 > 2048)
	{
		v4 -= 4096;
	}

	if (abs(v4) >= 0x600)
	{
		this->field_218 |= 0x80;
	}
	else if  (v4 < -256)
	{
		this->field_218 |= 0x20;
	}
	else if  (v4 > 256)
	{
		this->field_218 |= 0x40;
	}

	this->mAccellorVel.vz = 0;
	this->mAccellorVel.vy = 0;
	this->mAccellorVel.vx = 0;
	this->field_218 &= ~0x100;
	this->field_31C.bothFlags = 0x2000;
	this->dumbAssPad = 0;
}

// @Ok
void CSuperDocOck::PlayIdleOrGloatAnim(void)
{
	if ( !(this->field_218 & 0x10))
	{
		if ( !this->field_3D8 )
		{
			this->PlaySingleAnim(22, 0, -1);
			return;
		}

		if ( this->field_3E0 > 600 || MechList->field_E2 <= 0 )
		{
			if ( this->field_3D4 == 1 )
				this->PlaySingleAnim(35, 0, -1);
			else
				this->PlaySingleAnim(1, 0, -1);

			this->field_3E0 = 0;
			this->field_31C.bothFlags = 0x8000;
			this->dumbAssPad = 0;
		}
		else
		{
			this->PlaySingleAnim(1, 0, -1);
		}
	}
}

// @Ok
void CSuperDocOck::Gloat(void)
{
	if ( this->field_142 )
	{
		this->csuperend = 0x10000;
		this->PlayIdleOrGloatAnim();
	}
}

// @Ok
INLINE void CSuperDocOck::Initialise(void)
{
	this->field_39C = 455;
	this->field_368 = this->field_DE;
	this->field_31C.bothFlags = 0x10000;
	this->dumbAssPad = 0;
}

// @Ok
INLINE void CSuperDocOck::PlaySingleAnim(u32 a2, i32 a3, i32 a4)
{
	this->field_364 = 0;
	this->RunAnim(a2, a3, a4);
}

// @Ok
CSuperDocOck::~CSuperDocOck(void)
{
	this->DeleteFrom(reinterpret_cast<CBody**>(&BaddyList));
	this->KillAllCommandBlocks();

	delete reinterpret_cast<CItem*>(this->field_360);

	for (i32 i = 0; i< 4; i++)
	{
		if (this->field_3B4[i])
			Mem_Delete(this->field_3B4[i]);

		delete reinterpret_cast<CItem*>(this->field_404[i]);
		delete reinterpret_cast<CItem*>(this->field_3F4[i]);
	}
}

// @NotOk
// globals
CSuperDocOck::CSuperDocOck(int *a2, int a3)
{
	this->field_32C = 0;
	this->field_330 = 0;
	this->field_334 = 0;

	this->field_344 = reinterpret_cast<int>(
			this->SquirtAngles(reinterpret_cast<__int16*>(this->SquirtPos(a2))));

	this->InitItem("superock");
	this->mFlags |= 0x480;
	this->mCBodyFlags &= 0xFFEF;
	this->field_3C = 0x557928;

	this->field_E2 = 500;
	this->field_DC = 0;
	this->AttachTo(reinterpret_cast<CBody**>(0x56E9900));

	this->field_38 = 309;
	this->field_1F4 = a3;
	this->field_DE = a3;

	this->field_36C = 1024;
	this->field_374 = 0x10000;
	this->field_370 = 0x10000;
	this->field_3D8 = 4;
	this->field_31C.bothFlags = 1;
	this->field_21E = 100;

	*reinterpret_cast<int*>(0x54E8D4) = 4096;
	*reinterpret_cast<int*>(0x60F774) = 0xFFFFFF;
	*reinterpret_cast<unsigned char*>(0x60F772) = 1;
	*reinterpret_cast<int*>(0x60F778) = gTimerRelated;

	this->field_194 = 0xFFFE0000;
	this->field_198 = 0x1FFF;
}

// @Ok
void SuperDocOck_CreateSuperDocOck(const unsigned int *stack, unsigned int *result)
{
	int* v2 = reinterpret_cast<int*>(*stack);
	int v3 = static_cast<int>(stack[1]);

	*result = reinterpret_cast<unsigned int>(new CSuperDocOck(v2, v3));
}

// @Ok
void CSuperDocOck::Shouldnt_DoPhysics_Be_Virtual(void)
{
	this->DoPhysics();
}

// @Ok
void CSuperDocOck::RenderClaws(void)
{
	M3d_Render(this->field_3F4[0]);
}

// @Ok
// @Matching
INLINE i32* CSuperDocOck::KillCommandBlock(i32* a1)
{
	i32* res = reinterpret_cast<i32*>(a1[a1[1]-1]);

	if (this->field_348 == a1)
	{
		this->field_348 = res;
	}
	else
	{
		i32* it = this->field_348;

		while (it)
		{
			if (a1 == reinterpret_cast<i32*>(it[it[1]-1]))
			{
				it[it[1]-1] = reinterpret_cast<i32>(res);
				break;
			}

			it = reinterpret_cast<i32*>(it[it[1]-1]);
		}
	}

	Mem_Delete(reinterpret_cast<void*>(a1));
	return res;
}

// @Ok
// @Matching
INLINE void CSuperDocOck::KillAllCommandBlocks(void)
{
	for (int* cur = this->field_348; cur; cur = this->KillCommandBlock(cur))
		;
	this->field_348 = 0;
}

void validate_CSuperDocOck(void){
	VALIDATE_SIZE(CSuperDocOck, 0x414);

	VALIDATE(CSuperDocOck, field_32C, 0x32C);
	VALIDATE(CSuperDocOck, field_330, 0x330);
	VALIDATE(CSuperDocOck, field_334, 0x334);

	VALIDATE(CSuperDocOck, field_338, 0x338);

	VALIDATE(CSuperDocOck, field_344, 0x344);
	VALIDATE(CSuperDocOck, field_348, 0x348);

	VALIDATE(CSuperDocOck, field_360, 0x360);
	VALIDATE(CSuperDocOck, field_364, 0x364);
	VALIDATE(CSuperDocOck, field_368, 0x368);

	VALIDATE(CSuperDocOck, field_36C, 0x36C);
	VALIDATE(CSuperDocOck, field_370, 0x370);
	VALIDATE(CSuperDocOck, field_374, 0x374);

	VALIDATE(CSuperDocOck, field_3B4, 0x3B4);

	VALIDATE(CSuperDocOck, field_3D4, 0x3D4);
	VALIDATE(CSuperDocOck, field_3D8, 0x3D8);

	VALIDATE(CSuperDocOck, field_3E0, 0x3E0);

	VALIDATE(CSuperDocOck, field_3F4, 0x3F4);
	VALIDATE(CSuperDocOck, field_404, 0x404);
}
