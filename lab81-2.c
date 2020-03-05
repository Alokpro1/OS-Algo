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
  int cno;
};

void * matrix(void *q)
{
   struct node *ptr2;
   ptr2=(struct node*)q;
  int rowm =ptr2->r;
  int colm =ptr2->c;
  int m;
  
  int i=ptr2->rno;
  int j=ptr2->cno;
  (*ptr2->pointer3)[i][j]=0;
    for(m=0;m<colm;++m)
    {
      (*ptr2->pointer3)[i][j]+=((*ptr2->pointer1)[i][m])*((*ptr2->pointer2)[m][j]);
    }
  
  
   printf("row %d col %dadded by %d\n",i,j,(unsigned)pthread_self());
}



void main(int argc,char *argv[])
{
int a[20][20];
int b[20][20];
int c[20][20];
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
        a[l][m]=2;
        b[l][m]=2;
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
  pthread_t thread[rowm*colm];
  int t,re;
  t=0;
  for(l=0;l<rowm;++l)
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
  
  
  
  
