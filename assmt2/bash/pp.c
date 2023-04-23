#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <pwd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <time.h>
#include <time.h>
#include <sys/syscall.h>

#define SYS_kernel2Dcopy 451

int main()
{
    float mtrx1[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mtrx1[i][j] = 1;
        }
    }
    float mtrx2[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    printf("Initial Matrix 2: \n");

    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 3; b++)
        {
            printf("%f\t", mtrx2[a][b]);
        }
        printf("\n");
    }

    int res = syscall(SYS_kernel2Dcopy, mtrx1, mtrx2, 3, 3);

    if (res != 0)
    {
        printf("Error Occured while copying!\n");
        return -1;
    }

    printf("Final Matrix2: \n") for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mtrx2[i][j] = 1;
        }
        printf("\n");
    }
    return 0;
}