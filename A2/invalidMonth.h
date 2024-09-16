#pragma once
#include <iostream>
#include <string>
using namespace std;

class invalidMonth
{
	private:
		string message;

	public:

		invalidMonth(char, int);
		invalidMonth(int);
		invalidMonth();

		string what();
};