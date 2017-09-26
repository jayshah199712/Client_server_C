/*	
	gcc echoclient.c -o tt
	./tt
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<netinet/in.h>

int main()
{
	int fd;
	char buff1[1024];
	struct sockaddr_in addr1;	
	fd=socket(AF_INET,SOCK_STREAM,0);
	if(fd<0)
	{
		printf("Error\n");
		exit(1);
	}
 	addr1.sin_family=AF_INET;
        addr1.sin_addr.s_addr=inet_addr("127.0.0.1");
       	addr1.sin_port=htons(8888);
	if(connect(fd,(struct sockaddr*)&addr1,sizeof(addr1))<0)
	{
		printf("Connect Errror\n");
		exit(1);
	}
	strcpy(buff1,"Hello There");
	write(fd,buff1,1024);
	read(fd,buff1,1024);
	printf("From server::%s\n",buff1);
	close(fd);
	return 0;	
}

