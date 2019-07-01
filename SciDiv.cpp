#include "SciDiv.h"
#include <iostream>

std::string SciDiv::getMapa() const //Преобразование записи о студенте (unordered_map) в строку формата:
                                    /*<курс>*пробел*<студенты>*пробел*<стоимость обучения>*перенос строки*/{
    std::string loles = std::to_string(mapa.size()) + "\n";
    for (const auto& pair : mapa)
    {
        loles += std::to_string(pair.first) + " " + std::to_string(pair.second.price) + " " + 
        std::to_string(pair.second.students) + "\n";
    }
    return loles;
} 

std::string SciDiv::toStringMethod() const  //Виртуалбный метод для преоброзования полей класса SciDiv в строку
{
    return "Science\n" + SciDiv::nameOfInstGet() + "\n"
		+ SciDiv::nameOfManagGet()+ "\n" 
		+ std::to_string(SciDiv::numberOfGradStudGet()) + "\n"
		+ std::to_string(SciDiv::numberOfEmploGet()) + "\n"
		+ getMapa() + "\n";
}

void SciDiv::toCoutMethod() const
{
    std::cout << "Record type: " << SciDiv::toStringMethod(); 
}

int SciDiv::numberOfGradStudGet() const
{
	int result = AbsDiv::numberOfGradStudGet();

	for (const auto& pair : mapa)
	{
		result += pair.second.students;
	}

	return result;
}

void SciDiv::addGroup(int course, const SciGroup& group)
{
	mapa[course] = group;
}