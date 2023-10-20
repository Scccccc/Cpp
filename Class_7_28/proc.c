#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    printf("I am process, pid: %d, ppid %d\n", getpid(), getppid());
    pid_t id = fork();
    if(id == 0)
    {
        //child
        while(1)
        {
            printf("I am child, pid: %d, ppid: %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    else if(id > 0)
    {
        //father
        while(1)
        {
            printf("I am father, pid:%d, ppid: %d\n", getpid(), getppid());
            sleep(1);
        }
    }
    else
    {
        //err
        perror("worng\n");
    }
   //while(1)
   // {
   //     printf("I am process, My PID is:%d -- PPID is: %d\n", getpid(), getppid());
   //     sleep(1);
   // }
    return 0;
}
