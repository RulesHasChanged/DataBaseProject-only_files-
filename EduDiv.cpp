#include "EduDiv.h"
#include <iostream>

std::string EduDiv::getVectorValues() const
{
	std::string result = std::to_string(projVector.size()) + "\n";

	for (const Project& proj : projVector) {
		result += proj.name + "\n" + std::to_string(proj.price) + "\n";
	}

	return result;

}

std::string EduDiv::toStringMethod() const
{
    return "Education\n"
		+ EduDiv::nameOfInstGet() + "\n" 
		+ EduDiv::nameOfManagGet()+ "\n" 
		+ std::to_string(EduDiv::numberOfGradStudGet()) + "\n"
		+ std::to_string(EduDiv::numberOfEmploGet()) + "\n"
		+ getVectorValues();
}

void EduDiv::toCoutMethod() const
{
    std::cout << "Record type: Education\n" 
		+ EduDiv::nameOfInstGet() + "\n"
		+ EduDiv::nameOfManagGet() + "\n"
		+ std::to_string(EduDiv::numberOfGradStudGet()) + "\n"
		+ std::to_string(EduDiv::numberOfEmploGet()) + "\n"
		+ getVectorValues();
}

void EduDiv::addProject(const Project& proj)
{
	projVector.push_back(proj);
}