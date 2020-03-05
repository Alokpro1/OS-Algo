#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void main()
{
    int n;
    printf("enter the arr size:");
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;++i)
    {
      scanf("%d",&a[i]);
    }
    pid_t p1=fork();
    waitpid(p1,0,0);
    
    if(p1==0)
    {
      
      pid_t p2=fork();
      waitpid(p2,0,0);
      
      if(p2==0)
      {
        pid_t p3=fork();
        waitpid(p3,0,0);
        
        if(p3==0)
        {
           int c=0,k;
           for(k=0;k<n;++k)
           {
             if(a[k]%2==0)
                c++;
           }
           printf("pid:%d-> no.of even nos:%d\n",getpid(),c);
        }
        else
        {
        int b[20],t=0;
        int k;
        
        for(k=0;k<n;++k)
           {
             if(a[k]%2==0)
                {
                  b[t]=a[k];
                  t++;
                }
           }
           printf("pid:%d-> ",getpid());
        for(k=0;k<t;++k)
           a[k]=b[k];
        for(k=t;k<n;++k)
           a[k]=0;
        for(k=0;k<t;++k)
           printf("%d ",a[k]);
        
           
        printf("\n");
        }
      }
      else
      {
      int m;
      m=a[0];
      int p;
      for(p=1;p<n;++p)
      {
         if(a[p]>m)
           m=a[p];
      }
      printf("pid:%d-> max:%d \n",getpid(),m);
      
   }
   }
   else
   {
       int u,v;
       for(u=0;u<n-1;++u)
       {
          for(v=u+1;v<n;++v)
          {
             if(a[v]<a[u])
             {
               int t=a[v];
               a[v]=a[u];
               a[u]=t;
               }
          }
       }
       printf("pid:%d-> ",getpid());
       for(u=0;u<n;++u)
       {
         printf("%d ",a[u]);
         }
         
         printf("\n");
   }
}
   
      
      
      
      
      
      
      
      
      
           
           
           
           
           
           
          
      
