#include"filestats/filestats.h"

#include<stdio.h>

int main(int argc, char **argv)
{
	/* check for enough arguments */
	if (argc < 2)
	{
		printf("please give me some arguments!!!\n");
		return 0;
	}

	/* 
	 * loop for all arguments without the first one,
	 * because its the file Name.
	 * argv++ -> ++ does that.
	 */
	void *end;
	for (end = argv++ + argc; argv != end; argv++)
		filestats_file_count_lines(*argv); /* gets the lines of the file */

	return 0;
}
