#include "spool.h"
#include "utils.h"

int lowGraphics;
int CurrentSuit;

static const char SuitNames[5][32];

// @NotOk
// Change constants with proper variables
int Spool_FindRegion(const char *a1)
{
	char fileName[0x20];
	print_if_false(a1 != 0, "No FileName sent to Spool_PSX.");
	Utils_CopyString(a1, fileName, sizeof(fileName));


	if (!lowGraphics)
	{
		if (Utils_CompareStrings(fileName, "spidey"))
			Utils_CopyString(SuitNames[CurrentSuit], fileName, sizeof(fileName));
	}

	int region = 0;
	int regionAddress = 0x6B2440;

	do
	{
		if (!Utils_CompareStrings(fileName, reinterpret_cast<char*>(regionAddress)))
		{
			regionAddress += 0x44;
			region++;
		}
		else{
			return region;
		}


	} while (regionAddress < 0x6B2EE0);


	return -1;
}
