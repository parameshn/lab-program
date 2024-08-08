#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
int main()
{
    DIR *dp;
    char fn[2000];
    printf("Enetr the directory:");
    scanf("%s", fn);
    struct dirent *dirp;

    if ((dp = opendir(fn)) == NULL)
    {
        printf("\nCannot open directory %s!\n", fn);
        exit(1);
    }
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);
    closedir(dp);

    return 0;
}
