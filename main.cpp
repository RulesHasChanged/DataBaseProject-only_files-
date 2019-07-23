#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <experimental/filesystem>
#include "DataBase.h"
#include "AbsDiv.h"
#include "EduDiv.h"
#include "SciDiv.h"

namespace fs = std::experimental::filesystem;

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

			DataBase* newDataBase = new DataBase(command);

			std::cout << "Empty DataBase was created successfully\n";

			bool flags = true;

			while (flags) 
			{
				std::cout << "Do you wanna create new record? (Y/n): ";
				std::cin >> command;
				transform(command);
				if (command == "y")
				{
					std::cout << "Enter the name of institution: ";
					std::cin.ignore();
					std::getline(std::cin, command);
					transform(command);
					std::string nameOfInst = command;

					std::cout << "Enter the name of manager of institution: ";
					std::cin.ignore();
					std::getline(std::cin, command);
					transform(command);
					std::string nameOfManage = command;

					std::cout << "Enter the number of graduate students: ";
					std::cin >> command;
					transform(command);
					int numbrOfGrad;
					try
					{
						 numbrOfGrad = std::stoi(command);
					}
					catch (std::invalid_argument&)
					{
						std::cout << "Enter the number!\n";
					};
					std::cout << "Enter the number of employees: ";
					std::cin >> command;
					transform(command);

					int numbOfEmployees;

					try
					{
						numbOfEmployees = std::stoi(command);
					}
					catch (std::invalid_argument&)
					{
						std::cout << "Enter the number!\n";
					};

					std::cout << "Please, choose type of your new record (E/S): ";
					std::cin >> command;
					transform(command);

					if (command == "e")
					{
						EduDiv* newERecord = new EduDiv;

						newERecord->nameOfInstSet(nameOfInst);
						newERecord->nameOfManagSet(nameOfManage);
						newERecord->numberOfEmploSet(numbOfEmployees);
						newERecord->numberOfGradStudSet(numbrOfGrad);

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
								try
								{
									pro.price = std::stoi(command);
								}
								catch (std::invalid_argument&)
								{
									std::cout << "Enter the number!\n";
								};

								newERecord->addProject(pro);
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
						newDataBase->addDivision(newERecord);
						delete newERecord;
					}
					else if (command == "s")
					{
						SciDiv* newSRecord = new SciDiv;

						newSRecord->nameOfInstSet(nameOfInst);
						newSRecord->nameOfManagSet(nameOfManage);
						newSRecord->numberOfEmploSet(numbOfEmployees);
						newSRecord->numberOfGradStudSet(numbrOfGrad);

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

								try
								{
									course = std::stoi(command);
								}
								catch (std::invalid_argument&)
								{
									std::cout << "Enter the number!\n";
								};

								std::cout << "Enter number of students: ";
								std::cin >> command;
								transform(command);

								try
								{
									stud = std::stoi(command);
								}
								catch (std::invalid_argument&)
								{
									std::cout << "Enter the number!\n";
								};

								std::cout << "Enter price value: ";
								std::cin >> command;
								transform(command);

								SciGroup group;
								try
								{	
									group.price = std::stoi(command);
								}
								catch (std::invalid_argument&)
								{
									std::cout << "Enter the number!\n";
								};
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
						newDataBase->addDivision(newSRecord);
						delete newSRecord;
					}
					else
					{
						std::cout << "Invalid command\n";
					}

					mapa[newDataBase->nameOfDBGet()] = *newDataBase;

					std::cout << "Do ya wanna save this data base in the file? (Y/n): ";
					std::cin >> command;
					transform(command);

					if (command == "y") newDataBase->saveCurrent();
				}
				else if (command == "n")
				{
					std::cout << "Do ya wanna save this data base in the file? (Y/n): ";
					std::cin >> command;
					transform(command);

					if (command == "y") newDataBase->saveCurrent();

					flags = false;
				}
				else std::cout << "Wrong command, please try again\n";
			}
			delete newDataBase;
		}
		else if (command == "open")
		{
			std::cout << "Enter name of DataBase: ";
			std::string dBname;
			std::cin.ignore();
			std::getline(std::cin, dBname);

			DataBase* db = new DataBase(dBname);

			mapa[dBname] = *db;
			delete db;
			mapa[dBname].fromFile(dBname);

			for (AbsDiv* vector : mapa[dBname].mainVectorGet())
			{
				vector->toCoutMethod();
			}

			std::cout << ">";
			std::cin >> command;
			transform(command);

			if (command == "add")
			{
				bool flags = true;

				while (flags)
				{
					std::cout << "Do you wana create new record? (Y/n): ";
					std::cin >> command;
					transform(command);

					if (command == "y")
					{
						std::cout << "Enter the name of institution: ";
						std::getline(std::cin, command);
						transform(command);
						std::string nameOfInst = command;

						std::cout << "Enter the name of manager of institution: ";
						std::getline(std::cin, command);
						transform(command);
						std::string nameOfManag = command;

						std::cout << "Enter the number of graduate students: ";
						std::cin >> command;
						transform(command);
						int numberOfGrad;
						try
						{
							numberOfGrad = std::stoi(command);
						}
						catch (std::invalid_argument&)
						{
							std::cout << "Enter the number!\n";
						};

						std::cout << "Enter the number of employees: ";
						std::cin >> command;
						transform(command);
						int numberOfEmployees;
						try 
						{
							numberOfEmployees = std::stoi(command);
						}
						catch (std::invalid_argument&)
						{
							std::cout << "Enter the number!\n";
						};
						std::cout << "Please, choose type of your new record (E/S): ";
						std::cin >> command;
						transform(command);

						if (command == "e")
						{
							EduDiv* newERecord = new EduDiv;

							newERecord->nameOfInstSet(nameOfInst);
							newERecord->nameOfManagSet(nameOfManag);
							newERecord->numberOfEmploSet(numberOfEmployees);
							newERecord->numberOfGradStudSet(numberOfGrad);

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
									try
									{	
										pro.price = std::stoi(command);
									}
									catch (std::invalid_argument&)
									{
										std::cout << "Enter the number!\n";
									};

									newERecord->addProject(pro);
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
							mapa[dBname].addDivision(newERecord);
							delete newERecord;
						}
						else if (command == "s")
						{
							SciDiv* newSRecord = new SciDiv;

							newSRecord->nameOfInstSet(nameOfInst);
							newSRecord->nameOfManagSet(nameOfManag);
							newSRecord->numberOfEmploSet(numberOfEmployees);
							newSRecord->numberOfGradStudSet(numberOfGrad);

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

									try
									{
										course = std::stoi(command); 
									}
									catch (std::invalid_argument&)
									{
										std::cout << "Enter the number!\n";
									};

									std::cout << "Enter number of students: ";
									std::cin >> command;
									transform(command);

									try
									{
										stud = std::stoi(command);
									} 
									catch (std::invalid_argument&)
									{
										std::cout << "Enter the number!\n";
									};

									std::cout << "Enter price value: ";
									std::cin >> command;
									transform(command);

									SciGroup group;
									try 
									{
										group.price = std::stoi(command);
									}
									catch (std::invalid_argument&)
									{
										std::cout << "Enter the number!\n";
									};
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
							mapa[dBname].addDivision(newSRecord);
							delete newSRecord;
						}
						else
						{
							std::cout << "Invalid command\n";
						}
					}
					else if (command == "n")
					{
						std::cout << "Do ya wanna save this data base in the file? (Y/n): ";
						std::cin >> command;
						transform(command);

						if (command == "y") mapa[dBname].saveCurrent();

						flags = false;
					}
					else std::cout << "Wrong command, please try again\n";
				}
			}
		}
		else if (command == "save")
		{
			std::cout << "Enter name of DataBase: ";
			std::string dBname;
			std::getline(std::cin, dBname);
			if (mapa.find(dBname) == mapa.end())
			{
				std::cout << "There is no database with that name\n";
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
			std::cin.ignore();
			std::getline(std::cin, dBname);
			if (mapa.find(dBname) == mapa.end())
			{
				std::cout << "There is no database with that name\n";
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
						std::cout << "There is no your index record\n";
					}
				}
				mapa[dBname].deleteDivision(index);
				mapa[dBname].saveCurrent();
				std::cout << "Your record was deleted succesfully\n";
				std::cout << "DataBase was saved succesfully\n";
			}
		}
		else if (command == "selection")
		{
			std::cout << "Choose type of selection (A/E): ";
			std::cin >> command;
			transform(command);
			std::cout << "Enter the name of DataBase you need: ";
			std::string dBname;
			std::cin.ignore();
			std::getline(std::cin, dBname);

			int number;
			std::cout << "Enter number: ";
			std::cin >> number;

			std::cout << "Enter name for new DataBase: ";
			std::string name;
			std::cin.ignore();
			std::getline(std::cin, name);

			if (mapa.find(dBname) == mapa.end())
			{
				std::cout << "There is no database with that name\n";
			}
			else
			{
				if (command == "a")
				{
					DataBase* kill_me = new DataBase(mapa[dBname].selectByAPE(number), name);
					mapa[name] = *kill_me;
					mapa[name].saveCurrent();
					delete kill_me;
				}
				else if (command == "e")
				{
					DataBase* kill_me = new  DataBase(mapa[dBname].selectByEmplo(number), name);
					mapa[name] = *kill_me;
					mapa[name].saveCurrent();
					delete kill_me;
				}
				else
				{
					std::cout << "Invalid command\n";
				}
			}
		}
		else if (command == "show")
		{
			for (const auto& p : fs::directory_iterator(".")) {
				std::string exs = p.path().filename().extension().string();;
				std::string name = p.path().filename().stem().string();

				if (exs == ".txt")
					std::cout << name + "\n";
			}
		}
		else if (command == "sort")
		{
			std::cout << "Enter name of BD: ";
			std::cin >> command;
			transform(command);

			std::string dBname = command;

			std::cout << "Choose type of sort (n/e): ";
			std::cin >> command;
			transform(command);

			if (command == "n")
				mapa[dBname].sortByName();
			else if (command == "e")
				mapa[dBname].sortByEmplo();
			else std::cout << "Bad type!\n";

			std::cout << "Do ya wanna save this data base in the file? (Y/n): ";
			std::cin >> command;
			transform(command);

			if (command == "y") mapa[dBname].saveCurrent();
		}
		else if (command == "find")
		{
			std::cout << "Enter name of BD: ";
			std::cin >> command;
			transform(command);

			std::string dBname = command;

			std::cout << "Enter name of Manager: ";
			std::cin.ignore();
			std::getline(std::cin, command);
			std::cout << std::endl;

			mapa[dBname].findByNameOfManag(command)->toCoutMethod();
		}
		else if (command == "students")
		{
			std::cout << "Enter name of DataBase: ";
			std::string dBname;
			std::cin.ignore();
			std::getline(std::cin, dBname);
			if (mapa.find(dBname) == mapa.end())
			{
				std::cout << "There is no database with that name\n";
			}
			else {
				for (AbsDiv* record : mapa[dBname].mainVectorGet()) {
					std::cout << record->nameOfInstGet() << " " << record->numberOfGradStudGet() << "\n";
				}
			}
		}
		else if (command == "help")
		{
			std::cout << "create - create new DataBase and enter the information about it\n" << "open - open existing DataBase (file)\n";
			std::cout << "delete - delete existing DataBase record\n" << "selection - you may type this command to select records you need and create new DataBase\n";
			std::cout << "show - to show all DataBases\n" << "save - to save DataBase in to the file\n" << "sort - if you wanna choose one of two type of sort, and then sort records\n";
			std::cout << "find - to find record by name of Manager\n" <<"students - to find record by number of students\n";
		}
		else if (command == "quit")
		{
			return 0;
		}
		else
		{
			std::cout << "Invalid command\n";
		}
	}
}