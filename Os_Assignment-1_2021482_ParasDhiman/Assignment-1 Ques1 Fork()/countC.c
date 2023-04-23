#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <pwd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_SIZE_CMD 4294967296
#define MAX_SIZE_ARG 16

typedef long long int ll;

ll loop_count = 4294967296;

#define handle_error_en(en,mssg)\
do { errno = en; perror(msg); exit(EXIT_FAILURE); } while(0)


void main()
{
for (ll i = 0; i < loop_count; i++)
{

}
exit(0);

}