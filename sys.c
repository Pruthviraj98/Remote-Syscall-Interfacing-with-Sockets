#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
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

printf("\n%s", folder);

char folderappend[256];
int countappend=0;
	for(i=flag;i<strlen(inputcommand);i++)
	{
	folderappend[countappend++]=inputcommand[i];
	}
strncat(folder, folderappend, countappend);
strncat(cmdprint, folderappend, countappend);
}


    else//for commands except navigation
    {
	if(strlen(cmdprint)==3)//to go to the perticular directory and execute the commands
	{
	//system(inputcommand);//if no change in directory has occured, we directly execte the input commands;
	printf("\n");
	}
        else
	{
//to get according to syntax : 'chdir directoryname && chdir... && inputcommand' is executed
	char cdcommand[256]="cd ";
	strncat(cdcommand, folder, strlen(folder));
	strcat(cdcommand, " && ");
	strncat(cdcommand, inputcommand, strlen(inputcommand));
	printf("%s", cdcommand);	
	
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
printf("\n-------command executed-------\n\n%s\n",finalcommand);


//system(cdcommand);
	}
    }
}
}
