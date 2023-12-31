#include "pch.h"

User	gObjUser;
DWORD LastTime = 0;
char* ServerName;

void User::Load()
{
	this->m_CursorX = -1;
	this->m_CursorY = -1;
	this->m_MapNumber = -1;
}

void User::Refresh()
{
	this->lpPlayer = &*(ObjectCharacter*)*(int*)(0x8128AC8);
	this->lpViewPlayer = &*(ObjectPreview*)*(int*)(0x7BC4F04);
	this->GetTarget();

	this->m_CursorX = pCursorX;
	this->m_CursorY = pCursorY;
	this->m_MapNumber = pMapNumber;

}

bool User::GetTarget()
{
	if (pViewNPCTargetID != -1)
	{
		this->lpViewTarget = &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), pViewNPCTargetID);

		//NPCNAME_DATA* NpcName = gNPCName.GetNPCName(this->lpViewTarget->ID, pMapNumber, this->lpViewTarget->RespawnPosX, this->lpViewTarget->RespawnPosY);

		//if (NpcName != 0)
		//{
		//	memcpy(this->lpViewTarget->Name, NpcName->Name, sizeof(NpcName->Name));
		//}

		//this->m_TargetType	= 1;
		return true;
	}
	else if (pViewAttackTargetID != -1)
	{
		this->lpViewTarget = &*(ObjectPreview*)pGetPreviewStruct(pPreviewThis(), pViewAttackTargetID);
		//this->m_TargetType	= 2;
		return true;
	}

	if (this->lpViewTarget != 0)
	{
		ZeroMemory(&this->lpViewTarget, sizeof(this->lpViewTarget));
	}

	//this->m_TargetType = 0;
	return false;
}

int User::GetActiveSkill()
{
	lpCharObj lpPlayer = &*(ObjectCharacter*)*(int*)(0x8128AC8);
	lpViewObj lpViewPlayer = &*(ObjectPreview*)*(int*)(0x7BC4F04);
	return lpPlayer->pMagicList[lpViewPlayer->ActiveMagic];
	//return this->lpPlayer->pMagicList[this->lpViewPlayer->ActiveMagic];
}

void User::SetEventEffect(int PreviewStruct)
{

	lpViewObj lpPreview = &*(ObjectPreview*)PreviewStruct;

	if (lpPreview)
	{
		if (*(DWORD*)(0x00E609E8) == GameProcess_2)
		{
			if (lpPreview->m_Model.ObjectType == emPlayer)
			{
				VAngle Angle;
				int PosX;
				int PosY;

				Angle.X = *(float*)(PreviewStruct + 0x404);

				Angle.Y = *(float*)(PreviewStruct + 0x408);

				Angle.Z = *(float*)(PreviewStruct + 0x40C) + *(float*)(PreviewStruct + 0x3E8) + 100.0f;

				pGetPosFromAngle(&Angle, &PosX, &PosY);

				//gInterface.DrawItem(PosX,PosY-30,4,4,0,SET_ITEMOPT_LEVEL(0),0,0,0);

			}
		}
	}

	// ----
	if (lpPreview->CtlCode == 32)
	{
		if (*(DWORD*)(PreviewStruct + 672) && lpPreview->Unknown23 != 5)
		{
			pInitEventStatus(PreviewStruct);
		}
		// ----
		lpPreview->Unknown23 = 5;
	}
	// ----
	if (*(DWORD*)(PreviewStruct + 672) != 0 || !lpPreview->Unknown23)
	{
		return;
	}
	// ----
	switch (lpPreview->Unknown23)
	{
	case 5:	//-> GM
	{
		if (pEventEffectThis(668))
		{
			DWORD ModelID = 349;
			// ----
			if (!strncmp(lpPreview->Name, "[GM]", 4))
			{
				ModelID = 406;
			}
			else if (!strncmp(lpPreview->Name, "[EM]", 4))
			{
				ModelID = 407;
			}
			else if (!strcmp(lpPreview->Name, "Admin"))
			{
				ModelID = 408;
			}

			// ----
			*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect(pEventEffectThis(668), ModelID, 20, 1, 70.0, -5.0, 0.0, 0.0, 0.0, 45.0);
		}
	}
	break;
	// --
	case 6:
	{
		if (pEventEffectThis(668))
		{
			*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 0, 20, 120.0, 0.0, 0.0);
		}
	}
	break;
	// --
	case 7:
	{
		if (pEventEffectThis(668))
		{
			*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 1, 20, 120.0, 0.0, 0.0);
		}
	}
	break;
	// --
	case 8:
	{
		if (pEventEffectThis(668))
		{
			*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 2, 20, 120.0, 0.0, 0.0);
		}
	}
	break;
	// --
	case 9:
	{
		if (pEventEffectThis(668))
		{
			*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 3, 20, 120.0, 0.0, 0.0);
		}
	}
	break;
	// --
	case 10:
	{
		if (pEventEffectThis(668))
		{
			*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 4, 20, 120.0, 0.0, 0.0);
		}
	}
	break;
	// --
	case 11:
	{
		if (pEventEffectThis(668))
		{
			*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 5, 20, 120.0, 0.0, 0.0);
		}
	}
	break;
	// --
	case 12:
	{
		if (pEventEffectThis(668))
		{
			*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 6, 20, 120.0, 0.0, 0.0);
		}
	}
	break;
	// --
	case 13:
	{
		if (pEventEffectThis(668))
		{
			*(LPVOID*)(PreviewStruct + 672) = pAddEventEffect2(pEventEffectThis(668), 32241, 7, 20, 120.0, 0.0, 0.0);
		}
	}
	break;
	default:
	{
		lpPreview->Unknown23 = 0;
	}
	break;
	}
}