#include<stdio.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>
#include<stdlib.h>
#define MAX 80
#define PORT 9010
#define SA struct sockaddr
void func(int sockfd)
{
char buff[MAX];
int n;

char cmdprint[256]=">>>";
char folder[256]="";
for(;;)
{
bzero(buff,sizeof(buff));
//////////////////

    size_t buffersize=256;
    char *inputcommand=(char*)malloc(buffersize*(sizeof(char)));
  
    printf("%s", cmdprint);    
    getline(&inputcommand, &buffersize, stdin);
	if(strstr(inputcommand, "end"))
	{
	exit(1);
	}	
	
	if(strstr(inputcommand, "cd"))
	{
		
		if(strlen(inputcommand)==3)
		{
		strcpy(folder, "");
		strcpy(cmdprint, ">>>");
		}

		else
		{
		int i;
		int flag=0;
			for( i=0;i<strlen(inputcommand);i++)
			{
			flag++;
				if(inputcommand[i]==' ')
				{
				break;
				}
			}	

		char folderappend[256];
		int countappend=0;
			for(i=flag;i<strlen(inputcommand);i++)
			{
			folderappend[countappend++]=inputcommand[i];
			}
		strncat(folder, folderappend, countappend);
		//strcat(folder, "/");
		strncat(cmdprint, folderappend, countappend);
			int x;
			for(x=3;x<strlen(cmdprint);x++)//loop to display current directory
			{
				if(cmdprint[x]=='\n')
				{	
				cmdprint[x]=':';
				continue;
				}
				if(cmdprint[x]==' ')
				{
				cmdprint[x]='/';
				}
			}

		
		}
	}

	else//for commands except navigation
	{
		if(strlen(cmdprint)==3)//to go to the perticular directory and execute the commands
		{
	//	system(inputcommand);//if no change in directory has occured, we directly execte the 		input commands;
		printf("\n");
		}
		else
		{
		
		char cdcommand[256]="cd ";

		strncat(cdcommand, folder, strlen(folder));
	
		strcat(cdcommand, " && ");
		strncat(cdcommand, inputcommand, strlen(inputcommand));
	
	
		int x;
		char finalcommand[256];

			for(x=0;x<strlen(cdcommand);x++)
			{
				if(cdcommand[x]=='\n')
				{
				finalcommand[x]=' ';	
				cdcommand[x]==' ';
				continue;
				}
			finalcommand[x]=cdcommand[x];
			}

		char executedfolder[256]="";
		int counter=3;		
		int counter2=0;
			while(finalcommand[counter]!='&')
			{
				if(finalcommand[counter]==' ')
				{
				executedfolder[counter2++]='/';
				counter++;
				continue;
				}
				if(finalcommand[counter]=='/')
				{
				counter++;
				continue;	
				}	
				executedfolder[counter2++]=finalcommand[counter++];
			}
		
		char executedcommand[256]="";
		strncat(executedcommand, finalcommand, 3);
		strcat(executedcommand, executedfolder);
		strcat(executedcommand, " && ");
		strcat(executedcommand, inputcommand);
	
		printf("\n-------command executed-------\n\n\n");

	//	system(executedcommand);
		}
	}





//////////////////////

strcpy(buff, inputcommand);

write(sockfd,buff,sizeof(buff));
bzero(buff,sizeof(buff));
read(sockfd,buff,sizeof(buff));
printf("From Server : %s",buff);
if((strncmp(buff,"exit",4))==0)
{
printf("Client Exit...\n");
break;
}

}
}

int main()
{
int sockfd,connfd;
struct sockaddr_in servaddr,cli;
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
printf("socket creation failed...\n");
exit(0);
}
else
printf("Socket successfully created..\n");
bzero(&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=htons(PORT);
if(connect(sockfd,(SA *)&servaddr,sizeof(servaddr))!=0)
{
printf("connection with the server failed...\n");
exit(0);
}
else
printf("connected to the server..\n");
func(sockfd);
close(sockfd);
}

