#include <iostream>
#include <vector>
#include <utility>
#define INF 2147483647

using namespace std;

long long N, M;
vector<pair<long long, long long>> map[501];
vector<long long> city;

int			main()
{
	cin >> N >> M;
	city.assign(N + 1, INF);
	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({b, c});
	}
	city[1] = 0;
	for (int k = 0; k < N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (auto &n : map[i])
			{
				if (city[i] != INF && n.second + city[i] < city[n.first])
				{
					if (k == N - 1)
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