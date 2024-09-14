#pragma once

#ifndef WEAPONS_H
#define WEAPONS_H

#include "bit.h"
#include "export.h"

EXPORT extern CItem* CWeapons;

// @FIXME
#define SCalcBuffer i32

struct SSmokeRingRelated
{
	u8 padTop[0x4];

	u8 field_4;
	u8 field_5;
	u8 field_6;

	u8 field_7;
	u8 padAfter7[0xC-0x7-1];


	u8 field_C;
	u8 field_D;
	u16 field_E;

	u8 field_10;
	u8 field_11;
	u8 field_12;
	u8 padAfter12[0x18-0x12-1];

	u8 field_18;
	u8 field_19;

	u16 field_1A;

	u8 field_1C;
	u8 field_1D;
	u8 field_1E;
	u8 padAfter1E[0x24-(0x1E)-1];

	u8 field_24;
	u8 field_25;
	u8 padAfter25[2];

	u8 field_28;
	u8 field_29;
	u8 field_2A;
	u8 padAfter2A[0x30-0x2A-1];

	u8 field_30;
	u8 field_31;
	u8 padAfter31[0x38-0x31-1];

	u8 field_38;
	u8 field_39;
	u8 field_3A;

	u8 field_3B;
	u8 padAfter3B[0x40-0x3B-1];

	u8 field_40;
	u8 field_41;
	u16 field_42;

	u8 field_44;
	u8 field_45;
	u8 field_46;
	u8 padAfter46[0x4C-0x46-1];

	u8 field_4C;
	u8 field_4D;
	u16 field_4E;

	u8 field_50;
	u8 field_51;
	u8 field_52;
	u8 padAfter52[0x58-0x52-1];

	u8 field_58;
	u8 field_59;
	u8 padAfter59[2];

	u8 field_5C;
	u8 field_5D;
	u8 field_5E;
	u8 padAfter5E[0x64-(0x5E)-1];

	u8 field_64;
	u8 field_65;

	u8 padBottom[0x8C-0x65-1];
};

class CSmokeRing : public CSpecialDisplay
{
	public:
		EXPORT CSmokeRing(i32,u32);
		EXPORT void Display(void);
		EXPORT void SetParams(CVector const *,i32,i32);
		EXPORT void SetRGB(i32,i32,i32);
		EXPORT void SetUV(i32,i32,i32);
		EXPORT ~CSmokeRing(void);

		Texture* field_3C;
		i32 mNumSectors;
		SSmokeRingRelated* mpSectors;
		CSVector field_48;
		u8 padAfter48[0x58-0x48-sizeof(CSVector)];

		i32 field_58;
		i32 field_5C;
		i32 field_60;

		u8 padBottom[0x6C-0x60-4];
};

class CTexturedRibbon : public CSpecialDisplay
{
	public:
		EXPORT CTexturedRibbon(i32,i32);
		EXPORT void SetCoreRGBi(i32,u8,u8,u8);
		EXPORT void SetOuterRGBi(i32,u8,u8,u8);
		EXPORT void SetTexture(Texture *);
		EXPORT ~CTexturedRibbon(void);

		u8 mTrail;
		u8 padAfter3C[0x50-0x3C-1];

		i32 field_50;
		u8 padAfter50[0x58-0x50-4];

		i32 mNumPoints;
		SRibbonPoint* mpPoints;
		i32* field_60;
};

void validate_CGouraudRibbon(void);
void validate_CSmokeRing(void);
void validate_CTexturedRibbon(void);
void validate_SSmokeRingRelated(void);

EXPORT void CalcScreenNormal(SCalcBuffer *,i32 *,i32 *,i32);
EXPORT i32 Transform(CVector *,i32 *);

#endif
