//HTMLogger.h
#ifndef __HTMLogger_H_
#define __HTMLogger_H_
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "HTMLMarkers.h"
using namespace std;

namespace HTMLog
{
	class log
	{
	public:
		//pPlik, nazwa log'a
		static __declspec(dllexport) FILE* MakeLog(string param); 
		//pPlik, grubosc tabeli
		static __declspec(dllexport) void MakeTable(FILE *htmlFile, int border); 
		//pPlik, tresc, funkcja
		static __declspec(dllexport) void AddRow(FILE *htmlFile, string content, string function);
		//pPlik, tresc, funkcja
		static __declspec(dllexport) void AddInfoRow(FILE *htmlFile, string content, string function);
		//pPlik, tresc, funkcja
		static __declspec(dllexport) void AddErrorRow(FILE *htmlFile, string content, string function);
		//pPlik
		static __declspec(dllexport) void CloseTable(FILE *htmlFile); 
		//pPlik
		static __declspec(dllexport) int CloseLog(FILE *htmlFile);//konczenie log'a wraz z porzebnymi znacznikami
	};
}

#endif