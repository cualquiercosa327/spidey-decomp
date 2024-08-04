#pragma once

#include "export.h"
#include "baddy.h"

class CPlatform : public CBaddy {
public:
	EXPORT void AI(void);
	EXPORT void AdjustBruceHealth(void);
	EXPORT CPlatform(i16 *,i32);
	EXPORT i32 ExecuteCommand(u16) OVERRIDE;
	EXPORT i32 Hit(SHitInfo *) OVERRIDE;
	EXPORT void MoveTo(CVector *);
	EXPORT void NotifyTrodUpon(CBody *,CVector const *,CSVector const *);
	EXPORT void SetVariable(u16);
	EXPORT ~CPlatform(void);

	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void) OVERRIDE;
	EXPORT void DoPhysics(void);

	EXPORT unsigned __int16 GetVariable(unsigned __int16);

	unsigned char padTop[0x338-0x324];

	unsigned __int16 field_338;

	unsigned char padBottom[0x35C-0x338-2];
};

void validate_CPlatform(void);
