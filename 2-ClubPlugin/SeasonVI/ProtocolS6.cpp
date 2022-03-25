#include "pch.h"

CProtocolS6 gProtocolS6;

void CProtocolS6::ProtocolCore(BYTE head, BYTE* lpMsg, int size)
{
	switch (head)
	{
	case 0x13://Season 6
		switch (lpMsg[4])
		{
		case 0x00:
			gOffsetS6.RecvOffset((SDHP_REQUEST_OFFSET_S6_RECV*)lpMsg);
			break;
		case 0x01:
			this->RecvKeyboardS6((SDHP_REQUEST_KEYBOARD_S6_RECV*)lpMsg);
			break;
		}
		break;
	default:
		gConnection.Disconnect();
		break;
	}
}

void CProtocolS6::RequestOffSetS6()
{
	SDHP_REQUEST_OFFSET_S6_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x00, sizeof(pMsg));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolS6::RequestKeyboardS6()
{
	SDHP_REQUEST_KEYBOARD_S6_SEND pMsg;

	pMsg.header.set(gProtocol.VersionMuHEX, 0x01, sizeof(pMsg));

	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void CProtocolS6::RecvKeyboardS6(SDHP_REQUEST_KEYBOARD_S6_RECV* lpMsg)
{
	gHookKBS6.Func1 = lpMsg->Func1;
	gHookKBS6.Func2 = lpMsg->Func2;
	gHookKBS6.Func3 = lpMsg->Func3;
	gHookKBS6.Func4 = lpMsg->Func4;
	gHookKBS6.Func5 = lpMsg->Func5;
	gHookKBS6.Func6 = lpMsg->Func6;
	gHookKBS6.Func7 = lpMsg->Func7;
	gHookKBS6.Func8 = lpMsg->Func8;
	gHookKBS6.Func9 = lpMsg->Func9;
	gHookKBS6.Func10 = lpMsg->Func10;
	gHookKBS6.Func11 = lpMsg->Func11;
	gHookKBS6.Func12 = lpMsg->Func12;
	gHookKBS6.Func13 = lpMsg->Func13;
}