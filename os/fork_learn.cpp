//
// Created by xuyou on 19-3-29.
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <linux/sched.h>
void forkexample()
{
    // child process because return value zero
    if (fork() == 0)
        printf("Hello from Child!\n");

        // parent process because return value non-zero.
    else
        printf("Hello from Parent!\n");
}
int main()
{
    forkexample();
    return 0;
}


