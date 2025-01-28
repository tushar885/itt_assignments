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

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

int findNthOccurrence(struct Node *head, int target, int N)
{
    struct Node *current = head;
    int count = 0;
    int position = 1;

    while (current != NULL)
    {
        if (current->val == target)
        {
            count++;
            if (count == N)
            {
                return position;
            }
        }
        current = current->next;
        position++;
    }

    return -1;
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

    int target;
    scanf("%d", &target);

    int nthOccurence;
    scanf("%d", &nthOccurence);

    struct Node *head = createList(array, size);

    int result = findNthOccurrence(head, target, nthOccurence);

    if (result != -1)
    {
        printf("The %d-th occurrence of %d is at position: %d\n", nthOccurence, target, result);
    }
    else
    {
        printf("The %d-th occurrence of %d does not exist.\n", nthOccurence, target);
    }

    free(array);
    freeLinkedList(head);
    return 0;
}
