// ServerDisplayer.cpp: implementation of the CServerDisplayer class.
//
//////////////////////////////////////////////////////////////////////
#include "pch.h"

CServerDisplayer gServerDisplayer;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CServerDisplayer::CServerDisplayer() // OK
{
	for (int n = 0; n < MAX_LOG_TEXT_LINE; n++)
	{
		memset(&this->m_log[n], 0, sizeof(this->m_log[n]));
	}

	this->m_font = CreateFont(50, 0, 0, 0, FW_THIN, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Times");

	this->m_brush[0] = CreateSolidBrush(RGB(105, 105, 105));
	this->m_brush[1] = CreateSolidBrush(RGB(110, 240, 120));
	this->m_brush[2] = CreateSolidBrush(RGB(9, 99, 189));

	strcpy_s(this->m_DisplayerText[0], "STANDBY MODE");
	strcpy_s(this->m_DisplayerText[1], "ACTIVE MODE");

}

CServerDisplayer::~CServerDisplayer() // OK
{
	DeleteObject(this->m_font);
	DeleteObject(this->m_brush[0]);
	DeleteObject(this->m_brush[1]);
	DeleteObject(this->m_brush[2]);
}

void CServerDisplayer::Init(HWND hWnd) // OK
{
		this->m_hwnd = hWnd;
}

void CServerDisplayer::Run() // OK
{
	this->SetWindowName();
	this->PaintAllInfo();
	this->LogTextPaint();
	this->PaintName();
}

void CServerDisplayer::SetWindowName() // OK
{
	char buff[256];

	wsprintf(buff, "[%s] %s - DataServer (QueueSize : %d)", DATA_SERVER_VERSION, gUtil.DataServerName, gSocketManager.GetQueueSize());

	SetWindowTextW(this->m_hwnd, (LPCWSTR)buff);
}

void CServerDisplayer::PaintAllInfo() // OK
{
	RECT rect;

	GetClientRect(this->m_hwnd, &rect);

	rect.top = 50;
	rect.bottom = 100;

	HDC hdc = GetDC(this->m_hwnd);

	int OldBkMode = SetBkMode(hdc, TRANSPARENT);

	HFONT OldFont = (HFONT)SelectObject(hdc, this->m_font);

	this->state = 0;

	for (int n = 0; n < MAX_SERVER; n++)
	{
		if (gServerManager[n].CheckState() == 0)
		{
			continue;
		}

		if ((GetTickCount() - gServerManager[n].m_PacketTime) <= 60000)
		{
			this->state = 1;
			break;
		}
	}

	if (this->state == 0)
	{
		SetTextColor(hdc, RGB(200, 200, 200));
		FillRect(hdc, &rect, this->m_brush[0]);
		TextOut(hdc, 120, 50, this->m_DisplayerText[0], strlen(this->m_DisplayerText[0]));
	}
	else
	{
		SetTextColor(hdc, RGB(250, 250, 250));
		FillRect(hdc, &rect, this->m_brush[1]);
		TextOut(hdc, 150, 50, this->m_DisplayerText[1], strlen(this->m_DisplayerText[1]));
	}

	SelectObject(hdc, OldFont);
	SetBkMode(hdc, OldBkMode);
	ReleaseDC(this->m_hwnd, hdc);
}

void CServerDisplayer::PaintName() // OK
{
	RECT rect;


	GetClientRect(this->m_hwnd, &rect);

	rect.top = 0;
	rect.bottom = 50;

	HDC hdc = GetDC(this->m_hwnd);

	int OldBkMode = SetBkMode(hdc, TRANSPARENT);

	HFONT OldFont = (HFONT)SelectObject(hdc, this->m_font);

	if (this->state == 0)
	{
		SetTextColor(hdc, RGB(255, 255, 255));
		FillRect(hdc, &rect, this->m_brush[2]);
		TextOut(hdc, 120, 0, gUtil.DataServerName, sizeof(gUtil.DataServerName));
	}
	else
	{
		SetTextColor(hdc, RGB(255, 255, 255));
		FillRect(hdc, &rect, this->m_brush[2]);
		TextOut(hdc, 150, 0, gUtil.DataServerName, sizeof(gUtil.DataServerName));
	}

	SelectObject(hdc, OldFont);
	SetBkMode(hdc, OldBkMode);
	ReleaseDC(this->m_hwnd, hdc);

}

void CServerDisplayer::LogTextPaint() // OK
{
	RECT rect;

	GetClientRect(this->m_hwnd, &rect);

	rect.top = 100;

	HDC hdc = GetDC(this->m_hwnd);

	FillRect(hdc, &rect, (HBRUSH)GetStockObject(0));

	int line = MAX_LOG_TEXT_LINE;

	int count = (((this->m_count - 1) >= 0) ? (this->m_count - 1) : (MAX_LOG_TEXT_LINE - 1));

	for (int n = 0; n < MAX_LOG_TEXT_LINE; n++)
	{
		switch (this->m_log[count].color)
		{
		case LOG_BLACK:
			SetTextColor(hdc, RGB(0, 0, 0));
			break;
		case LOG_RED:
			SetTextColor(hdc, RGB(255, 0, 0));
			break;
		case LOG_GREEN:
			SetTextColor(hdc, RGB(0, 255, 0));
			break;
		case LOG_BLUE:
			SetTextColor(hdc, RGB(0, 0, 255));
			break;
		}

		int size = strlen(this->m_log[count].text);

		if (size > 1)
		{
			TextOut(hdc, 0, (85 + (line * 15)), this->m_log[count].text, size);
			line--;
		}

		count = (((--count) >= 0) ? count : (MAX_LOG_TEXT_LINE - 1));
	}

	ReleaseDC(this->m_hwnd, hdc);
}

void CServerDisplayer::LogAddText(eLogColor color, char* text, int size) // OK
{
		size = ((size >= MAX_LOG_TEXT_SIZE) ? (MAX_LOG_TEXT_SIZE - 1) : size);

	memset(&this->m_log[this->m_count].text, 0, sizeof(this->m_log[this->m_count].text));

	memcpy(&this->m_log[this->m_count].text, text, size);

	this->m_log[this->m_count].color = color;

	this->m_count = (((++this->m_count) >= MAX_LOG_TEXT_LINE) ? 0 : this->m_count);
}
