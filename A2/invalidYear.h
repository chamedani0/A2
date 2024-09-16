#pragma once
#include <iostream>
#include <string>
using namespace std;

class invalidYear
{
	private:
		string message;

	public:

		invalidYear(char, int);
		invalidYear();

		string what();
};