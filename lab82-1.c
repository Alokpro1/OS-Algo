#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <malloc.h>

int a[30][30];
int b[30][30];
int c[30][30];
//int rowm,colm;

struct node
{
  int r;
  int rno;
  int c;
  int cno;
};


void * matrix(void *q)
{
   struct node *ptr2;
   ptr2=(struct node*)q;
  int row =(int)ptr2->rno;
  int i,re1;
  
   printf("row %d added by %d\n",row,(unsigned)pthread_self());
}



void main(int argc,char *argv[])
{
  struct node *ptr=(struct node*)malloc(sizeof(struct node));
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
        a[l][m]=l*m;
        b[l][m]=l+m;
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
  pthread_t thread[rowm*colm];
  int t,re;
    t=0;
  for(l=0;l<rowm;++t)
  {
     for(m=0;m<colm;++m)
     {
        printf("creating->%d\n",t);
        ptr->rno=l;
        ptr->cno=m;
        re=pthread_create(&thread[t],NULL,matrix,(void *)ptr);
        pthread_join(thread[t],NULL);
        t++;
        if(re)
        {
            printf("error");
            exit(-1);
        }
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
  
  
  
  
