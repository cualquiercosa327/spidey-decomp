#pragma once

#ifndef WEAPONS_H
#define WEAPONS_H

#include "bit.h"
#include "export.h"

// @FIXME
#define SCalcBuffer i32

class CSmokeRing : public CSpecialDisplay
{
	public:
		EXPORT CSmokeRing(i32,u32);
		EXPORT void Display(void);
		EXPORT void SetParams(CVector const *,i32,i32);
		EXPORT void SetRGB(i32,i32,i32);
		EXPORT void SetUV(i32,i32,i32);
		EXPORT ~CSmokeRing(void);
		u8 padBottom[0x30];
};

class CTexturedRibbon : public CSpecialDisplay
{
	public:
		EXPORT CTexturedRibbon(i32,i32);
		EXPORT void SetCoreRGBi(i32,u8,u8,u8);
		EXPORT void SetOuterRGBi(i32,u8,u8,u8);
		EXPORT void SetTexture(Texture *);
		EXPORT ~CTexturedRibbon(void);

		u8 topPad[0x5C-0x3C];
		void* field_5C;
		i32* field_60;
};

void validate_CGouraudRibbon(void);
void validate_CSmokeRing(void);
void validate_CTexturedRibbon(void);
EXPORT void CalcScreenNormal(SCalcBuffer *,i32 *,i32 *,i32);
EXPORT i32 Transform(CVector *,i32 *);

#endif
