#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
   pid_t p,q;
   int n,fd[2];
   char line[900];
   if(pipe(fd)==0)
   {
    printf("pipe created\n");
    }
    p=fork();
    q=fork();
    if(p==0)
    {
      dup2(fd[1],1);
      execl("/bin/ls","ls","-l",NULL);
      }
      else{ wait(0);
    
      if(q==0)
      {
       //int n=read(fd[0],line,900);
       //line[n]='\n';
       dup2(fd[0],0);
       execl("/bin/wc","wc","-l",line,NULL);
       //puts(line);
       }
       }
      return 0;
      
      }
      
