// ClientManager.cpp: implementation of the CClientManager class.
//
//////////////////////////////////////////////////////////////////////

#include "pch.h"

CClientManager gClientManager[MAX_CLIENT];
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClientManager::CClientManager() // OK
{
	this->m_index = -1;

	this->m_state = CLIENT_OFFLINE;

	this->m_socket = INVALID_SOCKET;

	this->m_IoRecvContext = 0;

	this->m_IoSendContext = 0;

	this->m_OnlineTime = 0;

	this->m_PacketTime = 0;
}

CClientManager::~CClientManager() // OK
{

}

bool CClientManager::CheckState() // OK
{
	if (CLIENT_RANGE(this->m_index) == 0 || this->m_state == CLIENT_OFFLINE || this->m_socket == INVALID_SOCKET)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool CClientManager::CheckAlloc() // OK
{
	if (this->m_IoRecvContext == 0 || this->m_IoSendContext == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool CClientManager::CheckOnlineTime() // OK
{
	if ((GetTickCount() - this->m_OnlineTime) > MAX_ONLINE_TIME)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void CClientManager::AddClient(int index, char* ip, SOCKET socket) // OK
{
	this->m_index = index;

	this->m_state = CLIENT_ONLINE;

	strcpy_s(this->m_IpAddr, ip);

	this->m_socket = socket;

	gClientCount = ((this->CheckAlloc() == 0) ? (((++gClientCount) >= MAX_CLIENT) ? 0 : gClientCount) : gClientCount);

	this->m_IoRecvContext = ((this->m_IoRecvContext == 0) ? (new IO_RECV_CONTEXT) : this->m_IoRecvContext);

	this->m_IoSendContext = ((this->m_IoSendContext == 0) ? (new IO_SEND_CONTEXT) : this->m_IoSendContext);

	memset(&this->m_IoRecvContext->overlapped, 0, sizeof(this->m_IoRecvContext->overlapped));

	this->m_IoRecvContext->wsabuf.buf = (char*)this->m_IoRecvContext->IoMainBuffer.buff;
	this->m_IoRecvContext->wsabuf.len = MAX_MAIN_PACKET_SIZE;
	this->m_IoRecvContext->IoType = IO_RECV;
	this->m_IoRecvContext->IoSize = 0;
	this->m_IoRecvContext->IoMainBuffer.size = 0;

	memset(&this->m_IoSendContext->overlapped, 0, sizeof(this->m_IoSendContext->overlapped));

	this->m_IoSendContext->wsabuf.buf = (char*)this->m_IoSendContext->IoMainBuffer.buff;
	this->m_IoSendContext->wsabuf.len = MAX_MAIN_PACKET_SIZE;
	this->m_IoSendContext->IoType = IO_SEND;
	this->m_IoSendContext->IoSize = 0;
	this->m_IoSendContext->IoMainBuffer.size = 0;
	this->m_IoSendContext->IoSideBuffer.size = 0;

	memset(this->m_HardwareId, 0, sizeof(this->m_HardwareId));

	this->m_OnlineTime = GetTickCount();

	this->m_PacketTime = 0;

	//gIpManager.InsertIpAddress(this->m_IpAddr);
	//Comentado este log por excesso de log ->
	//LogAdd(LOG_BLACK, "[ClientManager][%d] AddClient (%s)", this->m_index, this->m_IpAddr);
}

void CClientManager::DelClient() // OK
{
	//Comentado este log por excesso de log ->
	//LogAdd(LOG_BLACK, "[ClientManager][%d] DelClient (%s)", this->m_index, this->m_IpAddr);

	memcpy(gClientManager[this->m_index].m_Account, "", sizeof(gClientManager[this->m_index].m_Account));

	//gIpManager.RemoveIpAddress(this->m_IpAddr);

	//gHidManager.RemoveHardwareId(this->m_HardwareId);

	this->m_index = -1;

	this->m_state = CLIENT_OFFLINE;

	memset(this->m_IpAddr, 0, sizeof(this->m_IpAddr));

	this->m_socket = INVALID_SOCKET;

	memset(this->m_HardwareId, 0, sizeof(this->m_HardwareId));

	this->m_OnlineTime = GetTickCount();

	this->m_PacketTime = 0;
}

void CClientManager::SetDataServer(int Index, char* NewHardwareId, char* HardwareId, char* account, char* PcName, int PortNumber)// OK
{
	std::string NewHWID = NewHardwareId;
	NewHWID.erase(std::remove_if(NewHWID.begin(), NewHWID.end(), [](char c) { return !isalnum(c); }), NewHWID.end());
	this->m_PortNumber = PortNumber;
	strcpy(this->m_NewHardwareId, NewHWID.c_str());
	memcpy(this->m_HardwareId, HardwareId, sizeof(this->m_HardwareId));
	memcpy(this->m_Account, account, sizeof(this->m_Account));
	memcpy(this->m_PcName, PcName, sizeof(this->m_PcName));

	memcpy(gClientManager[Index].m_Account, account, sizeof(gClientManager[Index].m_Account));
}