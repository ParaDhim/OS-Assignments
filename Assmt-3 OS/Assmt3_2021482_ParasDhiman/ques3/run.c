#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>

#define __NR_print_info 451

int main(){
	syscall(__NR_print_info, 1);
	return 0;

}
