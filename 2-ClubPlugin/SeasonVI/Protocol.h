#pragma once

#define SET_NUMBERHB(x) ((BYTE)((DWORD)(x)>>(DWORD)8))
#define SET_NUMBERLB(x) ((BYTE)((DWORD)(x)&0xFF))
#define SET_NUMBERHW(x) ((WORD)((DWORD)(x)>>(DWORD)16))
#define SET_NUMBERLW(x) ((WORD)((DWORD)(x)&0xFFFF))
#define SET_NUMBERHDW(x) ((DWORD)((QWORD)(x)>>(QWORD)32))
#define SET_NUMBERLDW(x) ((DWORD)((QWORD)(x)&0xFFFFFFFF))

#define MAKE_NUMBERW(x,y) ((WORD)(((BYTE)((y)&0xFF))|((BYTE)((x)&0xFF)<<8)))
#define MAKE_NUMBERDW(x,y) ((DWORD)(((WORD)((y)&0xFFFF))|((WORD)((x)&0xFFFF)<<16)))
#define MAKE_NUMBERQW(x,y) ((QWORD)(((DWORD)((y)&0xFFFFFFFF))|((DWORD)((x)&0xFFFFFFFF)<<32)))

//**********************************************//
//************ Packet Base *********************//
//**********************************************//

struct PBMSG_HEAD
{
	void set(BYTE head, BYTE size) // OK
	{
		this->type = 0xC1;
		this->size = size;
		this->key = rand() % 256;
		this->head = head;
	}

	BYTE type;
	BYTE size;
	BYTE key;
	BYTE head;
};

struct HEAD_VERSION
{
	void set(BYTE head, BYTE subh, BYTE size) // OK
	{
		this->type = 0xC1;
		this->size = size;
		this->key = rand() % 256;
		this->head = head;
		this->subh = subh;
	}

	BYTE type;
	BYTE size;
	BYTE key;
	BYTE head;
	BYTE subh;
};

struct PSBMSG_HEAD
{
	void set(BYTE head, BYTE subh, BYTE size) // OK
	{
		this->type = 0xC1;
		this->size = size;
		this->key = rand() % 256;
		this->head = head;
		this->subh = subh;
	}

	BYTE type;
	BYTE size;
	BYTE key;
	BYTE head;
	BYTE subh;
};

struct PWMSG_HEAD
{
	void set(BYTE head, WORD size) // OK
	{
		this->type = 0xC2;
		this->size[0] = SET_NUMBERHB(size);
		this->size[1] = SET_NUMBERLB(size);
		this->key = rand() % 256;
		this->head = head;
	}

	BYTE type;
	BYTE size[2];
	BYTE key;
	BYTE head;
};

struct PSWMSG_HEAD
{
	void set(BYTE head, BYTE subh, WORD size) // OK
	{
		this->type = 0xC2;
		this->size[0] = SET_NUMBERHB(size);
		this->size[1] = SET_NUMBERLB(size);
		this->key = rand() % 256;
		this->head = head;
		this->subh = subh;
	}

	BYTE type;
	BYTE size[2];
	BYTE key;
	BYTE head;
	BYTE subh;
};

//**********************************************//
//************ Server -> Dll *******************//
//**********************************************//

struct SDHP_CLIENT_INFO_RECV
{
	PBMSG_HEAD header; // C1:00
	BYTE result;
	BYTE Version;
	BYTE HackSwitch;
	DWORD PortNumberAddress;
	DWORD IpAddressAddress;
	DWORD ClientVersionAddress;
	DWORD ClientSerialAddress;
	DWORD AccountAddress;
	DWORD CharacterAddress;
	DWORD HwndAddress;
	DWORD FileProtectAddress1;
	DWORD FileProtectAddress2;
	int ActiveWindowName;
	int ActiveWindowClock;
	int ActiveWindowWebSite;
	char WindowWebSite[25];
	char ServerName[25];
	char IpAddress[32];
	char ClientVersion[8];
	char ClientSerial[17];
	int antiLag;
	int camera3D;
	int customICO;
	int removeSplash;
	int twoFactorAuth;
	int emoji;
	int customMoster;
	int guildIco;
	int petSafeZone;
	int customNPC;
	int customCloak;
	int customOption;
	int customEventTime;
};

struct SDHP_CLIENT_CLOCK_RECV
{
	PBMSG_HEAD header; // C1:00
	DWORD DateHour;
	DWORD DateMinute;
	DWORD DateSecond;
	DWORD DateDay;
	DWORD DateMonth;
	DWORD DateYear;
};

struct SDHP_CONNECTION_STATUS_RECV
{
	PBMSG_HEAD header; // C1:01
};

struct SDHP_WINDOW_LIST_RECV
{
	PSWMSG_HEAD header; // C1:02:03
	WORD MaxCount;
	BYTE count;
};

struct SDHP_CUSTOM_MONSTER_LIST_RECV
{
	PSWMSG_HEAD header; // C1:02:03
	WORD MaxCount;
	BYTE count;
};

struct SDHP_CUSTOM_NPC_LIST_RECV
{
	PSWMSG_HEAD header; // C1:02:03
	WORD MaxCount;
	BYTE count;
};

struct SDHP_CUSTOM_CLOAK_LIST_RECV
{
	PSWMSG_HEAD header; // C1:02:03
	WORD MaxCount;
	BYTE count;
};

