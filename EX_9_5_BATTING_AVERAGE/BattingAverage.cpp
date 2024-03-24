#include "BattingAverage.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void BattingAverage::displayMenu()
{
	cout << "1. Read player data from file" << endl;
	cout << "2. Sort player data by name" << endl;
	cout << "3. Sort player data by batting average" << endl;
	cout << "4. Exit" << endl;
	int choice;
	cin >> choice;
	if (choice ==1)
	{
		readPlayerData();
	}
	else if (choice == 2)
	{
		sortByName();
	}
	else if (choice == 3)
	{
		sortByBattingAgerage();
	}
	else if (choice == 4)
	{
		cout << "Goodbye." << endl;
		exit(0);
	}
	else
	{
		cout << "Invalid choice." << endl;
		displayMenu();
	}
}

void BattingAverage::readPlayerData()
{
	//reads the player data from a file
	ifstream inputFile;
	inputFile.open("names.txt");
	if (inputFile.fail())
	{
		cout << "Error opening file." << endl;
	}
	else
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				inputFile >> playerData[i][j];
			}
		}
	}
	inputFile.close();
	displayPlayerData();
}

void BattingAverage::sortByName()
{
	//sorts the player data by name
	string temp;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (playerData[i][0] < playerData[j][0])
			{
				for (int k = 0; k < 3; k++)
				{
					temp = playerData[i][k];
					playerData[i][k] = playerData[j][k];
					playerData[j][k] = temp;
				}
			}
		}
	}
	displayPlayerData();
	displayMenu();
}

void BattingAverage::sortByBattingAgerage()
{
	//sorts the player data by batting average
	string temp;
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (playerData[i][2] < playerData[j][2])
			{
				for (int k = 0; k < 3; k++)
				{
					temp = playerData[i][k];
					playerData[i][k] = playerData[j][k];
					playerData[j][k] = temp;
				}
			}
		}
	}
	displayPlayerData();
	displayMenu();
}

void BattingAverage::displayPlayerData()
{
	//displays the player data
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << playerData[i][j] << " ";
		}
		cout << endl;
	}
	displayMenu();
}
