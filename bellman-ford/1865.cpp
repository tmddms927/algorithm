#include <iostream>
#include <vector>
#include <utility>
#define INF 9999999
using namespace std;

int TC;
int N;
int M;
int W;

int main()
{
	cin >> TC;
	while (TC--)
	{
		int ans = 0;
		cin >> N >> M >> W;
		vector<vector<int>> map(N + 1, vector<int>(N + 1, 0));
		vector<int> dist(N + 1, INF);
		dist[1] = 0;
		for (int j = 0; j < M; ++j)
		{
			int a, b, c;
			cin >> a >> b >> c;
git			if ((map[a][b] != 0 && map[a][b] > c) || map[a][b] == 0)
			{
				map[a][b] = c;
				map[b][a] = c;
			}
		}
		for (int j = 0; j < W; ++j)
		{
			int a, b, c;
			cin >> a >> b >> c;
			map[a][b] = -c;
		}
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				for (int k = 1; k <= N; ++k)
				{
					if (map[j][k] + dist[j] < dist[k])
					{
						dist[k] = map[j][k] + dist[j];
						if (i == N)
							ans = 1;
					}
				}
			}
		}
		puts(ans ? "YES" : "NO");
	}
}