#include "DataBase.h"
#include "EduDiv.h"
#include "SciDiv.h"
#include "Tools.h"
#include <iostream>
#include <algorithm>
#include <fstream>


DataBase::DataBase(const std::vector <AbsDiv*>& vector)/* Копирование словленного вектора, выброшенного из выборки () */
{
	for (AbsDiv* div : vector)
	{
		auto edu = dynamic_cast <EduDiv*> (div);

		if (edu == NULL)
		{
			auto sci = dynamic_cast <SciDiv*> (div);
			mainVector.push_back(new SciDiv(*sci));
		}
		else
			mainVector.push_back(new EduDiv(*edu));
	}
}


DataBase::DataBase(std::string name)
	: nameOfDataBase(name)
{}

AbsDiv* DataBase::findByNameOfManag(const std::string& name) const
{
	std::vector <AbsDiv*> result;

	auto iterator = std::find_if(
		mainVector.cbegin(),
		mainVector.cend(),
		[&name](AbsDiv* div)
		{
			return div->nameOfManagGet() == name;
		}
	);

	if (iterator == mainVector.cend())
		return NULL;

	return *iterator;
}

void DataBase::sortByName()
{
	std::sort(
		mainVector.begin(),
		mainVector.end(),
		[](AbsDiv* a, AbsDiv* b) 
		{
			return a->nameOfInstGet() < b->nameOfInstGet();
		}
	);
}

void DataBase::sortByEmplo()
{
	std::sort(
		mainVector.begin(),
		mainVector.end(),
		[](AbsDiv* a, AbsDiv* b)
		{
			return a->numberOfEmploGet() < b->numberOfEmploGet();
		}
	);
}

std::vector <AbsDiv*> DataBase::selectByAPE(int number) const
{
	std::vector <AbsDiv*> result;

	for (AbsDiv* div : mainVector)
	{
		if (div->numberOfGradStudGet() / div->numberOfEmploGet() >= number)
			result.push_back(div);
	}

	return result;
}

std::vector <AbsDiv*> DataBase::selectByEmplo(int number) const
{
	std::vector <AbsDiv*> result;
	for (AbsDiv* div : mainVector)
	{
		if (div->numberOfEmploGet() <= number)
			result.push_back(div);
	}

	return result;
}

void DataBase::addDivision(AbsDiv* div)
{
	mainVector.push_back(div);
}

void DataBase::saveCurrent() const
{
	//Тут логика с сохранением mainVector в отдельный файл (конечное сохранение)
	std::ofstream f_stream;
	f_stream.open(nameOfDataBase + ".txt");

	f_stream << mainVector.size() + "\n";

	for (AbsDiv* div : mainVector)
	{
		f_stream << div->toStringMethod();
	}
	//С закрытием потока справится деструктор, у него это отлично получается
}


void DataBase::deleteDivision(int index) 
{
	mainVector.erase(mainVector.begin() + index);
}

std::string DataBase::nameOfDBGet() const
{
	return nameOfDataBase;
}

std::vector <AbsDiv*> DataBase::mainVectorGet() const
{
	return mainVector;
}

DataBase::~DataBase()
{
	for (AbsDiv* div : mainVector)
	{
		delete div;
	}
}

DataBase DataBase::fromFile(const std::string& fileName)
{
	std::ifstream f_stream;
	f_stream.open(fileName + ".txt");

	DataBase DB = DataBase(fileName);

	int size;
	f_stream >> size;

	for (int i = 0; i < size; i++)
	{
		std::string string;

		f_stream >> string;

		std::string name = ToolGetline(f_stream);
		std::string manage = ToolGetline(f_stream);
		int numberOfGrad;
		std::cin >> numberOfGrad;
		int numberOfEmplo;
		std::cin >> numberOfEmplo;

		if (string == "Education\n")
		{
			EduDiv* ED = new EduDiv;

			ED->nameOfInstSet(name);
			ED->nameOfManagSet(manage);
			ED->numberOfGradStudSet(numberOfGrad);
			ED->numberOfEmploSet(numberOfEmplo);

			int numba;
			std::cin >> numba;

			for (int k = 0; k < numba; k++)
			{
				std::string name;
				int price;
				std::cin >> name;
				std::cin >> price;
				
				Project proj;
				proj.name = name;
				proj.price = price;

				ED->addProject(proj);
			}

			DB.addDivision(ED);
		}
		else
		{
			SciDiv* SD = new SciDiv;

			SD->nameOfInstSet(name);
			SD->nameOfManagSet(manage);
			SD->numberOfGradStudSet(numberOfGrad);
			SD->numberOfEmploSet(numberOfEmplo);

			int numba;
			std::cin >> numba;

			for (int k = 0; k < numba; k++)
			{
				int course;
				std::cin >> course;
				int price;
				int students;
				std::cin >> price;
				std::cin >> students;

				SciGroup group;

				group.price = price;
				group.students = students;

				SD->addGroup(course, group);
			}

			DB.addDivision(SD);
		}
	}

	return DB;
}