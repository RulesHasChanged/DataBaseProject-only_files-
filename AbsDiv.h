#pragma once
#include <string>

class AbsDiv  //Класс-родитель и матушка всех классов-записей в БД 
{
	std::string nameOfInstitution;
	std::string nameOfManager;
	int gradStuds = 0;
	int employees = 0;
public:
	void nameOfInstSet(std::string a);
	void nameOfManagSet(std::string a);
	void numberOfGradStudSet(int a);
	void numberOfEmploSet(int a);
	std::string nameOfInstGet() const;
	std::string nameOfManagGet() const;
	virtual int numberOfGradStudGet() const;
	int numberOfEmploGet()const;
	virtual std::string toStringMethod() const = 0;
    virtual void toCoutMethod() const = 0;
	AbsDiv();
	~AbsDiv();
};

