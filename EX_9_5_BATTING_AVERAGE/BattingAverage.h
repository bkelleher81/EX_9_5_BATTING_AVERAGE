#pragma once
#include <iostream>
#include <string>
using namespace std;
class BattingAverage
{
private:
	int choice = 0;
	string playerData[12][3]; //12 names , 3 stats
public:
	void displayMenu();
	void readPlayerData();
	void sortByName();
	void sortByBattingAgerage();
	void displayPlayerData();


};