#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{

  int fd[2],n;
  char l[20];
  pid_t p;
  
  if(pipe(fd)==-1)
  {
    printf("error");
    exit(1);
  }
  p=fork();
  if(p<0)
  {
    printf("error");
    exit(1);
  }
  else if(p>0)
  { //char g[5]=(char)p;
   write(fd[1],"Hi child\n",9);
   pid =p;
   
   //write(fd[1],&pid,sizeof(int));
   waitpid(p,0,0);
   
   n=read(fd[0],l,20);
   printf("recieved msg to %d->%s",getpid(),l);
   
   }
   else
   {
    n=read(fd[0],l,20);
    
    int x;
    n=read(fd[0],&x,sizeof(int));
    printf("recieved msg to >%s %d\n",l,x);
    write(fd[1],"Hi parent:\n",10);
    
   }  
 return 0;
 }
