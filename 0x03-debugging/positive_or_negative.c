#include "main.h"
#include "stdlib.h"
#include "time.h"
#include "stdio.h"

/**
 * main - Determines if a number is positive, negative, or zero.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int n;
    int range = RAND_MAX / 2;

    srand(time(NULL));
    n = rand() % (range * 2 + 1) - range;

    if (n > 0)
    {
        printf("%d is positive\n", n);
    }
    else if (n == 0)
    {
        printf("%d is zero\n", n);
    }
    else
    {
        printf("%d is negative\n", n);
    }

    return 0;
}
