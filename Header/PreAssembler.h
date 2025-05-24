#ifndef PREASSEMBLER_H
#define PREASSEMBLER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Pre-assembles a given source file.
 *
 * This function pre-assembles the given source file.
 *
 * @param filename The name of the source file to be pre-assembled.
 */
void PreAssembler(const char *filename);

/**
 * @brief Checks if a macro is present in the source code.
 *
 * This function checks if a macro is present in the source code.
 *
 * @param srce The source code to be checked.
 * @param flag The macro to be searched for.
 *
 * @return Returns 1 if the macro is found, 0 otherwise.
 */
int Check_For_Macro(const char *srce, const char *flag);

/**
 * @brief Copies a macro from the source code to the destination.
 *
 * This function copies a macro from the source code to the destination.
 *
 * @param srce The source code containing the macro to be copied.
 * @param dest The destination where the macro will be copied.
 */
void Macro_Copy(const char *srce, const char *dest);

/**
 * @brief Removes lines from the destination.
 *
 * This function removes lines from the destination.
 *
 * @param dest The destination where the lines will be removed.
 */
void Remove_Lines(const char *dest);

/**
 * @brief Deletes a macro from the source code.
 *
 * This function deletes a macro from the source code.
 *
 * @param srce The source code containing the macro to be deleted.
 */
void Macro_Delete(const char *srce);

/**
 * @brief Gets the flag from the source code.
 *
 * This function gets the flag from the source code.
 *
 * @param srce The source code containing the flag to be retrieved.
 *
 * @return Returns a pointer to the flag in the source code.
 */
char *Get_Flag(const char *srce);

/**
 * @brief Finds a flag in the source code.
 *
 * This function finds a flag in the source code.
 *
 * @param srce The source code to be searched.
 * @param flag The flag to be searched for.
 *
 * @return Returns the location of the flag in the source code.
 */
int Find_Flag(const char *srce, const char *flag);

/**
 * @brief Pastes a macro into the destination at a specific location.
 *
 * This function pastes a macro into the destination at a specific location.
 *
 * @param srce The source code containing the macro to be pasted.
 * @param dest The destination where the macro will be pasted.
 * @param location The location where the macro will be pasted.
 */
void Macro_Paste(const char *srce, const char *dest, int location);

#endif