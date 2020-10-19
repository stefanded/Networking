
#include<stdio.h>
#include<string.h>

#include"lsocket.h"
int CreateSocket()
{
	int Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (Socket < 0)
	{
		perror("CreateSocket ERROR");
//		exit(0);
	}
	return Socket;
}
void BindSocket(int Socket)
{
	//struct address_len s;
   // struct sockaddr_storage s;

    struct sockaddr_in s; 
	s.sin_family = AF_INET;
	s.sin_port = htons(PORT);
	s.sin_addr.s_addr = htonl(IP);
	if (bind(Socket, (struct sockaddr*)&s, sizeof(s)) <0)
	{
	//	printf("%d", WSAGetLastError());
		perror("BindSocket ERROR");
	//	exit(0);

	}
}
int AcceptSocket(int Socket)
{
	int new_socket = accept(Socket, 0, 0);

	if (new_socket < 0)
	{
		perror("AcceptSocket ERROR");
	//	exit(0);
	}
	return new_socket;
}

void ReadMsg(int Socket, char* msg)
{
	int flags = 0;
	int length = recv(Socket, msg, SMSG, flags);
	if (length  < 0)
	{

		perror("ReadMsg ERROR");
		//exit(0);
	}
	msg[length] = '\0';
}
const char* ConstructMsg(const char* way)
{
	if (fopen(way, "r"))
	{
		return "File found";
		
	}
	return "File not found";
}
void WriteMsg(int Socket, const char* msg)
{
	int flags = 0;
	int  length = send(Socket, msg, strlen(msg), flags);
	if (length < 0)
	{

		perror("WriteMsg ERROR");
		//exit(0);
	}
}
void Start(){
//
	
	int Socket = CreateSocket();
	BindSocket(Socket);

	listen(Socket, SOMAXCONN);

	char read_msg[SMSG];

	while (1)
	{
		int new_socket = AcceptSocket(Socket);
		ReadMsg(new_socket, read_msg);
		WriteMsg(new_socket, ConstructMsg(read_msg));
		shutdown(new_socket, SHUT_RDWR);
	}
}