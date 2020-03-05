#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

#define FILE1 "myfile1.txt"
#define FILE2 "myfile2.txt"
int main()
{
    int num1,num2,fd1,fd2;
    
    pid_t p=fork();
    if(p==0)
    {
        mkfifo(FILE2,0666);
        printf("created\n");
        fd2=open(FILE2,O_RDONLY);
        printf("created pipe and ready\n");
        char s2[300];
        while(1)
        {
        
            
            if((num2=read(fd2,s2,300))==-1)
                perror("read");
            else
            {
                s2[num2]='\0';
                printf("Read:");
                puts(s2);
                if(s2[0]=='b' && s2[1]=='y' && s2[2]=='e' && s2[3]=='\0')
                break;
            }
        }
    }
    else
    {
       mkfifo(FILE1,0666);
    printf("created\n");
    fd1=open(FILE1,O_WRONLY);
    printf("created pipe and ready\n");
    char s1[300];
   
    while(1)
    {
        
      gets(s1);
      if((num1=write(fd1,s1,strlen(s1)))==-1)
            perror("write");
      else
            printf("Sent\n");
            
            
     if(s1[0]=='b' && s1[1]=='y' && s1[2]=='e' && s1[3]=='\0')
         { break;
           
           }
    }
        
    }
          
    return 0;
}
