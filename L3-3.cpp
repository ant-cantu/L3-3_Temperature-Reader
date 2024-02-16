#include <iostream>

using namespace std;

typedef bool temperature;

//Function Prototypes
bool getData(temperature isHigh);
int averageHigh();
int averageLow();
int indexHighTemp();
int indexLowTemp();

namespace weather
{
	int temp[12][2];		//12 rows, 2 columns
	const int highTemp = 0;	//Column 1 in temp[][]
	const int lowTemp = 1;	//Column 2 in temp[][] 
};

int main()
{
	char q;

	cout << "Anthony Cantu\t" << "L3-3\t" << "L3-3.exe" << endl;
	
	do
	{
		cout << "Enter high temperature for each month" << endl;
	} while (!getData(true));

	do
	{
		cout << "Enter low temperature for each month" << endl;
	} while (!getData(false));

	cout << "Average high temperature: " << averageHigh() << endl;
	cout << "Average low temperature: " << averageLow() << endl;
	cout << "Highest temperature: " << indexHighTemp() << endl;
	cout << "Lowest temperature: " << indexLowTemp() << endl;;
	
	cout << "Press any key to Exit.";
	cin.ignore(2, '\n');
	cin.get(q);
	return 0;
}

bool getData(temperature isHigh) //true for high temp, false for low temp
{
	for (int i = 0; i < 12; i++)
	{
		cin >> weather::temp[i][isHigh ? weather::highTemp : weather::lowTemp];
		if (!cin)
		{
			cout << "ERROR: Please only enter numeric values!" << endl;
			cin.clear();
			cin.ignore(2, '\n');
			return false;
		}

		if (weather::temp[i][isHigh ? weather::highTemp : weather::lowTemp] < -130 
			|| weather::temp[i][isHigh ? weather::highTemp : weather::lowTemp] > 140)
		{
			cout << "ERROR: Please enter numeric values between -130 and 140." << endl;
			return false;
		}	
	}
	return true;
}

int averageHigh()
{
	int sum = 0;

	for (int i = 0; i < 12; i++)
		sum += weather::temp[i][weather::highTemp];

	return sum / 12;
}

int averageLow()
{
	int sum = 0;

	for (int i = 0; i < 12; i++)
		sum += weather::temp[i][weather::lowTemp];

	return sum / 12;
}

int indexHighTemp()
{
	int index = 0;

	for (int i = 0; i < 12; i++)
		if (weather::temp[index][weather::highTemp] < weather::temp[i][weather::highTemp])
			index = i;

	return weather::temp[index][weather::highTemp];
}

int indexLowTemp()
{
	int index = 0;

	for (int i = 0; i < 12; i++)
		if (weather::temp[index][weather::lowTemp] > weather::temp[i][weather::lowTemp])
			index = i;

	return weather::temp[index][weather::lowTemp];
}

