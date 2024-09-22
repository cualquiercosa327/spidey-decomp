#include "pal.h"
#include "ps2funcs.h"

#include "validate.h"

const i32 PAL_ARRAY_SIZE = 259;
EXPORT tag_S_Pal gPalArrayData[PAL_ARRAY_SIZE];
EXPORT tag_S_Pal* gPalArray = &gPalArrayData[0];

EXPORT struct tag_S_Pal *pPaletteList;

const i32 MAXFREE16SLOTS = 192;
EXPORT u8 Free16Slots[MAXFREE16SLOTS];

const i32 MAXFREE256SLOTS = 68;
EXPORT u8 Free256Slots[MAXFREE256SLOTS];

// @Ok
// @Matching
INLINE void Free16Slot(u16 a1)
{
	for (i32 i = 0; i < MAXFREE16SLOTS; i++)
	{
		if (GetClut(Pal16X, Pal16Y + i) == a1)
			break;
	}

	Free16Slots[i] = 1;
}

// @Ok
// @Matching
INLINE i32 GetFree16Slot(void)
{
	i32 freeSlot;

	for (freeSlot = 0; freeSlot < MAXFREE16SLOTS; freeSlot++)
	{
		if (Free16Slots[freeSlot])
			break;
	}

	print_if_false(freeSlot < MAXFREE16SLOTS, "Run out of 16 colour palettes");
	Free16Slots[freeSlot] = 0;

	return freeSlot;
}

// @SMALLTODO
INLINE i32 GetFree256Slot(void)
{
	i32 freeSlot;

	for (freeSlot = 0; freeSlot < MAXFREE256SLOTS; freeSlot++)
	{
		if (Free256Slots[freeSlot])
			break;
	}

	print_if_false(freeSlot < MAXFREE256SLOTS, "Run out of 256 colour palettes");
	Free256Slots[freeSlot] = 0;

	return freeSlot;
}

// @SMALLTODO
void NewPaletteEntry(u32)
{
    printf("NewPaletteEntry(u32)");
}

// @SMALLTODO
void Pal_FindPaletteEntry(u32)
{
    printf("Pal_FindPaletteEntry(u32)");
}

// @SMALLTODO
void Pal_Init(void)
{
    printf("Pal_Init(void)");
}

// @SMALLTODO
void Pal_LoadPalette(u32,u32 *,u8)
{
    printf("Pal_LoadPalette(u32,u32 *,u8)");
}

// @SMALLTODO
void Pal_ProcessPalette(u16 *,i32)
{
    printf("Pal_ProcessPalette(u16 *,i32)");
}

// @Ok
// @Matching
void Pal_RemoveUnusedPalettes(void)
{
	tag_S_Pal* next;
	for (
			tag_S_Pal* pPal = pPaletteList;
			pPal;
			pPal = next)
	{
		next = pPal->pNext;

		if (!pPal->Usage)
		{
			if (pPal->flags & 1)
				Free16Slots[pPal->slot] = 1;

			if (pPal->flags & 2)
				Free256Slots[pPal->slot] = 1;

			RemovePaletteEntry(pPal);
		}
	}
}

// @Ok
// @Matching
INLINE void RemovePaletteEntry(tag_S_Pal* pEntry)
{
	tag_S_Pal* pPrev = 0;
	tag_S_Pal* pIter;

	for (pIter = pPaletteList; pIter; pIter = pIter->pNext)
	{
		if (pIter == pEntry)
			break;

		pPrev = pIter;
	}

	print_if_false(pIter != 0, "pEntry not found for deletion");

	if (pPrev)
		pPrev->pNext = pEntry->pNext;
	else
		pPaletteList = pEntry->pNext;

	pEntry->pNext = gPalArray;
	gPalArray = pEntry;
}

void validate_tag_S_Pal(void)
{
	VALIDATE_SIZE(tag_S_Pal, 0x18);

	VALIDATE(tag_S_Pal, slot, 0x2);
	VALIDATE(tag_S_Pal, flags, 0x3);
	VALIDATE(tag_S_Pal, Usage, 0x4);

	VALIDATE(tag_S_Pal, pNext, 0xC);
}
