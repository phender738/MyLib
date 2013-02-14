// StringMT.h: interface for the CStringMT class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRINGMT_H__6ACD0A71_1465_4C9A_832C_71E5F979850D__INCLUDED_)
#define AFX_STRINGMT_H__6ACD0A71_1465_4C9A_832C_71E5F979850D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MEM_ERR 1



class CStringMT  
{
public:
	CStringMT();
	virtual ~CStringMT();
	
	CStringMT(CStringMT &CStr);
	CStringMT &operator=(CStringMT &CStr);
	//CStringMT &operator=(LPTSTR pStr);
	DWORD  GetLength() {return wcslen(lpData);}
	LPTSTR GetBuffer() {return lpData;};
	CStringMT &operator+=(LPTSTR lpStr);
	CStringMT &operator+=(CStringMT &CStr);

protected:
	CRITICAL_SECTION m_hCSection;
	LPTSTR lpData;
};

#endif // !defined(AFX_STRINGMT_H__6ACD0A71_1465_4C9A_832C_71E5F979850D__INCLUDED_)
