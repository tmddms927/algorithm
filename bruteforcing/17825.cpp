#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<int>dice(10);
vector<int>simul(10, -1);
pair<int, int> dice_map[4];
int max_score = 0;

void	dice_set_position(int idx, int i)
{
	if (dice_map[idx].second == 0)
		dice_map[idx].first += 2 * dice[i];
	else if (dice_map[idx].second == 4)
		dice_map[idx].first += 5 * dice[i];
	else if (dice_map[idx].second == 1)
	{
		int j;
		for (j = 1; j <= dice[i]; ++j)
		{
			dice_map[idx].first += 3;
			if (dice_map[idx].first > 19)
				break ;
		}
		if (dice_map[idx].first > 19)
		{
			dice_map[idx].first = 25;
			dice_map[idx].second = 4;
		}
		if (j < dice[i])
			dice_map[idx].first += (dice[i] - j) * 5;
	}
	else if (dice_map[idx].second == 2)
	{
		int j;
		for (j = 1; j <= dice[i]; ++j)
		{
			dice_map[idx].first += 2;
			if (dice_map[idx].first > 24)
				break ;
		}
		if (dice_map[idx].first > 24)
		{
			dice_map[idx].first = 25;
			dice_map[idx].second = 4;
		}
		if (j < dice[i])
			dice_map[idx].first += (dice[i] - j) * 5;
	}
	else if (dice_map[idx].second == 3)
	{
		int j;
		for (j = 1; j <= dice[i]; ++j)
		{
			dice_map[idx].first -= 1;
			if (dice_map[idx].first == 29)
				dice_map[idx].first = 28;
			if (dice_map[idx].first == 25)
				break ;
		}
		if (dice_map[idx].first == 25)
			dice_map[idx].second = 4;
		if (j <= dice[i])
			dice_map[idx].first += (dice[i] - j) * 5;
	}
	if (dice_map[idx].second == 0)
	{
		if (dice_map[idx].first == 10)
			dice_map[idx].second = 1;
		else if (dice_map[idx].first == 20)
			dice_map[idx].second = 2;
		else if (dice_map[idx].first == 30)
			dice_map[idx].second = 3;
	}
	//if (simul[0] == 0 && simul[1] == 0 && simul[2] == 0 &&
	//	simul[3] == 0 && simul[4] == 1 && simul[5] == 1 &&
	//	simul[6] == 1 && simul[7] == 1 && simul[8] == 0 &&
	//	simul[9] == 1)
	//		cout <<  "i : " <<  i << ", " << dice_map[idx].first << ", " << dice_map[idx].second << ", " << idx << endl;
}

void	cal()
{
	int score = 0;

	for (int i = 0; i < 10; ++i)
	{
		if (dice_map[simul[i]].first > 40)
			return ;
		dice_set_position(simul[i], i);
		for (int j = 0; j < 4; ++j)
		{
			if (simul[i] == j)
				continue ;
			if ((dice_map[simul[i]].first == dice_map[j].first && dice_map[simul[i]].second == dice_map[j].second && dice_map[simul[i]].first < 40) ||
				(dice_map[simul[i]].first == dice_map[j].first && dice_map[simul[i]].first == 25) ||
				(dice_map[simul[i]].first == dice_map[j].first && dice_map[simul[i]].first == 40))
				return ;
		}
		if (dice_map[simul[i]].first <= 40)
			score += dice_map[simul[i]].first;
	}
	if (score > max_score)
		max_score = score;
}

void	set_dice(int idx)
{
	for (int i = 0; i < 4; ++i)
	{
		simul[idx] = i;
		if (idx == 9)
		{
			cal();
			for (int i = 0; i < 4; i++)
				dice_map[i].first = 0, dice_map[i].second = 0;
		}
		else
			set_dice(idx + 1);
	}
}

int		main()
{
	for (int i = 0; i < 4; i++)
		dice_map[i].first = 0, dice_map[i].second = 0;
	for (int i = 0; i < 10; ++i)
		cin >> dice[i];
    set_dice(0);
	cout << max_score << endl;
}