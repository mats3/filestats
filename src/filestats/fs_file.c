#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>

#include"simptypes.h"

int filestats_file_count_lines(char *file_path)
{
	FILE *file = fopen(file_path, "r"); /* open file with read access */

	/* check if file Exists */
	if (file == NULL)
	{
		printf("----\n"
			   "File: %s\n"
			   "Error: File does not exist's\n"
			   "----\n",
			   file_path);

		return -1; /* FILE_NOT_EXIST */
	}

	/* counters for Stats */
	uint amount_lines = 0; /* counter for file lienes */
	uint amount_characters = 0;
	uint amount_spaces = 0;

	uchar32 character;
	while ((character = fgetc(file)) != EOF)
	{
		if (character == '\n')
		{
			amount_lines++;
		}

		if (character == ' ')
			amount_spaces++;

		amount_characters++;
	}

	/* print the file stats */
	printf("----\n"
		   "File: %s\n"
		   "lines: %d\n"
		   "characters: %d\n"
		   "spaces: %d\n"
		   "characters without spaces: %d\n"
		   "----\n",
		   file_path,
		   amount_lines,
		   amount_characters,
		   amount_spaces,
		   amount_characters - amount_spaces);

	fclose(file); /* close the file */

	return amount_lines;
}
