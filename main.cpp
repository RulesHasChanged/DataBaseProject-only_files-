#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "DataBase.h"
#include "AbsDiv.h"
#include "EduDiv.h"
#include "SciDiv.h"



/*

ВАЖНО!!!!!

Try Catch блоки нужно бахнуть везде, где вылазиет тот или иной exception
А, ну да, ещё память чистить, не забывать ЧИСТИТЬ ПАМЯТЬ! (А то как VS code, блокнот на 0.5гб оперативы, тебе там нормально JS? (зато гит, да))

*/

int transform(std::string comm) //Важно сначала получить строку, а потом закинуть её в функцию, а не запрашивать её в самой функции, так надо (ну можно намного лучше)
{
	std::transform(comm.begin(), comm.end(), comm.begin(), tolower);
	if (comm == "quit") return 0;
}

int main()
{
	std::cout << "####################################################################" << std::endl;
	std::cout << " ____                      ____" << std::endl;
	std::cout << "|  _ \\  __ _  _____  __ _ |  _ \\  __ _  ___  ___ " << std::endl;
	std::cout << "| | | |/ _' ||_   _|/ _' || |/ / / _' |/ _/ / _ \\" << std::endl;
	std::cout << "| |_| | (_| |  | | ( (_| || |_\\ \\ (_| |\\__ \\  __/" << std::endl;
	std::cout << "|____/ \\__,_|  |_|  \\__,_||_____/\\__,_|____/\\___/  " << std::endl;
	std::cout << "                          by Khalidov from 'TEST Team Please Ignore'" << std::endl;
	std::cout << "####################################################################\n\n" << std::endl;
	std::cout << "Type 'help' to start HELP menu, also enter 'Quit' to close program in any moment\n" << std::endl;

	std::string command;

	while (true)
	{
		std::cout << ">";
		std::cin >> command;
		transform(command);

		if (command == "create") 
		{
			std::cout << "Choose a name for your new DataBase: ";
			std::cin >> command;
			transform(command);
			std::cout << "Processing...\n";
			// std::ofstream f_stream;
			// f_stream.open(command + ".txt");
			// DataBase newDataBase;

			DataBase newDataBase = DataBase(command);

			std::cout << "Empty DataBase was created successfully\n";
			std::cout << "Do you wana create new record? (Y/n): ";
			std::cin >> command;
			transform(command);

			if (command == "y")
			{
				std::cout << "Please, choose type of your new record (E/S): ";
				std::cin >> command;
				transform(command);

				if (command == "e")
				{
					//new EduDiv...
					AbsDiv* newERecord = new EduDiv;

					std::cout << "Enter the name of institution: ";
					std::getline(std::cin, command);
					transform(command);
					newERecord->nameOfInstSet(command);

					std::cout << "Enter the name of manager of institution: ";
					std::getline(std::cin, command);
					transform(command);
					newERecord->nameOfManagSet(command);

					std::cout << "Enter the number of graduate students: ";
					std::cin >> command;
					transform(command);
					newERecord->numberOfGradStudSet(std::stoi(command));

					std::cout << "Enter the number of employees: ";
					std::cin >> command;
					transform(command);
					newERecord->numberOfEmploSet(std::stoi(command));



					newDataBase.addDivision(newERecord);
				}
				else if (command == "s")
				{
					//new SciDiv...
					SciDiv newS;
					AbsDiv* newSRecord = &newS;

					std::cout << "Enter the name of institution: ";
					std::cin >> command;
					transform(command);
					newSRecord->nameOfInstSet(command);

					std::cout << "Enter the name of manager of institution: ";
					std::cin >> command;
					transform(command);
					newSRecord->nameOfManagSet(command);

					std::cout << "Enter the number of graduate students: ";
					std::cin >> command;
					transform(command);
					newSRecord->numberOfGradStudSet(std::stoi(command));

					std::cout << "Enter the number of employees: ";
					std::cin >> command;
					transform(command);
					newSRecord->numberOfEmploSet(std::stoi(command));

					bool flag = true;
					while (flag) 
					{
						std::cout << "Do you wanna add new information about students? (Y/n): ";
						std::cin >> command;
						transform(command);

						if (command == "y")
						{
							std::cout << "Enter course: ";
							std::cin >> command;
							transform(command);

							int course, stud;
							
							course = std::stoi(command); //Exception

							std::cout << "Enter number of students: ";
							std::cin >> command;
							transform(command);

							stud = std::stoi(command); //Exception

							std::cout << "Enter price value: ";
							std::cin >> command;
							transform(command);

							SciGroup group;
							group.price = std::stoi(command);
							group.students = stud;

							newSRecord->addGroup(course, group); //Из-за тупой механики (или просто моего непонимания) пришлось мутить гребанный костыль с виртуальными функциями в хидере (зато работает)
						}
						else if (command == "n")
						{
							flag = false;
						}
						else
						{
							//
						}

					}

					newDataBase.addDivision(newSRecord);
				}
				else
				{
					//
				}
			}
			else if (command == "n")
			{
				//No variation...
			}
			else std::cout << "Wrong command, please try again\n";
		}
		else if (command == "open") 
		{

		}
		else if (command == "delete")
		{

		}
		else if (command == "selection")
		{

		}
		else if (command == "help")
		{

		}
		else 
		{

		}

	}

	//Пункты, которые ещё должны быть добавлены в логику СУБД (их команды уже есть)
	//- Открыть или создать БД или удалить её
	//- Выборка записей из БД и сохранение их как новой БД
	//- Вывод списка существующих баз данных
}