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
};
void * matrix(void *q)
{
   struct node *ptr2;
   ptr2=(struct node*)q;
  int row =(int)ptr2->rno;
  int i;
  for(i=0;i<(int)(((struct node*)(ptr2))->c);++i)
  {
   c[row][i]=a[row][i]+b[row][i];
   //printf("sdkjf %d %d %d",row,a[row][i],c[row][i]);
   }
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
        a[l][m]=56;
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
  
  
  
  
