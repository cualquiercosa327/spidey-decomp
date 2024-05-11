#pragma once


#ifndef SPIDEY_H
#define SPIDEY_H

#include "export.h"
#include "ob.h"

class CPlayer : public CSuper 
{
	public:

		unsigned char padTopPlayer[0x1AC-0x194];
		char field_1AC;
		unsigned char padAfter1AC[0x56C-0x1AC-1];

		int field_56C;
		unsigned char padAfter56C[0x5D4-0x56C-4];

		int field_5D4;
		int field_5D8;
		unsigned char padAfter5D8[0x5E8-0x5D8-4];

		char field_5E8;
		unsigned char padAfter5E8[0x89C-0x5E8-4];

		MATRIX field_89C;
		unsigned char padAfter89C[0x8E9-0x89C-sizeof(MATRIX)];

		unsigned char field_8E9;
		unsigned char field_8EA;
		unsigned char padAFter8Ea;

		unsigned char gCamAngleLock; //8EC
		unsigned char padAfterLock[0xC90-0x8EC-1];

		int field_C90;
		unsigned char padAfterC90[0xCB4-0xC90-4];

		int field_CB4;
		unsigned char padAfterCB4[0xCE4-0xCB4-4];

		int field_CE4;
		unsigned char padAfterCE4[0xDC0-0xCE4-4];

		CVector field_DC0;
		unsigned char padAfterDC0[0xDE4-0xDC0-sizeof(CVector)];

		char field_DE4;
		unsigned char padAfterDE4[0xE10-0xDE4-1];

		char field_E10;
		__int16 field_E12;
		unsigned char padAfterE12[4];

		int field_E18;

		unsigned char padBottomPlayer[0xEFC-0xE18-4];


		EXPORT void SetCamAngleLock(unsigned __int16);
		EXPORT void ExitLookaroundMode(void);
		EXPORT void SetIgnoreInputTimer(int);
		EXPORT void PutCameraBehind(int);
		EXPORT void SetSpideyLookaroundCamValue(unsigned __int16, unsigned __int16, __int16);
		EXPORT void SetTargetTorsoAngleToThisPoint(CVector *a2);

		EXPORT __int16 GetEffectiveHeading(void);
		EXPORT void SetTargetTorsoAngle(__int16, int);
		EXPORT char DecreaseWebbing(int);
		EXPORT void RenderLookaroundReticle(void);
		EXPORT void DrawRecticle(unsigned __int16, unsigned __int16, unsigned int);
};

void validate_CPlayer(void);

#endif
