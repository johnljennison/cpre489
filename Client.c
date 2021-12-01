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
#include <unistd.h>
#include "finalProject.h" 


int main(){

	int msgSize;
	char mptcpMsg[msgSize];








//-------------------------------------------------------------------------
//STEP 2
//GENERATE MESSAGE


	generateMessage(mptcpMsg, msgSize);


				
//-------------------------------------------------------------------------
//STEP 3
//ESTABLISH 4 TCP CONNECTIONS

	//A
	//ESTABLISH CONTROLL CONNECTION:
	//1 DSS SENT FOR EACH DATA SEGMENT SEND ON A SUBFLOW

	tcpConnect2Server()
		
	

	//B
	//ESTABLISH DATA CONNECTIONS:
	//3 TCP SUBLOSW TO SERVER. EACH CONNECTION TO BE FORKED AS CHILD PROCESS. 
	//PARENT COMS WITH CHILD USING pipe() OU BY UNIX SOCKETS. 
	//NOTE - PIPE/SOCKET MUST BE MADE BEFORE TEH FORK



	

	//C
	//SEND DATA
	//SEND DATA TO 3 TCP SUBLFOWS AT 4 BYTES AT A TIME IN CYCLIC MANNER.
	



	//D
	//SEND DSS:
	//CLIENT SENDS DSS ON TCP CONTROL CONNECTION FOR EACH SEGMENT SENT ON TCP SUBFLOW
	//TO ESTABLISH DATA MAPPING TO SERVER
	


	
	//E
	//WRITE MAPPING OF 992 BYTES TO THE SEQ. NUMBERS ON ALL 3 CONNETIONS
	//INTO LOG FILE







return 0;

}
