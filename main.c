#include <stdio.h>
#include <stdlib.h>

int string_length(char *string)
{
    int size = 0;
    while (string[size] != '\0')
        size++;

    return size;
}

int compute_frequency(char *string, char frequency_char)
{

    int len = string_length(string);
    int frq = 0;
    for (int iterator = 0; iterator < len; iterator++)
    {
        if (string[iterator] == frequency_char)
            frq++;
    }

    return frq;
}

int main()
{

    int size;
    printf("Enter the length of string array: ");
    scanf("%d", &size);

    char **string_array = (char **)malloc(size * sizeof(char *));

    for (int i = 0; i < size; i++)
    {

        string_array[i] = (char *)malloc(50 * sizeof(char));
        scanf("%s%*c", string_array[i]);
    }

    char input_char;
    printf("\nEnter the Character to count occurrences for: ");
    scanf(" %c", &input_char);

    int max_freq = 0;
    int max_freq_string_index = -1;

    for (int i = 0; i < size; i++)
    {

        int freq = compute_frequency(string_array[i], input_char);
        if (freq > max_freq)
        {
            max_freq = freq;
            max_freq_string_index = i;
        }
    }

    if (max_freq_string_index == -1)
    {
        printf("\nCharacter %c is not in any string.", input_char);
    }
    else
    {

        printf("Maximum Frequency is : %d, and in string: %s", max_freq, string_array[max_freq_string_index]);
    }

    return 0;
}