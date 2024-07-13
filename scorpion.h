#pragma once

#ifndef SCORPION_H
#define SCORPION_H

#include "export.h"
#include "baddy.h"


class CScorpion : public CBaddy {
	public:
		EXPORT void NextRoom(void);
		EXPORT void* GetCurrentTarget(void);
		EXPORT CSuper* FindJonah(void);
		EXPORT i32 SetJonahHandle(SHandle*);
		EXPORT void DoIntroSequence(void);
		EXPORT void Gloat(void);
		EXPORT void DetermineTarget(void);
		EXPORT void TakeHit(void);
		EXPORT void GetTrapped(void);
		EXPORT void PlayXA_NoRepeat(i32, i32, i32, i32*, CBody*);
		EXPORT i32 ScorpPathCheck(CVector*, CVector*, CVector*, i32);
		EXPORT i32 PathLooksGood(CVector*);
		EXPORT i32 WhatShouldIDo(void);
		EXPORT void TargetPlayer(i32);
		EXPORT i32 GetEnvironmentalObjectTarget(void);


		i32 field_324;
		u8 padAfter324[0xBD4-0x324-4];

		i32 field_BD4;
		i32 field_BD8;
		u8 padAfterBD8[0xBE8-0xBD8-4];

		i32 field_BE8;
		CSuper* field_BEC;
		SHandle hCurrentTarget;

		i32 field_BF8;
		u8 padAfterBF8[0xC10-0xBF8-4];

		i32 field_C10;
		i32 field_C14;
		i32 field_C18;
		u8 padAfterC18[0x4];

		i32 field_C20;

		u8 padScorpion[0xC28-0xC20-4];
};

class CConstantLaser : public CNonRenderedBit
{
	public:

		EXPORT CConstantLaser(i32);
		EXPORT void SetRGB(u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8, u8);

		u8 topPad[0x10];
		u8 field_4C[12];
		u8 padAfter4C[0x60-0x4C-0xC];


		i32 field_60;
};

EXPORT void Scorpion_GetCurrentTarget(unsigned int*, unsigned int*);

void validate_CScorpion(void);
void validate_CConstantLaser(void);

#endif
