#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>

int main(){
	struct sockaddr_in svr,cl;
	char clientpacket[4321];
	int socdec,c_sock,x,read_length;
	
	

	
	socdec=socket(AF_INET,SOCK_STREAM,0);
	if(socdec==-1){
		printf("Socket Unsuccesfully Created");
	}
	
	puts("Socket Succesffuly Created!");
	
	
	svr.sin_family=AF_INET;
	svr.sin_addr.s_addr=INADDR_ANY;
	svr.sin_port=htons(6788);
	

	if(bind(socdec,(struct sockaddr *)&svr,sizeof(svr))<0){
	perror("Unsuccesfully Bind Socket To Server");
	return 1;
	}
	
	puts("uccesffuly Bind");


	listen(socdec,3);


	puts("Waiting For Packet...");
	x=sizeof(struct sockaddr_in);


	c_sock=accept(socdec,(struct sockaddr *)&cl,(socklen_t *)&c);
	if(c_sock<0){
	perror("Unsuccesfully To Accept");
	return 1;
	}
	puts("Succesfuly Accept Connection!");

	read_length=recv(c_sock,clientpacket,4321,0);

	printf("%s",clientpacket);
	
	
}
