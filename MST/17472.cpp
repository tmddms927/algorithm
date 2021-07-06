#include <vector>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

int N, M;
vector<vector<int>> map;

void set_island(int x, int y, int num)
{
	if (map[x][y] == 1)
	{
		map[x][y] = num;
		if (x - 1 >= 0)
			set_island(x - 1, y, num);
		if (y - 1 >= 0)
			set_island(x, y - 1, num);
		if (x + 1 <= N)
			set_island(x + 1, y, num);
		if (y + 1 <= M)
			set_island(x, y + 1, num);
	}
}

int main()
{
    cin >> N >> M;
    map.assign(N + 1, vector<int>(M + 1, 0));
	for (int i = 1; i < N + 1; ++i)
		for (int j = 1; j < M + 1; ++j)
			cin >> map[i][j];
	int island = 2;
	for (int i = 1; i < N + 1; ++i)
	{
		for (int j = 1; j < M + 1; ++j)
		{
			if (map[i][j] == 1)
				set_island(i, j, island++);
		}
	}
	for (int i = 1; i < N + 1; ++i)
	{
		
	}
	for (int i = 1; i < N + 1; ++i)
	{
		for (int j = 1; j < M + 1; ++j)
			cout << map[i][j] << ", ";
		cout << endl;
	}
}
