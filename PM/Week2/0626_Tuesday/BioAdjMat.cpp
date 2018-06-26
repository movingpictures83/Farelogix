#include "stdafx.h"
#include "BioAdjMat.h"

//template <>
//Register BioAdjMat<int>::reg = Register(string("BioAdjMatInt"), &BioAdjMat<int>::make);

//template<>
Register BioAdjMat::reg = Register(string("BioAdjMat"), &BioAdjMat::make);