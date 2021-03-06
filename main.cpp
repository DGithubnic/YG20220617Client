#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <iostream>
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main()
{
	WSAData wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN ServerSockADDR;
	memset(&ServerSockADDR, 0, sizeof(SOCKADDR_IN));
	ServerSockADDR.sin_family = PF_INET;
	ServerSockADDR.sin_addr.s_addr = inet_addr("172.16.5.65");   // "172.16.5.216", "127.0.0.1"
	ServerSockADDR.sin_port = htons(20000);

	if (connect(ServerSocket, (SOCKADDR*)&ServerSockADDR, sizeof(SOCKADDR_IN)) == SOCKET_ERROR) // 자기 ip와 port 필요없다. 서버에 접속하면 된다.
	{
		cout << "Connect Failed." << endl;
		exit(-1);
	}

	char Message[1024] = { 0, };
	int RevLength = recv(ServerSocket, Message, sizeof(Message), 0);

	cout << Message << endl;



	WSACleanup();
}