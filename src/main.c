#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define BUFFERSIZE 500
#define DAILYNOTEBUFFER 15
#define TOKENSIZE 2

int main(int argc, char* argv[]) {

	FILE *reminder_csv_ptr = fopen("rem.csv","r");
	if (reminder_csv_ptr == NULL) {
		fprintf(stderr, "file not found\n");
		return -1;
	}

	time_t t = time(0);
	struct tm *current = localtime(&t);
	fprintf(stdout, "current local time and date: %s\n", asctime(current));

	char buffer[BUFFERSIZE];
	char *token;
	char *date_token;

	char *token_arr[TOKENSIZE];
	int date_token_arr[2];

	// delim: <date>,<name>
	char *delim = ",";
	// delim: dd-mm-yyyy
	char *date_delim = "-";

	int field_counter = 0;
	int date_field_counter = 0;

	int day, month;

	char daily_file_name[DAILYNOTEBUFFER];
	int var = snprintf(daily_file_name, DAILYNOTEBUFFER,
			"%d-%d-%d.md",(int)current->tm_mday,current->tm_mon+1,current->tm_year + 1900);

	while (fgets(buffer, BUFFERSIZE, reminder_csv_ptr) != NULL ) {
		token = strtok(buffer, delim);
		while (token != NULL) {
			token_arr[field_counter] = token;
			token = strtok(NULL, delim);
			field_counter++;
		}

		// token_arr[0] is going to the day in dd-mm-yyyy
		// format we need to split this and compare the 
		// dates; kinda of a hassle.
		date_token = strtok(token_arr[0], date_delim);	
		while (date_token != NULL) {
			date_token_arr[date_field_counter] = atoi(date_token);
			date_token = strtok(NULL, date_delim);
			date_field_counter++;
		}

		// reset the field counter
		field_counter = 0;
		date_field_counter = 0;

		// checking the dates with the current date and
		// create a file and append information to the file
		if ((current->tm_mday == date_token_arr[0]) && 
				(current->tm_mon == date_token_arr[1] - 1)) {
			FILE *daily_tracker = fopen(daily_file_name, "w");
			fprintf(daily_tracker, "- [ ] %s", token_arr[1]);
			fclose(daily_tracker);
		}
	}

	fclose(reminder_csv_ptr);


	return 0;
}
