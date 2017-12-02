#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>


int main(){
	char packet[4321];
	int socketline;
	struct sockaddr_in sv;
	

	socketline=socket(AF_INET,SOCK_STREAM,0);
	if(socketline==-1){
	   printf("Failed To Create A Socket");
	}
	puts("Socket Succesfully Created");
	
	sv.sin_addr.s_addr=inet_addr("192.168.116.129");
	sv.sin_family=AF_INET;
	sv.sin_port=htons(1221);

	
	if(connect(socketline,(struct sockaddr *)&sv,sizeof(sv))<0){
		perror("Not Connected To The Loadbalancer");
		return 1;
	}

	printf("Enter Packet Message : ");
	scanf("%s",packet);
	if(send(socketline,packet,strlen(packet),0)<0){
	puts("Packet Sending Was Unsucessful");
	return 1;
	}
	close(socketline);
return 0;
}
