// Connection.h: interface for the CConnection class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "CriticalSection.h"

#define MAX_BUFF_SIZE 8192

class CConnectionAuth
{
public:
	CConnectionAuth();
	virtual ~CConnectionAuth();
	bool Init(void* function);
	bool Connect(char* IpAddress, WORD port);
	void Disconnect();
	bool CheckState();
	bool DataRecv();
	bool DataSend(BYTE* lpMsg, int size);
	bool DataSendEx();
	static DWORD WINAPI ClientWorkerThread(CConnectionAuth* lpConnection);

	void CHConnectionStatusSend();
	void CHClientInfoSend();
	void PacketDecryptDataAuth(BYTE* lpMsg, int size, BYTE key);
	void PacketEncryptDataAuth(BYTE* lpMsg, int size, BYTE key);

	DWORD gConnectionStatusTime;
	DWORD gReconnectStatus;
	DWORD gReconnectSwitch;
	SOCKET m_socket;
private:
	WSAEVENT m_event;
	BYTE m_RecvBuff[MAX_BUFF_SIZE];
	int m_RecvSize;
	BYTE m_SendBuff[MAX_BUFF_SIZE];
	int m_SendSize;
	void (*wsProtocolCore)(BYTE, BYTE*, int);
	CCriticalSection m_critical;
	HANDLE m_WorkerThread;
	bool m_active;
};

extern CConnectionAuth gConnectionAuth;