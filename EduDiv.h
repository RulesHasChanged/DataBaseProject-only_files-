#pragma once
#include "AbsDiv.h"
#include <vector>


struct Project /*Pair?*/ //Структура Проект для класса EduDiv
{
	std::string name;
	int price;
};

class EduDiv : //Класс EduDiv ещё не начинал толком
	public AbsDiv
{
	std::vector<Project> projVector;
public:
	std::string getVectorValues() const;
	void addProject(const Project& proj);
    std::string toStringMethod() const override;
    void toCoutMethod() const override;
};

