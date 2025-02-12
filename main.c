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
    if (array == NULL)
    {
        printf("Error in memory allocation");
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

int hasCycle(struct Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return 1;
        }
    }

    return 0;
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

struct Node *createList(int *arr, int size, int pos)
{
    if (size == 0)
        return NULL;

    struct Node *head = createNode(arr[0]);
    struct Node *current = head;
    struct Node *cycleNode = NULL;

    for (int iterator = 1; iterator < size; iterator++)
    {
        current->next = createNode(arr[iterator]);
        current = current->next;

        if (iterator == pos)
        {
            cycleNode = current;
        }
    }

    if (pos != -1)
    {
        current->next = cycleNode;
    }

    return head;
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

    int position;
    scanf("%d", &position);

    struct Node *head = createList(array, size, position);

    if (hasCycle(head))
    {
        printf("Cycle detected\n");
    }
    else
    {
        printf("No cycle detected\n");
    }

    free(array);
    freeLinkedList(head);

    return 0;
}
