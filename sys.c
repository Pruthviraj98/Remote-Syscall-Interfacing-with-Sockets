#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
for(;;)
{
char username[100];
char password[100];

system("clear");

printf("\n\t\t------------WELCOME TO REMOTE SYSCALL SYSTEM INTERFACE-------------\n\t\t");
printf("\n\t\t USERNAME: ");
scanf("%s", username);
printf("\n\t\t PASSWORD: ");
scanf("%s", password);

if((strstr(username, "admin"))&&(strtr(password, "password")))
{
printf("\n\t\t------------WELCOME %s-------------\n", username);

char cmdprint[256]=">>>";
char folder[256]="";

for(;;)
{

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
		system(inputcommand);//if no change in directory has occured, we directly execte the 		input commands;
		printf("\n");
		}
		else
		{
		//to get according to syntax : 'chdir directoryname && chdir... && inputcommand' is executed
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

		system(executedcommand);
		}
	}
}
}

else
{
printf("\n\n\t------tryagain!!!!------\n\n");
}
}
}
