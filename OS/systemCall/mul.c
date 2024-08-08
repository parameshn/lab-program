#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define buffer_size 30

int main()
{
    int fd, n;
    char buffer[buffer_size];

    fd = open("input.txt", O_RDONLY);
    printf("File descriptor is %d\n", fd);

    if (fd == -1)
    {
        printf("Failed to open file\n");
        exit(0);
    }

    printf("Reading first 10 characters from file\n");
    n = read(fd, buffer, 10);
    write(1, buffer, n);

    printf("\nSkipping 5 characters from current position in the file\n");
    lseek(fd, 5, SEEK_CUR);
    n = read(fd, buffer, 10);
    write(1, buffer, n);

    printf("\nGoing to 5th last character in file\n");
    lseek(fd, -2, SEEK_END);
    n = read(fd, buffer, 1);
    write(1, buffer, n);

    printf("\nGoing to 3rd character in the file\n");
    lseek(fd, 3, SEEK_SET);
    n = read(fd, buffer, 1);
    write(1, buffer, n);

    printf("\n");

    return 0;
}
