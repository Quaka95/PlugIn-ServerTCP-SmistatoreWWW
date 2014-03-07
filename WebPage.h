#ifndef WEBPAGE_H
#define WEBPAGE_H

#include "stringa.h"
#include <stdio.h>
#include <stdlib.h>

#define HTTP_GET_HEAD "GET "
#define HTTP_GET_FOOT " HTTP"
#define HTTP_HEADER_LEN 4

/*############# Prototipi ###############*/
char* GetFileRequest(char* HTTP_Request);
char* CheckPageExistence(char* path);


/*########### Implementazione ##############*/
char* CheckPageExistence(char* path){
		printf("%s\n",path );
	 /*FILE* fp;
	char* text;
	int size;

   fp = fopen(Path, "r");
    if(fp) {
    	fseek(fp, 0, SEEK_END); 
		size = ftell(fp);
		printf("%d\n\n",size);fclose(fp);/*
		fseek(fp, 0, SEEK_SET);
		text = malloc(size);
		fread(text, 1, size, fp);
		fclose(fp);
		return text;
    }
    else return NULL;*/
}

char* GetFileRequest(char* HTTP_Request){
	int start,stop;

	start = getFistIndex(HTTP_Request,HTTP_GET_HEAD);
	stop = getFistIndex(HTTP_Request,HTTP_GET_FOOT);
	if(start>=0 && stop>=0) return getSubString(HTTP_Request, start+HTTP_HEADER_LEN, stop-start-HTTP_HEADER_LEN);
	return NULL;
}

#endif 