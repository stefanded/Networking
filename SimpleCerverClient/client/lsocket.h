// Task1GL.cpp : Defines the entry point for the application.
//
#define LIBRARY_LSOCKET_H
#ifdef LIBRARY_LSOCKET_H

#include <netinet/in.h>
#include <sys/socket.h>

#define SMSG 256
#define PORT 1234

static const char*const file = "/home/stefan/task1/client/wsocket.c";
int CreateSocket();
void ConnectSocket(int S);
void ReadMsg(int Socket, char* msg);
void WriteMsg(int Socket, const char* msg);

void Start();
#endif
