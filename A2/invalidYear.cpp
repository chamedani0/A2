#include "invalidYear.h"

invalidYear::invalidYear(char character, int index)
{
	string charStr = string(1, character);
	string indStr = to_string(index);

	message = "The character '" + charStr +
		"' at Index #" + indStr +
		" of the year is not an integer!";
}

invalidYear::invalidYear()
{
	message = "Input for the year is invalid!";
}

string invalidYear::what()
{
	return message;
}