#pragma once

class COffset
{
public:
	COffset();
	virtual ~COffset();
	void Init(int version, SDHP_CLIENT_INFO_RECV* lpMsg);
public:
	DWORD PortNumberAddress;
	DWORD IpAddressAddress;
	DWORD ClientVersionAddress;
	DWORD ClientSerialAddress;
	DWORD AccountAddress;
	DWORD CharacterAddress;
	DWORD HwndAddress;
	DWORD FileProtectAddress1;
	DWORD FileProtectAddress2;
};
extern COffset gOffset;