#include "Shared.h"
#include "GenUtils.h"
#include <string>
#include <tchar.h>
#include "CharacterStruct.h"


using namespace Shared;

ExtClass::CharacterStruct *currChar;




void modelReload(DWORD* ptr) {
	currChar = (ExtClass::CharacterStruct*)ptr;
}

ExtClass::CharacterStruct* Shared::getCharStruct()
{
	return currChar;
}


std::string Shared::getDLLPath()
{
	//here
	TCHAR path[_MAX_PATH + 1];
	TCHAR result[_MAX_PATH + 1];

	GetModuleFileName(GetModuleHandle(("AAFaceDll.dll")), path, sizeof(path) / sizeof(path[0]));
	int len = _tcslen(path) - 13;
	_tcsncpy_s(result, path, len); 
	return result;
		//	auto pathS = std::to_wstring(path);
}

std::string CastToString(const std::wstring& str) {
	return std::string(str.begin(), str.end());
}