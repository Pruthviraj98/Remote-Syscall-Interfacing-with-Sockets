#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cmdprint=">>>";
char folder[256]="";

char* findloc(char* command[]) // function to seperate the linux command and fetch back only the directory part.
{
int flag=0;
for(int i=0;i<strlen(command);i++)
{
flag++;
if(command[i]==' ')
{
break;
}
}

if(flag==0)
{
folder="";	
return("n");
}

int count=0;
for(int i=flag;i<strlen(command);i++)
{
folder[i]=command[count++];
}
folder=strcat(folder, command);
return "y";
}

int main(int argc, char *argv[])
{
while(0)
{
    printf("%s", cmdprint);
    char inputcommand[256];
    scanf("%s", inputcommand);
 
	if(strstr("end", inputcommand))//we assume 'end'  is the keyword for stopping the file navigation. 
	exit(0);
    
	char* ctr="";
    if(strstr("cd", inputcommand))
	{
	system(inputcommand);
//	folder=strcat(folder, findloc(inputcommand));
        ctr=findloc(inputcommand);
	folder=strcat(folder, "cd");//tobe changed here
	cmdprint=strcat(cmdprint, folder); //to make the client feel apparently that we are into that folder or directory
	cmdprint=strcat(cmdprint, "/");
	continue;
	}
    
    if(ctr=="n")
	{
	cmdprint=">>>";
	} 
    if(strcmp(">>>", cmdprint)==0)//to go to the perticular directory and execute the commands
	{
	system(inputcommand);//if no change in directory has occured, we directly execte the input commands;
	printf("\n");
	}
     else
	{
	char* a=strcat("chdir ", folder);//to get according to syntax : 'chdir directoryname && chdir... && inputcommand' is executed 
	a=strcat(a, "&&");
	char* b=strcat(a, inputcommand);	
	system(b);
	}
    return 0;
}
}
