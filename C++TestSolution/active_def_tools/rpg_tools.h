#pragma once
#include<string>
class rpg_tools
{
public:
	static void attack_loop(int bonus_diff, int dam_diff);
	static double expected_damage(int bonus_diff, int dam_diff);
};