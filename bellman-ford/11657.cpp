#include <iostream>
#include <vector>
#include <utility>
#define INF 2147483647

using namespace std;

unsigned long long N, M;
vector<pair<int, int>> map[501];
vector<int> city;

int			main()
{
	cin >> N >> M;
	city.assign(N + 1, INF);
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (!map[a].empty() && map[a][0].first == b && map[a][0].second > c)
			map[a][0].second = c;
		else if (map[a].empty())
			map[a].push_back({b, c});
	}
	city[1] = 0;
	for (int k = 0; k < 2; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (auto &n : map[i])
			{
				if (city[i] != INF && n.second + city[i] < city[n.first])
				{
					if (k == 1)
					{
						cout << "-1" << endl;
						return 0;
					}
					city[n.first] = city[i] + n.second;
				}
			}
		}
	}
	for (int i = 2; i <= N; ++i)
	{
		if (city[i] != INF)
			cout << city[i] << endl;
		else
			cout << "-1" << endl;
	}
}