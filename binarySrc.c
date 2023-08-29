// Binary search

#include <stdio.h>
int main()
{
    int n, a[10], key, beg, end, mid;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the key element to search: ");
    scanf("%d", &key);
    beg = 0;
    end = n - 1;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (key == a[mid])
        {
            printf("%d found at the position %d", key, mid + 1);
            break;
        }
        else if (key > a[mid])
            beg = mid + 1;
        else
            end = mid - 1;
    }
    if (beg > end)
        printf("%d is not found", key);
    return 0;
}
