#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prints an error message for memory allocation failure and exits the program.
 */
void Malloc_Error();

/**
 * @brief Prints an error message for file opening failure and exits the program.
 *
 * @param filename The name of the file that failed to open.
 */
void File_Open_Error(const char *filename);

/**
 * @brief Prints an error message for label length exceeding the defined limit and includes file name and line number.
 *
 * @param filename The name of the file where the error occurred.
 * @param line_num The line number where the label length error occurred.
 */
void Label_Length_Error(const char *filename, int line_num);

#endif 
