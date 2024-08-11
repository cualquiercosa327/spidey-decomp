#include "bmr.h"
#include "dcshellutils.h"
#include "utils.h"
#include "front.h"
#include "ps2funcs.h"

EXPORT Sprite2* gLoadedBmp = 0;

// @SMALLTODO
void BMP_Draw(char const *)
{
    printf("BMP_Draw(char const *)");
}

// @Ok
INLINE void DeleteBMP(void)
{
	if (gLoadedBmp)
	{
		delete gLoadedBmp;
		gLoadedBmp = 0;
	}
}

// @Ok
INLINE void DrawBMP(void)
{
	if (gLoadedBmp)
	{
		Front_ClearScreen();
		gLoadedBmp->screenHeight();
		gLoadedBmp->draw(0, 0, 0, 0);
		DrawSync();
	}
}

// @Ok
void LoadBMP(const char * pName)
{
	print_if_false(gLoadedBmp == 0, "BMP already loaded");

	gLoadedBmp = new Sprite2(pName, 1, 0, 0, 3);
	Pause(2);
}
