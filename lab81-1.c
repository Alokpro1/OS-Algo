#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <malloc.h>


//int rowm,colm;

struct node
{
  int (*pointer1)[20][20];
  int (*pointer2)[20][20];
  int (*pointer3)[20][20];
  int r;
  int rno;
  int c;
};
struct add
{
  int (*pointer1)[20][20];
  int (*pointer2)[20][20];
  int (*pointer3)[20][20];
  int r1;
  int c1;
 };
void * add(void *ad)
{
    struct add *ptr2;
   ptr2=(struct add*)ad;
  int row =(int)ptr2->r1;
  int col =(int)ptr2->c1;
  (*ptr2->pointer3)[row][col]=(*ptr2->pointer2)[row][col]+(*ptr2->pointer1)[row][col];
}
void * matrix(void *q)
{
   struct node *ptr2;
   ptr2=(struct node*)q;
  int row =(int)ptr2->rno;
  int i,re1;
  pthread_t thread2[ptr2->c];
  for(i=0;i<(int)(((struct node*)(ptr2))->c);++i)
  {
    struct add *ptr=(struct add*)malloc(sizeof(struct add));
    ptr->r1=row;
    ptr->c1=i;
    ptr->pointer1=ptr2->pointer1;
    ptr->pointer2=ptr2->pointer2;
    ptr->pointer3=ptr2->pointer3;
    re1=pthread_create(&thread2[i],NULL,add,(void *)ptr);
    pthread_join(thread2[i],NULL);
     if(re1)
     {
       printf("error");
       exit(-1);
     }
  }
   printf("row %d added by %d\n",row,(unsigned)pthread_self());
}



void main(int argc,char *argv[])
{
    int a[20][20];//local//stack
    int b[20][20];
    int c[20][20];
  struct node *ptr=(struct node*)malloc(sizeof(struct node));//heap
  int rowm,colm;
  printf("enter no.of rows and colms:");
  scanf("%d %d",&rowm,&colm);
  ptr->r=rowm;
  ptr->c=colm;
  int l,m;
  for(l=0;l<rowm;l++)
  {
    for(m=0;m<colm;m++)
    {
        a[l][m]=44;
        b[l][m]=1;
     }
  }
  printf("matrix A:\n");
  for(l=0;l<rowm;l++)
  {
    for(m=0;m<colm;m++)
    {
        printf("%-5d",a[l][m]);
     }
     printf("\n");
  }
  printf("matrix B:\n");
  for(l=0;l<rowm;l++)
  {
    for(m=0;m<colm;m++)
    {
        printf("%-5d",b[l][m]);
     }
     printf("\n");
  }
  ptr->pointer1=&a;
  ptr->pointer2=&b;
  ptr->pointer3=&c;
  pthread_t thread[rowm];
  int t,re;
  for(t=0;t<rowm;++t)
  {
     printf("creating->%d\n",t);
     ptr->rno=t;
     re=pthread_create(&thread[t],NULL,matrix,(void *)ptr);
     pthread_join(thread[t],NULL);
     if(re)
     {
       printf("error");
       exit(-1);
     }
     
     
  }
  
  
        
  

  
  printf("main executing: \nmatrix is:\n");
  for(l=0;l<rowm;l++)
  {
    for(m=0;m<colm;m++)
    {
        printf("%-5d",c[l][m]);
     }
     printf("\n");
  }
  pthread_exit(0);
}
  
  
  
  
