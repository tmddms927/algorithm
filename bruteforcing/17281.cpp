#include <iostream>
#include <vector>

using namespace std;

int N;
int ans;
vector<vector<int>> v;
vector<int> player;

void	cal()
{
	vector<int>ground;
	int n = 0;
	int out = 0;
	int p_n = 0;
	int score = 0;
	ground.assign(3, 0);

	while (n < N)
	{
		if (v[n][player[p_n]] > 0)
		{
			for (int i = 2; i>-1;--i)
			{
				if (ground[i] == 1)
				{
					if (i + v[n][player[p_n]] > 2)
					{
						score++;
						ground[i] = 0;
					}
					else
					{
						ground[i] = 0;
						ground[i + v[n][player[p_n]]] = 1;
					}
				}
			}
			if (v[n][player[p_n]] - 1 > 2)
				score++;
			else
				ground[v[n][player[p_n]] - 1] = 1;
		}
		else
			out++;
		if (out == 3)
		{
			out = 0;
			n++;
			ground.assign(3, 0);
		}
		p_n++;
		if (p_n > 8)
			p_n = 0;
	}
	ans = max(score, ans);
}

void	make_player(int idx)
{
	for (int i = 0; i < 9; ++i)
	{
		if (player[i] == -1)
		{
			player[i] = idx;
			if (idx == 8)
				cal();
			else
				make_player(idx+1);
			player[i] = -1;
		}
	}
}

int		main()
{
	cin >> N;
	ans = 0;
	v.assign(N, vector<int>(9, -1));
	player.assign(9, -1);
	player[3] = 0;
	for (int i = 0; i < N; ++i)
		cin >> v[i][0] >> v[i][1]>> v[i][2]>> v[i][3]>> v[i][4]>> v[i][5]>> v[i][6]>> v[i][7]>> v[i][8];
	make_player(1);
	cout << ans << endl;
}