#pragma once
#include <vector>
#include "AbsDiv.h"


class DataBase 
{
	std::vector <AbsDiv*> mainVector;
	std::string nameOfDataBase;
public:
	std::vector <AbsDiv*> mainVectorGet() const;
	void deleteDivision(int index);
	std::string nameOfDBGet() const;
	AbsDiv* findByNameOfManag(const std::string& name) const;
	void sortByName();
	void sortByEmplo();
	std::vector <AbsDiv*> selectByAPE(int number) const;
	std::vector <AbsDiv*> selectByEmplo(int number) const;
	void addDivision(AbsDiv* div);
	void saveCurrent() const;
	DataBase() = default;
	DataBase(std::string name);
	DataBase(const std::vector <AbsDiv*>& vector);
	~DataBase();
	static DataBase fromFile(const std::string& fileName);
};