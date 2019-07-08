#pragma once
#include "AbsDiv.h"
#include <unordered_map>


struct SciGroup //Структура "Количество студентов - цена обучения" для класса SciDiv
{
	int students;
	int price;
};

class SciDiv :
	public AbsDiv  //Класс - запись в БД формата "Научное учреждение"
{
	std::unordered_map<int, SciGroup> mapa;
public:
	std::string getMapa() const;
	void addGroup(int course, const SciGroup& group);
	int numberOfGradStudGet()const override; 
	std::string toStringMethod() const override;
    void toCoutMethod() const override;
};