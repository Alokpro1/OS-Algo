#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void main()
{
  int i=5;
  int *ptr;
  pid_t p=fork();
  *ptr=&i;
  if(p==-1)
  {
    perror("fork");
    exit(1);
  }
  if(p>0)
  {
     
     
     for(;i<10;++i)
     {
     printf("This is parent ID:%d and value of i:%d\n",getpid(),i);
     }
     
     
     
     
     
     
  
  }
  else{
    for(;i<12;++i)
     {
     printf("This is child ID:%d and value of i:%d\n",getpid(),i);
     }
     
     
     printf("This is child ID:%d and value of i:%d\n",getpid(),i);
   }
   
   printf("This is  ID:%d and value of i:%d\n",getpid(),i);
}
