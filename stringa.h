#ifndef STRINGA_H
#define STRINGA_H

#include <string.h>

/*############# Prototipi ###############*/
int getFistIndex(char* str1, char* str2);
char* getSubString(char* str,int start, int lenght);
char* stringConcat(char* str1, char* str2);

/*########### Implementazione ##############*/
int getFistIndex(char* str1, char* str2){
	int i,j;
	for (i = 0; i < strlen(str1); ++i)
	{
		j=0;
		while(str1[i+j]==str2[j]) j++;
		if(j==strlen(str2)) return i;
	}

	return -1;
}

char* getSubString(char* str,int start, int lenght){
	char ret[lenght];
	int i;

	for(i=0;i<lenght;i++)ret[i]=str[start+i];
	ret[lenght]='\0';
	return strdup(ret);
}

char* stringConcat(char* str1, char* str2){
	char ret[strlen(str1)+strlen(str2)];
	int i,j;
	for (i = 0; i < strlen(str1); ++i) ret[i]=str1[i];
	for (j = 0; j < strlen(str2); ++j) ret[i+j]=str2[j];
	ret[strlen(str1)+strlen(str2)]='\0';
	return strdup(ret);
}
#endif 