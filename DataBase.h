#pragma once
#include <vector>
#include "AbsDiv.h"


class DataBase //ЫыыаыаыААаыаыы
{
	std::vector <AbsDiv*> mainVector;
public:
	AbsDiv* findByNameOfManag(const std::string& name) const;
	void sortByName();
	void sortByEmplo();
	std::vector <AbsDiv*> selectByAPE(int number) const;
	std::vector <AbsDiv*> selectByEmplo(int number) const;
	void addDivision(AbsDiv* div);
	DataBase() = default;
	DataBase(const std::vector <AbsDiv*>& vector);
	~DataBase();
};