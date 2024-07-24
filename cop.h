#pragma once

#ifndef COP_H
#define COP_H

#include "export.h"
#include "baddy.h"
#include "mem.h"
#include "m3dutils.h"
#include "weapons.h"


class CCop : public CBaddy {

public:
	EXPORT CCop(int*, int);

	EXPORT void ClearAttackFlags(void);
	EXPORT void LookForPlayer(void);
	EXPORT i32 GetLaunched(CVector*, i32, i32, i32);

	EXPORT virtual u8 TugImpulse(CVector*, CVector*, CVector*);
	EXPORT virtual void Victorious(void);

	i32 field_324;
	u8 padAfter324[0x340-0x324-4];

	int field_340;
	unsigned char padAfter340[0x20 - 4];

	i32 field_360;
	i32 field_364;
	i32 field_368;
	i32 field_36C;
	i32 field_370;
	i32 field_374;
	u8 padAfter374[0x37C - 0x374 - 4];
	i32 field_37C;
	u8 padAfter37C[0x384 - 0x37C - 4];

	CVector* field_384;
	u8 padAfter384[0x390 - 0x384 - 4];

	u8 field_390;
	u8 field_391;
	u8 endPad[0x394 - 0x391 - 1];
};

class CCopPing : public CSimpleAnim
{
	public:
		EXPORT CCopPing(CSuper*, SHook*);
		EXPORT void Move(void);
		EXPORT void SetPosition(void);

		unsigned char padTop[8];
		SHandle field_70;
		SHook field_78;
};

class CCopBulletTracer : public CNonRenderedBit
{
	public:
		EXPORT CCopBulletTracer(CVector*, CVector*, CSuper*, SLineInfo*, u8, u8, u8);
		EXPORT virtual ~CCopBulletTracer(void);

		EXPORT void SetWidth(void);

		EXPORT virtual void Move(void);

		CGouradRibbon *field_3C;
		CGouradRibbon *field_40;

		u8 padBottom[0x48-0x40-4];
};


void validate_CCop(void);
void validate_CCopPing(void);
void validate_CCopBulletTracer(void);

EXPORT void Cop_CreateCop(const unsigned int *stack, unsigned int *result);


#endif
