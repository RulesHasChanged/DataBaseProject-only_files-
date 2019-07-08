#pragma once
#include <string>
#include <istream>

std::string ToolGetline(std::istream& istream) {
	while (istream.peek() == '\n') {
		istream.ignore(1);
	}

	std::string result;
	std::getline(istream, result);
	return result;
}