#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Error_Functions.h"
#include "Data.h"
#include "Table.h"



int Temp_Equal_Label(const temp *md_temp, const mdefine *mdefines, int define_counter) /*Function to check if a given 'temp' md_temp matches any labels in an array of 'mdefine' md_temps*/
{
    int i;
    for (i = 0; i < define_counter; i++) 
    {
        if (strcmp(md_temp->label, mdefines[i].label) == 0) /*Compare the label of the 'temp' md_temp with the label of the current 'mdefine' md_temp*/
        {
            return 1;  /*Match found*/
        }
    }
    return 0; 
}

void Move_To_Mdefine(const temp *md_temp, mdefine *mdefines, int *define_counter) /*Function to move a 'temp' md_temp to an 'mdefine' md_temp in an array of 'mdefine' md_temps*/
{
    mdefines[*define_counter].value = md_temp->value;
    strcpy(mdefines[*define_counter].label, md_temp->label);
}

int Define_Format(const char *line, temp *md_temp) /* Function to parse a line and extract a defined format, populating a 'temp' md_temp */
{
    const char *pattern = ".define";
    char word[MAX_LABEL_LENGTH];
    int integer = 0, wordLength = 0, foundDefine = 0, foundWord = 0, foundInteger = 0;

    while (*line && wordLength < MAX_LABEL_LENGTH) 
    {
        if (!isspace(*line)) 
        {
            if (!foundDefine && strncmp(line, pattern, strlen(pattern)) == 0) /* Check if the '.define' pattern is found */
            {
                line += strlen(pattern);
                foundDefine = 1;
                continue;
            }
            if (foundDefine && !foundWord && isalpha(*line)) /* Check if the pattern was found and a word has not been found yet, and the character is alphabetic */
            {
                while (isalnum(*line) || *line == '_') 
                {
                    if (wordLength < MAX_LABEL_LENGTH) 
                    {
                        word[wordLength++] = *line++;
                    }
                    else 
                    {                        
                        break;  /* Word exceeds max length */
                    }
                }
                word[wordLength] = '\0';
                foundWord = 1;
                continue;
            }
            if (foundDefine && foundWord && *line == '=') /* Check if the pattern and word have been found, and the current character is '=' */
            {
                line++;
                while (*line && isspace(*line)) 
                {
                    line++;
                }
                if (*line && isdigit(*line)) /* Check if there's a digit after the '=' character */
                {
                    integer = atoi(line);
                    foundInteger = 1;
                }
                break;
            }
            line++;
        }
    }
    
    if (foundDefine && foundWord && foundInteger) /* Check if the pattern, word, and integer were all found successfully */
    {
        md_temp->value = integer;
        strcpy(md_temp->label, word);
        return 1;  /* Parsing successful */
    } 
    else /* Set default values if parsing fails */
    {
        md_temp->value = 0; 
        md_temp->label[0] = '\0'; 
        return 0; 
    }
}


void *handle_malloc(long object_size)
{
    void *resize;
    resize = malloc(object_size);
    if (resize == NULL)
    {
        Malloc_Error();
    }
    return resize;
}
