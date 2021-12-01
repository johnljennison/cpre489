#include <sys/types.h>
#include <arpa/inet.h> 
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include <dirent.h>

#define IPDOTNOTATION "127.0.0.1"


int generateMessage(char* message, int msgSize){

	int i = 0;
	char j = '0';
	while(i<msgSize-62){
		while(j<='9'){
			message[i] = j;
			i++;
			j++;	
			}
		j = 'A';
		while(j<='Z'){
			message[i] = j;	
			i++;
			j++;
			}
		j = 'a';
		while(j<='z'){
			message[i] = j;	
			i++;
			j++;
			}
		j='0';		
		}	

	while(i<msgSize){
		while(j<='9'){
			message[i] = j;
			i++;
			j++;	
			if(i==msgSize)
				break;
			}
		if(i==msgSize)
			break;
		j = 'A';
		while(j<='Z'){
			message[i] = j;	
			i++;
			j++;
			if(i==msgSize)
				break;
			}
		if(i==msgSize)
			break;
		j = 'a';
		while(j<='z'){
			message[i] = j;	
			i++;
			j++;
			if(i==msgSize)
				break;
			}
		j='0';		
		}	
		
			
	message[msgSize-1] = '\0';

	printf("This is the message:\n%s\n", message);

	return msgSize;

}




int tcpConnectClient(){

//A
//	DEFINE FIELDS FOR ServerAddr	

	struct sockaddr_in ServerAddr, clientAddr;

	
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_port = htons(SERVERPORTNUM);
	ServerAddr.sin_addr.s_addr =  inet_addr(IPDOTNOTATION);
	int ServerAddrLen = sizeof(ServerAddr)	;
	printf("ServerAddrLen: %d\n", ServerAddrLen);
	int clientAddrLen;

	int ServerSocketFD, AcceptSocketFD;
	int BindCheck, ListenCheck, sendCheck; // For Troubleshooting




//B
//	ESTABLISH SERVER TCP SOCKET
//	BIND SOCKET
	
	ServerSocketFD = socket(AF_INET, SOCK_STREAM, 0);
	//Returns socket FD. Returns (-) num if unsuccessful
	if(ServerSocketFD < 0){
		printf("ServerSocket Failed\n");
		}
	

	BindCheck = bind(ServerSocketFD, (struct sockaddr*)&ServerAddr, ServerAddrLen); 
	//returns 0 if successful

	if(!(BindCheck == 0)){
		printf("BindCheck Failed\n");
		}
	else
		printf("Server IP/Port:%d %d\n",ServerAddr.sin_port, ServerAddr.sin_addr.s_addr);






return 0;
}



int tcpServerSocket(){




return 0;
}


int tcpConnect2Client(){





//A
//	CONNECT TO CLIENT
//	SERVER LISTEN
//	LISTEN FOR SOCKET CONNECTIONS AND LIMIT THE QUEUE OF INCOMING CONNECTIONS

	
	ListenCheck = listen(ServerSocketFD, 0); //returns 0 if sucessful
	if(!(ListenCheck == 0)){
		printf("ListenCheck Fail\n");
		}
	else
		printf("listen complete\n");

//B
//	SERVER ACCECPT
//	EXTRACT THE FIRST CONNECTION ON THE QUEUE OF PENDING CONNECTIONS
//	CREATES A NEW SOCKET THAT IS SAME TYPE AND FAMILY AS THE SPECIFIED SOCKET
//	ALLOCATES A NEW FD FOR THE SOCKET

	AcceptSocketFD = accept(ServerSocketFD, (struct sockaddr*)&clientAddr, 	
				(socklen_t*)&clientAddrLen); 
	//returns non-negative file descriptor

	if(AcceptSocketFD <=0){
		printf("Accept Fail\n");
	}
	else	
		printf("accept complete\n");

return 0;
}












