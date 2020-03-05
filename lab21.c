#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void make(int dg,int n,int i,int a[],int k)
  {
    
     a[k]=getpid();
     if(i>=n)
     {
      int p=0;
      for(p=0;p<i;++p)
      {
        printf("%d ",a[p]);
      }
      printf("\n");
      return;
      }
     int j;
     for(j=0;j<dg;++j)
     {
        pid_t p=fork();
        
        waitpid(p,0,0);
        if(p==0)
        {
           make(dg+1,n,i+1,a,k+1);
           return;
        }
       
     }

 }
 
void main()
{
  int dg=1,n,i=1;
  printf("enter  depth:");
  scanf("%d",&n);
  int a[100];
 
   make(1,n,1,a,0);
 
}  


