#include <stdio.h>
#include <stdlib.h>

int string_length(char *string)
{
    int size = 0;
    while (string[size] != '\0')
        size++;

    return size;
}

int is_sub_string(char *sub_string, char *super_string)
{
    int sub_string_length = string_length(sub_string);
    int super_string_length = string_length(super_string);

    for (int super_string_index = 0; super_string_index <= super_string_length - sub_string_length; super_string_index++)
    {
        int sub_string_index;
        for (sub_string_index = 0; sub_string_index < sub_string_length; sub_string_index++)
        {
            if (super_string[super_string_index + sub_string_index] != sub_string[sub_string_index])
                break;
        }

        if (sub_string_index == sub_string_length)
            return 1;
    }

    return 0;
}

void free_dynamic_memory(char **string_array, int size)
{

    for (int index = 0; index < size; index++)
    {
        free(string_array[index]);
    }

    free(string_array);
}

int main()
{

    int size;
    printf("Enter the length of string array: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid Input!!!");
        return 0;
    }

    char **string_array = (char **)malloc(size * sizeof(char *));

    if (string_array == NULL)
    {
        printf("Error in Memory Allocation");
        return 0;
    }

    printf("\nEnter the strings of array: \n");
    for (int index = 0; index < size; index++)
    {

        string_array[index] = (char *)malloc(50 * sizeof(char));
        scanf("%s%*c", string_array[index]);
    }

    char sub_string_input[50];
    printf("\nEnter the String to check for as substring: ");
    scanf("%s", sub_string_input);

    int found_super_string = 0;

    for (int index = 0; index < size; index++)
    {

        if (is_sub_string(sub_string_input, string_array[index]) == 1)
        {
            found_super_string = 1;
            printf("\n%s", string_array[index]);
        }
    }

    if (found_super_string == 0)
    {
        printf("\nNo Match Found!!!");
    }

    free_dynamic_memory(string_array, size);

    return 0;
}