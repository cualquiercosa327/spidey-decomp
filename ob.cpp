#include "ob.h"
#include "mem.h"
#include "spool.h"
#include <cstring>
#include "validate.h"


// @Ok
// Random move from global to eax and test eax, eax that doesn't change shit
void* CItem::operator new(unsigned int size) {

  void *result = DCMem_New(size, 0, 1, 0, 1);

  unsigned int adjusted_size = ((size + 3) & 0xFFFFFFFC) >> 2;
  if ( adjusted_size )
    memset(result, 0, 4 * adjusted_size);

  return result;
}


/// @NotOk
// missing 3C assignement need to understand what it is
CItem::CItem()
{
	this->mPos.vx = 0;
	this->mPos.vy = 0;
	this->mPos.vz = 0;


	this->mAngles.vx = 0;
	this->mAngles.vy = 0;
	this->mAngles.vz = 0;

	//this->field_2C = 0;

	this->field_28 = 0x1000;
	this->field_2A = 0x1000;
	this->field_2C = 0x1000;

	///this->field_3C = ???;
}

CItem::~CItem(){}


// @NotOk
// indices not matching, rest is okay
void CItem::InitItem(const char * a1)
{

	int Region = Spool_FindRegion(a1);
	this->mRegion = Region;
	this->mModel = 0;

	int index = (Region & 0xFF)  * 0x11;

	if (Regions[index])
	{
		int *tmp = *CItemRelatedList[index];
		tmp[2] = 0x64000;
		tmp[3] = 0xFF9C0064;
		tmp[4] = 0xFF9C0064;
		tmp[5] = 0xFF9C0064;
	}
}



// @Ok
// has weird xor eax, eax at the top
int __inline CBody::IsDead(void) const{
	return (this->mCBodyFlags >> 6) & 1;
}
	


// @Ok
void CBody::Die(void){
	int isDead = this->IsDead();
	if(!isDead)
	{
		this->mCBodyFlags |= 0x40;
	}
}

// @Ok
void CBody::ShadowOn(void){
	this->mCBodyFlags |= 8;
}


// @NotOk
// dessutrctor
void __inline CBody::KillShadow(void){

  this->mCBodyFlags &= ~8u;
  if ( this->bodyQuadBit )
  {
    //result = (**somethingWithVtableDestructor)(somethingWithVtableDestructor, 1);
    this->bodyQuadBit = 0;
  }
}

// @NotOk
// Inlined KillShadow and weird part where we store data but it's just xor eax, eax
void CBody::UpdateShadow(void){

	__int16 flags = this->mCBodyFlags;

	if(flags & 8){

		if(!this->bodyQuadBit){

			CQuadBit *quad = new CQuadBit();
			this->bodyQuadBit = quad;

			quad->SetTexture(0, 0);
			this->bodyQuadBit->SetSubtractiveTransparency();
			this->bodyQuadBit->mFrigDeltaZ = 32;
			this->bodyQuadBit->mProtected = 1;
		}

		SVector vec;
		vec.vx = 0;
		vec.vy = -4096;
		vec.vz = 0;

		unsigned __int16 lastParam = this->field_D0;
		this->bodyQuadBit->OrientUsing(&this->bodyVector, &vec, lastParam, lastParam);


		__int8 trans = ((this->field_D4 - this->field_D2) << 7) / this->field_D4;

		if(trans < 0){
			trans = 0;
		}

		this->bodyQuadBit->SetTransparency(trans);

	}
	else{
		   this->KillShadow();
	}

}


// @Ok
void CBody::AttachTo(CBody** a1)
{

	CBody *v2 = *a1;
	this->field_34 = 0;
	this->field_20 = v2;

	*a1 = this;

	CItem *v3 = this->field_20;
	if (v3)
		v3->field_34 = this;

}

// @NotOk
// missing vtable call
void CBody::InterleaveAI(void)
{
	if (this->mFlags & 2)
	{
		this->EveryFrame();
		CSuper *super = reinterpret_cast<CSuper*>(this);
		super->UpdateFrame();
	}
	else
	{
		this->EveryFrame();
	}

	// vcall here
}


CSuper::CSuper(){
  this->gAnim = 1;
  this->field_142 = 1;
  this->field_13E = 100;
  this->field_13F = 94;

}

