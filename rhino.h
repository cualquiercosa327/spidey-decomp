#pragma once

#ifndef RHINO_H
#define RHINO_H

#include "export.h"
#include "baddy.h"

class CRhino : public CBaddy {
public:
	EXPORT CRhino(int*, int);
	EXPORT CRhino(void);
	EXPORT virtual ~CRhino(void);

	EXPORT void PlaySingleAnim(u32, i32, i32);
	EXPORT u32 GetNextFootstepSFX(void);
	EXPORT i32 GetShockDamage(void);
	EXPORT void ShakePad(void);
	EXPORT void StandStill(void);
	EXPORT void FuckUpSomeBarrels(void);
	EXPORT void RhinoInit(void);
	EXPORT void Laugh(void);
	EXPORT void HitWall(void);
	EXPORT void TakeHit(void);
	EXPORT i32 DetermineFightState(i32);

	EXPORT void AI(void);
	EXPORT void AttackPlayer(void);
	EXPORT void ChargePlayer(void);
	EXPORT void ChasePlayer(i32);
	EXPORT void CheckIfPlayerHit(void);
	EXPORT void DieRhino(void);
	EXPORT void DoDazedEffect(void);
	EXPORT void DoMGSShadow(void);
	EXPORT void FollowWaypoints(void);
	EXPORT void GetLaunched(void);
	EXPORT void GetShocked(void);
	EXPORT void GetTrapped(void);
	EXPORT void GonnaHitWall(i32);
	EXPORT void LineOfSightCheck(CVector const *,i32);
	EXPORT void PlaySounds(void);
	EXPORT void PlayXAPlease(i32,i32,i32);
	EXPORT void SetUpStuckHorn(SLineInfo *,i32);
	EXPORT void SlideFromHit(i32,i32,CVector *);
	EXPORT void StompGround(void);
	EXPORT void StuckInWall(void);

	unsigned char padTop[0x344 - 0x324];
	i32 field_344;
	u8 padAfter344[0x358-0x344-4];

	i32 field_358;
	u8 padAfter358[0x388-0x358-4];

	i32 field_388;
	u8 padAfter88[0x3E0-0x388-4];

	u32 field_3E0;
	u32 field_3E4[5];
	u32 field_3F8[5];
	u32 field_40C[5];

	u8 padBottom[0x424-0x420];
};

class CRhinoNasalSteam : public CFlatBit
{
	public:
		EXPORT CRhinoNasalSteam(CVector*, CVector*);
		EXPORT ~CRhinoNasalSteam(void);
		EXPORT void Move(void);
};

void validate_CRhino(void);
void validate_CRhinoNasalSteam(void);
EXPORT void Rhino_CreateRhino(const unsigned int *stack, unsigned int *result);
EXPORT void Rhino_RelocatableModuleClear(void);


#endif
