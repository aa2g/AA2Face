#pragma once
#include <Windows.h>
/*
* Represents an XXFile with values specific to faces. Can be safely casted to XXFile.
*/
class XXFileFace
{
public:
	XXFileFace();
	~XXFileFace();

	BYTE m_unknown1[0x224];
	void* m_morphsPointer1;
	DWORD m_morphsUnknown1;
	void* m_morphShapesPointer;
	DWORD m_morphsUnknown2;
	void* m_morphsPointer3;
	BYTE m_unknown2[0x4];
	// mouth shape
	int m_mouth;
	BYTE m_unknown3[0x18];
	// eye shape
	int m_eye;
	BYTE m_unknown4[0x18];
	// eyebrow shape
	int m_eyebrow;
	BYTE m_unknown5[0x30];
	// max eye open status
	float m_eyeOpen;
	BYTE m_unknown6[0x8];
	// min mouth open status
	float m_mouthOpen;
	BYTE m_unknown7[0x1C768];
	// lock eye tracking
	bool m_eyeTracking;

};

