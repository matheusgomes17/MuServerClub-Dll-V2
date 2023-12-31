#pragma once
#include "pch.h"

enum eObjectType	//-> Complete
{
	emPlayer = 1,
	emMonster = 2,
	emNPC = 4,
	emNone = 8,
};

//--------------------------------------CustomMonster.CPP-----------------------------------------
#pragma pack(push, 1)
typedef struct  //-> Complete (size: 27)
{
	WORD	ObjectID;
	char	Name[25];
} NpcNameList, * lpNpcNameList;
#pragma pack(pop)


//--------------------------------------USER.CPP-----------------------------------------

//--------------------------------------USER.CPP-----------------------------------------
#pragma pack(push, 1)
typedef struct	//-> Complete (size: 107)
{
	/*+0*/		short	ItemID;
	/*+2*/		int		Level;
	/*+6*/		char	Unknown6;
	/*+7*/		char	Unknown7;
	/*+8*/		char	Unknown8;
	/*+9*/		short	DamageMin;
	/*+11*/		short	DamageMax;
	/*+13*/		char	Unknown13;
	/*+14*/		short	Unknown14;
	/*+16*/		short	Unknown16;
	/*+18*/		char	Unknown18;
	/*+19*/		char	Unknown19;
	/*+20*/		short	Unknown20;
	/*+22*/		char	Durability;
	/*+23*/		char	ExcellentOption;
	/*+24*/		char	AncientOption;
	/*+25*/		short	ReqStrenght;
	/*+27*/		short	ReqDextirity;
	/*+29*/		short	ReqEnergy;
	/*+31*/		short	ReqVitality;
	/*+33*/		short	ReqCommand;
	/*+35*/		short	ReqLevel;
	/*+37*/		char	SpecialCount;
	/*+38*/		WORD	SpecialType[8];
	/*+54*/		BYTE	SpecialValue[8];
	/*+62*/		int		UniqueID;
	/*+66*/		char	Unknown66;
	/*+67*/		char	 PosX;
	/*+68*/		char	 PosY;
	/*+69*/		WORD	 HarmonyType;
	/*+71*/		short	HarmonyValue;
	/*+73*/		char	 Is380Item;
	/*+74*/		char	SocketOption[5];
	/*+79*/		char	Unknown79;
	/*+80*/		char	SocketSeedIndex[5];
	/*+85*/		char	SocketSphereLevel[5];
	/*+90*/		char	SocketSet;
	BYTE gap01[5];
	/*+96*/		char	DurabilityState;
	/*+97*/		char	 PeriodItem;
	/*+98*/		char	 ExpiredItem;
	/*+99*/		int		ExpireDateConvert;
	/*+103*/	int		Unknown103;
} ObjectItem, * lpItemObj;
#pragma pack(pop)

