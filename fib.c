// Fibonacci numbers

#include <stdio.h>
void main()
{
    int n, first, second, third, term;
    printf("enter the limit\n");
    scanf("%d", &n);
    first = 0;
    second = 1;
    printf("the fibonacci series are\n");
    if (n == 1)
    {
        printf("%d", first);
    }
    else
    {
        printf("%d %d", first, second);
    }
    third = first + second;
    term = 2;
    while (term < n)
    {
        printf("%d\t", third);
        first = second;
        second = third;
        third = first + second;
        term++;
    }
}
