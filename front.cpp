#include "front.h"
#include "validate.h"
#include "utils.h"



// @Ok
CMenu::CMenu(int x,int y,unsigned char Justification,int HiScale,int LowScale, int LineSep)
{
	this->mX = x;
	this->mY = y;
	this->mJustification = Justification;
	this->mLineSep = LineSep;

	for (int i = 0; i<40; i++)
	{
		this->mEntry[i].unk_c = 0x80;
		this->mEntry[i].unk_d = 0x80;
		this->mEntry[i].unk_e = 0x80;
		this->mEntry[i].field_14 = 69;
		this->mEntry[i].field_15 = 60;
		this->mEntry[i].field_16 = 107;
		this->mEntry[i].field_11 = 69;
		this->mEntry[i].field_12 = 60;
		this->mEntry[i].field_13 = 107;
		this->mEntry[i].field_17 = 40;
		this->mEntry[i].field_18 = 35;
		this->mEntry[i].field_19 = 62;
		this->mEntry[i].field_8 = HiScale;
		this->mEntry[i].field_A = LowScale;
	}

	/*
	this->scrollbar_one = 2;

	this->field_1B = -1;
	this->scrollbar_zero = 1;
	this->field_32 = 0;
	this->field_30 = 0;
	this->field_34 = 0;
	this->field_38 = 0;
	*/

	this->scrollbar_one = 2;
	this->field_32 = 0;
	this->field_30 = 0;
	this->field_34 = 0;
	this->field_38 = 0;
	this->mLine = 0;
	this->field_1B = -1;
	this->scrollbar_zero = 1;

	this->Reset();
}


// @Ok
int CMenu::FinishedZooming(void)
{
	int *ptr_to = reinterpret_cast<int*>(this->ptr_to);
	if (!ptr_to)
	{
		return 1;
	}

	return ptr_to[12] != 0;
}

// @Ok
void CMenu::AdjustWidth(int width)
{
	this->width_val_a = width;
}

// @Ok
int CMenu::ChoiceIs(const char* pString)
{
	if (this->mLine < 0x28)
	{
		return Utils_CompareStrings(pString, this->mEntry[this->mLine].name);
	}

	return 0;
}

// @Ok
// slightly different registers but the same
void CMenu::SetRedText(unsigned char Line)
{
	print_if_false(Line < this->mNumLines, "Bad line sent to SetRedText");

	this->mEntry[Line].unk_c = 255;
	this->mEntry[Line].unk_d = 0;
	this->mEntry[Line].unk_d = -1;

	this->mEntry[Line].field_15 = 0;
	this->mEntry[Line].field_16 = 0;

	this->mEntry[Line].field_11 = 96;
	this->mEntry[Line].field_12 = 0;
	this->mEntry[Line].field_13 = 0;

	
	this->mEntry[Line].field_17 = 96;
	this->mEntry[Line].field_18 = 0;
	this->mEntry[Line].field_19 = 0;
}

// @Ok
void CMenu::Reset(void)
{
	this->SetLine(0);
}

// @Ok
// loop offset starts in field_8, instead of unk_b, but that's fine
void CMenu::SetLine(char Line)
{
	this->mLine = Line;

	SEntry *entries = this->mEntry;
	for(int i = 0; i<40; i++)
	{
		__int16 v5;

		if (i != this->mLine)
		{
			v5 = entries[i].field_A;
		}
		else
		{
			v5 = entries[i].field_8;
		}

		entries[i].val_b = v5;
		entries[i].val_a = v5;
	}
}

CMenu::~CMenu()
{
}

void validate_CMenu(void)
{
	VALIDATE_SIZE(CMenu, 0x53C);

	VALIDATE(CMenu, ptr_to, 0x4);
	VALIDATE(CMenu, menu_width, 0x8);
	VALIDATE(CMenu, text_val_b, 0xA);
	VALIDATE(CMenu, width_val_a, 0xC);

	VALIDATE(CMenu, scrollbar_one, 0x10);
	VALIDATE(CMenu, scrollbar_zero, 0x11);
	VALIDATE(CMenu, mJustification, 0x12);
	VALIDATE(CMenu, mLine, 0x14);

	VALIDATE(CMenu, mCursorLine, 0x15);
	VALIDATE(CMenu, mNumLines,  0x1A);
	VALIDATE(CMenu, field_1B,  0x1B);
	VALIDATE(CMenu, field_1E, 0x1E);
	VALIDATE(CMenu, mX, 0x24);
	VALIDATE(CMenu, mY, 0x28);
	VALIDATE(CMenu, mLineSep, 0x2C);

	VALIDATE(CMenu, field_30, 0x30);
	VALIDATE(CMenu, field_32, 0x32);
	VALIDATE(CMenu, field_34, 0x34);
	VALIDATE(CMenu, field_38, 0x38);

	VALIDATE(CMenu, mEntry, 0x3C);
}

void validate_SEntry(void)
{
	VALIDATE_SIZE(SEntry, 0x20);

	VALIDATE(SEntry, name, 0x0);
	VALIDATE(SEntry, val_a, 0x4);
	VALIDATE(SEntry, val_b, 0x6);
	VALIDATE(SEntry, field_8, 0x8);
	VALIDATE(SEntry, field_A, 0xA);
	VALIDATE(SEntry, unk_a, 0xC);
	VALIDATE(SEntry, unk_b, 0xD);
	VALIDATE(SEntry, unk_c, 0xE);
	VALIDATE(SEntry, unk_d, 0xF);
	VALIDATE(SEntry, unk_e, 0x10);
	VALIDATE(SEntry, field_11, 0x11);
	VALIDATE(SEntry, field_12, 0x12);
	VALIDATE(SEntry, field_13, 0x13);
	VALIDATE(SEntry, field_14, 0x14);
	VALIDATE(SEntry, field_15, 0x15);
	VALIDATE(SEntry, field_16, 0x16);
	VALIDATE(SEntry, field_17, 0x17);
	VALIDATE(SEntry, field_18, 0x18);
	VALIDATE(SEntry, field_19, 0x19);
	VALIDATE(SEntry, field_1A, 0x1A);
	VALIDATE(SEntry, field_1B, 0x1B);
	VALIDATE(SEntry, what, 0x1C);
}
