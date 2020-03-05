#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
void make(int d,int fd[])
{
  if(d>0)
  {
    pid_t p=fork();
    if(p==0)
    { int i;
      int u=read(fd[0],&i,sizeof(int));
      //printf("%d",i);
      ++i;
      printf("%d\n",i);
      write(fd[1],&i,sizeof(i));
      make(--d,fd);
       return; 
    }
    
  }
  else
  {
      int i;
      int u=read(fd[0],&i,sizeof(int));
      
      printf("num is%d\n",i);
      return;
  }
 }
int main()
{
    int d,n;
    printf("enter depth and num:");
    scanf("%d %d",&d,&n);
    int fd[2];
    
    
  
    if(pipe(fd)==-1)
    {
        printf("error");
        exit(1);
    }
    write(fd[1],&n,sizeof(int));
    make(d,fd);
    return 0;
 }
