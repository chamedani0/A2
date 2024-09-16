#pragma once
#include <iostream>
#include <string>
using namespace std;

class invalidDay
{
	private:
		string message;
	
	public:
		
		invalidDay(char, int);
		invalidDay(int);
		invalidDay();

		string what();
};