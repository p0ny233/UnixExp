#include <apue.h>

int main(void)
{
    printf("userid = %d \t groupid = %d\n", getuid(), getgid());
    exit(0);
}
