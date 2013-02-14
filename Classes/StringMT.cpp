// StringMT.cpp: implementation of the CStringMT class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StringMT.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStringMT::CStringMT()
{
	lpData = NULL;
}
CStringMT::CStringMT( CStringMT &CStr)
{
	int len;
	len = CStr.GetLength();
	if(len == 0){
		lpData = NULL;
		return;
	}
	lpData = new TCHAR[len + 1];
	if(lpData == NULL)
		return;
	wcscpy(lpData,CStr.GetBuffer());
	
}
CStringMT::~CStringMT()
{
	delete[] lpData;
}




CStringMT &CStringMT::operator=(CStringMT &CStr)
{
	int len;
	delete [] lpData;
	if(len = CStr.GetLength() == 0){
		lpData = NULL;
		return *this;
	}
	lpData = new TCHAR[len + 1];
	if(lpData == NULL)
		return *this;
	wcscpy(lpData,CStr.GetBuffer());
	return *this;	


}

/*

CStringMT &CStringMT::operator=(LPTSTR pStr)
{
	int len;
	delete [] lpData;
	if(len = wcslen(pStr) == 0){
		lpData = NULL;
		//throw(MEM_ERR);
		return *this;
	}
	lpData = new TCHAR[len + 1];
	if(lpData == NULL){
		throw(MEM_ERR);
		return *this;
	}
	wcscpy(lpData,pStr);
	return *this;	


}

*/
/*

CStringMT &CStringMT::operator+=(CStringMT &CStr)
{
	DWORD dwLen,dwLenSource;
	
	dwLenSource = CStr.GetLength();
	if(!dwLenSource)
		return *this;
	dwLen = this->GetLength() + 1;
	LPTSTR pTempStr = new TCHAR[dwLen];
	if(pTempStr == NULL)
		goto _errExit;

	wcscpy(pTempStr,lpData);
	//wcscat(pTempStr,CStr.GetBuffer());
	//lpData[iNewStr] = NULL;
	dwLen += dwLenSource;
	delete [] lpData;
	
	lpData = new TCHAR[dwLen];
	if(lpData == NULL){
		delete [] pTempStr;
		goto _errExit;
	}
	wcscpy(lpData,pTempStr);
	wcscat(lpData,CStr.GetBuffer());

	return *this;
_errExit:	
	throw(MEM_ERR);
	return *this;;

}




CStringMT &CStringMT::operator+=(LPTSTR lpStr)
{
	

	DWORD dwLen,dwLenSource;
	
	if(dwLenSource = wcslen(lpStr) == 0){
		delete [] lpData;
		lpData = NULL;
		return *this;

	}
	dwLen = wcslen(lpData);
	if(dwLen ){	//concatenate mode ...save the string in a temp location
		LPTSTR pTempStr = new TCHAR[dwLen + 1];
		if(pTempStr == NULL)
			goto _errExit;
		wcscpy(pTempStr,lpData);
		delete [] lpData;
		lpData = new TCHAR[dwLenSource + dwLen + 1];
		if(lpData == NULL){
			delete [] pTempStr;
			goto _errExit;
		}
		if( wsprintf(lpData,L"%s%s",pTempStr,lpStr) == (int)(dwLenSource + dwLen))
			return *this;
		else
			goto _errExit;
			
	
	}
	else{//just copy the string
		lpData = new TCHAR[dwLenSource + 1];
		if(lpData == NULL)
			goto _errExit;
		wcscpy(lpData,lpStr);
			return *this;

	}


_errExit:	
	throw(MEM_ERR);
	return *this;;

}
*/

