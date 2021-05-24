#pragma once
#include <Windows.h>

#include "CharacterData.h"
#include "CharacterStatus.h"
#include "XXFile.h"
#include "XXFileFace.h"

namespace ExtClass {
extern BYTE g_anim_data[25][6];

#pragma pack(push, 1)
	/*
	 * Represents a character in the game and its state.
	 */
	class CharacterStruct
	{
	public:
		// CAVEAT: order const.lua
		enum Models {
			FACE = 0,
			SKELETON = 1,
			BODY = 2,
			LEGS = 3,
			HAIR_FRONT = 4,
			HAIR_SIDE = 5,
			HAIR_BACK = 6,
			HAIR_EXT = 7,
			FACE_SLIDERS = 8,
			SKIRT = 9,
			N_MODELS = 10,
			TONGUE = 11,
			GLASSES = 12,
			H3DROOM = 13,
			INVALID
		};

	public:
		//	void* m_virtualTable;

		// Known caveats:
		// - Despawn must be called in reverse-spawn order
		// - Materials will be all over place, the clones must be same "family"

		// original game vtable
		/* #0 */ virtual DWORD Destroy(int free); // destroys the character, 1 frees it too i think
		/* #1 */ virtual DWORD Spawn(BYTE clothstate, BYTE materialSlot, BYTE light, BYTE isedit); // Loads character on scene
		/* #2 */ virtual DWORD Update(BYTE clothstate, BYTE isedit); // second argument indicates if maker/play pp
		/* #3 */ virtual DWORD fn3();
		/* #4 */ virtual DWORD Despawn(); // removes the character from scene
		/* #5 */ virtual DWORD fn5();
		/* #6 */ virtual DWORD Despawn2(); // called together with Despawn, frees memory?
		/* #7 */ virtual DWORD fn7();
		/* #8 */ virtual DWORD fn8();
		/* #9 */ virtual DWORD LoadXA(const wchar_t *pp, const wchar_t *xa, int pose, int z0, int z1);
		/* #10 */ virtual DWORD fn10();
		/* #11 */ virtual DWORD Animate1(DWORD a, DWORD b, DWORD c);
		/* #12 */ virtual DWORD Animate2(DWORD a, void *b, DWORD c, DWORD d, DWORD e, DWORD f);
		inline bool AnimateFace() {
			DWORD fn;
			bool retv;
			__asm {
				mov eax, this
				call [fn]
				mov retv, al
			}
			return retv;
		}

		BYTE m_unknown4[4];
		void *m_xxinstance1;
		BYTE m_unknown8[8];
		void *m_xxinstance2;
		BYTE m_unknown18[0x10];
		CharacterData* m_charData; // 0x28
		void* m_somePointer; // 0x2c
		void* m_charPos;
		void* m_somePointer3;
		int m_materialSlot;
		int m_seat; //seat number; from top to bottom, right to left, zero based, teacher is exception and 24 //3c
		BYTE m_boobs; // weird female boobs state. girls generally have some, boys dont. // 40
		BYTE m_clothState;
		BYTE m_bClothesOn;
		BYTE m_currClothSlot;
		BYTE m_currClothes;
		BYTE m_unknown5[3];
		XXFile* m_xxFace; //0x48 certain pointers to model files. all of these may be NULL if they are not loaded yet or not used

		XXFile* m_xxGlasses;
		union {
			struct {
				XXFile* m_xxFrontHair;
				XXFile* m_xxSideHair;
				XXFile* m_xxBackHair;
				XXFile* m_xxHairExtension;
			};
			XXFile* m_xxHairs[4];
		};
		XXFile* m_xxTounge;
		XXFile* m_xxSkeleton;
		XXFile* m_xxBody;
		XXFile* m_xxLegs;
		BYTE m_unknown6[0x130];
		DWORD** m_bonePtrArray; //note that this is an array of only certain frequently used frames with a fixed position; the bone might be NULL thought.
								//first one is neck (focused on q press), second one is spin (focused on w press), 10th (0x24 offset) is tears
		DWORD** m_bonePtrArrayEnd; //(exclusive, not part of array anymore)
		BYTE m_unknown7[0xD78];
		BYTE m_lovers[0x19];	//array of lovers, by seat	//F20
		BYTE m_daysLovers[0x19];
		BYTE m_unknown7_1[0x2];
		DWORD m_stamina;
		DWORD* m_npcData;
		void* m_somedata; //F5C
		void* m_moreUnknownData;
		void* m_moreData;		//where m_moreData+0x16A18 is pointer to array of CharacterRelation, m_moreData+0x16A1C is end (typical array structure)
		void* m_evenMoreData;	//m_evenMoreData+0x30 is pointer to moods array1; m_evenMoreData+0x40 is pointer to moods array2	  //F68
		CharacterStatus* m_characterStatus; //F6C
		DWORD* m_moreData1;	//F70	//m_moreData1+18 is pointer to CharacterActivity struct
		DWORD* m_moreData2;	//F74	//m_moreData2+0x18 is pointer to CharacterActivity struct
		BYTE m_unknown10[0x4];
		XXFile* m_xxSkirt;
		BYTE m_unknown11[0x1C];


	public:
		CharacterStruct() = delete;
		~CharacterStruct() = delete;

	static void ApplyAnimData();
	};
	static_assert(sizeof(CharacterStruct) == 0xF9C, "CharacterStruct size missmatch; must be 0xF9C bytes (allocation size)");
#pragma pack(pop)
}
