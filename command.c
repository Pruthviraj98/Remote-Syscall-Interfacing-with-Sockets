#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<errno.h>


int main()
{	

	printf("WELCOME");
	char dirname[]="command.txt";// the command.txt is a file where our commands are being specified
	char err[]="sudo-apt";
	FILE* file=fopen(dirname, "r");
	char inputcommand[256]="hi";	
	char commandonly[256];
	while (strstr("end", inputcommand)==0)//end assumed to be the final pt
	{
	
	char line[256];
	printf(">>>");
	scanf("%s", inputcommand);
	int i;
	for(i=0;i<strlen(inputcommand);i++)
	{
		if(inputcommand[i]==' ')
		{
			break;
		}	
		commandonly[i]=inputcommand[i];
	}
		
	if(strstr(inputcommand, err))
	{
		perror("The packages cant be installled");
	}
	
	while (fgets(line, sizeof(line), file))
	{
		if(strstr(line, commandonly))
			system(inputcommand);
		else
			perror("command is not recognized");
	}
	}
	fclose(file);
	return 0;
}
