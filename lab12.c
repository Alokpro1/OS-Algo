#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void main()
{
  int dg,n,i,j;
  printf("enter degree and depth:");
  scanf("%d %d",&dg,&n);
 
   make(dg,n);
 
 }
  
  void make(int dg,int n)
  {if(n>=0)
  { int i;
   printf("parent id:%d",getpid());
  //intf("pid:%d\n",getpid());
  
     pid_t p1=fork();
     printf("child pid p1:%d  ",p1);
     if(p1>0){
     for(i=0;i<dg-1;++i)
     {
      pid_t p2=fork();
       printf("child pid p2:%d\n---------\n",p2);}}
     else{
     --n;
       make(dg,n);
     }
 }
 
 
 }

 
  
