#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
char cmdprint[256]=">>>";
char folder[256]="";

for(;;)
{

    printf("%s", cmdprint);
    size_t buffersize=256;
    char *inputcommand=(char*)malloc(buffersize*(sizeof(char)));
    
    getline(&inputcommand, &buffersize, stdin);

	if(strstr(inputcommand, "end"))//we assume 'end'  is the keyword for stopping the file navigation.
	{
	exit(1);
	}

    if(strstr("cd", inputcommand))
	{
	system(inputcommand);

	//edit 8/1/18

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


	if(flag==0)
	{
	strcpy(folder, "");
	}
	else
	{
	char folderappend[256];
	int countappend=0;
	for(i=flag;i<strlen(inputcommand);i++)
	{
	folderappend[countappend++]=inputcommand[i];
	}

	strncat(folder, folderappend, countappend);
	strncat(cmdprint, folderappend, countappend);		
	strcat(folder, "/");
	}

	
	}
    else
    {
    
	if(strcmp(">>>", cmdprint)==0)//to go to the perticular directory and execute the commands
	{
	system(inputcommand);//if no change in directory has occured, we directly execte the input commands;
	printf("\n");
	}
    else
	{
	char* a=strcat("chdir ", folder);//to get according to syntax : 'chdir directoryname && chdir... && inputcommand' is executed
	strcat(a, "&&");
	strcat(a, inputcommand);
	system(a);
	}

    }
}
}
