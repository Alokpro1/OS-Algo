#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <malloc.h>


int flag[2]={0,0};
int turn=1;
int balance=100;
void d()
{
    int i,j,k;
    for(i=0;i<100000;++i)
    { 
      for(j=0;j<100000;++j)
        {
         for(j=0;j<100000;++j)
            {
            }
         }
        }
 }
void * thr(void *q)
{
   
   int p=(int)q;
   int x;
   if(p==0)
      x=1;
   else
      x=0;
   do{
   flag[p]=1;
   turn=x;
    while(flag[x] && turn==x)
     {printf("blocked thread%d\n",p);
     d();
    }
    //critical section;
        printf("critical section....%d\n",p);
    d();
    //end critical section
    flag[p]=0;
    printf("out of critical section%d\n",p);
    d();
    }while(1);      
}


int main()
{
    printf("main executing:\n");
    pthread_t thread[2];
    int t,re;
    t=0;
    re=pthread_create(&thread[t],NULL,thr,(void *)t);
    printf("thread1 created.............\n");
    if(re)
    {
            printf("error");
            exit(-1);
    }
    t=1;
    re=pthread_create(&thread[t],NULL,thr,(void *)t);
    printf("thread2 created.............\n");
    if(re)
    {
            printf("error");
            exit(-1);
    }
    
    pthread_join(thread[0],NULL);
    pthread_join(thread[1],NULL);
    
}
