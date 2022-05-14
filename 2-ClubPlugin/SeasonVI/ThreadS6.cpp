#include "pch.h"

CThreadS6 gThreadS6;

CThreadS6::CThreadS6() // OK
{
	this->GET_HWND = 0;
	this->Count = 0;
	this->GetAntLag = 0;
}

CThreadS6::~CThreadS6() // OK
{

}

void CThreadS6::Init()
{
	switch (*(DWORD*)(gOffsetS6.MAIN_SCREEN_STATE))
	{
	case SelectServer_2:
		gWindowCheck.CHeckCheat = 0;
		gSpeed.CHeckSpeed = 0;
		if (this->GET_HWND == 0)
		{
			this->GET_HWND = 1;
			gMain.hWnd = *(HWND*)(gOffset.HwndAddress);
			this->SelectServerThread(0);
		}
		else if (this->GET_HWND == 3 || this->GET_HWND == 4)
		{
			this->GET_HWND = 2;
			this->SelectServerThread(1);
		}
		break;
	case SwitchCharacter_2:
		gWindowCheck.CHeckCheat = 0;
		gSpeed.CHeckSpeed = 0;
		if (this->GET_HWND == 1 || this->GET_HWND == 2)
		{
			this->Count++;
			if (this->Count == 3)
			{
				this->GET_HWND = 3;
				this->SwitchCharacterThread(0);
			}
		}
		break;
	case GameProcess_2:
		gWindowCheck.CHeckCheat = 1;
		gSpeed.CHeckSpeed = 1;
		if (this->GET_HWND == 3)
		{
			this->GET_HWND = 4;
			this->GameProcessThread(1);
		}
		this->GetAntLag++;
		if (this->GetAntLag >= 10)
		{
			this->GetAntLag = 0;
			if (gFeatures.antiLag != 0) { gAntiLagS6.ActiveDisabled(1); }
		}
		this->GameProcessThread(0);
		break;
	default:
		break;
	}
}


