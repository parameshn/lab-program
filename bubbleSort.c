// “BUBBLE SORT”

#include <stdio.h>
int main()
{
    int a[10], n, i, j, temp;
    printf("enter the number of elements");
    scanf("% d", &n);
    printf("enter the elments");
    for (i = 0; i < n; i++)
    {
        scanf("% d", &a[i]);
    }
    for (i = 0; i < n -1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("the sorted elments are");
    for (i = 0; i < n; i++)
        printf("% d\t", a[i]);
    return 0;
}
