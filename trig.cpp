#include "trig.h"
#include "validate.h"

i16 **gTrigNodes;
i32 gNumNodes;
static SCommandPoint* CommandPoints;

// @Ok
void Trig_ResetCPExecutedFlags(void)
{
	for(SCommandPoint *cur = CommandPoints; cur; cur = cur->pNext)
	{
		if (cur->Executed && !cur->Collision)
			cur->Executed = 0;
	}
}

// @Ok
void* Trig_GetLinkInfoList(
		i32 a1,
		SLinkInfo* pLink,
		i32 count)
{
	i32 result = 0;

	u16* linksPtr = reinterpret_cast<u16*>(Trig_GetLinksPointer(a1));

	if (*linksPtr)
	{
		u16 *v8 = linksPtr + 1;
		result = *linksPtr;

		if (result)
		{
			for (i32 i = 0; i<result && i < count; i++, v8++)
			{
				i16 *v11 = gTrigNodes[*v8];

				pLink[i].field_0 = *v8;
				pLink[i].field_4 = *v11;
				if (*v11 == 1002)
					pLink[i].field_8 = v11[1];
				else
					pLink[i].field_8 = 0;
				pLink[i].field_C = 0;
			}
		}
	}


	if (result <= count)
	{
		return reinterpret_cast<void*>(result);
	}

	return reinterpret_cast<void*>(count);

}

// @MEDIUMTODO
int Trig_GetLevelId(void)
{
	return 0x686868;
}

// @BIGTODO
u16* Trig_GetPosition(CVector*, int)
{
	return reinterpret_cast<u16*>(0x13072024);
}

// @Ok
u16* Trig_GetLinksPointer(int node)
{
	print_if_false(node >= 0 && node < gNumNodes, "Bad node sent to Trig_GetLinksPointer");

	i16* trigNodePtr = gTrigNodes[node];

	if (*trigNodePtr <= 0xD)
	{
		if (*trigNodePtr < 0xC)
		{
			switch (*trigNodePtr)
			{
				case 1:
					return reinterpret_cast<u16*>(trigNodePtr + 3);
				case 2:
				case 3:
				case 6:
				case 8:
				case 9:
				case 10:
					return reinterpret_cast<u16*>(trigNodePtr + 1);
				case 5:
					return reinterpret_cast<u16*>(trigNodePtr + 2);
				default:
					print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
					print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
					return 0;
			}
		}
		else
		{
			return reinterpret_cast<u16*>(trigNodePtr + 1);
		}
	}
	else if (*trigNodePtr <= 0x3E9)
	{
		if (*trigNodePtr < 0x3E8)
		{
			if (*trigNodePtr != 0x14)
			{
				print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
				print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
				return 0;
			}

			return reinterpret_cast<u16*>(trigNodePtr + 2);
		}

		return reinterpret_cast<u16*>(trigNodePtr + 1);
	}
	else if (*trigNodePtr != 0x3EA)
	{
		print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
		print_if_false(0, "Unrecognized node type in\n Trig_GetLinksPointer");
		return 0;
	}

	return reinterpret_cast<u16*>(trigNodePtr + 2);
}

// @MEDIUMTODO
void Trig_SendPulse(unsigned __int16*)
{}

// @SMALLTODO
void Trig_SendSignalToLinks(unsigned __int16*)
{}

static int gTrigMenu[40];
static int gRestartPoints;

// @NotOk
// Globals
void Trig_ClearTrigMenu(void)
{
	for (int i = 0; i<40; i++)
	{
		gTrigMenu[i] = 0;
	}

	gRestartPoints = 0;
}

// @Ok
unsigned char* SkipFlags(unsigned char* pFlags)
{
	while(*pFlags != 0xFF)
		pFlags++;

	return pFlags+1;
}


// @Ok
void Trig_ResetCPCollisionFlags(void)
{
	for(SCommandPoint *cur = CommandPoints; cur; cur = cur->pNext)
	{
		cur->Collision = 0;
	}
}

// @NotOk
// check inline later
INLINE u8 GetFlag(unsigned char flag, unsigned char *pFlags)
{
	while (*pFlags != 0xFF)
	{
		if (*pFlags == flag)
		{
			return 1;
		}
	}

	return 0;
}

// @BIGTODO
void Trig_SendPulseToNode(int)
{}

void validate_SLinkInfo(void)
{
	VALIDATE_SIZE(SLinkInfo, 0x10);

	VALIDATE(SLinkInfo, field_0, 0x0);
	VALIDATE(SLinkInfo, field_4, 0x4);
	VALIDATE(SLinkInfo, field_8, 0x8);
	VALIDATE(SLinkInfo, field_C, 0xC);
}

void validate_SCommandPoint(void)
{
	VALIDATE_SIZE(SCommandPoint, 0x18);

	VALIDATE(SCommandPoint, Collision, 0x4);
	VALIDATE(SCommandPoint, Executed, 0x5);

	VALIDATE(SCommandPoint, pNext, 0x14);
}
