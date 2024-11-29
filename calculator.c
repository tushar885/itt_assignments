#include <stdio.h>
#include <string.h>
int operands_st[200];
int od_top = -1;
int operators_st[100];
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

int precedence(char op1, char op2)
{
    int precedence1, precedence2;
    switch (op1)
    {
    case '+':
    case '-':
        precedence1 = 1;
        break;
    case '*':
    case '/':
        precedence1 = 2;
        break;
    default:
        return -1;
    }
    switch (op2)
    {
    case '+':
    case '-':
        precedence2 = 1;
        break;
    case '*':
    case '/':
        precedence2 = 2;
        break;
    default:
        return -1;
    }
    if (precedence1 == precedence2)
        return 0;
    return (precedence1 > precedence2) ? 1 : -1;
}

int calculate()
{
    int op2 = operands_st[od_top--];
    int op1 = operands_st[od_top--];
    char op = operators_st[op_top--];

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

int parse_expression(char exp[])
{
    int all_empty = 1;
    int i = 0;
    int expect_operand = 1;

    while (i < strlen(exp))
    {
        if (exp[i] == ' ')
        {
            i++;
            continue;
        }

        if (exp[i] == '-' && expect_operand)
        {

            if (i + 1 < strlen(exp) && isOperand(exp[i + 1]))
            {
                int num = 0;
                int sign = -1;
                i++;

                while (i < strlen(exp) && isOperand(exp[i]))
                {
                    num = num * 10 + (exp[i] - '0');
                    i++;
                }

                operands_st[++od_top] = sign * num;
                expect_operand = 0;
                continue;
            }
        }

        if (isOperand(exp[i]))
        {
            if (all_empty)
                all_empty = 0;
            int num = 0;
            while (i < strlen(exp) && isOperand(exp[i]))
            {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            operands_st[++od_top] = num;
            expect_operand = 0;
        }
        else if (isOperator(exp[i]))
        {

            if (expect_operand && exp[i] != '-')
            {
                return -1;
            }

            if (i + 1 == strlen(exp) || (isOperator(exp[i + 1]) && exp[i + 1] != '-'))
            {
                return -1;
            }

            while (op_top != -1 && precedence(exp[i], operators_st[op_top]) <= 0)
            {
                int result = calculate();
                if (result == -2)
                {
                    return -2;
                }
                operands_st[++od_top] = result;
            }
            operators_st[++op_top] = exp[i];
            expect_operand = 1;
            i++;
        }
        else
        {
            return -1;
        }
    }

    while (op_top != -1)
    {
        int result = calculate();
        if (result == -2)
        {
            return -2;
        }
        operands_st[++od_top] = result;
    }

    if (all_empty)
        return -3;
    return 0;
}

int main()
{
    char str[200];
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin))
    {
        str[strcspn(str, "\n")] = 0;
    }
    size_t len = strlen(str);
    if (len == 0)
    {
        printf("You entered an empty string\n");
        return 0;
    }

    int result = parse_expression(str);
    if (result == -1)
    {
        printf("Error: Invalid expression\n");
    }
    else if (result == -2)
    {
        printf("Error: Division by zero\n");
    }
    else if (result == -3)
    {
        printf("Error: Empty expression\n");
    }
    else
    {
        printf("Result: %d\n", operands_st[od_top]);
    }
    return 0;
}