void CThreadS6::InitCustom()
{
	SetCompleteHook(0xE9, 0x0095DFBE, 0x0095DFD3); // Help Iventory

	SetCompleteHook(0xE9, 0x004D1CF0, 0x004D1DC2); //-- Remove MuError.DMP
	MemorySet(0x00D20170, 0x90, 0x1B); //-- Remove Creation MuError.log

	// item limit
	SetByte(0x00777FD6, 0x70); // Item Text Limit
	SetByte(0x00777FD7, 0x17); // Item Text Limit
	SetByte(0x004EBEC7, 0x3C); // Item Text Limit
	SetByte(0x005C4004, 0x3C); // Item Text Limit
	SetByte(0x007E40BB, 0x3C); // Item Text Limit
	SetByte(0x0081B546, 0x3C); // Item Text Limit
	SetByte(0x0081B58D, 0x3C); // Item Text Limit
	SetByte(0x0086E284, 0x3C); // Item Text Limit
	SetByte(0x0086E44C, 0x3C); // Item Text Limit
	SetByte(0x0086E573, 0x3C); // Item Text Limit
	SetByte(0x0086F8FC, 0x3C); // Item Text Limit
	SetByte(0x007DA373, 0xB7); // Item Type Limit
	SetByte(0x007E1C44, 0xB7); // Item Type Limit

	gObjUser.Load();
	gInterface.Load();
	gCustomInterface.Load();

	if (gFeatures.customMoster == 1)
	{
		gCustomMonster.Scan();
	}

	if (gFeatures.customNPC == 1)
	{
		gNPCName.Scan();
	}

	gCustomMonster.Load(gCustomMonster.m_CustomMonster);
	gNPCName.Load(gNPCName.m_CustomNpcName);
	gCustomMonster.InitMonster();

	if (gFeatures.guildIco == 1)
	{
		InitGuildIcon();
	}

	if (gFeatures.petSafeZone == 1)
	{
		if (gThreadS6.PetSafeZone_Fenrir == 1)
		{
			SetByte(0x00501955 + 2, 0);
			MemorySet(0x0054EAE1, 0x90, 0x06);//SetPlayerStop
			MemorySet(0x0054FC92, 0x90, 0x06);//SetPlayerWalk
		}

		if (gThreadS6.PetSafeZone_Horse == 1)
		{
			//Horse SafeZone (Struct +14)
			SetByte(0x00502269 + 2, 0);
			MemorySet(0x0054ECA3, 0x90, 0x6);
			MemorySet(0x0054FCEC, 0x90, 0x6);
		}

		if (gThreadS6.PetSafeZone_Dinorant == 1)
		{
			//Dinorant e Uniria (Struct +14)
			SetByte(0x00502C4B + 2, 0);
			MemorySet(0x0054ED6D, 0x90, 0x6);
			MemorySet(0x0054FD5F, 0x90, 0x6);
			MemorySet(0x0054FE3E, 0x90, 0x6);
		}
	}

	if (gThreadS6.ActiveNameServer == 1)
	{
		SetDword(0x00954148 + 1, (DWORD)gThreadS6.Name1Server);
		SetDword(0x0040B6EB + 1, (DWORD)0xEAB);
		SetDword(0x0077F93E + 1, (DWORD)0xEAB);
		SetDword(0x00954115 + 1, (DWORD)gThreadS6.Name2Server);
		SetDword(0x0040B6D6 + 1, (DWORD)0xEAC);
		SetDword(0x0077F929 + 1, (DWORD)0xEAC);
		SetDword(0x009540E2 + 1, (DWORD)gThreadS6.Name3Server);
		SetDword(0x0040B6C1 + 1, (DWORD)0xEAD);
		SetDword(0x0077F914 + 1, (DWORD)0xEAD);
		SetDword(0x009540AC + 1, (DWORD)gThreadS6.Name4Server);
		SetDword(0x0040B6AC + 1, (DWORD)0xEAE);
		SetDword(0x0077F8FF + 1, (DWORD)0xEAE);
	}

	/* rafael downgrade
	MemorySet(0x00D20170, 0x90, 0x1B);            //-> Remove Creation MuError.log


MemorySet(0x0085B6AC, 0x90, 0x05);            //-> Remove Helper Top Screen
MemorySet(0x0085CC50, 0x90, 0x05);            //-> Disable Helper (Key Z)
MemorySet(0x007D40A2, 0x90, 0x05);            //-> Disable Helper (Key Home)

MemorySet(0x0085BF15, 0x90, 0x05);            //-> Disable Tree (Key A)

MemorySet(0x007C5AD2, 0x90, 0x05);            //-> Disable Gens (Key B)

MemorySet(0x0062F876, 0x90, 0x30);            //-> Disable ViewMap (Key TAB)

MemorySet(0x00661700, 0x90, 0x43);            //-> Disable CashShop (Key X) SafeZone
MemorySet(0x007D3D7A, 0x90, 0x05);            //-> Disable CashShop (Key X) MonsterZone

MemorySet(0x008583F9, 0x90, 0x08);            //-> Disable Red Lucky Item Inv -> Trade
MemorySet(0x00858752, 0x90, 0x08);            //-> Disable Red Lucky Item Inv -> Baul
MemorySet(0x0085875F, 0x90, 0xF6);            //-> Allow Move Lucky Item Inv -> Baul

MemorySet(0x008684F0, 0x90, 0x52);            //-> Disable FastMenu (Key U)


[b]COORDENADAS PARA DOWNGRADE S3[/b]
#define pDrawTextBig            ((int(__cdecl*)(float, float, int, float)) 0x791000)
pDrawTextBig(23.0f,(MAX_WIN_HEIGHT-20),*(BYTE*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x0AC),0.9f);
pDrawTextBig(45.0f,(MAX_WIN_HEIGHT-20),*(BYTE*)(*(DWORD*)(MAIN_VIEWPORT_STRUCT)+0x0B0),0.9f);*/

}

void CThreadS6::SelectServerThread(int Cod_ID)
{
}

void CThreadS6::SwitchCharacterThread(int Cod_ID)
{
	if (Cod_ID == 0)
	{
		char* GetAccountN = (char*)gOffset.AccountAddress;
		wsprintf(gThread.NameAccount, GetAccountN);
		gProtocol.ClientConnectSend();
	}
}

void CThreadS6::GameProcessThread(int Cod_ID)
{
	if (Cod_ID == 0)
	{
		this->BaseAddress = (DWORD)GetModuleHandle("Main.dll");
		lpViewObj lpViewPlayer = &*(ObjectPreview*)*(int*)(gOffsetS6.MAIN_VIEWPORT_STRUCT);

		DWORD Map = *(DWORD*)(gOffsetS6.MAIN_MAP_CODE);
		DWORD PosX = lpViewPlayer->MapPosX;
		DWORD PosY = lpViewPlayer->MapPosY;

		if (gSpeed.CHeckSpeed == 1) {
			gSpeed.m_SpeedMain.Map = Map;
			gSpeed.m_SpeedMain.X = PosX;
			gSpeed.m_SpeedMain.Y = PosY;

			gSpeed.CheckLimit(Map, PosX, PosY);
		}
	}
	else
	{
		if (gFeatures.antiLag != 0) { gAntiLagS6.ActiveDisabled(0); }
	}
}