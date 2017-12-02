#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>

int main(){
	char clientpacket[4321];
	struct sockaddr_in lb,client,sv1,sv2;
	int socdec,c_sock,x,read_length,svsock1,svsock2;

	
	socdec=socket(AF_INET,SOCK_STREAM,0);
	if(socdec==-1){
		printf("Socket Uncessfully Created");
	}
	puts("Loadbalancer Successfuly Created");
	
	
	lb.sin_family=AF_INET;
	lb.sin_addr.s_addr=INADDR_ANY;
	lb.sin_port=htons(1221);
	
	
	if(bind(socdec,(struct sockaddr *)&lb,sizeof(lb))<0){
	perror("Binding Socket To Server Failed");
	return 1;
	}
	
	puts("Succesffuly Bind");


	listen(socdec,3);

	
	puts("Waiting For Packet");
	x=sizeof(struct sockaddr_in);

	//accept connection from incoming client
	c_sock=accept(socdec,(struct sockaddr *)&client,(socklen_t *)&c);
	if(c_sock<0){
	perror("Failed To Accept");
	return 1;
	}
	puts("Connection Accept");

	read_length=recv(c_sock,clientpacket,4321,0);
	
	if(strcmp(clientpacket,"Admin")==0){

		
		svsock1=socket(AF_INET,SOCK_STREAM,0);
		sv1.sin_family=AF_INET;
		sv1.sin_addr.s_addr=inet_addr("192.168.232.128");
		sv1.sin_port=htons(5942);
		if(connect(svsock1,(struct sockaddr *)&sv1,sizeof(sv1))<0){
		perror("Uncessfully Connect To Server");
		return 1;
		}

		if(send(svsock1,clientpacket,strlen(clientpacket),0)<0){
		puts("Uncessfully Send Packet");
		return 1;
		}
	close(svsock1);
	}else if(strcmp(clientpacket,"Mail")==0){

		//create socket for server2
		svsock2=socket(AF_INET,SOCK_STREAM,0);
		sv2.sin_family=AF_INET;
		sv2.sin_addr.s_addr=inet_addr("192.168.232.129");
		sv2.sin_port=htons(6788);
		if(connect(svsock2,(struct sockaddr *)&sv2,sizeof(sv2))<0){
		perror("Uncessfully Connect To Loadbalancer");
		return 1;
		}

		if(send(svsock2,clientpacket,strlen(clientpacket),0)<0){
		puts("Uncessfully To Send");
		return 1;
		}
		close(svsock2);	
	}else{
	printf("Uncessfully To Reroute To Any Server");	
	}
	
	
}
