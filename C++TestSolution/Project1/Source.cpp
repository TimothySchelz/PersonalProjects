#include<stdlib.h>
#include<iostream>
#include<string>
#include <time.h> 
#include<algorithm>/* time */

using namespace std;

int main()
{
	bool running = true;
	srand(time(NULL));

	int total_damage = 0;

	while (running)
	{
		int att_roll = 15 + rand() % 10 + 1;
		int def_roll = 18 + rand() % 10 + 1;
		int roll_diff = att_roll - def_roll;

		if (roll_diff >= 0)
		{
			total_damage += max(0, roll_diff + 6);
			cout << "HIT\nDamage:\t\t" << max(0, roll_diff + 6) <<
				"\nTotal Damage:\t"<< total_damage << endl << endl;

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

