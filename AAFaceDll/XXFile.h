#pragma once

#include <Windows.h>


namespace ExtClass {

class Frame;

#pragma pack(push, 1)
/*
* Represents an in-game XX file structure
*/
class XXFile
{
public:
	DWORD m_unknown;
	char m_name[0x200];
	BYTE m_unknown2[0x3];
	BYTE m_attachmentLevel; // seems to be the depth at which this xxfile is attached
	Frame* m_attachmentFrame; // frame that attaches to another XXFile frame
	Frame* m_attacherFrame; // 0x20C // frame from another XXFile this attaches to
	XXFile* m_attacherXXFile;
	BYTE m_unknown3[0x4];
	Frame* m_root; // 0x218

	BYTE m_unknown4[0x8];
	void* m_morphsPointer1; // 0x224
	DWORD m_morphsUnknown1;
	void* m_morphShapesPointer;
	DWORD m_morphsUnknown2;
	void* m_morphsPointer3;

	BYTE m_unknown5[0x4];
	int m_mouth; // 0x23C
	BYTE m_unknown6[0x18];
	int m_eye; // 0x258
	BYTE m_unknown7[0x18];
	int m_eyebrow; // 0x274
	BYTE m_unknown8[0x30];
	float m_eyeOpenMax;
	float m_eyeOpenMin;
	float m_mouthOpenMax;
	float m_mouthOpenMin;

	BYTE m_unknown9[0x34]; // 0x2B8
	size_t m_lightsCount; // Only the skeleton seems to have this
	DWORD* m_lightsArray;

	DWORD m_unknownLight; // unused?

	// The whole DWORD is checked for not null for the setting to have effect
	BYTE m_ambientLightBlue;
	BYTE m_ambientLightGreen;
	BYTE m_ambientLightRed;
	BYTE m_ambientLightPadding;

	BYTE m_unknown10[0x34];
	uint32_t m_materialCount; // 0x330
	DWORD* m_materialArray;
	BYTE m_unknown11[0x1C];
	DWORD m_animArraySize; // 0x354
	DWORD* m_animArray;
	BYTE m_unknown12[0x1C018]; // 0x35C
	DWORD m_poseNumber;
	BYTE m_unknown13[0x8];
	float m_animFrame; // 0c1C380
	BYTE m_unknown14[0x69C];
	DWORD m_eyeTracking; //0x1CA20

	template<class Callback>
	void EnumBonesPreOrder_sub(Callback& callback, Frame* bone);
	template<class Callback>
	void EnumBonesPostOrder_sub(Callback& callback,Frame* bone);
public:

	XXFile() = delete;
	~XXFile() = delete;
	
};
#pragma pack(pop)

static_assert(sizeof(XXFile) == 0x1CA24, "XXFile size mismatch; must be 0x1CA24 bytes");



}