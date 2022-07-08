#include"filestats/filestats.h"

#include<stdio.h>

int main(int argc, char **argv)
{
	uint total_lines = 0; /* store the total of lines for all files */

	/* 
	 * loop for all arguments without the first one,
	 * because its the file Name.
	 * argv++ -> ++ does that.
	 */
	void *end;
	for (end = argv++ + argc; argv != end; argv++)
	{
		int lines = filestats_file_count_lines(*argv); /* gets the lines of the file */
		
		if (lines == FILE_NOT_EXIST)
		{
			printf("--File: %s\nerror: %s", *argv, "File don't exist's");
		} else
		{
			total_lines += lines; /* add the lines to the total lines */
			printf("--File: %s\nlines: %d\n\n", *argv, lines); /* print the Filename and the lines of the File */
		}
	}

	printf("Total Lines: %d\n", total_lines); /* printout the total lines from all files */

	return 0;
}
