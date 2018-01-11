#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cmdprint=">>>";
char folder[256]="";
int main(int argc, char *argv[])
{
for(;;)
{

    printf("%s", cmdprint);
    size_t buffersize=256;
    char *inputcommand=(char*)malloc(buffersize*(char));
    
    getline(&inputcommand, &buffersize, stdin);

	if(strstr("end", inputcommand))//we assume 'end'  is the keyword for stopping the file navigation.
	exit(0);


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
	int count=0;
	for(i=flag;i<strlen(inputcommand);i++)
	{
	folder[i]=inputcommand[count++];
	}

//	strcat(folder, inputcommand);
	}
	//end edit 8/1/18

	strcat(folder, "cd");
	strcat(cmdprint, folder); //to make the client feel apparently that we are into that folder or directory
	strcat(cmdprint, "//");
	continue;
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
