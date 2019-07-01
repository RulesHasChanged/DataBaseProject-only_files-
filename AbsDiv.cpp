#include "AbsDiv.h"
#include <string>

void AbsDiv::nameOfInstSet(std::string a)
{
	nameOfInstitution = a;
}

void AbsDiv::nameOfManagSet(std::string a)
{
	nameOfManager = a;
}

void AbsDiv::numberOfGradStudSet(int a)
{
	gradStuds = a;
}

void AbsDiv::numberOfEmploSet(int a)
{
	employees = a;
}

std::string AbsDiv::nameOfInstGet() const
{
	return nameOfInstitution;
}

std::string AbsDiv::nameOfManagGet() const
{
	return nameOfManager;
}

int AbsDiv::numberOfGradStudGet() const
{
	return gradStuds;
}

int AbsDiv::numberOfEmploGet() const
{
	return employees;
}

AbsDiv::AbsDiv()
{}

AbsDiv::~AbsDiv()
{}