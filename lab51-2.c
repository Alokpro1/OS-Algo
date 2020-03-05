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
    fd=open(FILE,O_RDONLY);
        printf("created pipe and ready\n");
    int f=1;
    while(1)
    {
        
      //char s[300];
      if((num=read(fd,s,300))==-1)
            perror("read");
      else
      {
            s[num]='\0';
            printf("Read:");
            puts(s);
         if(s[0]=='b' && s[1]=='y' && s[2]=='e' && s[3]=='\0')
          break;
       }
    }
          
    return 0;
}
