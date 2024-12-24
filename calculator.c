#include <stdio.h>
#include <string.h>

#define MAX 300

int operands_st[MAX];
int od_top = -1;
int operators_st[MAX];
int op_top = -1;

int isOperand(char ch)
{
    if (ch >= '0' && ch <= '9')
    {
        return 1;
    }
    return 0;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int calculate(char op)
{
    int op2 = operands_st[od_top--];
    int op1 = operands_st[od_top--];

    switch (op)
    {
    case '+':
        return op1 + op2;
    case '-':
        return op1 - op2;
    case '*':
        return op1 * op2;
    case '/':
        if (op2 == 0)
            return -2;
        return op1 / op2;
    }

    return 0;
}

int infix_to_postfix_conversion(char infix[], char postfix[])
{

    int i, j;
    i = j = 0;

    int expecting_operand = 1;

    while (i < strlen(infix))
    {

        if (infix[i] == ' ')
        {
            i++;
            continue;
        }

        if (isOperand(infix[i]) || (infix[i] == '-' && isOperand(infix[i + 1]) && expecting_operand))
        {

            if (!expecting_operand)
                return -1;

            int isNegative = 1;
            if (infix[i] == '-')
            {
                isNegative = -1;
                i++;
            }

            int operand = 0;
            while (isOperand(infix[i]))
            {
                operand = operand * 10 + (infix[i] - '0');
                i++;
            }

            operand *= isNegative;

            if (operand < 0)
            {
                postfix[j] = '-';
                j++;
                operand = -operand;
            }

            char buffer[12];
            int len = 0;

            do
            {
                buffer[len] = (operand % 10) + '0';
                operand /= 10;
                len++;
            } while (operand > 0);

            for (int k = len - 1; k > -1; k--)
            {
                postfix[j] = buffer[k];
                j++;
            }

            postfix[j] = ' ';
            j++;

            expecting_operand = 0;
        }
        else if (isOperator(infix[i]))
        {

            if (expecting_operand)
                return -1;

            while (op_top != -1 && precedence(operators_st[op_top]) >= precedence(infix[i]))
            {

                postfix[j++] = operators_st[op_top--];
                postfix[j++] = ' ';
            }

            operators_st[++op_top] = infix[i++];

            expecting_operand = 1;
        }
        else
        {
            return -1;
        }
    }

    if (expecting_operand)
        return -1;

    while (op_top != -1)
    {
        postfix[j++] = operators_st[op_top--];
        postfix[j++] = ' ';
    }

    postfix[j] = '\0';
    return 1;
}

int parse_expression(char exp[])
{
    int i = 0;

    while (i < strlen(exp))
    {

        if (isOperand(exp[i]) || (exp[i] == '-' && isOperand(exp[i + 1])))
        {

            int operand = 0, isNeg = 1;
            if (exp[i] == '-')
            {
                isNeg = -1;
                i++;
            }
            while (isOperand(exp[i]))
            {
                operand = operand * 10 + (exp[i] - '0');
                i++;
            }

            operand *= isNeg;

            operands_st[++od_top] = operand;
        }
        else if (isOperator(exp[i]))
        {

            if (od_top < 1)
                return -1;

            int result = calculate(exp[i]);

            if (result == -2)
                return result;

            operands_st[++od_top] = result;

            i++;
        }
        else
            i++;
    }
    return operands_st[od_top--];
}

int main()
{
    char infix[MAX];
    char postfix[MAX];

    printf("Enter a string: ");

    scanf("%299[^\n]%*c", infix);
    size_t len = strlen(infix);
    if (len == 0)
    {
        printf("You entered an empty string\n");
        return 0;
    }

    int result = infix_to_postfix_conversion(infix, postfix);

    if (result == -1)
    {
        printf("Error: Invalid Expression");
        return 0;
    }

    printf("Postfix Expression is: %s\n", postfix);

    result = parse_expression(postfix);
    if (result == -1)
    {
        printf("Error: Invalid expression\n");
    }
    else if (result == -2)
    {
        printf("Error: Division by zero\n");
    }
    else
    {
        printf("Result: %d\n", result);
    }
    return 0;
}