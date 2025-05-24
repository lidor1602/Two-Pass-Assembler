#ifndef TEXT_FUNCTIONS_H
#define TEXT_FUNCTIONS_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Checks if a line is a comment.
 *
 * This function checks if the given line is a comment by examining the first non-space/tab character.
 *
 * @param line The line to check.
 * @return Returns 1 if the line is a comment, otherwise returns 0.
 */
int Check_For_Comment(char *line);

/**
 * @brief Checks if a line contains a specific flag.
 *
 * This function checks if the given line contains a specific flag.
 *
 * @param line The line to check.
 * @param flag The flag to search for in the line.
 * @return Returns 1 if the flag is found in the line, otherwise returns 0.
 */
int Flag_Check(const char *line, const char *flag);

#endif 
