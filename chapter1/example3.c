#include <apue.h>
#include <error.c>
int main()
{
    int c;

    while((c = getc(stdin)) != EOF)
    {
        if(putc(c, stdout) == EOF)
        {
            err_sys("out error");
        }
    }

    if(ferror(stdin))
    {
        err_sys("read error");
    }
    
}