void CSuper::OutlineOff(void){
	this->outlineRelated &= 0xFFFFFFFB;
}

// NEED TO FINISH
void CSuper::OutlineOn(void){
	this->outlineRelated |= 4;
	if (!this->SNbrFaces){
	}

	this->outlineR = -1;
	this->outlineG = -1;
	this->outlineB = -1;
	this->alsoOutlineRelated = 0x50000000;
}


void CSuper::SetOutlineSemiTransparent(){
	this->alsoOutlineRelated |= 0x20000000;
}

void CSuper::SetOutlineRGB(unsigned char a2, unsigned char a3, unsigned char a4){
	this->outlineR = a2;
	this->outlineG = a3;
	this->outlineB = a4;
}

void CSuper::UpdateFrame(void){
	char v1; // bl
	int v2; // esi
	int v3; // edx
	int v4; // eax
	int v5; // edx
	int v6; // eax
	unsigned __int16 v7; // dx


	if ( !this->field_80 )
	  this->field_80 = 2;
	v1 = this->field_141;
	v2 = this->field_80 * this->csuperend / 2;
	v3 = (unsigned __int16)this->field_146 | (this->field_128 << 16);
	if ( this->field_141 == 1 )
	  v3 += v2;
	if ( v1 == -1 )
	  v3 -= v2;
	v4 = v3;
	this->field_146 = v3;
	v5 = (unsigned __int8)this->field_140;
	v6 = v4 >> 16;
	this->field_128 = v6;

	if (v5) {
		if ( --v5 == 0)
		{
		  v7 = this->gAnim;
		  if ( (__int16)v6 >= (int)v7 )
		  {
			  this->field_128 = v6 - v7;
        
		  }
		  else
		  {

			if ( (__int16)(v6) < 0 )
			  this->field_128 = v6 + v7;
		  }
		}
	}
	else if( (this->field_141 == 1 && (__int16)v6 >= this->field_144)
		||
		(v1 == -1 && (__int16)v6 <= this->field_144)
		){
		this->field_128 = this->field_144;
		this->field_142 = 1;
	}
}


// Revisit
void CSuper::CycleAnim(int a2, char a3){
  if (this->field_12A != a2 )
  {
    this->field_128 = 0;
	this->field_146 = 0;
	this->field_12A = a2;
    int mRegion = (unsigned __int8)this->mRegion;

	print_if_false(
      (unsigned int)(unsigned __int16)a2 < *(unsigned int *)Animations[17 * mRegion],
      "Bad anim sent to CycleAnim");
    this->gAnim = *(__int16 *)(Animations[17 * (unsigned __int8)this->mRegion]
                           + 8 * (unsigned __int16)this->field_12A
                           + 8);

    
    this->field_141 = a3;
  }
  this->field_140 = 1;
  this->field_142 = 0;
}


//Revisit
void CSuper::ApplyPose(__int16 *a2){

	if (!this->field_188){
		this->actualcsuperend = a2;
	}

	if ((this->mFlags & 4) != 0){
		this->field_13E = 69;
	}
}


//TODO
void CSuper::RunAnim(int, int, int){
}

static int * const gTimerRelated = (int*)0x006B4CA8;

// @NotOk
// timerRelated needs to be fixed and call to print_if_false looks wrong
void CBody::EveryFrame(void)
{
	int v3; // edx
	int v4; // ecx
	__int16 v6; // ax
	__int16 v7; // cx
	char v8; // dl
	bool v9; // [esp-8h] [ebp-Ch]

	if ( (this->mCBodyFlags & 4) != 0 )
	{
		this->field_80 = 2;
		this->mCBodyFlags &= 0xFFFB;
		this->field_7C = *gTimerRelated;
		this->field_84 = 0;
	}
	else
	{
		v3 = this->field_7C;
		v9 = *gTimerRelated - v3 >= 0;
		this->field_80 = *gTimerRelated - v3;
		print_if_false(v9, "Timing error");
		v4 = this->field_80;
		this->field_7C = *gTimerRelated;
		if ( v4 > 6 )
		this->field_80 = 6;
	}

	this->field_84 += this->field_80;
	if ( (this->mFlags & 2) != 0 )
	{
		CSuper *super = reinterpret_cast<CSuper*>(this);
		v6 = super->field_128;
		v7 = super->field_12A;
		v8 = super->field_141;
		super->field_152 = v6;
		super->field_150 = v6;
		super->field_154 = v7;
		super->field_143 = v8;
	}

}

