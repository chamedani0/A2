#include "invalidDay.h"

invalidDay::invalidDay(char character, int index)
{
	string charStr = string(1, character);
	string indStr = to_string(index);

	message = "The character '" + charStr + 
			  "' at Index #" + indStr + 
			  " of the day is not an integer!";
}

invalidDay::invalidDay(int num)
{
	string numStr = to_string(num);
	message = "The number '" + numStr +
			  "' inputted for the day is out of range"
			  " for the given month!";
}

invalidDay::invalidDay()
{
	message = "Input for the day is invalid!";
}

string invalidDay::what()
{
	return message;
}