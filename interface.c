#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <string.h>

void *myThreadFun(void *vargp)
{
system("gnome-terminal -x sh -c 'gcc pruter.c; ./a.out'");
}

void *fun2(void *vargp)
{
system("firefox http://www.google.co.in");
}

void *fun3(void *vargp)
{
system("gnome-terminal -x sh -c 'gcc todo.c; ./a.out'");
}

void *fun4(void *vargp)
{
system("gnome-terminal -x sh -c 'gcc database.c; ./a.out'");
}


int main()
{

while(1)
{


system("clear");

printf("\n\t\t------------WELCOME TO REMOTE SYSCALL SYSTEM INTERFACE-------------\n\t\t");
printf("\nn\n\t\t------------SELECT THE SERVICE NEEDED-------------\n\t\t");
printf("\nn\n\t\t------------1. FILESYSTEM-------------\n\t\t");
printf("\nn\n\t\t------------2. WEBSERVICE-------------\n\t\t");
printf("\nn\n\t\t------------3. TODO-------------\n\t\t");
printf("\nn\n\t\t------------4. DATABASE-------------\n\t\t");
printf("\nn\n\t\t------------5. EXIT-------------\n\t\t");
for(;;)
{
int option;
printf("\n\t\t >>> ");
scanf("%d", &option);
pthread_t tid, tid2, tid3, tid4;


if(option==1)
{
    printf("TAKING TO THE FILE SYSTEM.....\n");
    int i=1;
    pthread_create(&tid, NULL, myThreadFun, NULL);
    pthread_join(tid, NULL);
}
else if(option==2)
{
    printf("TAKING TO THE WEB .....\n");
    int j=2;
    pthread_create(&tid2, NULL, fun2, NULL);
    pthread_join(tid2, NULL);
}

else if(option==3)
{
    printf("TAKING TO THE TODO APP.....\n");
    int k=3;
    pthread_create(&tid3, NULL, fun3, NULL);
    pthread_join(tid3, NULL);
}
else if(option==4)
{
    printf("TAKING TO THE DATABASE SYSTEM.....\n");
    int l=4;
    pthread_create(&tid4, NULL, fun4, NULL);
    pthread_join(tid4, NULL);
}

else if(option==5)
{
	exit(0);
}
}
}
}
