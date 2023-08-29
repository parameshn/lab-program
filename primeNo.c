// GEnerating prime number between n1 and n1

#include <stdio.h>
int main()
{
    int n1, n2, i, flag;
    printf("Enter start value:");
    scanf("%d", &n1);
    printf("Enter end value : ");
    scanf("%d", &n2);
    printf("Prime Numbers between %d and %d :", n2, n1);
    while (n1 < n2)
    {
        flag = 0;
        for (i = 2; i <= n1 / 2; ++i)
        {
            if (n1 % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            printf("%d\t", n1);
        ++n1;
    }
    return 0;
}
