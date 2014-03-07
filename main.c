// TO COMPLE: clear; gcc main.c -o main
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
	if(CheckIfExist("404.html")) printf("trovato\n");
		else printf("non trovato\n");
	return 0;
}

int CheckIfExist(char* page){
	DIR *dp;
	struct dirent *ep;     
	dp = opendir ("./www");

	if (dp != NULL)
	{
		while (ep = readdir (dp))
			if(strcmp(ep->d_name,page)==0)return 1;

		closedir(dp);
	}
	return 0;
}