#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>


class SocketLogWriter
{
	private:
	FILE* log;
	
	public:
	 SocketLogWriter(char* path)
	 {
	 log = fopen(path,"w");
	 }

	char* Time()
	{
		char* time_buf;
		time_t now;
		time(&now);
		strftime(time_buf, 21, "%Y-%m-%dT%H:%S:%MZ", gmtime(&now));
		return time_buf;
    	
	}
	 
	 bool Write(char* stringa)
	 {
	 	if(log && stringa != NULL)
	 	{
	 		char* final = Time();
	 		final = strcat (final, "\t");
	 		final = strcat (final, stringa);
	 		final = strcat (final, "\n");
	 		return (fprintf (log, final)>0) ? true : false;
	 	}
	 	return false;
	 }
	 
	 ~SocketLogWriter()
	 {
	 	fclose(log);
	 }
};
