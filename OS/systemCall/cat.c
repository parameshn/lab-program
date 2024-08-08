
// simulate CAT cmd (VIEW only)
#include <stdio.h>
#include <stdlib.h>
void main()
{
    FILE *fp;
    char ch;
    char fn[200];
    // if (argc < 2)
    // {
    //     printf("File not entered");
    //     exit(1);
    // }
    printf("Enter the file name:");
    scanf("%s", fn);
    fp = fopen(fn, "r");
    if (fp == NULL)
    {
        printf("File does not exist\n");
        exit(1);
    }
    while ((ch = fgetc(fp)) != EOF)
        printf("%c", ch);
    fclose(fp);
    printf("\n");
}