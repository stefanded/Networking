// Task1GL.cpp : Defines the entry point for the application.
//
#define LIBRARY_WSOCKET_H
#ifdef LIBRARY_WSOCKET_H


#define SMSG 256
#define PORT 12345


#include<WinSock2.h>
#include <windows.h>
#define IP INADDR_LOOPBACK

static const char*const file = "C:\\Users\\ADMIN\\Desktop\\basecamp lection\\Git - First Steps.pptx";

SOCKET CreateSocket();
void ConnectSocket(SOCKET S);
void ReadMsg(SOCKET Socket, char* msg);
void WriteMsg(SOCKET Socket, const char* msg);

void Start();
#endif