void validate_CItem(void){

	VALIDATE_SIZE(CItem, 0x40);

	VALIDATE(CItem, mFlags, 0x4);
	VALIDATE(CItem, mPos, 0x8);
	VALIDATE(CItem, mAngles, 0x14);
	VALIDATE(CItem, mModel, 0x1A);
	VALIDATE(CItem, mRegion, 0x1F);

	VALIDATE(CItem, field_20, 0x20);


	VALIDATE(CItem, field_28, 0x28);
	VALIDATE(CItem, field_2A, 0x2A);
	VALIDATE(CItem, field_2C, 0x2C);

	VALIDATE(CItem, field_34, 0x34);
	VALIDATE(CItem, field_3C, 0x3C);

}


void validate_CBody(void){

	VALIDATE_SIZE(CBody, 0xF4);
	
	VALIDATE(CBody, field_44, 0x44);
	VALIDATE(CBody, mCBodyFlags, 0x46);
	VALIDATE(CBody, mAccellorVel, 0x60);

	VALIDATE(CBody, gVec, 0x6C);

	VALIDATE(CBody, field_78, 0x78);
	VALIDATE(CBody, field_79, 0x79);
	VALIDATE(CBody, field_7A, 0x7A);


	VALIDATE(CBody, field_7C, 0x7C);

	VALIDATE(CBody, field_80, 0x80);
	VALIDATE(CBody, field_84, 0x84);

	VALIDATE(CBody, csVector1, 0x88);

	VALIDATE(CBody, field_8E, 0x8E);
	VALIDATE(CBody, bodyVector, 0xB8);
	VALIDATE(CBody, bodyQuadBit, 0xCC);
	VALIDATE(CBody, field_D0, 0xD0);
	VALIDATE(CBody, field_D2, 0xD2);
	VALIDATE(CBody, field_D4, 0xD4);
	VALIDATE(CBody, field_DC, 0xDC);
	VALIDATE(CBody, field_E2, 0xE2);

}

void validate_CSuper(void){

	/*
		unsigned char field_13E;
	unsigned char field_13F;
	unsigned char field_142;
	__int16 field_148;
	*/
	
	VALIDATE(CSuper, field_F8, 0xF8);
	VALIDATE(CSuper, field_FC, 0xFC);
	VALIDATE(CSuper, field_100, 0x100);
	VALIDATE(CSuper, field_104, 0x104);
	VALIDATE(CSuper, field_108, 0x108);

	VALIDATE(CSuper, field_10C, 0x10C);
	VALIDATE(CSuper, SNbrFaces, 0x11C);
	VALIDATE(CSuper, alsoOutlineRelated, 0x120);
	VALIDATE(CSuper, outlineR, 0x124);
	VALIDATE(CSuper, outlineG, 0x125);
	VALIDATE(CSuper, outlineB, 0x126);

	VALIDATE(CSuper, field_128, 0x128);
	VALIDATE(CSuper, field_12A, 0x12A);
	VALIDATE(CSuper, field_141, 0x141);
	VALIDATE(CSuper, field_143, 0x143);
	VALIDATE(CSuper, field_150, 0x150);
	VALIDATE(CSuper, field_152, 0x152);
	VALIDATE(CSuper, field_154, 0x154);


	VALIDATE(CSuper, field_128, 0x128);

	VALIDATE(CSuper, field_12A, 0x12A);
	VALIDATE(CSuper, outlineRelated, 0x12C);

	VALIDATE(CSuper, field_13E, 0x13E);
	VALIDATE(CSuper, field_13F, 0x13F);

	VALIDATE(CSuper, field_140, 0x140);
	VALIDATE(CSuper, field_141, 0x141);
	VALIDATE(CSuper, field_142, 0x142);

	VALIDATE(CSuper, field_144, 0x144);	
	VALIDATE(CSuper, field_146, 0x146);	

	VALIDATE(CSuper, gAnim, 0x148);	
	VALIDATE(CSuper, csuperend, 0x14C);

	VALIDATE(CSuper, field_164, 0x164);

	VALIDATE(CSuper, field_188, 0x188);
	VALIDATE(CSuper, actualcsuperend, 0x190);
}
