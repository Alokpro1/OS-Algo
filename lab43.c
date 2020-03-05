#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
void main()
{
    int i=0;
    pid_t p=fork();
    //printf("parentsd %d\n",getpid());
    if(p==-1)
    {
        printf("error");
    }
    else if(p==0)
    {   printf("child %d\n",getpid());
        execl("/home/administrator/117cs0222/ex.out","./ex.out","7",NULL);
        printf("child %d",getpid());
    }
    
    

    
}
