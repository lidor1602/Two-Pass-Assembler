#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Creates a new file.
 *
 * This function creates a new file with the specified name.
 *
 * @return Returns 0 if the file is successfully created, otherwise returns -1.
 */
int New_File();

/**
 * @brief Creates a new file name by combining the provided base name and file extension.
 *
 * This function creates a new file name by combining the provided base name and file extension.
 *
 * @param file_name The base name of the file.
 * @param dot_file The file extension.
 *
 * @return Returns a pointer to the newly created file name.
 */
char* Name_Creating(char *file_name, char *dot_file);

/**
 * @brief Renames a file.
 *
 * This function renames a file from the old name to the new name.
 *
 * @param old_name The original name of the file.
 * @param new_name The new name of the file.
 */
void Rename_File(const char *old_name, const char *new_name);

/**
 * @brief Writes content to a file.
 *
 * This function writes the provided content to the specified file.
 *
 * @param filename The name of the file to write to.
 * @param content The content to be written to the file.
 */
void Write_File(const char *filename, char *content);

/**
 * @brief Deletes a file.
 *
 * This function deletes the specified file.
 *
 * @param filename The name of the file to be deleted.
 */
void Delete_File(const char *filename);

/**
 * @brief Copies a file.
 *
 * This function copies a file from the source file to the destination file.
 *
 * @param file_from The source file to be copied.
 * @param file_to The destination file to which the source file will be copied.
 */
void Copy_File(const char *file_from, const char *file_to);

/**
 * @brief Creates a new assembly file (.as).
 *
 * This function creates a new assembly file with the provided arguments and returns the file name.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 *
 * @return Returns a pointer to the newly created assembly file name.
 */
char* As_Creation(int argc, char *argv[]);

/**
 * @brief Creates a new machine code file (.am).
 *
 * This function creates a new machine code file with the provided arguments and returns the file name.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 *
 * @return Returns a pointer to the newly created machine code file name.
 */
char* Am_Creation(int argc, char *argv[]);

#endif 


/*
void Confirmation (int result)   
{
    if (result == 0)
    {
        printf("File created successfully.\n");
    }
    else
    {
        printf("Failed to create file.\n");
    }
}
*/

