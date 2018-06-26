#include "stdafx.h"
#include "BioAdjList.h"

template<class T>
Register BioAdjList<T>::reg = Register(string("BioAdjList"), &BioAdjList<T>::make);