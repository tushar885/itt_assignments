#include <stdio.h>
#include <stdlib.h>

struct matrix
{
    int **array;
    int rows;
    int columns;
};

struct matrix *input_matrix()
{

    struct matrix *matrix = (struct matrix *)malloc(sizeof(struct matrix));

    if (matrix == NULL)
    {
        printf("Memory couldn't be allocated!!!");
        return NULL;
    }

    printf("\nEnter the Matrix Size: ");

    int size = 0;
    printf("\nSize: ");
    scanf("%d", &size);

    if (size <= 0)
    {
        printf("Invalid Size Input!!!");
        return NULL;
    }

    matrix->rows = size;
    matrix->columns = size;

    matrix->array = (int **)calloc(matrix->rows, sizeof(int *));

    for (int row = 0; row < matrix->rows; row++)
    {
        matrix->array[row] = (int *)calloc(matrix->columns, sizeof(int));
    }

    printf("\n Enter elements: \n");

    for (int row = 0; row < matrix->rows; row++)
    {
        for (int column = 0; column < matrix->columns; column++)
        {
            scanf("%d", (*(matrix->array + row) + column));
        }
    }

    return matrix;
}

void free_matrix_memory(struct matrix *ptr)
{

    for (int i = 0; i < ptr->rows; i++)
    {
        free(ptr->array[i]);
    }

    free(ptr->array);
    free(ptr);
}

int calculate_trace(struct matrix *ptr)
{

    int trace = 0;

    for (int row = 0; row < ptr->rows; row++)
    {

        trace += ptr->array[row][row];
    }

    return trace;
}

int main()
{

    struct matrix *first_matrix = input_matrix();
    struct matrix *second_matrix = input_matrix();

    if (first_matrix == NULL || second_matrix == NULL)
        return 0;

    int first_matrix_trace = calculate_trace(first_matrix);
    int second_matrix_trace = calculate_trace(second_matrix);

    printf("\nTrace of first matrix: %d", first_matrix_trace);
    printf("\nTrace of second matrix: %d", second_matrix_trace);

    if (first_matrix_trace == second_matrix_trace)
    {
        printf("\nTrace of both matrix are equal");
    }
    else
        printf("\nTrace is not equal");

    free_matrix_memory(first_matrix);
    free_matrix_memory(second_matrix);

    return 0;
}
