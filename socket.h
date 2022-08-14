#pragma once

#ifndef _WINSOCK_DEPRECATED_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#endif
#ifdef _WIN32
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")
#else 
#include <sys/sock.h>
#include <aspas/inet.h>
#endif

#include <iostream>

class Socket {
private:
	char* ip_{ new char[500] };
	int port_;
	int type_;
	int family_;
	int protocol_;
	int count_p_;

	struct sockaddr_in addr;

#ifdef _WIN32
	SOCKET __socket__;

#else 
	int __socket__;

#endif
public:
	Socket(char* ip, int port, int cout_p, int type, int family, int protocol) :
		ip_{ ip },
		port_{ port },
		count_p_{ cout_p },
		type_{ type },
		family_{ family },
		protocol_{ protocol }
	{
	};

	~Socket() {};

	sockaddr_in getAddr() {
		return this->addr;
	}

	const char* getIp() {
		return this->ip_;
	}

	int getPort() {
		return this->port_;
	}

	int getFamily() {
		return this->family_;
	}


	void registerAddr() {
		addr.sin_family = this->getFamily();
		addr.sin_addr.s_addr = inet_addr(this->getIp());
		addr.sin_port = htons(this->getPort());
	}

	bool socket_() {
#ifdef _WIN32
		WSADATA data;
		int a{ WSAStartup(MAKEWORD(2, 2), &data) };
		if (a < 0) {
			std::cout << "PROBLEMA NO WSASTARTUP(2,2)" << '\n';
		}
#endif 

		this->__socket__ = { socket(addr.sin_family, this->type_, this->protocol_)};
		if (__socket__ > 0) {
			return true;
		}
		else {
			return false;
		}

		return false;
	}

#ifdef _WIN32
	SOCKET getSocket() {
		return this->__socket__;
	}
#else
	int getSocket() {
		return this->__socket__;
	}
#endif

	bool bind_() {
		int si__addr__{ sizeof(addr) };
		int bi{ bind(this->getSocket(), (sockaddr*)&addr, si__addr__) };
		if (bi >= 0) {
			return true;
		}
		else {
			return false;
		}

		return false;
	}

	bool connect_() {
		int si_addr__{ sizeof(addr) };
		int c = connect(this->getSocket(), (sockaddr*)&addr, si_addr__);
		if (c >= 0) {
			return true;
		}
		else {
			return false;
		}

		return false;
	}

	int getCountP() {
		return this->count_p_;
	}

	bool listen_() {
		int li{ listen(this->getSocket(), this->getCountP()) };
		if (li >= 0) {
			return true;
		}
		else {
			return false;
		}

		return false;
	}

#ifdef _WIN32
	SOCKET accept_() {
		int si___{ sizeof(addr) };
		SOCKET __client__{ accept(this->getSocket(), (sockaddr*)&addr, &si___) };
		if (__client__ >= 0) {
			return __client__;
		}
		else {
			return 0;
		}

		return 0;
	}
#else 
	int accept_() {
		int si___{ sizeof(addr) };
		int __client__{ accept(this->getSocket(), (sockaddr*)&addr, &si___) };
		if (__client__ >= 0) {
			return __client__;
		}
		else {
			return 0;
		}

		return 0;
	}
#endif

	bool messageSend(const char* buffer, int flag) {
		int teste = sizeof(buffer);
		int se{ send(this->getSocket(), buffer, teste, flag) };
		if (se >= 0) {
			return true;
		}
		else {
			return false;
		}

		return false;
	}

	bool messageRev(char* buffer, int flag) {
		int teste = sizeof(buffer);
		int re{ recv(this->getSocket(), buffer, teste, flag) };
		if (re >= 0) {
			return true;
		}
		else {
			return false;
		}

		return false;
	}
};
