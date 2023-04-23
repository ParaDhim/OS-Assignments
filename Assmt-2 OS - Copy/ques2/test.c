#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>

#define SYS_kernel2Dcopy 451


#include <linux/syscalls.h>
#include <linux/types.h>
#include <linux/sched.h>

#define print_info 451

SYSCALL_DEFINE1(print_info, pid_t, pid)
{
struct task_struct *task;
tsk = pid_task(find_vpid(pid),PIDTYPE_PID);

printf("%d :pid\n",task->pid);
printf("%d :user_id\n",task->cred->uid.val);
printf("%d :pgid\n",task->group_leader->pid);
printf("%s : command path\n",task->comm);

return 0;
}

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