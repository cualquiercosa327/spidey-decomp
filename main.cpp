#define WINDOWS_LEAN_AND_MEAN

#include <windows.h>

#include "main.h"
#include "ob.h"
#include "vector.h"
#include "friction.h"
#include "bit.h"
#include "front.h"
#include "pshell.h"
#include "baddy.h"
#include "mj.h"
#include "submarin.h"
#include "venom.h"
#include "ps2funcs.h"
#include "blackcat.h"
#include "torch.h"
#include "hostage.h"
#include "cop.h"
#include "carnage.h"
#include "chopper.h"
#include "docock.h"
#include "jonah.h"
#include "lizard.h"
#include "lizman.h"
#include "mysterio.h"
#include "platform.h"
#include "rhino.h"
#include "scorpion.h"
#include "simby.h"
#include "spclone.h"
#include "superock.h"
#include "thug.h"
#include "turret.h"
#include "shell.h"
#include "web.h"
#include "bit2.h"
#include "camera.h"
#include "quat.h"
#include "mem.h"
#include "exp.h"
#include "m3dcolij.h"
#include "m3dinit.h"
#include "spidey.h"
#include "message.h"
#include "bullet.h"
#include "trig.h"
#include "effects.h"
#include "FontTools.h"
#include "wire.h"
#include "powerup.h"
#include "switch.h"
#include "chain.h"


// @Ok
void* CClass::operator new(unsigned int size)
{
	void *result = DCMem_New(size, 0, 1, 0, 1);

	unsigned int adjusted_size = ((size + 3) & 0xFFFFFFFC) >> 2;
	if ( adjusted_size )
		memset(result, 0, 4 * adjusted_size);

	return result;
}

// @Ok
void CClass::operator delete(void *ptr)
{
	Mem_Delete(ptr);
}

// @Ok
CClass::~CClass()
{
}

template<bool b>

struct StaticAssert{};



template<>

struct StaticAssert<true>

{

	static void assert() {}
};

void compile_time_assertions(){
	StaticAssert<sizeof(CVector)==12>::assert();
	StaticAssert<sizeof(CFriction)==3>::assert();
	//StaticAssert<sizeof(CBit) == 0x38>::assert();

	//StaticAssert<sizeof(CMenu)==0x53C>::assert();

	//StaticAssert<sizeof(CExpandingBox)==52>::assert();

	StaticAssert<sizeof(CSVector)==6>::assert();

	StaticAssert<sizeof(SVector)==6>::assert();

	StaticAssert<sizeof(CQuadBit)==0x84>::assert();

	//StaticAssert<sizeof(CMJ)==0x324>::assert();

	StaticAssert<sizeof(MATRIX)==0x20>::assert();
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, int nCmdShow)
{
	compile_time_assertions();



	AllocConsole();



	freopen("CONOUT$", "w", stdout);



	puts("[*] Starting validation");



	validate_CItem();

	validate_CVector();

	validate_CSVector();

	validate_CBit();

	validate_CQuadBit();

	validate_CFT4Bit();

	validate_CFlatBit();

	validate_CBody();

	validate_SVector();

	validate_CSuper();

	validate_CBaddy();

	validate_CMJ();

	validate_CSubmariner();

	validate_CVenom();

	validate_CBlackCat();

	validate_CTorch();

	validate_CHostage();

	validate_CScriptOnlyBaddy();

	validate_CCop();

	validate_CCarnage();

	validate_CChopper();

	validate_CDocOc();

	validate_CJonah();

	validate_CLizard();

	validate_CLizMan();

	validate_CMystFoot();

	validate_CMysterio();

	validate_CSoftSpot();

	validate_CPlatform();

	validate_CRhino();

	validate_CScorpion();

	validate_CPunchOb();

	validate_CSimby();

	validate_CSimbyBase();

	validate_CSpClone();

	validate_CSuperDocOck();

	validate_CThug();

	validate_CTurret();

	validate_MATRIX();

	validate_CRudeWordHitterSpidey();

	validate_CBulletFrag();

	validate_CImpactWeb();

	validate_CDomePiece();

	validate_CDome();

	validate_CDomeRing();

	validate_CWeb();

	validate_CSwinger();

	validate_CTurretBase();

	validate_CDummy();

	validate_CSniperSplat();

	validate_SStateFlags();
	validate_CGPolyLine();
	validate_CCamera();
	validate_CQuat();
	validate_SBlockHeader();
	validate_SHandle();
	validate_CItemFrag();
	validate_SLineInfo();
	validate_STexWibItemInfo();
	validate_CPlayer();
	validate_CSmokeTrail();
	validate_CMessage();
	validate_CTrapWebEffect();
	validate_CMenu();
	validate_SEntry();
	validate_CBullet();
	validate_SLinkInfo();
	validate_CElectrify();
	validate_CSimbySlimeBase();
	validate_CMysterioLaser();
	validate_Font();
	validate_CTurretLaser();
	validate_CLaserFence();
	validate_CGoldFish();
	validate_CPowerUp();
	validate_CSwitch();
	validate_CChain();
	validate_CGLine();


	puts("[*] Validation done!");

	__asm {

		      //int 3

			 }
	CItem* items = new CItem[1];
	while(1){}


    return 0;
}
