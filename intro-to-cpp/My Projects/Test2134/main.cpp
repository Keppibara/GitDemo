// Test2134.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <string>
#include <iostream>

using std::string;

int main()
{
	string line;
	std::getline(stream, line);

	std::vector<float> floats;
	string current;

	for (char c : line)
	{
		if (c != ',' && c != ' ')
		{
			current += c;
		}
		else if (c == ' ')
		{
			// convert the string to a float and add it to the vector
			floats.emplace_back(atof(current.c_str()));
			current = "";
		}
	}
	return stream;
}

