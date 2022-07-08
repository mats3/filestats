#ifndef FILESTATS_H
#define FILESTATS_H

#include"simptypes.h"

/* Return error Codes */
#define FILE_NOT_EXIST -1 /* for the count_lines function */

int filestats_file_count_lines(char *file_path); /* Returns the amount of lines of a File or FILE_NOT_EXIST when don't exist*/

#endif
