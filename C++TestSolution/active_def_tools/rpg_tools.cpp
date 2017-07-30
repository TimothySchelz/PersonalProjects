#include "rpg_tools.h"
#include<stdlib.h>
#include<iostream>
#include <time.h> 
#include<algorithm>

using namespace std;


void rpg_tools::attack_loop(int bonus_diff, int dam_diff)
{
	bool running = true;
	srand(time(NULL));

	int total_damage = 0;

	while (running)
	{
		int att_roll = bonus_diff + rand() % 10 + 1;
		int def_roll = rand() % 10 + 1;
		int roll_diff = att_roll - def_roll;

		if (roll_diff >= 0)
		{
			total_damage += max(0, roll_diff + dam_diff);
			cout << "HIT\nDamage:\t\t" << max(0, roll_diff + 6) <<
				"\nTotal Damage:\t" << total_damage << endl << endl;

		}
		else
		{
			cout << "MISS" << endl << endl;
		}

		string input;
		cin >> input;
		if (input.compare("quit") == 0)
		{
			running = false;
		}
	}
}

double rpg_tools::expected_damage(int bonus_diff, int dam_diff)
{
	int x = max(0, bonus_diff - 9);
	int y = min(0, bonus_diff + 9);

	if (bonus_diff - 9 > 0)
	{
		x = bonus_diff - 9;
		y = bonus_diff + 9;
	} else if (bonus_diff + 9 > 0)
	{
		x = 0;
		y = bonus_diff + 9;
	} else
	{
		return 0;
	}

	double sum = 0;
	for (int i = x; i <= y; i++)
	{
		sum += (max(0, i + bonus_diff + dam_diff))*(10 - abs(i - bonus_diff))/100.0;
	}

	return sum;
}

int main()
{
	cout << "Expected Damage:\t" << rpg_tools::expected_damage(5, 10) << endl;
	cout << "Expected Damage:\t" << rpg_tools::expected_damage(4, 10) << endl;
	cout << "Expected Damage:\t" << rpg_tools::expected_damage(3, 10) << endl;
	cout << "Expected Damage:\t" << rpg_tools::expected_damage(2, 10) << endl;
	cout << "Expected Damage:\t" << rpg_tools::expected_damage(1, 10) << endl;
	cout << "Expected Damage:\t" << rpg_tools::expected_damage(0, 10) << endl;
	cout << "Expected Damage:\t" << rpg_tools::expected_damage(-1, 10) << endl;
	cout << "Expected Damage:\t" << rpg_tools::expected_damage(-2, 10) << endl;
	cout << "Expected Damage:\t" << rpg_tools::expected_damage(-3, 10) << endl;
	cout << "Expected Damage:\t" << rpg_tools::expected_damage(-4, 10) << endl;
	cout << "Expected Damage:\t" << rpg_tools::expected_damage(-5, 10) << endl;



	string a;
	cin >> a;
	return 0;
}
