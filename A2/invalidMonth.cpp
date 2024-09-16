#include "invalidMonth.h"

invalidMonth::invalidMonth(char character, int index)
{
	string charStr = string(1, character);
	string indStr = to_string(index);

	message = "The character '" + charStr +
		"' at Index #" + indStr +
		" of the month is not an integer!";
}

invalidMonth::invalidMonth(int num)
{
	string numStr = to_string(num);
	message = "The number '" + numStr +
		"' inputted for the month is out of range"
		" and does not correlate to a month!";
}

invalidMonth::invalidMonth()
{
	message = "Input for the day is invalid!";
}

string invalidMonth::what()
{
	return message;
}