// Task1GL.cpp : Defines the entry point for the application.
//
#define LIBRARY_WSOCKET_H
#ifdef LIBRARY_WSOCKET_H

#define SMSG 256//size msg
#define PORT 12345


#include<WinSock2.h>
#include <windows.h>

#define IP INADDR_LOOPBACK

SOCKET CreateSocket();
void BindSocket(SOCKET Socket);
//
SOCKET AcceptSocket(SOCKET Socket);
void ReadMsg(SOCKET Socket, char* msg);
//
const char* ConstructMsg(const char* way);
void WriteMsg(SOCKET Socket, const char* msg);
//
void Start();
#endif