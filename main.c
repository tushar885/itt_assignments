#include <stdio.h>
#include <stdlib.h>

void transpose_matrix(int *array, int size)
{

    for (int row = 0; row < size; row++)
    {
        for (int column = row; column < size; column++)
        {

            int temp = *(array + (row * size) + column);
            *(array + (row * size) + column) = *(array + (column * size) + row);
            *(array + (column * size) + row) = temp;
        }
    }
}

void reverse_matrix_by_rows(int *array, int size)
{

    for (int row = 0; row < size; row++)
    {

        int column_start = 0;
        int column_end = size - 1;

        while (column_start < column_end)
        {

            int temp = *(array + (row * size) + column_start);
            *(array + (row * size) + column_start) = *(array + (row * size) + column_end);
            *(array + (row * size) + column_end) = temp;

            column_end--;
            column_start++;
        }
    }
}

int main()
{

    printf("Enter the matrix size: ");
    int size;
    scanf("%d", &size);

    int *array = (int *)calloc(size * size, sizeof(int));

    printf("\n Enter elements: \n");
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            scanf("%d", array + ((row * size) + column));
        }
    }

    printf("Matrix is: \n");

    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            printf("%d ", *(array + ((row * size) + column)));
        }

        printf("\n");
    }

    transpose_matrix(array, size);
    reverse_matrix_by_rows(array, size);

    printf("Rotated Matrix is: \n");

    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            printf("%d ", *(array + ((row * size) + column)));
        }

        printf("\n");
    }

    free(array);

    return 0;
}