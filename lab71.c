#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int a[30][30];
int b[30][30];
int c[30][30];
int rowm,colm;
void * matrix(void *rowq)
{
  int row =(int)rowq;
  int i;
  for(i=0;i<colm;++i)
  {
   c[row][i]=a[row][i]+b[row][i];
   }
   printf("row %d added by %d\n",row,(unsigned)pthread_self());
}

void main(int argc,char *argv[])
{
  
  printf("enter no.of rows and colms:");
  scanf("%d %d",&rowm,&colm);
  int l,m;
  for(l=0;l<rowm;l++)
  {
    for(m=0;m<colm;m++)
    {
        a[l][m]=0;
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
     re=pthread_create(&thread[t],NULL,matrix,(void *)t);
     if(re)
     {
       printf("error");
       exit(-1);
     }
     
     
  }
  
  for(l=0;l<rowm;++l)
        pthread_join(thread[l],NULL);
  

  
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
  
  
  
  
