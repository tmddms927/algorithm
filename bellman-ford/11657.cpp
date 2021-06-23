#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector< vector<int> > map;
vector< int > city;

int			main()
{
	cin >> N >> M;
	city.assign(N + 1, 9999999);
	map.resize(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a][b] = c;
	}
	city[1] = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == j)
				continue ;
			if (map[i][j] != 0 && city[])
			{
			}
		}
	}
}