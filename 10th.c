#include <stdio.h>
#include <math.h>
void read(int p, int q, int a[p][q]);
void print(int p, int q, int a[p][q]);
void trace(int p, int q, int a[p][q]);
void norm(int p, int q, int a[p][q]);
int main()
{
    int m, n, r, s;
    printf("Enter the order of the matrix\n");
    scanf("%d %d", &m, &n);
    int a[m][n];
    printf("Enter elements of matrix\n");
    read(m, n, a);
    if (m != n)
    {
        printf("Trace can't be found\n");
    }
    else
    {
        trace(m, n, a);
    }
    norm(m, n, a);
    return 0;
}

void read(int p, int q, int a[p][q])
{
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
void print(int p, int q, int a[p][q])
{
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}
void trace(int p, int q, int a[p][q])
{
    int sum = 0;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            sum += a[i][j];
        }
    }
    printf("Trace is %d\n", sum);
}
void norm(int p, int q, int a[p][q])
{
    float s = 0.0;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            s += a[i][j] * a[i][j];
        }
    }
    s = sqrt(s);
    printf("Norm is %f\n", s);
}