#include <stdio.h>
#include <string.h>
#include <unistd.h>


#include "lsocket.h"

#define IP INADDR_LOOPBACK

int CreateSocket()
{
	int Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (Socket < 0)
	{
		perror("CreateSocket ERROR");
	}
	return Socket;
}
void ConnectSocket(int Socket)
{
	//struct address_len s;
   // struct sockaddr_storage s;

    struct sockaddr_in s; 
	s.sin_family = AF_INET;
	s.sin_port = htons(PORT);
	s.sin_addr.s_addr = htonl(IP);
	if (connect(Socket, (struct sockaddr*)&s, sizeof(s)) <0)
	{
	//	printf("%d", WSAGetLastError());
		perror("ConnectSocket ERROR");

	}
}

void ReadMsg(int Socket, char* msg)
{
	int flags = 0;
	int length = recv(Socket, msg, SMSG, flags);
	if (length  < 0)
	{

		perror("ReadMsg ERROR");
	}
	msg[length] = '\0';
}
void WriteMsg(int Socket, const char* msg)
{
	int flags = 0;
	int  length = send(Socket, msg, strlen(msg), flags);
	if (length < 0)
	{

		perror("WriteMsg ERROR");
	}
}
void Start()
{
	char msg[SMSG];


	while (1)
	{
		int Socket = CreateSocket();
		ConnectSocket(Socket);

		WriteMsg(Socket, file);
		ReadMsg(Socket, msg);
		shutdown(Socket, SHUT_RDWR);
		printf("%s\n", msg);
		sleep(5);
		
	}
}
