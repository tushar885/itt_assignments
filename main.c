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
    char str[1000];
    scanf("%[^\n]%*c", str);
    int i = 0;
    *size = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ')
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

    while (str[i] != '\0')
    {
        int sign = 1;
        if (str[i] == '-')
        {
            sign = -1;
            i++;
        }
        if (isDigit(str[i]))
        {
            int num = 0;
            while (isDigit(str[i]))
            {
                num = num * 10 + (str[i] - '0');
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

    for (int i = 1; i < size; i++)
    {
        current->next = createNode(arr[i]);
        current = current->next;

        if (i == pos)
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
    }
}

int main()
{
    int *array;
    int size;

    inputStringToArray(&array, &size);

    int pos;
    scanf("%d", &pos);

    struct Node *head = createList(array, size, pos);

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
