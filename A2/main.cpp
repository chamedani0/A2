#include "invalidDay.h";
#include "invalidMonth.h";
#include "invalidYear.h";

int main()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "Test Data #" << i + 1 << ":\n";

		string dateNumeric = "00-00-0000";
		int month = 0;
		int day = 0;
		int year = 0;
		bool isLeapYear = false;

		cout << "Please enter your date of birth (MM-DD-YYYY): ";
		cin >> dateNumeric;

		if (dateNumeric[1] == '-')
		{
			dateNumeric = "0" + dateNumeric;
		}

		if (dateNumeric[4] == '-')
		{
			dateNumeric.insert(3, "0");
		}

		string monthTemp = dateNumeric.substr(0, 2);
		string dayTemp = dateNumeric.substr(3, 2);
		string yearTemp = dateNumeric.substr(6, 4);

		try
		{
			for (int i = 0; i < 2; i++)
			{
				if (dayTemp[i] < 48 || dayTemp[i] > 57) {
					throw invalidDay(dayTemp[i], i + 1);
				}
			}

			for (int i = 0; i < 2; i++)
			{
				if (monthTemp[i] < 48 || monthTemp[i] > 57) {
					throw invalidMonth(monthTemp[i], i + 1);
				}
			}

			for (int i = 0; i < 4; i++)
			{
				if (yearTemp[i] < 48 || yearTemp[i] > 57) {
					throw invalidYear(yearTemp[i], i + 1);
				}
			}

			month = stoi(monthTemp);
			day = stoi(dayTemp);
			year = stoi(yearTemp);

			int yearAbs = abs(year);
			bool isLeapYear = false;

			if ((yearAbs % 4) == 0)
			{
				if ((yearAbs % 100) == 0)
				{
					if (yearAbs % 400 == 0)
					{
						isLeapYear = true;
					}
					else
					{
						isLeapYear = false;
					}
				}
				else
				{
					isLeapYear = true;
				}
			}
			else
			{
				isLeapYear = false;
			}

			switch (month)
			{
			case 1: monthTemp = "January";
				break;
			case 2: monthTemp = "February";
				break;
			case 3: monthTemp = "March";
				break;
			case 4: monthTemp = "April";
				break;
			case 5: monthTemp = "May";
				break;
			case 6: monthTemp = "June";
				break;
			case 7: monthTemp = "July";
				break;
			case 8: monthTemp = "August";
				break;
			case 9: monthTemp = "September";
				break;
			case 10: monthTemp = "October";
				break;
			case 11: monthTemp = "November";
				break;
			case 12: monthTemp = "December";
				break;
			default: throw invalidMonth(month);
				break;
			}

			if (month == 1 || month == 3 || month == 5 ||
				month == 7 || month == 8 || month == 10 ||
				month == 12)
			{
				if (day < 1 || day > 31)
				{
					throw invalidDay(day);
				}
			}
			else if (month == 4 || month == 6 || month == 9 ||
				month == 11)
			{
				if (day < 1 || day > 30)
				{
					throw invalidDay(day);
				}
			}
			else if (month == 2 && isLeapYear)
			{
				if (day < 1 || day > 29)
				{
					throw invalidDay(day);
				}
			}
			else if (month == 2 && !isLeapYear)
			{
				if (day < 1 || day > 28)
				{
					throw invalidDay(day);
				}
			}

			cout << "Your date of birth is " << monthTemp << " " << day << ", " << year << endl << endl;
		}
		catch (invalidDay obj)
		{
			cout << obj.what() << endl << endl;
		}
		catch (invalidMonth obj)
		{
			cout << obj.what() << endl << endl;
		}
		catch (invalidYear obj)
		{
			cout << obj.what() << endl << endl;
		}
	}
	return 0;
}
