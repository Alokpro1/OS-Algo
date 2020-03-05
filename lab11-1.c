#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <malloc.h>
#include <semaphore.h>

sem_t mutex,wsem;

int rdcount=0;

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
void * reader(void * p)
{
  int q=(int)p;
  do
  {
  printf("reader%d is interested\n",q);
    sem_wait(&mutex);
    rdcount++;
    if(rdcount==1)
        sem_wait(&wsem);
    sem_post(&mutex);
    /////////////////////////
    
    printf("reader%d is reading\n",q);
    delay();
    
    /////////////////////////
    sem_wait(&mutex);
      rdcount--;
      if(rdcount==0)
         sem_post(&wsem);
    sem_post(&mutex);
    printf("reader%d has read\n",q);
    delay();
  }while(1);
}
void * writer(void * p)
{
  int q=(int)p;
  do
  {
      printf("writer%d is interested\n",q);
     sem_wait(&wsem);
     /////////////////
      
      printf("writer %d is writing\n",q);
      delay();
     ////////////////
     sem_post(&wsem);
     printf("writer %d has written\n",q);
     delay();
  }while(1);
}

main()
{
  
  int i;
  
  sem_init(&mutex,0,1);
  sem_init(&wsem,0,1);
  
  pthread_t thread[6];
  pthread_t thread2[4];
  
   int t,re;
    t=0;
    for(t=0;t<3;++t)
    {
    re=pthread_create(&thread[t],NULL,reader,(void *)t);
    printf("thread reader%d created.............\n",t);
    if(re)
    {
            printf("error");
            exit(-1);
    }
    }
    //---------------------------------------------------------------
    
    for(t=0;t<4;++t)
    {
    re=pthread_create(&thread2[t],NULL,writer,(void *)t);
    printf("thread writer%d created.............\n",t);
    if(re)
    {
            printf("error");
            exit(-1);
    }
    }
    
    //--------------------------------------------------------------------
    for(t=3;t<6;++t)
    {
    re=pthread_create(&thread[t],NULL,reader,(void *)t);
    printf("thread reader%d created.............\n",t);
    if(re)
    {
            printf("error");
            exit(-1);
    }
    }
    
    
    
    
    
   // =====================================================================
    
    
    
    
    
    for(t=0;t<6;++t)
    {
    pthread_join(thread[t],NULL);
    
    }
    for(t=0;t<4;++t)
    pthread_join(thread2[t],NULL);
   }
