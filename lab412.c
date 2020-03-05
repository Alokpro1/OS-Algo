#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
void main()
{
  printf("%d",getpid());
  
  int i;
  for(i=0;i<4;++i)
    printf("hello %d\n",i);
    
    
    }
