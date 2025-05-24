#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data.h"
#include "Error_Functions.h"
#include "File_Functions.h"
#include "PreAssembler.h"

int Check_For_Macro(const char *srce,const char *flag) /* Checks if a specific flag (macro) exists in a file and returns 1 if it occurs exactly once, 0 otherwise. */
{
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int mcr_found = 0;
    
    fp = fopen(srce, "r");
    if (!fp)
    {
        File_Open_Error(srce);
    }
    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, flag) != NULL) 
        {
            mcr_found = 1;
        }
    }
    fclose(fp);    
    return mcr_found;
}

void Macro_Copy(const char *srce, const char *dest) /* Copies content from one file to another until it encounters a specific macro ("mcr") and stops copying after encountering its end ("endmcr") */
{
    FILE *fp, *fp1;
    char line[MAX_LINE_LENGTH];
    int flagFound = 0, copy = 0;

    fp = fopen(srce, "r");
    if (!fp)
    {
        File_Open_Error(srce);
    }
    fp1 = fopen(dest, "w");
    if (!fp1)
    {
        fclose(fp);
        File_Open_Error(dest);
    }
    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, "mcr") != NULL && !flagFound && !copy) /* Check for start of macro block */
        {
            flagFound = 1;
            fprintf(fp1, "%s", line);
        }
        else if (flagFound)
        {
            fprintf(fp1, "%s", line);
            if (strstr(line, "endmcr") != NULL) /* Check for end of macro block */
            {
                flagFound = 0;
                copy = 1;
            }
        }
    }    
    fclose(fp);
    fclose(fp1);    
}

void Remove_Lines(const char *dest) /* Removes the first and last lines from a file and saves the modified content to a temporary file */
{
    FILE *fp, *temp;
    char line[MAX_LINE_LENGTH];
    int line_count = 0;

    fp = fopen(dest, "r");
    if (!fp)
    {
        File_Open_Error(dest);
    }    
    New_File();
    temp = fopen("Temp_1.txt", "w");
    if (!temp)
    {
        File_Open_Error("Temp_1.txt");
    }
    while (fgets(line, sizeof(line), fp))
    {        
        line_count++;
        if (line_count != 1 && !feof(fp)) /* Skip first and last lines*/
        {
            fputs(line, temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove(dest);
    rename("Temp_1.txt", dest);
}

void Macro_Delete(const char *srce) /* Deletes a block of lines between "mcr" and "endmcr" from a file */
{
    FILE *fp, *temp;
    char line[MAX_LINE_LENGTH];
    int inside_block  = 0, block_deleted = 0;

    fp = fopen(srce, "r");
    if (!fp)
    {
        File_Open_Error(srce);
    }    
    New_File();
    temp = fopen("Temp_1.txt", "w");
    if (!temp)
    {
        File_Open_Error("Temp_1.txt");
    }    
    while (fgets(line, sizeof(line), fp)) 
    {        
        if (strstr(line, "mcr") != NULL && !inside_block && !block_deleted) /* Check if line contains "mcr" */
        {
            inside_block = 1; 
        }
        else if (strstr(line, "endmcr") != NULL) /* Check if line contains "endmcr" */
        {
            inside_block = 0; 
            block_deleted = 1; 
        }        
        else if (!inside_block)
        {
            fputs(line, temp); /* Write non-flagged lines to temp file */
        }
    }
    fclose(fp);
    fclose(temp);    
    remove(srce);
    rename("Temp_1.txt", srce);    
}

char *Get_Flag(const char *srce) /* Retrieves the next word after "mcr" from a line in a file and returns it as a dynamically allocated string */
{
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *flag = NULL;
    char *token;
    int found_flag = 0;
    flag = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    if (flag == NULL)
    {
        free(flag);
        Malloc_Error();        
    }    
    fp = fopen(srce, "r");
    if (!fp)
    {
        free(flag);
        File_Open_Error(srce);
    }
    while (fgets(line, sizeof(line), fp))
    {
        if (strstr(line, "mcr") != NULL && !found_flag) 
        {
            found_flag = 1;
            token = strtok(line, " "); /* Tokenize the line using space as delimiter */
            while (token != NULL) {
                if (strcmp(token, "mcr") == 0) 
                {
                    token = strtok(NULL, " "); 
                    if (token != NULL)
                    {
                        if (flag != NULL) 
                        {
                            strcpy(flag, token); /* Copy the next word into the allocated memory */
                            break; 
                        }
                    }
                }
                token = strtok(NULL, " ");
            }
            break; /* Exit the loop after finding and processing "mcr" once */
        }
    }
    fclose(fp);
    return flag; 
}

int Find_Flag(const char *srce, const char *flag) /* Searches for a specific flag in a file and returns the line number if found, otherwise returns 0 */
{
    FILE *fp;
    char line[MAX_LINE_LENGTH];    
    int line_count = 0;

    fp = fopen(srce, "r");
    if (!fp)
    {
        File_Open_Error(srce);
    }
    while (fgets(line, sizeof(line), fp)) 
    {
        line_count++;
        if (strstr(line, flag) != NULL) 
        {
            fclose(fp);
            return line_count; /* Return line number if flag is found */
        }
    }
    fclose(fp);
    return 0; 
}

void Macro_Paste(const char *srce, const char *dest, int location) /* Pastes content from one file into another file at a specified location, replacing a line at that location */
{
    FILE *fp, *temp, *macro;
    char line[MAX_LINE_LENGTH];
    char content;
    int current_line = 0;

    fp = fopen(srce, "r");
    if (!fp)
    {
        File_Open_Error(srce);
    }
    New_File();
    temp = fopen("Temp_1.txt", "w");
    if (!temp)
    {
        File_Open_Error("Temp_1.txt");
    }
    macro = fopen(dest, "r");
    if (!macro) 
    {
        fclose(fp);
        fclose(temp);
        File_Open_Error(dest);        
    }
    while (fgets(line, sizeof(line), fp)) 
    {
        current_line++;
        if (current_line == location)  /* Skip the line to be deleted */
        {
            continue;
        }
        fprintf(temp, "%s", line);

        if (current_line == location - 1)
        {           
            while ((content = fgetc(macro)) != EOF)
            {
                fputc(content, temp);
            }
            fprintf(temp, "\n"); 
        }
    }
    fclose(fp);
    fclose(temp);
    fclose(macro);
    remove(srce);
    rename("Temp_1.txt", srce);
}

void PreAssembler(const char *filename) /* Handles preprocessing operations like copying, renaming, and processing macros in source files */
{
    char *srce  = "am_test", *dest = "Macro", *flag = NULL;
    int result = 0, line_num = 0;

    New_File();
    Copy_File(filename, "Temp_1.txt");
    Rename_File("Temp_1.txt", "am_test");
    New_File();
    Rename_File("Temp_1.txt", "Macro");

    while ((result = Check_For_Macro(srce, "mcr")) == 1)
    {
        flag = Get_Flag(srce);
        if (flag == NULL)
        {
            free(flag);
            Malloc_Error();
        }
        Macro_Copy(srce, dest);
        Remove_Lines(dest);
        Macro_Delete(srce);
        while ((result = Check_For_Macro(srce, flag)) == 1)
        {
            line_num = Find_Flag(srce, flag);            
            Macro_Paste(srce, dest, line_num);
        }
        free(flag); 
        flag = NULL;         
    }
    if (result == -1)
    {
        free(flag);
        printf("Error opening file am_test.\n the program will stop now.\n");
        exit(1);
    }    
}