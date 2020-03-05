#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <malloc.h>
#include <semaphore.h>
sem_t chop[5];

delay()
{
  int i,j;
  for(i=0;i<1000000;++i)
   {
    for(j=0;j<1000;j++)
    {
      }
      }
}
void * thr(void * p)
{
  int q=(int)p;
  do
  {
  if(q%2==0)
  {
    printf("philosopher%d is willing to  enter\n",q);
    delay();
    sem_wait(&chop[(q+1)%5]);
    sem_wait(&chop[q]);
    ////////////////////////////////
    printf("philosopher%d is in critical section\n",q);
    delay();
    //////////////////////////////////
    sem_post(&chop[q]);
    sem_post(&chop[(q+1)%5]);
 
    printf("philosopher%d is outside section\n",q);
    delay();
    }
    else
    {
    
    printf("philosopher%d is willing to  enter\n",q);
    delay();
    sem_wait(&chop[q]);
    sem_wait(&chop[(q+1)%5]);
    //critical section
    printf("philosopher%d is in critical section\n",q);
    delay();
    //////////////////////
    sem_post(&chop[(q+1)%5]);
    sem_post(&chop[q]);
    
    printf("philosopher%d is outside section\n",q);
    delay();
    }
   }while(1);
   }
main()
{
  
  int i;
  for(i=0;i<5;++i)
  {
  sem_init(&chop[i],0,1);
  }
  pthread_t thread[5];
  
   int t,re;
    t=0;
    for(t=0;t<5;++t)
    {
    re=pthread_create(&thread[t],NULL,thr,(void *)t);
    printf("thread%d created.............\n",t);
    if(re)
    {
            printf("error");
            exit(-1);
    }
    }
    
    for(t=0;t<5;++t)
    {
    pthread_join(thread[t],NULL);
    }
}
