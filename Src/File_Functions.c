#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Data.h"
#include "Error_Functions.h"


int New_File() /*Creates a new temporary file named "Temp_1.txt".*/
{
    FILE *temp_File;
    temp_File = fopen("Temp_1.txt","w"); 
    if (temp_File == NULL)
    {
        File_Open_Error("Temp_1.txt");
    }
    fclose(temp_File);
    return 0;
}

char* Name_Creating(char *file_name, char *dot_file) /*Takes a file name and a dot file extension, and returns a new file name with the dot file extension appended*/
{
    char *new_file_name, *dot_position;
    new_file_name = malloc(MAX_LINE_LENGTH);
    if (new_file_name == NULL)
    {
        Malloc_Error();         
    }
    strcpy(new_file_name, file_name);
    dot_position = strchr(new_file_name, '.');      
    if (dot_position != NULL)
    {
        *dot_position = '\0';  
    }
    strcat(new_file_name, dot_file);
    return new_file_name;
}

void Rename_File(const char *old_name, const char *new_name)  /*Renames a file from the old name to the new name*/
{
    if (rename(old_name, new_name) == 0)
    {
        return;
    }
    else
    {
        perror("Error renaming file");                
    }    
}

void Write_File(const char *filename, char *content) /*Writes the content to a file*/
{
    FILE *fp;
    fp=fopen(filename, "w");
    if (fp == NULL)
    {
        File_Open_Error("Temp_1.txt");
    }
    fprintf(fp, "%s\n", content);
    fclose(fp);    
}
void Delete_File(const char *filename) /*Deletes a file*/
{
    if (remove(filename) == 0) 
    {
        printf("File '%s' deleted successfully.\n", filename);
    } 
    else 
    {
        perror("Error deleting file");
    }
}
void Copy_File(const char *file_from, const char *file_to) /*Copies the content of one file to another file.*/
{
    FILE *to, *from;
    char words;
    from = fopen(file_from, "r");
    if (from == NULL)
    {
        File_Open_Error(file_from);
    }
    to = fopen(file_to, "w");
    if (to == NULL)
    {
        fclose(from);
        File_Open_Error(file_to);
    }    
    while ((words = fgetc(from)) != EOF)
    {
        fputc(words, to);
    }
    fclose(from);
    fclose(to);
}

/*They create new files with specific extensions (.as and .am, respectively) and return the file names.*/

char* As_Creation(int argc, char *argv[])
{
    char *filename;
    New_File();
    filename = Name_Creating(argv[argc], ".as");
    Rename_File("Temp_1.txt", filename);
    Write_File(filename, argv[argc]);
    printf("As_file created successfully\n");    
    return(filename);
}

char* Am_Creation(int argc, char *argv[])
{
    char *filename;     
    filename = Name_Creating(argv[argc], ".am");
    Rename_File("am_test", filename);    
    printf("Am_file created successfully\n");  
    return(filename);
}