#pragma pack(push, 1)
struct UnknownStruct0
{
	/*+0*/	WORD	Unknown0;//?
	/*+2*/	WORD	Unknown2;//?
	/*+4*/	WORD	Unknown4;//?
	/*+6*/	WORD	Unknown6;
	/*+8*/	WORD	Unknown8;
	/*+10*/	WORD	Unknown10;
	/*+12*/	WORD	Unknown12;//?
	/*+14*/	WORD	Unknown14;
	/*+16*/	WORD	Unknown16;
};
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct	//-> InDev (size: 6012)
{
	/*+0*/		char	Name[11];
	/*+11*/		char	Class;
	/*+12*/		BYTE	Unknown12;
	/*+13*/		BYTE	Unknown13;
	/*+14*/		short	Level;
	/*+16*/		DWORD	Experience;
	/*+20*/		DWORD	NextExperience;
	/*+24*/		WORD	Strength;
	/*+26*/		WORD	Dexterity;
	/*+28*/		WORD	Vitality;
	/*+30*/		WORD	Energy;
	/*+32*/		WORD	Leadership;
	/*+34*/		WORD	Life;
	/*+36*/		WORD	Mana;
	/*+38*/		WORD	MaxLife;
	/*+40*/		WORD	MaxMana;
	/*+42*/		WORD	Shield;
	/*+44*/		WORD	MaxShield;
	/*+46*/		WORD	AttackRate;
	/*+48*/		WORD	DefenseRate;
	/*+50*/		short	AddStrength;
	/*+52*/		short	AddDexterity;
	/*+54*/		short	AddVitality;
	/*+56*/		short	AddEnergy;
	BYTE gap01[4];
	/*+62*/		WORD	AddLeadership;	//GS use unsigned value...
	/*+64*/		WORD	Stamina;
	/*+66*/		WORD	MaxStamina;
	/*+68*/		BYTE	ItemSpecialUseFlag;		//Bit decomposit (1, 2, 8)
	BYTE UnknownGap;
	/*+70*/		WORD	ItemSpecialUseTime[3];	//[ ]
	/*+76*/		WORD	AddPoint;	//FruitStat start
	/*+78*/		WORD	MaxAddPoint;
	/*+80*/		WORD	MinusPoint;
	/*+82*/		WORD	MaxMinusPoint;	//FruitStat end
	/*+84*/		WORD	AttackSpeed;
	/*+86*/		WORD	DamageRate;
	/*+88*/		WORD	DamageMin;
	/*+90*/		WORD	DamageMax;
	/*+92*/		WORD	Unknown92;
	/*+94*/		WORD	Unknown94;
	/*+96*/		WORD	MagicSpeed;
	BYTE gap02[10];
	/*+108*/	WORD	Unknown108;
	/*+110*/	WORD	Unknown110;
	BYTE gap03[4];
	/*+116*/	WORD	LevelPoint;
	/*+118*/	BYTE	MagicCount;
	/*+119*/	BYTE	Unknown119;
	/*+120*/	WORD	pMagicList[650];	//maybe 150?
	/*1420*/
	BYTE gap04[3252];	//maybe preview struct some here
	/*+4672*/	ObjectItem pEquipment[12];
	/*+5956*/	DWORD	MoneyInventory;	//(C4)
	/*+5960*/	DWORD	MoneyWarehouse;	//(C4)
	BYTE gap05[8];
	/*+5972*/	UnknownStruct0 Unknown5972;
	BYTE gap06[2];
	/*+5992*/	WORD	Unknown5992;
	/*+5994*/	WORD	Unknown5994;
	BYTE gap07[2];
	/*+5998*/	WORD	Unknown5998;
	/*+6000*/	WORD	Unknown6000;
	/*+6002*/	WORD	Unknown6002;
	/*+6004*/	WORD	Unknown6004;
	/*+6006*/	WORD	Unknown6006;
	/*+6008*/	BYTE	Unknown6008;
	/*+6009*/	BYTE	Unknown6009;
	/*+6010*/	BYTE	Unknown6010;
	/*+6011*/	BYTE	Unknown6011;
} ObjectCharacter, * lpCharObj;
#pragma pack(pop)
//--------------------------------------USER.CPP-----------------------------------------

