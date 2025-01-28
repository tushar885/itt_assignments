#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int val;
    struct Node *next;
};

struct FreqNode
{
    int val;
    int freq;
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
            if (freq[i].val == value)
            {
                freq[i].freq++;
                found = 1;
                break;
            }
        }

        if (!found)
        {
            freq[*uniqueCount].val = value;
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
                     freq[j].val > freq[j + 1].val)
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
            current->val = freq[i].val;
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
