#pragma once

#ifndef SUPEROCK_H
#define SUPEROCK_H

#include "export.h"
#include "baddy.h"


class CSuperDocOck : public CBaddy {

public:
	EXPORT CSuperDocOck(int*, int);
	EXPORT virtual ~CSuperDocOck(void);

	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT void DoPhysics(void);
	EXPORT void RenderClaws(void);
	EXPORT void KillAllCommandBlocks(void);
	EXPORT int* KillCommandBlock(int*);

	unsigned char padTop[0x32C-0x324];

	int field_32C;
	int field_330;
	int field_334;
	unsigned char padAfter334[0x344-0x334-4];

	int field_344;
	int* field_348;
	u8 padAfter348[0x360-0x348-4];

	void* field_360;
	u8 padAfter360[0x36C-0x360-4];

	i32 field_36C;
	i32 field_370;
	i32 field_374;
	u8 padAfter374[0x3B4-0x374-4];

	void* field_3B4[4];
	u8 padAfter3B4[0x11];

	i32 field_3D8;
	u8 padAfter3D8[0x3F4-0x3D8-4];

	void* field_3F4[4];
	void* field_404[4];
};


void validate_CSuperDocOck(void);
EXPORT void SuperDocOck_CreateSuperDocOck(const unsigned int *stack, unsigned int *result);
#endif
