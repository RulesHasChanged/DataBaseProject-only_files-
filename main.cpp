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
А, ну да, ещё память чистить

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

	std::unordered_map<std::string, DataBase> mapa;

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
					EduDiv* newERecord = new EduDiv;

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
					newERecord->numberOfGradStudSet(std::stoi(command)); //Exception

					std::cout << "Enter the number of employees: ";
					std::cin >> command;
					transform(command);
					newERecord->numberOfEmploSet(std::stoi(command)); //Exception

					bool flag = true;
					while (flag)
					{
						std::cout << "Do you wanna add new information about projects? (Y/n): ";
						std::cin >> command;
						transform(command);

						if (command == "y")
						{
							std::cout << "Enter name of project: ";
							std::cin >> command;
							transform(command);

							std::string name;

							name = command;

							std::cout << "Enter the price: ";
							std::cin >> command;
							transform(command);

							Project pro;
							pro.name = name;
							pro.price = std::stoi(command); //Exception

							newERecord->addProject(pro);
						}
						else if (command == "n")
						{
							flag = false;
						}
						else
						{
							//---------------------------------------------------------------------------------
						}
					}

					newDataBase.addDivision(newERecord);
				}
				else if (command == "s")
				{
					//new SciDiv...
					SciDiv* newSRecord = new SciDiv;

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
					newSRecord->numberOfGradStudSet(std::stoi(command)); //Exception

					std::cout << "Enter the number of employees: ";
					std::cin >> command;
					transform(command);
					newSRecord->numberOfEmploSet(std::stoi(command)); //Exception



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

							int course = 0;
							int stud = 0;
							
							course = std::stoi(command); //Exception

							std::cout << "Enter number of students: ";
							std::cin >> command;
							transform(command);

							stud = std::stoi(command); //Exception

							std::cout << "Enter price value: ";
							std::cin >> command;
							transform(command);

							SciGroup group;
							group.price = std::stoi(command); //Угадай, что тут? (uoıʇdǝɔxǝ)
							group.students = stud;

							newSRecord->addGroup(course, group);
						}
						else if (command == "n")
						{
							flag = false;
						}
						else
						{
							std::cout << "Invalid command\n";
						}

					}

					newDataBase.addDivision(newSRecord);
				}
				else
				{
					std::cout << "Invalid command\n";
				}

				mapa[newDataBase.nameOfDBGet()] = newDataBase;

				std::cout << "Do ya wanna save this data base in the file? (Y/n): ";
				std::cin >> command;
				transform(command);

				if (command == "y") newDataBase.saveCurrent();

			}
			else if (command == "n")
			{
				std::cout << "Do ya wanna save this data base in the file? (Y/n): ";
				std::cin >> command;
				transform(command);

				if (command == "y") newDataBase.saveCurrent();
			}
			else std::cout << "Wrong command, please try again\n";
		}
		else if (command == "open") 
		{
			std::cout << "Enter name of DataBase: ";
			std::string dBname;
			std::getline(std::cin, dBname);

			mapa[dBname] = DataBase::fromFile(dBname);
		}
		else if (command == "save") 
		{
			std::cout << "Enter name of DataBase: ";
			std::string dBname;
			std::getline(std::cin, dBname);
			if (mapa.find(dBname) == mapa.end()) 
			{
				std::cout << "There is no database with this name\n";
			}
			else 
			{
				mapa[dBname].saveCurrent();
			}
		}
		else if (command == "delete")
		{
			std::cout << "Enter name of DataBase: ";
			std::string dBname;
			std::getline(std::cin, dBname);
			if (mapa.find(dBname) == mapa.end())
			{
				std::cout << "There is no database with this name\n";
			}
			else
			{
				bool isIndexCorrect = false;
				int index;

				while (!isIndexCorrect)
				{
					std::cout << "Enter index of record: ";
					std::cin >> index;
					try
					{
						mapa[dBname].mainVectorGet().at(index);
						isIndexCorrect = true;
					}
					catch (std::out_of_range&)
					{
						std::cout << "There is no your index\n";
					}
				}
				mapa[dBname].deleteDivision(index);
				std::cout << "Your record was deleted succesfully\n";
			}
		}
		else if (command == "selection")
		{
			std::cout << "Choose type of selection (A/E): ";
			std::cin >> command;
			transform(command);
			std::cout << "Enter the name of DataBase you need: ";
			std::string dBname;
			std::getline(std::cin, dBname);

			int number;
			std::cout << "Enter number: ";
			std::cin >> number;

			std::cout << "Enter name for new DataBase: ";
			std::string name;
			std::getline(std::cin, dBname);

			if (mapa.find(dBname) == mapa.end())
			{
				std::cout << "There is no database with this name\n";
			}
			else
			{
				if (command == "a")
				{
					DataBase kill_me = DataBase(mapa[dBname].selectByAPE(number));
					mapa[name] = kill_me;
				}
				else if (command == "e")
				{
					DataBase kill_me = DataBase(mapa[dBname].selectByEmplo(number));
					mapa[name] = kill_me;
				}
				else
				{
					std::cout << "Invalid command\n";
				}
			}

		}
		else if (command == "help")
		{
			std::cout << "create - create new DataBase and enter the information about it\n" << "open - open existing DataBase\n";
			std::cout << "delete - delete existing DataBase record\n" << "selection - you may type this command to select records you need and create new DataBase\n";
			std::cout << "show - to show all DataBases\n" << "save - to save DataBase in to the file\n";
		}
		else 
		{
			std::cout << "Invalid command\n";
		}

	}

	//Пункты, которые ещё должны быть добавлены в логику СУБД (их команды уже есть)
	//- Открыть БД или удалить её
	//- Выборка записей из БД и сохранение их как новой БД
	//- Вывод списка существующих баз данных
}