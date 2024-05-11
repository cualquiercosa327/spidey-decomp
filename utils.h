#pragma once

#include "export.h"
#include "vector.h"


EXPORT int Utils_CrapDist(const CVector& a,const CVector& b);
EXPORT int Utils_CrapXZDist(const CVector& a,const CVector& b);
EXPORT int Utils_CompareStrings(const char* left, const char* right);
EXPORT int Utils_ArcCos(int val);
EXPORT int Utils_CopyString(const char*, char*, int);
EXPORT int Rnd(int);
