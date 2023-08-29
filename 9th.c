// Add and Sub

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n, p, q, i, j;

    printf("Enter the row and column size of first matrix\n");
    scanf("%d %d", &m, &n);
    printf("Enter the row and column size of second matrix\n");
    scanf("%d %d", &p, &q);
    if (m != p || n != q)
    {
        return 1;
    }
    int a[m][n], b[p][q], sum[m][n], sub[m][n];
    printf("Enter the first matrix elements\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the second matrix elements\n");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    printf("The first matrix is\n ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    printf("The second matrix is\n ");
    for (i = 0; i < p; i++)
    {
        for (j = 0; j < q; j++)
        {
            printf("%d", b[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            sub[i][j] = a[i][j] - b[i][j];
        }
    }
    printf("The sum of the matrices is\n ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d", sum[i][j]);
        }
        printf("\n");
    }
    printf("The difference of the matrices is\n ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d", sub[i][j]);
        }
        printf("\n");
    }
    return 0;
}
