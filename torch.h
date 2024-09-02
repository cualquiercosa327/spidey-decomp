#pragma once

#ifndef TORCH_H
#define TORCH_H

#include "baddy.h"
#include "export.h"

class CTorch : public CBaddy {

public:

	EXPORT CTorch(int* a2, int a3);
	EXPORT ~CTorch(void);

	EXPORT void Shouldnt_DoPhysics_Be_Virtual(void);
	EXPORT void DoPhysics(void);
	EXPORT int* KillCommandBlock(int*);
	EXPORT void KillAllCommandBlocks(void);

	int field_324;
	int field_328;	
	int field_32C;
	int field_330;
	int field_334;
	int field_338;

	CQuadBit *gTorchQuadBit;

	unsigned char field_340;
	int field_344;
	unsigned char field_348;

	int field_34C;
	i32* field_350;
};


void validate_CTorch(void);
EXPORT void Torch_CreateTorch(const unsigned int *stack, unsigned int *result);
#endif 
