#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>



void main(int x,char* argv[])
{


  int i,j,a[12][12];
  for(i=0;i<12;i++)
  {
        for(j=0;j<12;++j)
        {
            a[i][j]=i+j;
         }
   }
   int sum=0;
    j=(int)(*argv[1]-'0');
    for(i=0;i<12;i++)
  {
        if(j<12)
        {
            sum=sum+a[i][j];
            //printf("%d",sum);
            
         j=j+2;
         }
         else break;
   }
   
   printf("sum is:%d ",sum);
}
