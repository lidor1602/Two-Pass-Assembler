#include <stdio.h>
#include <stdlib.h>

void Malloc_Error()
{
    fprintf(stderr, "Memory allocation failed. Exiting program.\n");
    exit(EXIT_FAILURE);
}

void File_Open_Error(const char *filename)
{
    perror(filename);
    exit(EXIT_FAILURE);
}

void Label_Length_Error(const char *filename, int line_num)
{
    fprintf(stderr, "%s , line number %d , Label length is bigger than define.\n", filename, line_num);
}

