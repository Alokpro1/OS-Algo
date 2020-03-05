#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

#define FILE "myfile.txt"
int main()
{
    int num,fd;
    char s[300];
    mkfifo(FILE,0666);
    printf("created\n");
    fd=open(FILE,O_WRONLY);
    printf("created pipe and ready\n");
    
    int f=1;
    while(f)
    {
      //char s[300];  
      gets(s);
      if((num=write(fd,s,strlen(s)))==-1)
            perror("write");
      else
            printf("Sent\n");
            
            
     if(s[0]=='b' && s[1]=='y' && s[2]=='e' && s[3]=='\0')
          break;
    }
          
    return 0;
}
