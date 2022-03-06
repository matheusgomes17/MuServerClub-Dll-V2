#include "pch.h"

COffset gOffset;

COffset::COffset() // OK
{
}

COffset::~COffset() // OK
{
}

void COffset::Init(int version, SDHP_CLIENT_INFO_RECV* lpMsg)
{
	switch (version)
	{
	case 1://Season 0
		gProtocol.VersionMuHEX = 0x10;
		gOffsetS0.InitOffset(lpMsg);
		break;
	case 2://Season 2
		gProtocol.VersionMuHEX = 0x11;
		gOffsetS2.InitOffset(lpMsg);
		break;
	case 3://Season 4
		gProtocol.VersionMuHEX = 0x12;
		gOffsetS4.InitOffset(lpMsg);
		break;
	case 4://Season 6
		gProtocol.VersionMuHEX = 0x13;
		gOffsetS6.InitOffset(lpMsg);
		break;
	case 5://Season 8
		gProtocol.VersionMuHEX = 0x14;
		gOffsetS8.InitOffset(lpMsg);
		break;
	case 6://Season 10
		gProtocol.VersionMuHEX = 0x15;
		gOffsetS10.InitOffset(lpMsg);
		break;
	case 7://Season 12
		gProtocol.VersionMuHEX = 0x16;
		gOffsetS12.InitOffset(lpMsg);
		break;
	case 8://Season 13
		gProtocol.VersionMuHEX = 0x17;
		gOffsetS13.InitOffset(lpMsg);
		break;
	case 9://Season 14
		gProtocol.VersionMuHEX = 0x18;
		gOffsetS14.InitOffset(lpMsg);
		break;
	case 10://Season 15
		gProtocol.VersionMuHEX = 0x19;
		gOffsetS15.InitOffset(lpMsg);
		gProtocolS15.RequestOffSetS15();
		gProtocolS15.RequestKeyboardS15();
		break;
	case 11://Season 16
		gProtocol.VersionMuHEX = 0x20;
		gOffsetS16.InitOffset(lpMsg);
		break;
	case 12://Season 12 IGC
		break;
	case 13://Season 17
		gProtocol.VersionMuHEX = 0x21;
		gOffsetS17.InitOffset(lpMsg);
		gProtocolS17.RequestOffSetS17();
		gProtocolS17.RequestKeyboardS17();
		break;
	default:
		break;
	}
}