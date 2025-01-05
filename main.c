#include <stdio.h>
#include <stdlib.h>

void matrix_spiral_traversal(int *array, int rows, int columns)
{

    int row_start = 0;
    int row_end = rows - 1;
    int column_start = 0;
    int column_end = columns - 1;

    while (row_start <= row_end && column_start <= column_end)
    {

        for (int i = column_start; i <= column_end; i++)
        {
            printf("%d ", *((array + (row_start * columns) + i)));
        }
        row_start++;

        for (int i = row_start; i <= row_end; i++)
        {
            printf("%d ", *((array + (i * columns) + column_end)));
        }
        column_end--;

        if (row_start <= row_end)
        {
            for (int i = column_end; i >= column_start; i--)
            {
                printf("%d ", *((array + (row_end * columns) + i)));
            }
            row_end--;
        }

        if (column_start <= column_end)
        {

            for (int i = row_end; i >= row_start; i--)
            {
                printf("%d ", *((array + (i * columns) + column_start)));
            }
            column_start++;
        }
    }
}

int main()
{

    int rows, columns;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    int *array = (int *)calloc(rows * columns, sizeof(int));

    printf("\nEnter Elements: \n");

    for (int itr = 0; itr < rows; itr++)
    {
        for (int iitr = 0; iitr < columns; iitr++)
        {

            scanf("%d", array + ((itr * columns) + iitr));
        }
    }
    printf("\n Spiral Traverse of Matrix is: \n");
    matrix_spiral_traversal(array, rows, columns);

    free(array);
    return 0;
}