struct SDHP_CUSTOM_SMOKE_EFFECT_LIST_RECV
{
	PSWMSG_HEAD header; // C1:02:03
	WORD MaxCount;
	BYTE count;
};

struct SDHP_CUSTOM_FOG_LIST_RECV
{
	PSWMSG_HEAD header; // C1:02:03
	WORD MaxCount;
	BYTE count;
};

struct SDHP_CUSTOM_MAP_NAME_LIST_RECV
{
	PSWMSG_HEAD header; // C1:02:03
	WORD MaxCount;
	BYTE count;
};

struct SDHP_CHECKSUM_LIST_RECV
{
	PSWMSG_HEAD header; // C1:02:01
	WORD MaxCount;
	BYTE count;
};

struct SDHP_CLIENT_DISCONNECT_RECV
{
	PBMSG_HEAD header; // C1:03
	BYTE type;
};

//**********************************************//
//************ Dll -> Server *******************//
//**********************************************//

struct SDHP_CLIENT_HACK_SEND
{
	PBMSG_HEAD header; // C1:00
	int Status;
	char Name[12];
	char Program[100];
	int Map;
	int X;
	int Y;
};

struct SDHP_CLIENT_INFO_SEND
{
	PBMSG_HEAD header; // C1:00
	DWORD ClientFileCRC;
	char VersionPlugin[8];
	char HardwareId[36];
};

struct SDHP_CONNECTION_STATUS_SEND
{
	PBMSG_HEAD header; // C1:01
};

struct SDHP_CLIENT_DISCONNECT_SEND
{
	PBMSG_HEAD header; // C1:03
	BYTE type;
	char account[11];
	char name[11];
	char CaptionName[64];
	char ProcessName[64];
};

struct SDHP_CLIENT_SEND_CONNECT
{
	PBMSG_HEAD header; // C1:00
	char NewHardwareId[50];
	char HardwareId[36];
	char account[11];
	char PcName[50];
	int PortNumber;
};

//**********************************************//
//***************** Class **********************//
//**********************************************//

class CProtocol
{
public:
	CProtocol();
	virtual ~CProtocol();
	void ClientInfoRecv(SDHP_CLIENT_INFO_RECV* lpMsg);
	void ConnectionStatusRecv(SDHP_CONNECTION_STATUS_RECV* lpMsg);
	void ChecksumListRecv(SDHP_CHECKSUM_LIST_RECV* lpMsg);
	void WindowListRecv(SDHP_WINDOW_LIST_RECV* lpMsg);
	void CustomMonsterListRecv(SDHP_CUSTOM_MONSTER_LIST_RECV* lpMsg);
	void CustomNPCListRecv(SDHP_CUSTOM_NPC_LIST_RECV* lpMsg);
	void CustomCloakListRecv(SDHP_CUSTOM_CLOAK_LIST_RECV* lpMsg);
	void CustomSmokeEffectListRecv(SDHP_CUSTOM_SMOKE_EFFECT_LIST_RECV* lpMsg);
	void CustomFogListRecv(SDHP_CUSTOM_FOG_LIST_RECV* lpMsg);
	void CustomMapNameListRecv(SDHP_CUSTOM_MAP_NAME_LIST_RECV* lpMsg);
	void ClientDisconnectSend(int type, char* text, DWORD pid);
	void ClientDisconnectRecv(SDHP_CLIENT_DISCONNECT_RECV* lpMsg);
	void ClientClockRecv(SDHP_CLIENT_CLOCK_RECV* lpMsg);
	void ClientSendHack(char* Account, char* Prog, int Status, int Map, int X, int Y);
	void ClientInfoSend();
	void ConnectionStatusSend();
	void ClientConnectSend();
public:
	int DebuggerCustomDisable;
	DWORD VersionMu;
	DWORD VersionMuHEX;
	DWORD ConnectionStatusTime;
	DWORD ChecksumListMaxCount;
	DWORD WindowListMaxCount;
	DWORD CustomMonsterListMaxCount;
	DWORD CustomNPCListMaxCount;
	DWORD CustomCloakListMaxCount;
	DWORD CustomSmokeEffectListMaxCount;
	DWORD CustomFogListMaxCount;
	DWORD CustomMapNameListMaxCount;
	DWORD ReconnectStatus;
	DWORD ReconnectSwitch;
	DWORD HackSwitch;
	DWORD ClientInfoOK;
	DWORD ChecksumListOK;
	DWORD WindowListOK;
	DWORD CustomMonsterListOK;
	DWORD CustomNPCListOK;
	DWORD CustomCloakListOK;
	DWORD CustomSmokeEffectListOK;
	DWORD CustomFogListOK;
	DWORD CustomMapNameListOK;
	DWORD DetectCloseTime;
	DWORD UserAccount;
	DWORD UserStruct;
	//
	int PortNumber;//Pega a Port Number
	DWORD PortNumberAddress;
	char ServerName[50];
	char IpAddress[32];
	BYTE ClientVersion[5];
	BYTE ClientSerial[17];
	//WindowName
	int ActiveWindowName;
	int ActiveWindowClock;
	int ActiveWindowWebSite;
	char WindowWebSite[50];
};

void ProtocolCoreMain(BYTE head, BYTE* lpMsg, int size);
extern CProtocol gProtocol;