#include "init.h"
#include "mem.h"
#include "PCGfx.h"
#include "dcfileio.h"
#include "dcmemcard.h"
#include "tweak.h"
#include "ps2lowsfx.h"
#include "pack.h"
#include "ps2redbook.h"
#include "m3dinit.h"
#include "spool.h"
#include "ps2pad.h"
#include "ps2gamefmv.h"
#include "pal.h"
#include "ps2card.h"
#include "front.h"
#include "mess.h"
#include "FontTools.h"
#include "trig.h"
#include "bit.h"
#include "utils.h"
#include "panel.h"
#include "spidey.h"
#include "DXinit.h"
#include "db.h"

EXPORT Texture* gShadowBit;
EXPORT i32 gPsxSpArmorIndex;
EXPORT i32 gPsxRingIndex;

EXPORT i32 gInitRelatedOne;
EXPORT i32 gInitRelatedTwo;
EXPORT i32 gInitRelatedThree;
EXPORT i32 gSpideyMainRelated;

// @SMALLTODO
void DeleteList(CBody *)
{
    printf("DeleteList(CBody *)");
}

// @SMALLTODO
void Init_AtEnd(void)
{
    printf("Init_AtEnd(void)");
}

EXPORT i32 dword_60D218;

// @NotOk
// regvisit after memory stuff done
u8 Init_AtStart(i32)
{
	Port_InitAtStart();
	/*
	dword_628618 = (int *)&unk_628690;
	dword_654F54 = (int)&unk_62A5D0;
	*/
	/*
	gMemInitRelatedBottom = gPortRelatedOne;
	dword_60D218 = gPortRelatedOne + 64;
	dword_60D21C = gPortRelatedOne + 64;
	dword_60D220 = gPortRelatedOne + gSomeSize;
	*/

	Mem_Init();

	SetDispMask();

	Db_Init();
	Mem_Init();

	ClearImage2();
	DrawSync();
	SetDispMask();

	PCGfx_InitAtStart();

	FileIO_Init();
	Card_Init(1);
	Pad_InitAtStart();

	Spool_Init();

	gSpideyMainRelated = 20;
	SFX_InitAtStart();
	GameFMV_Init();
	M3dInit_InitAtStart();
	Redbook_XAInitAtStart();
	Tweak_Init();

	Pack_Init();
	Pal_Init();

	Mess_LoadFont("sp_fnt00.fnt", -1, -1, -1);
	Mess_LoadFont("sp_fnt01.fnt", -1, -1, -1);
	Front_Init();
	FontManager::ResetCharMaps();
	SFX_Init("spidey.kat");
	gReStartDeathRelated = 0;

	PutDispEnv();

	Bit_Init();
	i32 v5 = Vblanks;

	DrawSync();
	PSXRegion[Spool_PSX("webdome2", 0)].Protected = 1;
	PSXRegion[Spool_PSX("webdome3", 0)].Protected = 1;
	gInitRelatedThree = 0;

	i32 v8 = Spool_PSX("spidey", 0);
	gSpideyPsxIndex = v8;
	PSXRegion[v8].Protected = 1;
	Spidey_CopyHeadModel(v8);
	PSXRegion[Spool_PSX("bits", 0)].Protected = 1;
	Utils_InitLoadIcons();

	gPsxSpArmorIndex = Spool_PSX("spArmor", 0);
	PSXRegion[gPsxSpArmorIndex].Protected = 1;
	PSXRegion[Spool_PSX("shell_dc", 0)].Protected = 1;
	PSXRegion[Spool_PSX("costarm", 0)].Protected = 1;

	i32 v9 = Spool_PSX("items", 0);
	gPsxItemsIndex = v9;
	PSXRegion[v9].Protected = 1;
	gPsxRingIndex = Spool_PSX("ring", 0);

	PSXRegion[gPsxRingIndex].Protected = 1;
	if (!gLowGraphics)
		PSXRegion[Spool_PSX("sparmour", 0)].Protected = 1;
	Spool_Sync();

	Vblanks = v5 + 300;

	gInitRelatedTwo = 5;
	gInitRelatedOne = 5;

	Panel_Init();
	Spool_TextureAccess(0xB79DD55B, &gShadowBit);
	print_if_false(gShadowBit != 0, "No shadow bit");

	gLevelStatus = 0;
	return 0;
}

// @SMALLTODO
void Init_Cleanup(i32)
{
    printf("Init_Cleanup(i32)");
}

// @MEDIUMTODO
void Init_KillAll(void)
{
    printf("Init_KillAll(void)");
}
