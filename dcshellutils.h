#pragma once

#ifndef DCSHELLUTILS_H
#define DCSHELLUTILS_H

#include "Image.h"
#include "export.h"

class Sprite2 : public SlicedImage2
{
	public:
		EXPORT Sprite2(const char*, i32, i32, i32, u32);
		u8 padBottom[4];
};

EXPORT void Load8BitBMP2(char *, char **, int *, int *, unsigned __int16 *, bool);

void validate_Sprite2(void);
#endif
