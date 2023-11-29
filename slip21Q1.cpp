/*
Q.1 Write a C Program to create a child process using fork (), display parent and
child process id. Child process will display the message “I am Child Process”
and the parent process should display “I am Parent Process”.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{

    pid_t pid = fork();

    if(pid==0)
    {
        printf("I am the child process %d" , getpid());
    }
    else if(pid >0)
    {
        printf("I am the parent process %d ",getpid());
    }
    else {
        printf("No process created");
    }
    return 0;
}
