#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define DAILYNOTEBUFFER 32

int main(int argc, char* argv[]) {

	if (argc <= 1) {
		fprintf(stdout, "usage:\tjournal -e <entry>\n");
		return -1;
	}

	time_t t = time(0);
	struct tm *current = localtime(&t);

	char daily_file_name[DAILYNOTEBUFFER];
	int var = snprintf(daily_file_name, DAILYNOTEBUFFER,
			"/home/kana/bin/JE-%02d-%02d-%d.md", (int)current->tm_mday,
			current->tm_mon+1, current->tm_year + 1900);

	// adding an entry option; 
	if ((strcmp(argv[1],"-e") == 0) && (argc > 2)) {
		FILE * dfnptr = fopen(daily_file_name, "a");
		fprintf(dfnptr, "### %d:%d:%02d\n", current->tm_hour, current->tm_min, current->tm_sec);
		for (int i = 2; i < argc; i++)
			fprintf(dfnptr, "%s ", argv[i]);
		fprintf(dfnptr, "\n");
		return 1;
	} 

	return 0;
}
