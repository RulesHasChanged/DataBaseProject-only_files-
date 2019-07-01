#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "DataBase.h"
#include "AbsDiv.h"
#include "EduDiv.h"

int main()
{
	//Приветсвие, HELP меню
	std::cout << "####################################################################" << std::endl;
	std::cout << " ____                      ____" << std::endl;
	std::cout << "|  _ \\  __ _  _____  __ _ |  _ \\  __ _  ___  ___ " << std::endl;
	std::cout << "| | | |/ _' ||_   _|/ _' || |/ / / _' |/ _/ / _ \\" << std::endl;
	std::cout << "| |_| | (_| |  | | ( (_| || |_\\ \\ (_| |\\__ \\  __/" << std::endl;
	std::cout << "|____/ \\__,_|  |_|  \\__,_||_____/\\__,_|____/\\___/  " << std::endl;
	std::cout << "                                      by 'TEST Team Please Ignore'" << std::endl;
	std::cout << "####################################################################" << std::endl;
	std::cout << std::endl << std::endl << "Enter 'H' in any moment, to start HELP menu, also enter 'Q' to close program" << std::endl;

	char command; //Символ - команда, которая вводится пользователем

	while (true)
	{
		std::cout << ">";
		std::cin >> command; //Ввод команды
		switch (command) //СУБД (логика ещё не доделана)
		{
		case 'H':
			std::cout << "O - open existing database" << std::endl;
			std::cout << "C - create a new database" << std::endl;
			std::cout << "E - chousE a rEcord and crEatE nEw databasE" << std::endl;
			std::cout << "W - show the existing databases" << std::endl;
			std::cout << "Q - close the program" << std::endl;
			break;
		case 'Q':
			return 0;
		case 'O':
		case 'C':
		case 'E':
		case 'W':
		default: break;
		}
		std::cout << std::endl;
	}

	//Пункты, которые ещё должны быть добавлены в логику СУБД (их команды уже есть)
	//- Открыть или создать БД
	//- Выборка записей из БД и сохранение их как новой БД
	//- Вывод списка существующих баз данных

}
