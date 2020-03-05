#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

#define FILE1 "file11.txt"
#define FILE2 "file21.txt"
#define FILE3 "file31.txt"
#define FILE4 "file41.txt"
int main()
{
    int num1,num2,num3,num4,fd1,fd2,fd3,fd4;
   
    pid_t p=fork();
    if(p==0)
    {
        mkfifo(FILE3,0666);
        printf("created\n");
        fd3=open(FILE3,O_RDONLY);
        printf("created pipe and ready\n");
        char s1[300];
        while(1)
        {
        
            
            if((num3=read(fd3,s1,300))==-1)
                perror("read");
            else
            {
                s1[num3]='\0';
                printf("Read:");
                puts(s1);
                
            }
        }
    }
    else
    {
        mkfifo(FILE1,0666);
        printf("created1\n");
        mkfifo(FILE2,0666);
        printf("created2\n");
        mkfifo(FILE4,0666);
        printf("created4\n");
        fd1=open(FILE1,O_WRONLY);
        printf("created pipe and ready1\n");
        fd2=open(FILE2,O_WRONLY);
        printf("created pipe and ready2\n");
        fd4=open(FILE4,O_WRONLY);
        printf("created pipe and ready4\n");
        
        char s2[300];  
   
    while(1)
    {
       
      gets(s2);
      char s5[300];
      s5[0]='u';
      s5[1]=':';
      s5[2]='3';
      int i;
      for(i=0;i<strlen(s2);++i)
            s5[i+3]=s2[i];   
      if(((num1=write(fd1,s5,strlen(s5)))==-1))
            perror("write");
      else
            printf("Sent1\n");
      if((num2=write(fd2,s5,strlen(s5)))==-1)
            perror("write");
      else
            printf("Sent2\n");
      
     if((num4=write(fd4,s5,strlen(s5)))==-1)
            perror("write");
      else
            printf("Sent4\n");
            
            
     if(s2[0]=='b' && s2[1]=='y' && s2[2]=='e' && s2[3]=='\0')
         {
           
         break;
           
           }
    }
        
    }
          
    return 0;
}
