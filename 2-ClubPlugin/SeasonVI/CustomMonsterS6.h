#pragma once

#define MAX_CUSTOMMONSTER 100

#define MAX_MONSTER		1024
#define MAX_MONSTER_MODEL	644

#define pMapNumber				*(int*)0x0E61E18
#define pLoadTexture			((void(__cdecl*)(int TextureID, char * Folder, int GLREPEAT, int GLNEAREST, int GLTRUE)) 0x614710)
#define pLoadMonsterBMD			((void(__cdecl*)(signed int a1, char* a2, char* a3, signed int a4)) 0x614D10)
#define pViewObject				((int(__cdecl*)(int a1, signed int a2, unsigned __int8 a3, unsigned __int8 a4, float a5)) 0x57EEC0)
#define pLoadMonsterID			((int(__cdecl*)(signed int a1)) 0x61FDE0)

#define sub_580BB0 ((void(__cdecl*)(int This, int))0x00580BB0)
#define pGetMonsterName			((char*(__cdecl*)(int)) 0x590DD0)

enum eMonsterType
{
	CUSTOM_MONSTER_TYPE_NPC = 0,
	CUSTOM_MONSTER_TYPE_MOB = 1,
};

class CCustomMonster
{
public:
	CCustomMonster();
	virtual ~CCustomMonster();
	void Init();
	void Load(CUSTOMMONSTER_DATA* info);
	void SetInfo(CUSTOMMONSTER_DATA info);
	CUSTOMMONSTER_DATA* GetInfoByMonsterID(int MonsterID);
	CUSTOMMONSTER_DATA* GetInfoByIndex(int Index);
	void InitMonster();
	void Scan();
private:
	static void LoadMonsterBMD(signed int Class, char* FileDir, char* BmdName, signed int BmdType);
	static void LoadMonsterTexture(signed int Class, char* FolderDir, int a3, int a4);
	static int ShowMonster(int Class, int a2, int a3, int a4);
	static void SetMainAttribute(lpViewObj Object, int MonsterID);
	int LoadMonster;
	NpcNameList m_NpcName[MAX_CUSTOMMONSTER];
public:
	CUSTOMMONSTER_DATA m_CustomMonster[MAX_CUSTOMMONSTER];
};

extern CCustomMonster gCustomMonster;
