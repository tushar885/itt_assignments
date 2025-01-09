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

    struct matrix *m = (struct matrix *)malloc(sizeof(struct matrix));

    printf("\nEnter the Matrix Size: ");

    int size = 0;
    printf("\nSize: ");
    scanf("%d", &size);

    m->rows = size;
    m->columns = size;

    m->array = (int **)calloc(m->rows, sizeof(int *));

    for (int i = 0; i < m->rows; i++)
    {
        m->array[i] = (int *)calloc(m->columns, sizeof(int));
    }

    printf("\n Enter elements: \n");

    for (int i = 0; i < m->rows; i++)
    {
        for (int j = 0; j < m->columns; j++)
        {
            scanf("%d", (*(m->array + i) + j));
        }
    }

    return m;
}

int free_matrix_memory(struct matrix *ptr)
{

    for (int i = 0; i < ptr->rows; i++)
    {
        free(ptr->array[i]);
    }

    free(ptr->array);
    free(ptr);
    return 0;
}

int calculate_trace(struct matrix *ptr)
{

    int trace = 0;

    for (int i = 0; i < ptr->rows; i++)
    {

        trace += ptr->array[i][i];
    }

    return trace;
}

int main()
{

    struct matrix *first_m = input_matrix();
    struct matrix *second_m = input_matrix();

    int first_m_trace = calculate_trace(first_m);
    int second_m_trace = calculate_trace(second_m);

    printf("\nTrace of first matrix: %d", first_m_trace);
    printf("\nTrace of second matrix: %d", second_m_trace);

    if (first_m_trace == second_m_trace)
    {
        printf("\nTrace of both matrix are equal");
    }
    else
        printf("\nTrace is not equal");

    free_matrix_memory(first_m);
    free_matrix_memory(second_m);

    return 0;
}
