#include "apue.h"
#include <dirent.h>
#include <error.c>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;
    if( argc != 2)
    {
        err_quit("usage: ls dirname");
    }
    
    if( dp = opendir(argv[1]))
    {
        err_sys("can't open %s\n", argv[1]);

    }
    while(dirp = readdir(dp))
    {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    exit(0);
}
