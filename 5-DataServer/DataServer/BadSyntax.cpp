// BadSyntax.cpp: implementation of the CBadSyntax class.
//
//////////////////////////////////////////////////////////////////////

#include "pch.h"

CBadSyntax gBadSyntax;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBadSyntax::CBadSyntax() // OK
{
	this->m_BadSyntaxInfo.clear();
}

CBadSyntax::~CBadSyntax() // OK
{

}

void CBadSyntax::Load(const char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if (lpMemScript == 0)
	{
		gUtil.ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR, path);
		return;
	}

	if (lpMemScript->SetBuffer((char *)path) == 0)
	{
		gUtil.ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->m_BadSyntaxInfo.clear();

	try
	{
		while (true)
		{
			if (lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if (strcmp("end", lpMemScript->GetString()) == 0)
			{
				break;
			}

			BAD_SYNTAX_INFO info;

			strcpy_s(info.syntax, lpMemScript->GetString());

			this->m_BadSyntaxInfo.push_back(info);
		}
	}
	catch (...)
	{
		gUtil.ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

bool CBadSyntax::CheckSyntax(char* text) // OK
{
	for (std::vector<BAD_SYNTAX_INFO>::iterator it = this->m_BadSyntaxInfo.begin(); it != this->m_BadSyntaxInfo.end(); it++)
	{
		if (strstr(text, it->syntax) != 0)
		{
			return 0;
		}
	}

	return 1;
}
