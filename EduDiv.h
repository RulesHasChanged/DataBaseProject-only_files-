#pragma once
#include "AbsDiv.h"
#include <vector>


struct Project //Структура "Проект" спешл для класса-наследника EduDiv
{
	std::string name;
	int price;
};

class EduDiv :
	public AbsDiv //Класс-наследник EduDiv - запись в базе данных формата "Образовательное учреждение"
{
	std::vector<Project> projVector;
public:
	std::string getVectorValues() const;
	void addProject(const Project& proj);
    std::string toStringMethod() const override;
    void toCoutMethod() const override;
};

