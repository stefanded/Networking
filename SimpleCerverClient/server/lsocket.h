// Task1GL.cpp : Defines the entry point for the application.
//
#define LIBRARY_LSOCKET_H
#ifdef LIBRARY_LSOCKET_H

#define SMSG 256//size msg
#define PORT 1234

#include<sys/socket.h>
#include <netinet/in.h>
#define IP INADDR_LOOPBACK
int CreateSocket();
void BindSocket(int Socket);
int AcceptSocket(int Socket);
void ReadMsg(int Socket, char* msg);
const char* ConstructMsg(const char* way);
void WriteMsg(int Socket, const char* msg);
void Start();
#endif