#pragma once

#define MAX_CUSTOM_NPCNAME	100

class cNPCName
{
public:
	cNPCName();
	virtual ~cNPCName();
	void Init();
	void Load(NPCNAME_DATA* info);
	void SetInfo(NPCNAME_DATA info);
	NPCNAME_DATA* GetNPCName(int MonsterID, int Map, int X, int Y);
	NPCNAME_DATA* GetNPCNameByIndex(int index);
	void Scan();
public:
	NPCNAME_DATA m_CustomNpcName[MAX_CUSTOM_NPCNAME];
}; extern cNPCName gNPCName;