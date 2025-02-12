#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct FreqNode
{
    int value;
    int freq;
};

int isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
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
    int iterator = 0;

    while (str[iterator] != '\0')
    {
        int sign = 1;
        if (str[iterator] == '-')
        {
            sign = -1;
            iterator++;
        }
        if (isDigit(str[iterator]))
        {
            int num = 0;
            while (isDigit(str[iterator]))
            {
                num = num * 10 + (str[iterator] - '0');
                iterator++;
            }
            (*array)[index++] = num * sign;
        }
        else
        {
            iterator++;
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

void countFrequencies(struct Node *head, struct FreqNode *freq, int *uniqueCount)
{
    struct Node *current = head;
    *uniqueCount = 0;

    while (current != NULL)
    {
        int value = current->val;
        int found = 0;

        for (int i = 0; i < *uniqueCount; i++)
        {
            if (freq[i].value == value)
            {
                freq[i].freq++;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            freq[*uniqueCount].value = value;
            freq[*uniqueCount].freq = 1;
            (*uniqueCount)++;
        }

        current = current->next;
    }
}

void sortFreqArray(struct FreqNode *freq, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            if (freq[j].freq > freq[j + 1].freq)
            {
                struct FreqNode temp = freq[j];
                freq[j] = freq[j + 1];
                freq[j + 1] = temp;
            }

            else if (freq[j].freq == freq[j + 1].freq &&
                     freq[j].value > freq[j + 1].value)
            {
                struct FreqNode temp = freq[j];
                freq[j] = freq[j + 1];
                freq[j + 1] = temp;
            }
        }
    }
}

void constructSortedList(struct Node *head, struct FreqNode *freq, int uniqueCount)
{
    struct Node *current = head;

    for (int i = 0; i < uniqueCount; i++)
    {
        int count = freq[i].freq;
        while (count > 0)
        {
            current->val = freq[i].value;
            current = current->next;
            count--;
        }
    }
}

void printLinkedList(struct Node *head)
{

    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
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

    struct FreqNode *freq = (struct FreqNode *)malloc(size * sizeof(struct FreqNode));
    int uniqueCount = 0;

    countFrequencies(head, freq, &uniqueCount);

    sortFreqArray(freq, uniqueCount);

    constructSortedList(head, freq, uniqueCount);

    printLinkedList(head);

    free(array);
    free(freq);
    freeLinkedList(head);
    return 0;
}
