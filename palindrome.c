// palindrome

#include <stdio.h>
int main()
{
    int n, rem, revno, orno;
    printf("enter the number\n");
    scanf("%d", &n);
    orno = n;
    revno = 0;
    while (n != 0)
    {
        rem = n % 10;
        revno = (revno * 10) + rem;
        n = n / 10;
    }
    if (orno == revno)
        printf("%d is a palindrome number", orno);
    else
        printf("%d is not a palindrome number", orno);
    return 0;
}