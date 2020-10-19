
#include<stdio.h>
#include<string.h>
#include"wsocket.h"

SOCKET CreateSocket()
{
	SOCKET Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (Socket < 0)
	{
		perror("CreateSocket ERROR");
		exit(EXIT_FAILURE);
	}
	return Socket;
}
void BindSocket(SOCKET Socket)
{
	struct sockaddr_in s;
	s.sin_family = AF_INET;
	s.sin_port = htons(PORT);
	s.sin_addr.S_un.S_addr = htonl(IP);
	if (bind(Socket, (struct sockaddr*)&s, sizeof(s)) <0)
	{
	//	printf("%d", WSAGetLastError());
		perror("BindSocket ERROR");
		exit(EXIT_FAILURE);

	}
}
SOCKET AcceptSocket(SOCKET Socket)
{
	SOCKET new_socket = accept(Socket, 0, 0);

	if (new_socket < 0)
	{
		perror("AcceptSocket ERROR");
		exit(EXIT_FAILURE);
	}
	return new_socket;
}

void ReadMsg(SOCKET Socket, char* msg)
{
	int flags = 0;
	int length = recv(Socket, msg, SMSG, flags);
	if (length  < 0)
	{

		perror("ReadMsg ERROR");
		exit(EXIT_FAILURE);
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
void WriteMsg(SOCKET Socket, const char* msg)
{
	int flags = 0;
	int  length = send(Socket, msg, strlen(msg), flags);
	if (length < 0)
	{

		perror("WriteMsg ERROR");
		exit(EXIT_FAILURE);
	}
}
void Start(){
//
	WSADATA wsaData;
	WSAStartup(WINSOCK_VERSION, &wsaData);

	SOCKET Socket = CreateSocket();
	BindSocket(Socket);

	listen(Socket, SOMAXCONN);

	char read_msg[SMSG];

	while (1)
	{
		SOCKET new_socket = AcceptSocket(Socket);
		ReadMsg(new_socket, read_msg);
		WriteMsg(new_socket, ConstructMsg(read_msg));
		shutdown(new_socket, SD_BOTH);
	}
}