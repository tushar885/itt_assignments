#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

int isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
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
    if (array == NULL)
    {
        printf("Error in memory allocaiton");
        return;
    }
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
        printf("Error in memory allocaiton");
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

    for (int i = 1; i < size; i++)
    {
        current->next = createNode(array[i]);
        current = current->next;
    }

    return head;
}

struct Node *partition(struct Node *head, struct Node **left, struct Node **right)
{
    struct Node *pivot = head;
    struct Node *current = head->next;

    struct Node *leftTail = NULL, *rightTail = NULL;

    while (current)
    {
        struct Node *next = current->next;
        if (current->val < pivot->val)
        {
            if (*left == NULL)
            {
                *left = current;
                leftTail = current;
            }
            else
            {
                leftTail->next = current;
                leftTail = current;
            }
        }
        else
        {
            if (*right == NULL)
            {
                *right = current;
                rightTail = current;
            }
            else
            {
                rightTail->next = current;
                rightTail = current;
            }
        }
        current->next = NULL;
        current = next;
    }
    if (leftTail)
        leftTail->next = NULL;
    if (rightTail)
        rightTail->next = NULL;

    return pivot;
}

struct Node *quickSort(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *left = NULL, *right = NULL;
    struct Node *pivot = partition(head, &left, &right);

    left = quickSort(left);
    right = quickSort(right);

    if (left)
    {
        struct Node *temp = left;
        while (temp->next)
            temp = temp->next;
        temp->next = pivot;
    }
    else
    {
        left = pivot;
    }
    pivot->next = right;

    return left;
}

void printLinkedList(struct Node *head)
{

    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
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

    struct Node *head = createList(array, size);

    head = quickSort(head);

    printLinkedList(head);

    free(array);
    freeLinkedList(head);
    return 0;
}
