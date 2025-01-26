#include <stdio.h>
#include <stdlib.h>

int string_length(char *string)
{
    int size = 0;
    while (string[size] != '\0')
        size++;

    return size;
}

int compute_frequency(char *string, char target_char)
{

    int length = string_length(string);
    int target_char_freq = 0;
    for (int iterator = 0; iterator < length; iterator++)
    {
        if (string[iterator] == target_char)
            target_char_freq++;
    }

    return target_char_freq;
}

void free_dynamic_memory(char **string_array, int size)
{

    for (int itr = 0; itr < size; itr++)
    {
        free(string_array[itr]);
    }

    free(string_array);
}

void string_with_max_freq(char **string_array, int size, char target_char)
{

    int max_freq = 0;
    int max_freq_string_index = -1;

    for (int i = 0; i < size; i++)
    {

        int freq = compute_frequency(string_array[i], target_char);
        if (freq > max_freq)
        {
            max_freq = freq;
            max_freq_string_index = i;
        }
    }

    if (max_freq_string_index == -1)
    {
        printf("\nCharacter %c is not in any string.", target_char);
    }
    else
    {

        printf("Maximum Frequency is : %d, and in string: %s", max_freq, string_array[max_freq_string_index]);
    }
}

int main()
{

    int size;
    printf("Enter the length of string array: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid Length Input!!!");
        return 0;
    }

    char **string_array = (char **)malloc(size * sizeof(char *));
    printf("\nEnter the Strings: \n");
    for (int i = 0; i < size; i++)
    {

        string_array[i] = (char *)malloc(50 * sizeof(char));
        scanf("%s", string_array[i]);
    }

    char input_char;
    printf("\nEnter the Character to count occurrences for: ");
    scanf(" %c", &input_char);

    string_with_max_freq(string_array, size, input_char);

    free_dynamic_memory(string_array, size);

    return 0;
}