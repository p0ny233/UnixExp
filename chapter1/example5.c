#include <apue.h>
#include <error.c>
#include <sys/wait.h>
int main(void)
{
    char buf[MAXLINE] = {0};
    pid_t pid;
    int status;
    while(fgets(buf, MAXLINE, stdin))
    {
        if(buf[strlen(buf) + 1 ] == '\n')
        {   
            buf[strlen(buf)] = 0;

        //pid = fork();
        //printf("pid from %ld\n", (long)pid);

            if((pid = fork()) < 0)
                err_sys("fork error");
            else if(pid == 0)
            {
                execlp(buf, buf, (char*)0);
                err_ret("coudn't execute: %s", buf);
                exit(127);
            }



        }

        if((pid = waitpid(pid, &status, 0)) < 0)
        {
            err_sys("waitpid error");
        }
        printf("%% ");

    }
    exit(0);
}
