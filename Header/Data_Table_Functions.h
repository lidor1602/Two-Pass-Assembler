#ifndef DATA_TABLE_FUNCTIONS_H
#define DATA_TABLE_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Data.h"
#include "Table.h"

/**
 * @brief Check if a given 'temp' md_temp matches any labels in an array of 'mdefine' md_temps.
 *
 * This function checks if a given 'temp' md_temp matches any labels in an array of 'mdefine' md_temps.
 *
 * @param md_temp Pointer to the 'temp' structure to check.
 * @param mdefines Array of 'mdefine' structures.
 * @param define_counter Number of elements in the 'mdefines' array.
 * @return Returns 1 if a match is found, otherwise returns 0.
 */
int Temp_Equal_Label(const temp *md_temp, const mdefine *mdefines, int define_counter);

/**
 * @brief Move a 'temp' md_temp to an 'mdefine' md_temp in an array of 'mdefine' md_temps.
 *
 * This function moves a 'temp' md_temp to an 'mdefine' md_temp in an array of 'mdefine' md_temps.
 *
 * @param md_temp Pointer to the 'temp' structure to move.
 * @param mdefines Array of 'mdefine' structures.
 * @param define_counter Pointer to the number of elements in the 'mdefines' array.
 */
void Move_To_Mdefine(const temp *md_temp, mdefine *mdefines, int *define_counter);

/**
 * @brief Parse a line and extract a defined format, populating a 'temp' md_temp.
 *
 * This function parses a line and extracts a defined format, populating a 'temp' md_temp.
 *
 * @param line The input line to parse.
 * @param md_temp Pointer to the 'temp' structure to populate.
 * @return Returns 1 if parsing is successful, otherwise returns 0.
 */
int Define_Format(const char *line, temp *md_temp);

/**
 * @brief Allocate memory dynamically.
 *
 * This function allocates memory dynamically and handles any errors that may occur during allocation.
 *
 * @param object_size The size of the object to allocate memory for.
 * @return Returns a pointer to the allocated memory.
 */
void *handle_malloc(long object_size);

#endif
