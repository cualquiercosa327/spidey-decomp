#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "ob.h"
#include "vector.h"
#include "quat.h"

static int * const gCameraRelated = (int*)0x56F254;

enum ECameraMode {
	ECam_mode_0x10 = 0x10,
	ECam_mode_0x11 = 0x11,
};

class CCamera : public CBody {
public:
	EXPORT void SetFixedFocusMode(CVector *a2, unsigned __int16 a3, unsigned __int16 a4);
	EXPORT int SetMode(ECameraMode mode);
	EXPORT void SetCollisionRayLR(int a2);
	EXPORT void SetCollisionRayBack(int a2);
	EXPORT void SetCollisionAngLR(__int16 a2);
	EXPORT void SetCollisionAngBack(__int16 a2);
	EXPORT void SetZoom(int a2, unsigned __int16 a3);
	EXPORT int GetZoom(void) const;


	int padTop;

	unsigned char field_F8;
	unsigned char field_F9;
	int field_FC;
	unsigned char field_100;
	int field_104;
	int field_108;
	int field_10C;
	int field_110;
	int field_114;
	int field_118;
	int field_11C;
	int field_120;
	int field_124;
	int field_128;
	int field_12C;
	int field_130;
	int field_134;
	int field_138;
	int field_13C;
	unsigned char field_140;
	int field_144;
	int field_148;
	int field_14C;
	int field_150;
	int field_154;
	int field_158;
	int field_15C;
	int field_160;
	int field_164;
	int field_168;
	int field_16C;
	int mZoom;

	__int16 field_174;
	unsigned char padAfter174[2];

	int field_178;
	int field_17C;

	unsigned char padAfter17C[0x1A8-0x17C-4];


	int field_1A8;
	int field_1AC;
	int field_1B0;
	int field_1B4;
	int field_1B8;
	int field_1BC;
	int field_1C0;

	int padAfter1C0;


	int field_1C8;
	__int16 field_1CC;
	__int16 field_1CE;

	unsigned char padAfter1CE[0x8];


	int field_1D8;
	int field_1DC;
	int field_1E0;
	int field_1E4;
	int field_1E8;
	int field_1EC;
	int field_1F0;
	int field_1F4;
	int field_1F8;
	int field_1FC;
	int field_200;
	int field_204;
	int field_208;
	int field_20C;
	int field_210;
	int field_214;
	int field_218;
	int field_21C;
	int field_220;
	int field_224;
	int field_228;
	int field_22C;
	int field_230;
	int field_234;
	__int16 field_238;

	unsigned char padAfter238[2];

	unsigned char field_23C;
	int field_240;
	int field_244;
	int field_248;
	CVector field_24C;

	int field_258;
	int field_25C;
	int field_260;
	int field_264;
	int field_268;
	__int16 field_26C;
	__int16 field_26E;

	int padAfter26E;

	__int16 field_274;
	unsigned char field_276;
	unsigned char field_277;
	unsigned char field_278;
	__int16 field_27A;
	__int16 field_27C;
	__int16 field_27E;

	int padAfter27E;

	int field_284;
	int field_288;
	int field_28C;
	int field_290;
	int field_294;
	int field_298;
	int field_29C;

	int mMode;

	int field_2A4;
	int field_2A8;

	unsigned char field_2AC;


	int field_2B0;
	int field_2B4;
	int field_2B8;
	int field_2BC;

	int field_2C0;

	int field_2C4;
	int field_2C8;
	int field_2CC;
	int field_2D0;
	CQuat field_2D4;

	__int16 field_2E4;

	CVector field_2E8;

};

void validate_CCamera(void);

#endif
