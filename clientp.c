#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>          /* See NOTES */
#include<sys/socket.h>
#include<time.h>
#include<netinet/in.h>


void error(const char* err){
	printf("%s", err);
	exit(0);
}

int main(){

	int sockid=socket(AF_INET, SOCK_STREAM, 0), portno;
	
	printf("Enter port no\n");
	scanf("%d", &portno);

	if(sockid<0)
		error("Error creating socket\n");
	else
		printf("Socket Created successfully\n\n");

	struct sockaddr_in serv_addr;
	
	char send_msg[200], recv_msg[200];
	
	serv_addr.sin_family= AF_INET;

	//serv_addr.sin_addr.s_addr=htonl("172.16.10.105");
	//https://stackoverflow.com/questions/15673846/how-to-give-to-a-client-specific-ip-address-in-c
	
	serv_addr.sin_addr.s_addr=inet_addr("172.16.10.105");	
	serv_addr.sin_port= htons(portno);
	
	if (connect(sockid,(struct sockaddr*)&serv_addr, sizeof(serv_addr))>=0)
		printf("Connected to Server Socket at port %d\n\n", portno);
	else
		error("Error Connecting to server\n");
	
	char buffer[200];
	printf("Received msgs:");
	
	l1:	

		if(recv(sockid, buffer, sizeof(buffer), 0)>0)
			printf("%s\n", buffer);

	goto l1;
	
	close(sockid);
}
