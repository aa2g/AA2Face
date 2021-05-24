#pragma once

#ifdef AAFACELIBRARY_EXPORTS
#define AAFACELIBRARY_API __declspec(dllexport)
#else
#define AAFACELIBRARY_API __declspec(dllimport)
#endif
#include <string>
#include <Windows.h>
#include "CharacterStruct.h"


namespace Shared {
	ExtClass::CharacterStruct * getCharStruct();
	std::string getDLLPath();

}
extern "C" AAFACELIBRARY_API void modelReload(DWORD* ptr);

