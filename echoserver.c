/*	
	gcc echoserver.c -o t1
	./t1
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>

int main()
{
	int fd,connfd;
	char buff1[1024];
	struct sockaddr_in addr1;	
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
	{
		printf("Error\n");
		exit(1);
	}
 	addr1.sin_family=AF_INET;
        addr1.sin_addr.s_addr=INADDR_ANY;
       	addr1.sin_port=htons(8888);
	if(bind(fd,(struct sockaddr*)&addr1,sizeof(addr1))<0)
	{
		printf("Bind Errror\n");
		exit(1);
	}
	listen(fd,5);
	connfd=accept(fd,NULL,NULL);
	read(connfd,buff1,1024);
	printf("From Client::%s\n",buff1);
	write(connfd,buff1,1024);
	close(connfd);
	return 0;	
}

