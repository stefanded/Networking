
//#ifdef _WIN32

#include<stdio.h>
#include<string.h>
#include"wsocket.h"
SOCKET CreateSocket()
{
	SOCKET Socket = socket(AF_INET, SOCK_STREAM, 0);
	if (Socket < 0)
	{
		perror("CreateSocket ERROR");
	}
	return Socket;
}
void ConnectSocket(SOCKET S)
{
	struct sockaddr_in s;
	s.sin_family = AF_INET;
	s.sin_port = htons(PORT);
	s.sin_addr.S_un.S_addr = htonl(IP);
	if (connect(S, (struct sockaddr*)&s, sizeof(s)) < 0)
	{
		perror("ConnectSocket ERROR");
		exit(EXIT_FAILURE);
	}
}
void ReadMsg(SOCKET Socket, char* msg)
{
	int flags = 0;
	int length = recv(Socket, msg, SMSG, flags);
	if (length < 0)
	{
		perror("ReadMsg ERROR");
	}
	msg[length] = '\0';
}
void WriteMsg(SOCKET Socket, const char* msg)
{
	int flags = 0;
	int length = send(Socket, msg, strlen(msg), flags);
	if (length <0)
	{
		perror("WriteMsg ERROR");
		
	}
}
void Start(){
	char msg[SMSG];

	WSADATA wsaData;
	WSAStartup(WINSOCK_VERSION, &wsaData);

	while (1)
	{
		SOCKET Socket = CreateSocket();
		ConnectSocket(Socket);

		WriteMsg(Socket, file);
		ReadMsg(Socket, msg);
		shutdown(Socket, SD_BOTH);
		printf("%s\n", msg);
		Sleep(5000);
	}
}
//#endif