#include <stdio.h>
#include <stdlib.h>

int string_length(char *string)
{
    int size = 0;
    while (string[size] != '\0')
        size++;

    return size;
}

int isSubstring(char *substring, char *superstring)
{
    int len_sub = string_length(substring);
    int len_super = string_length(superstring);

    for (int i = 0; i <= len_super - len_sub; i++)
    {
        int j;
        for (j = 0; j < len_sub; j++)
        {
            if (superstring[i + j] != substring[j])
                break;
        }

        if (j == len_sub)
            return 1;
    }

    return 0;
}

void free_dynamic_memory(char **string_array, int size)
{

    for (int itr = 0; itr < size; itr++)
    {
        free(string_array[itr]);
    }

    free(string_array);
}

int main()
{

    int size;
    printf("Enter the length of string array: ");
    scanf("%d", &size);

    char **string_array = (char **)malloc(size * sizeof(char *));
    printf("\nEnter the strings of array: \n");
    for (int i = 0; i < size; i++)
    {

        string_array[i] = (char *)malloc(50 * sizeof(char));
        scanf("%s%*c", string_array[i]);
    }

    char string_to_check_for[50];
    printf("\nEnter the String to check for as substring: ");
    scanf("%s%*c", string_to_check_for);

    int found_super_string = 0;

    for (int itr = 0; itr < size; itr++)
    {

        if (isSubstring(string_to_check_for, string_array[itr]) == 1)
        {
            found_super_string = 1;
            printf("\n%s", string_array[itr]);
        }
    }

    if (found_super_string == 0)
    {
        printf("\nNo Match Found!!!");
    }

    free_dynamic_memory(string_array, size);

    return 0;
}