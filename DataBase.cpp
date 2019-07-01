#include "DataBase.h"
#include "EduDiv.h"
#include "SciDiv.h"
#include <iostream>
#include <algorithm>


DataBase::DataBase(const std::vector <AbsDiv*>& vector) /* Копирование словленного вектора, выброшенного из выборки () */
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

DataBase::~DataBase()
{
	for (AbsDiv* div : mainVector)
	{
		delete div;
	}
}