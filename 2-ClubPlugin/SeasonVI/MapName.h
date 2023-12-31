#pragma once

#define MAX_MAP 150

class CMapName
{
public:
	CMapName();
	virtual ~CMapName();
	void Init();
	void LoadMap(MAP_NAME* info);
	void SetMap(MAP_NAME info);
	MAP_NAME* GetMapName(int index);
	MAP_NAME* GetIndexMap(int index);
	char* GetMap(int index);
	void Scan();
public:
	char m_DefaultMap[128];
	int m_MapNumberDefault;
	MAP_NAME m_MapName[MAX_MAP];
};

extern CMapName gMapName;