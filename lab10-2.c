#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

sem_t mutex;
sem_t fbuffer;
sem_t lbuffer;
void* prodr(void* p)
{
    int q=(int)p;
    int i;
    
    for(i=0;i<4;++i)
    {
       printf("producer%d is willing to enter\n",q);
        sem_wait(&fbuffer);
        sem_wait(&mutex);
    /////////////
       printf("produced %d by %d\n",i,q);
       
       
    //////////////
    printf("producer%d is outside critical section\n",q);
        sem_post(&mutex);
        sem_post(&lbuffer);
        
        sleep(1);
    }
}
void* conr(void* p)
{
    int q=(int)p;
    printf("consumer%d is willing to enter\n",q);
    int i;
    for(i=0;i<4;++i)
    {
    sem_wait(&lbuffer);
    sem_wait(&mutex);
    /////////////
      
      printf("consumed%d by %d\n",i,q);
      
      
       
       
    //////////////
    sem_post(&mutex);
    sem_post(&fbuffer);
    
    printf("consumer%d is outside critical section\n",q);
    sleep(1);
}
}
main()
{
    printf("%d",sem_init(&mutex,0,1));
    sem_init(&fbuffer,0,5);
    sem_init(&lbuffer,0,0);
    
    
    pthread_t producer[3];
    pthread_t consumer[3];
  
  
  
    int t;
    t=0;
    for(t=0;t<3;++t)
    {
    pthread_create(&producer[t],NULL,prodr,(void *)t);
    printf("producer%d created.............\n",t);
    pthread_create(&consumer[t],NULL,conr,(void *)t);
    printf("consumer%d created.............\n",t);
    
    }
    
    
    for(t=0;t<3;++t)
    {
    pthread_join(producer[t],NULL);
    pthread_join(consumer[t],NULL);
    }
    
}
