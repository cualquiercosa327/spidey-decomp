#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "vector.h"

class CBit
{
	public:
		CBit* mPrevious;
		CBit* mNext;

		int unk;

		CVector mPos;
		CVector mVel;
		CVector mAcc;
		CFriction mFric;
		EXPORT CBit();
		virtual ~CBit();
};
