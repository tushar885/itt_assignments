#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

int isDigit(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return 1;
    }
    return 0;
}

void inputStringToArray(int **array, int *size)
{
    char string[1000];
    scanf("%[^\n]%*c", string);
    int i = 0;
    *size = 0;

    while (string[i] != '\0')
    {
        if (string[i] == ' ')
        {
            (*size)++;
            i++;
            continue;
        }
        i++;
    }
    *size = *size + 1;

    *array = malloc(*size * sizeof(int));
    int index = 0;
    i = 0;

    while (string[i] != '\0')
    {
        int sign = 1;
        if (string[i] == '-')
        {
            sign = -1;
            i++;
        }
        if (isDigit(string[i]))
        {
            int num = 0;
            while (isDigit(string[i]))
            {
                num = num * 10 + (string[i] - '0');
                i++;
            }
            (*array)[index++] = num * sign;
        }
        else
        {
            i++;
        }
    }
}

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Error in memory allocation");
        return newNode;
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct Node *createList(int *array, int size)
{
    if (size == 0)
        return NULL;
    struct Node *head = createNode(array[0]);
    struct Node *current = head;

    for (int iterator = 1; iterator < size; iterator++)
    {
        current->next = createNode(array[iterator]);
        current = current->next;
    }

    return head;
}

int canDistribute(struct Node *head, int noOfChildren, int targetCandies)
{
    int children = 0;

    while (head != NULL)
    {
        children += head->val / targetCandies;
        head = head->next;
    }

    return children >= noOfChildren;
}

int maximumCandies(struct Node *head, int noOfChildren)
{
    int left = 1, right = 0;

    struct Node *current = head;
    while (current != NULL)
    {
        if (current->val > right)
        {
            right = current->val;
        }
        current = current->next;
    }

    int result = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (canDistribute(head, noOfChildren, mid))
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return result;
}

void freeLinkedList(struct Node *head)
{

    struct Node *temp = head;
    while (head != NULL)
    {

        temp = head;
        head = head->next;
        free(temp);
        temp = NULL;
    }
}

int main()
{

    int *array;
    int size;

    inputStringToArray(&array, &size);

    int noOfChildren;
    scanf("%d", &noOfChildren);

    struct Node *head = createList(array, size);

    int result = maximumCandies(head, noOfChildren);

    printf("%d\n", result);

    free(array);
    freeLinkedList(head);

    return 0;
}
