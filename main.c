#include <stdio.h>

#define MAX_STRING_LENGTH 51

int is_vowel(char ch)
{
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') ? 1 : 0;
}

int string_length(char *string)
{

    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }

    return length;
}

void count_vowels_and_find_longest_word(int rows, int columns, char matrix[rows][columns][MAX_STRING_LENGTH])
{

    int words_with_vowel = 0, max_length = 0, coordinate_x = 0, coordinate_y = 0;

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("%s ", matrix[row][column]);
            if (is_vowel(matrix[row][column][0]))
            {
                words_with_vowel++;
            }
            int curr_length = string_length(matrix[row][column]);
            if (curr_length > max_length)
            {
                max_length = curr_length;
                coordinate_x = row;
                coordinate_y = column;
            }
        }
        printf("\n");
    }

    printf("Number of words starting with a vowel: %d\n", words_with_vowel);
    printf("Longest word: %s\n", matrix[coordinate_x][coordinate_y]);
}

int main()
{
    int rows, columns;
    printf("enter the rows: ");
    scanf("%d", &rows);
    printf("enter the columns: ");
    scanf("%d", &columns);

    if (rows <= 0 || columns <= 0)
    {
        printf("Invalid Input!!!");
        return 0;
    }

    char matrix[rows][columns][MAX_STRING_LENGTH];

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("Enter the element at (%d %d) : ", row, column);
            scanf("%s", matrix[row][column]);
        }
    }

    printf("\n");

    count_vowels_and_find_longest_word(rows, columns, matrix);

       return 0;
}