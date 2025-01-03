#include <stdio.h>

int modularExponentiation(int base, int exponent, int mod)
{
    int result = 1;
    base = base % mod;

    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % mod;
        }
        exponent = exponent / 2;
        base = (base * base) % mod;
    }

    return result;
}

int main()
{
    int base, exponent, mod;

    printf("Enter the base: ");
    scanf("%d", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    printf("Enter the modulo: ");
    scanf("%d", &mod);

    if (mod <= 0)
    {
        printf("Invalid modulo! Modulo should be greater than 0.\n");
        return 1;
    }

    int result = modularExponentiation(base, exponent, mod);

    printf("%d^%d %% %d = %d\n", base, exponent, mod, result);

    return 0;
}