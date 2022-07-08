#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#include"simptypes.h"
#include"internal.h"

int filestats_file_count_lines(char *file_path)
{
	FILE *file = fopen(file_path, "r"); /* open file with read access */

	/* check if file Exists */
	if (file == NULL)
	{
		fprintf(stderr, "File [%s] don't exist's\n", file_path);
		return -1; /* FILE_NOT_EXIST */
	}

	/* count the lines of the File */
	uint amountLines = 0; /* counter for file lienes */

	uchar32 character;
	while ((character = fgetc(file)) != EOF)
	{
		if (character == '\n')
			amountLines++;
	}

	fclose(file); /* close the file */

	return amountLines;
}