//--------------------------------------ITEM.CPP-----------------------------------------
#pragma pack(push, 1)
struct VAngle
{
	float X;
	float Y;
	float Z;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct ObjectModel_424
{
	float Unknown0;
	float Unknown4;
	float Unknown8;
	float Unknown12;
	float Unknown16;
	float Unknown20;
	float Unknown24;
	float Unknown28;
	float Unknown32;
	float Unknown36;
	float Unknown40;
	float Unknown44;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct ObjectModel	//648? 848!!
{
	/*+0*/		int		Prev;
	/*+4*/		BYTE	Unknown4;
	BYTE gap01[4];
	/*+9*/		BYTE	Unknown9;
	BYTE gap02[2];
	/*+12*/		BYTE	Unknown12;
	BYTE gap022[2];
	/*+15*/		BYTE	Unknown15;
	BYTE gap03[2];
	/*+18*/		WORD	AnimationID;
	/*+20*/		WORD	Unknown20;
	/*+22*/		BYTE	Unknown22;
	/*+23*/		BYTE	Unknown23;
	/*+24*/		BYTE	ObjectType;
	BYTE gap04[13];
	/*+38*/		WORD	Unknown38;
	BYTE gap05[8];
	/*+48*/		DWORD	SkinID;
	BYTE gap06[44];
	/*+96*/		float	Scale;
	BYTE gap07[16];
	/*+116*/	float	Unknown116;
	BYTE gap08[20];
	/*+140*/	float	Unknown140;
	/*+144*/	float	Unknown144;
	BYTE gap09[56];
	/*+204*/	VAngle	Unknown204;
	/*+216*/	VAngle	Unknown216;
	BYTE gap10[24];
	/*+252*/	float	VecPosX;
	/*+256*/	float	VecPosY;
	/*+260*/	float	VecPosZ;
	/*+264*/	float	Unknown264;
	/*+268*/	float	Unknown268;
	/*+272*/	float	Unknown272;
	BYTE gap11[148];
	/*+424*/	ObjectModel_424 Unknown424;
	BYTE gap12[176];
	/*+484*/
};
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct	//-> InDev (size: 1432)
{
	BYTE gap01[14];
	/*+14*/		bool	InSafeZone;
	/*+15*/		BYTE	Unknown15;
	/*+16*/		BYTE	Unknown16;
	/*+17*/		BYTE	IsLiveObject;
	/*+18*/		BYTE	Unknown18;
	/*+19*/		BYTE	Class;
	/*+20*/		BYTE	Unknown20;
	/*+21*/		BYTE	CtlCode;	//Bit decomposit (0x10)
	/*+22*/		BYTE	Unknown22;
	/*+23*/		BYTE	Unknown23;
	/*+24*/		BYTE	Unknown24;
	/*+25*/		BYTE	Unknown25;
	/*+26*/		BYTE	Unknown26;
	/*+27*/		BYTE	Unknown27;
	/*+28*/		BYTE	Unknown28;
	/*+29*/		BYTE	Unknown29;
	/*+30*/		BYTE	Unknown30;
	/*+31*/		BYTE	GensInfluence;	//0 - None, 1 - D, 2 - V
	/*+32*/		BYTE	Unknown32;
	/*+33*/		BYTE	Unknown33;
	/*+34*/		BYTE	Unknown34;
	/*+35*/		BYTE	Unknown35;
	/*+36*/		BYTE	Unknown36;	//Personal Shop
	/*+37*/		BYTE	Unknown37;
	/*+38*/		WORD	Unknown38;
	/*+40*/		BYTE	Unknown40;
	/*+41*/		BYTE	Unknown41;
	/*+42*/		BYTE	Unknown42;
	BYTE gap03[2];
	/*+45*/		BYTE	RespawnPosX;
	/*+46*/		BYTE	RespawnPosY;
	BYTE gap04[3];
	/*+50*/		BYTE	ActiveMagic;
	BYTE gap05[5];
	/*+56*/		char	Name[25];	//need check size
	BYTE gap06[39];
	/*+120*/	BYTE	Unknown120;
	/*+121*/	BYTE	Unknown121;
	BYTE gap07[2];
	/*+124*/	WORD	Unknown124;
	/*+126*/	WORD	aIndex;
	/*+128*/	WORD	Unknown128;
	/*+130*/	WORD	Unknown130;
	/*+132*/	WORD	ID;
	/*+134*/	WORD	Unknown134;
	/*+136*/	//maybe word
	BYTE gap09[36];
	/*+172*/	DWORD	MapPosX;
	/*+176*/	DWORD	MapPosY;
	BYTE gap10[8];
	/*+188*/	float	Unknown188;
	BYTE gap11[76];
	/*+268*/	short	HelmSlot;
	/*+270*/	BYTE	HelmLevel;
	/*+271*/	BYTE	HelmExcellent;
	/*+272*/	BYTE	HelmAncient;
	BYTE gap12[31];
	/*+304*/	short	ArmorSlot;
	/*+306*/	BYTE	ArmorLevel;
	/*+307*/	BYTE	ArmorExcellent;
	/*+308*/	BYTE	ArmorAncient;
	BYTE gap13[31];
	/*+340*/	short	PantsSlot;
	/*+342*/	BYTE	PantsLevel;
	/*+343*/	BYTE	PantsExcellent;
	/*+344*/	BYTE	PantsAncient;
	BYTE gap14[31];
	/*+376*/	short	GlovesSlot;
	/*+378*/	BYTE	GlovesLevel;
	/*+379*/	BYTE	GlovesExcellent;
	/*+380*/	BYTE	GlovesAncient;
	BYTE gap15[31];
	/*+412*/	short	BootsSlot;
	/*+414*/	BYTE	BootsLevel;
	/*+415*/	BYTE	BootsExcellent;
	/*+416*/	BYTE	BootsAncient;
	BYTE gap16[31];
	/*+448*/	short	WeaponFirstSlot;
	/*+450*/	BYTE	WeaponFirstLevel;
	/*+451*/	BYTE	WeaponFirstExcellent;
	/*+452*/	BYTE	WeaponFirstAncient;
	BYTE gap17[31];
	/*+484*/	short	WeaponSecondSlot;
	/*+486*/	BYTE	WeaponSecondLevel;
	/*+487*/	BYTE	WeaponSecondExcellent;
	/*+488*/	BYTE	WeaponSecondAncient;
	BYTE gap18[31];
	/*+520*/	short	WingsSlot;
	/*+522*/	BYTE	WingsLevel;
	/*+523*/	BYTE	WingsExcellent;
	/*+524*/	BYTE	WingsAncient;
	BYTE gap19[31];
	/*+556*/	short	PetSlot;
	/*+558*/	BYTE	PetLevel;
	/*+559*/	BYTE	PetExcellent;
	/*+560*/	BYTE	PetAncient;
	BYTE gap20[111];
	/*+672*/	DWORD	Unknown672;
	/*+676*/	DWORD	Unknown676;
	BYTE gap21[84];
	/*+764*/	DWORD	Unknown764;
	BYTE gap22[8];
	/*+776*/	ObjectModel	m_Model;
	/*+1424*/	BYTE	Unknown1424;	//maybe gens rank
	BYTE gap23[3];
	/*+1428*/	DWORD	Unknown1428;	//-> end
} ObjectPreview, * lpViewObj;
#pragma pack(pop)

enum ObjWindow // -> Season 6.3
{
	FriendList = 1,
	MoveList = 2,
	Party = 3,
	Quest = 4,
	NPC_Devin = 5,
	Guild = 6,
	Trade = 7,
	Warehouse = 8,
	ChaosBox = 9,
	CommandWindow = 10,
	PetInfo = 11,
	Shop = 12,
	Inventory = 13,
	Store = 14,
	OtherStore = 15,
	Character = 16,
	DevilSquare = 19,
	BloodCastle = 20,
	CreateGuild = 21,
	GuardNPC = 22,
	SeniorNPC = 23,
	GuardNPC2 = 24,
	CastleGateSwitch = 25,
	CatapultNPC = 26,
	CrywolfGate = 29,
	IllusionTemple = 30,
	HeroList = 32,
	ChatWindow = 33,
	FastMenu = 34,
	Options = 35,
	Help = 36,
	FastDial = 39,
	SkillTree = 57,
	GoldenArcher1 = 58,
	GoldenArcher2 = 59,
	LuckyCoin1 = 60,
	LuckyCoin2 = 61,
	NPC_Duel = 62,
	NPC_Titus = 63,
	CashShop = 65,
	Lugard = 66,
	QuestList1 = 68,
	QuestList2 = 69,
	Jerint = 70,
	FullMap = 72,
	NPC_Dialog = 73,
	GensInfo = 74,
	NPC_Julia = 75,
	NPC_ChaosMix = 76,
	ExpandInventory = 77,
	ExpandWarehouse = 78,
	MuHelper = 79,
};

enum eMapNumber
{
	Lorencia = 0,
	Dungeon = 1,
	Devias = 2,
	Noria = 3,
	LostTower = 4,
	Exile = 5,
	Stadium = 6,
	Atlans = 7,
	Tarkan = 8,
	DevilSquaree = 9,
	Icarus = 10,
	BloodCastle1 = 11,
	BloodCastle2 = 12,
	BloodCastle3 = 13,
	BloodCastle4 = 14,
	BloodCastle5 = 15,
	BloodCastle6 = 16,
	BloodCastle7 = 17,
	ChaosCastle1 = 18,
	ChaosCastle2 = 19,
	ChaosCastle3 = 20,
	ChaosCastle4 = 21,
	ChaosCastle5 = 22,
	ChaosCastle6 = 23,
	Kalima1 = 24,
	Kalima2 = 25,
	Kalima3 = 26,
	Kalima4 = 27,
	Kalima5 = 28,
	Kalima6 = 29,
	Kalima7 = 36,
	Loren = 30,
	Trials = 31,
	DevilSquare6 = 32,
	Aida = 33,
	Crywolf = 34,
	Kanturu1 = 37,
	Kanturu3 = 38,
	Kanturu_Event = 39,
	Silent = 40,
	Barracks = 41,
	Refuge = 42,
	Illusion1 = 45,
	Illusion2 = 46,
	Illusion3 = 47,
	Illusion4 = 48,
	Illusion5 = 49,
	Illusion6 = 50,
	Elbeland = 51,
	BloodCastle8 = 52,
	ChaosCastle7 = 53,
	Calmness = 56,
	Raklion = 57,
	RaklionBoss = 58,
	SantaTown = 62,
	Vulcanus = 63,
	Collosseum = 64,
	Karutan1 = 80,
	Karutan2 = 81,
};