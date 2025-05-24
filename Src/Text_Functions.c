#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int Check_For_Comment(char *line)
{
    int i = 0;
    while (line[i] == ' ' || line[i] == '\t') /*Skip leading spaces and tabs*/
    {
        i++;
    }    
    if (line[i] == ';') /*Check if the first non-space/tab character is a semicolon*/
    {
        return 1;  
    }
    return 0;  /*Line is not a comment*/
}

int Flag_Check(const char *line, const char *flag)
{
    if (strstr(line, flag) != NULL)
    {
        return 1;   /*Flag found*/
    } else
    {
        return 0;  
    }
}
