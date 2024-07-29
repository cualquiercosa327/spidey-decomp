#pragma once


#ifndef QUAT_H
#define QUAT_H

#include "export.h"

struct MATRIX;

class CQuat {
public:

	int x,y,z,w;

};

void validate_CQuat(void);

EXPORT void Quat_Slerp (CQuat& a1, CQuat const & a2, int a3, CQuat& a4);
EXPORT void MToQ(MATRIX const &, CQuat&);
EXPORT void QToM(CQuat*, MATRIX*);

#endif
