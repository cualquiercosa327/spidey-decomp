#include "pcdcFile.h"
#include "PCMovie.h"
#include "pkr.h"
#include "SpideyDX.h"
#include "validate.h"

#include <cstring>

#ifdef _WIN32
EXPORT TCHAR gCurrentDir[260];
#endif

EXPORT char gFsBase[260];

// @FIXME: real size
EXPORT SGDOpenFile gOpenFiles[0xFF];

EXPORT HANDLE gOpenFile;

// @Ok
// @Matching
void gdFsClose(HANDLE handle)
{
	if (handle != gOpenFile)
	{
		// @FIXME: portability issues
		closeFilePKR(reinterpret_cast<i32>(handle));
		return;
	}

	CloseHandle(gOpenFile);
	PKR_LockFile(gDataPkr);
}

// @Ok
EXPORT i32 gdFsInit(void)
{
#ifdef _WIN32
	GetCurrentDirectoryA(260, gCurrentDir);
#endif

	strcpy(gFsBase, "data\\");
	openPKR();

	PCMOVIE_InitOnce();
	PCMOVIE_OpenPKR();

	return 0;
}

// @Ok
// @Matching
INLINE void closeFilePKR(i32 id)
{
	i32 i = (id ^ 0xFF);
	i--;
	if (gOpenFiles[i].field_0)
	{
		delete gOpenFiles[i].field_0;
		gOpenFiles[i].field_0 = 0;
		gOpenFiles[i].field_4 = 0;
		gOpenFiles[i].field_8 = 0;
	}
}

// @SMALLTODO
void closePKR(void)
{
    printf("closePKR(void)");
}

// @SMALLTODO
void findFilePKR(char *,char const *)
{
    printf("findFilePKR(char *,char const *)");
}

// @SMALLTODO
void nextFile(void)
{
    printf("nextFile(void)");
}

// @SMALLTODO
void openFilePKR(char *,char const *)
{
    printf("openFilePKR(char *,char const *)");
}

// @Ok
INLINE void openPKR(void)
{
	char error[512];

	if (!gDataPkr)
	{
		if (!PKR_Open(&gDataPkr, "data.pkr", 1))
		{
			if (PKR_GetLastError(error))
			{
				DXERR_printf("PKR\t: %s\r\n", error);
			}
		}
		else
		{
			DXERR_printf("PKR\t: Name       : %s\r\n", gDataPkr->name);
			DXERR_printf("PKR\t: N.O. Dir   : %i\r\n", gDataPkr->mFooter.numDirs);
			DXERR_printf("PKR\t: N.O. Files : %i\r\n", gDataPkr->mFooter.numFiles);
		}
	}
	else
	{
		DXERR_printf("PKR\t: PKR %s already open\r\n", gDataPkr->name);
	}
}

// @SMALLTODO
void readFilePKR(i32,char *,i32)
{
    printf("readFilePKR(i32,char *,i32)");
}

// @SMALLTODO
void seekFilePKR(i32,i32,i32)
{
    printf("seekFilePKR(i32,i32,i32)");
}

// @SMALLTODO
void tellFilePKR(i32)
{
    printf("tellFilePKR(i32)");
}

void validate_SGDOpenFile(void)
{
	VALIDATE_SIZE(SGDOpenFile, 0xC);
	VALIDATE(SGDOpenFile, field_0, 0x0);
	VALIDATE(SGDOpenFile, field_4, 0x4);
	VALIDATE(SGDOpenFile, field_8, 0x8);
}
