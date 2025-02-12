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
    if (array == NULL)
    {
        printf("Error in memory allocation");
        return;
    }
    int index = 0;
    int itr = 0;

    while (str[itr] != '\0')
    {
        int sign = 1;
        if (str[itr] == '-')
        {
            sign = -1;
            itr++;
        }
        if (isDigit(str[itr]))
        {
            int num = 0;
            while (isDigit(str[itr]))
            {
                num = num * 10 + (str[itr] - '0');
                itr++;
            }
            (*array)[index++] = num * sign;
        }
        else
        {
            itr++;
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

    for (int i = 1; i < size; i++)
    {
        current->next = createNode(array[i]);
        current = current->next;
    }

    return head;
}

void splitEvenIndexAndOddIndexLinkedList(struct Node *head, struct Node **oddHead, struct Node **evenHead)
{
    *oddHead = NULL;
    *evenHead = NULL;

    struct Node *oddTail = NULL;
    struct Node *evenTail = NULL;
    struct Node *current = head;
    int index = 1;

    while (current != NULL)
    {
        if (index % 2 == 0)
        {

            if (*evenHead == NULL)
            {
                *evenHead = current;
                evenTail = *evenHead;
            }
            else
            {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        }
        else
        {

            if (*oddHead == NULL)
            {
                *oddHead = current;
                oddTail = *oddHead;
            }
            else
            {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }

        current = current->next;
        index++;
    }

    if (evenTail != NULL)
    {
        evenTail->next = NULL;
    }
    if (oddTail != NULL)
    {
        oddTail->next = NULL;
    }
}

struct Node *findMinNode(struct Node *start)
{
    struct Node *minNode = start;
    struct Node *current = start->next;

    while (current != NULL)
    {
        if (current->val < minNode->val)
        {
            minNode = current;
        }
        current = current->next;
    }

    return minNode;
}

struct Node *findMaxNode(struct Node *start)
{
    struct Node *maxNode = start;
    struct Node *current = start->next;

    while (current != NULL)
    {
        if (current->val > maxNode->val)
        {
            maxNode = current;
        }
        current = current->next;
    }

    return maxNode;
}

void swapNodes(struct Node *node1, struct Node *node2)
{
    int temp = node1->val;
    node1->val = node2->val;
    node2->val = temp;
}

void ascendingSortLinkedList(struct Node **head)
{
    struct Node *current = *head;

    while (current != NULL)
    {
        struct Node *minNode = findMinNode(current);

        if (minNode != current)
        {
            swapNodes(current, minNode);
        }

        current = current->next;
    }
}

void descendingSortLinkedList(struct Node **head)
{
    struct Node *current = *head;

    while (current != NULL)
    {
        struct Node *maxNode = findMaxNode(current);

        if (maxNode != current)
        {
            swapNodes(current, maxNode);
        }

        current = current->next;
    }
}

void mergeLinkedList(struct Node **head, struct Node *oddHead, struct Node *evenHead)
{
    if (oddHead == NULL)
    {
        *head = evenHead;
        return;
    }
    if (evenHead == NULL)
    {
        *head = oddHead;
        return;
    }

    struct Node *mergedHead = NULL;
    struct Node *mergedTail = NULL;

    mergedHead = oddHead;
    mergedTail = oddHead;
    oddHead = oddHead->next;

    while (oddHead != NULL || evenHead != NULL)
    {
        if (evenHead != NULL)
        {
            mergedTail->next = evenHead;
            mergedTail = evenHead;
            evenHead = evenHead->next;
        }

        if (oddHead != NULL)
        {
            mergedTail->next = oddHead;
            mergedTail = oddHead;
            oddHead = oddHead->next;
        }
    }
    mergedTail->next = NULL;
    *head = mergedHead;
}
void printLinkedList(struct Node *head)
{

    while (head = NULL)
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

    struct Node *oddHead;
    struct Node *evenHead;

    splitEvenIndexAndOddIndexLinkedList(head, &oddHead, &evenHead);

    ascendingSortLinkedList(&oddHead);
    descendingSortLinkedList(&evenHead);

    mergeLinkedList(&head, evenHead, oddHead);

    printLinkedList(head);

    free(array);
    freeLinkedList(head);
    return 0;
}
