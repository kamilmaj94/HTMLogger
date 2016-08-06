#include "HTMLoggerDLL.h"
#include "HTMLMarkers.h"
#include <string.h>
#include <stdexcept>
#include <iostream>
#include <stdio.h>
#include <ctime>

namespace HTMLog
{
	FILE* log::MakeLog(string param)
	{
		string param_exe = param;
		param += ".html";
		FILE* htmlFile = fopen(param.c_str(), "w");
		fprintf(htmlFile,"%s \n",html);
		fprintf(htmlFile,"%s \n",body);
		fprintf(htmlFile,"%s%s ",title,param.c_str());
		fprintf(htmlFile,"%s\n",_title);
		fprintf(htmlFile,"%s%s%s%s%s%s",
				center,
				b,
				i,
				param_exe.c_str(),
				_b,
				_i);
		fprintf(htmlFile,".exe");
		fprintf(htmlFile," - log(app)%s",_center);
		fprintf(htmlFile,"%s \n",_title);
		
		return htmlFile;
		}
	void log::MakeTable(FILE *htmlFile, int border)
	{
		time_t rawtime;
		time (&rawtime);
		fprintf(htmlFile,"\n%s\n%s border = %i>\n",
			center,
			table,
			border); //<table border = x>
		
		//DEFAULT ROW----------------------------------------
		fprintf(htmlFile,"%s\n",trHead); //<tr bgcolor = #FFCC99>
		fprintf(htmlFile,"%s%s%s%sTIME%s%s%s%s",
			td,
			center,
			b,
			u,
			//TIME
			_b,
			_u,
			_center,
			_td); //TIME 
		fprintf(htmlFile,"%s%s%s%sComment/Content%s%s%s%s",
			td,
			center,
			b,
			u,
			//Comment / Content
			_b,
			_u,
			_center,
			_td); //C/C
		fprintf(htmlFile,"%s%s%s%sFunction%s%s%s%s",
			td,
			center,
			b,
			u,
			//FUNCTION
			_b,
			_u,
			_center,
			_td); //()

		fprintf(htmlFile,"%s\n",_tr); //</tr>
	}
	void log::AddRow(FILE *htmlFile, string content, string function)
	{
		time_t rawtime;
		time (&rawtime);
		fprintf(htmlFile,"%s%s%s%s%s%s%s",
			tdTime,
			center,
			b,
			ctime(&rawtime),
			_b,
			_center,
			_td); //godzina wycentrowana

		fprintf(htmlFile,"%s%s%s%s%s",
			tdContent,
			i,
			content.c_str(), //!!!
			_i,
			_td); //C/C

		fprintf(htmlFile,"%s%s%s%s%s%s%s",
			tdFunction,
			i,
			u,
			function.c_str(), //!!!
			_i,
			_u,
			_td); //()
	}
	void log::AddInfoRow(FILE *htmlFile, string content, string function)
	{
		//TODO: zmiana komorki TIME na "#FFCC99"
		{
		time_t rawtime;
		time (&rawtime);
		fprintf(htmlFile,"%s%s%s%s%s%s%s",
			tdTime,
			center,
			b,
			ctime(&rawtime),
			_b,
			_center,
			_td); //godzina wycentrowana

		fprintf(htmlFile,"%s%s%s%s%s",
			td,
			i,
			content.c_str(), //!!!
			_i,
			_td); //C/C

		fprintf(htmlFile,"%s%s%s%s%s%s%s",
			tdFunction,
			i,
			u,
			function.c_str(), //!!!
			_i,
			_u,
			_td); //()
	}
	}
	void log::AddErrorRow(FILE *htmlFile, string content, string function)
	{
		//TODO: TIME: #FFCC99 Content, Function: red
		{
		time_t rawtime;
		time (&rawtime);
		fprintf(htmlFile,"%s%s%s%s%s%s%s",
			tdTime,
			center,
			b,
			ctime(&rawtime),
			_b,
			_center,
			_td); //godzina wycentrowana

		fprintf(htmlFile,"%s%s%s%s%s",
			tdError,
			i,
			content.c_str(), //!!!
			_i,
			_td); //C/C

		fprintf(htmlFile,"%s%s%s%s%s%s%s",
			tdError,
			i,
			u,
			function.c_str(), //!!!
			_i,
			_u,
			_td); //()
	}
	}
	void log::CloseTable(FILE *htmlFile)
	{
			fprintf(htmlFile,"%s\n",_table); //</table>
			fprintf(htmlFile,"%s\n",_center); //</center> god...
	}
	int  log::CloseLog(FILE *htmlFile)
	{
		fprintf(htmlFile,"%s\n",_body);
		fprintf(htmlFile,"%s\n",_html);
		return fclose(htmlFile);
	}//konczenie log'a wraz z porzebnymi znacznikami
}