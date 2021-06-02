#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int N;
int M;
int safe;
vector<vector<int>> v;
vector<int> inf;
//pair<int, int> p1;
vector<vector<int>> check;
vector<vector<int>> inf_v;

void check_inf(int i, int j)
{
	if (i-1 > -1 && inf_v[i-1][j] == 0)
	{
		inf_v[i-1][j] = 2;
		check_inf(i-1, j);
	}
	if (j-1 > -1 && inf_v[i][j-1] == 0)
	{
		inf_v[i][j-1] = 2;
		check_inf(i, j-1);
	}
	if (i+1 < N && inf_v[i+1][j] == 0)
	{
		inf_v[i+1][j] = 2;
		check_inf(i+1, j);
	}
	if (j+1 < M && inf_v[i][j+1] == 0)
	{
		inf_v[i][j+1] = 2;
		check_inf(i, j+1);
	}
}

void infection()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			if (inf_v[i][j] == 2)
				check_inf(i, j);
		}
}

void set_inf_v()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			if ((inf[0] == i && inf[1] == j) ||
				(inf[2] == i && inf[3] == j) ||
				(inf[4] == i && inf[5] == j))
				inf_v[i][j] = 1;
			else
				inf_v[i][j] = v[i][j];
		}
	infection();

	int ret = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			if (inf_v[i][j] == 0)
				ret++;
		}
	safe = max(safe, ret);
}

void set_t(int idx)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (v[i][j] == 0 && check[i][j] == 0)
			{
				inf[idx * 2] = i;
				inf[idx * 2 + 1] = j;
				check[i][j] = 1;
				if (idx == 2)
					set_inf_v();
				else
					set_t(idx+1);
				check[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	v.assign(N, vector<int>(M, 0));
	inf_v.assign(N, vector<int>(M, 0));
	check.assign(N, vector<int>(M, 0));
	inf.assign(6, -1);
	safe = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> v[i][j];
	set_t(0);
	cout << safe << endl;
}