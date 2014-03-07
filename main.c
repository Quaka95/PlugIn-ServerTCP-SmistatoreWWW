#include <stdio.h>
#include <stdlib.h>
#include "WebPage.h"

int main(int argc,char** argv){
	char* word;
	char* sup="";
	char* pro="";

	if(argc!=2){ printf("USAGE: %s WORD\n",argv[0]); return -1; }
	word=argv[1];
	
	sup = stringConcat("./www",GetFileRequest(word));
	printf("%s\n",sup );
	pro = CheckPageExistence(sup);
	printf("%s\n",pro );

	return 0;
}