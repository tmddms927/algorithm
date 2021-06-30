#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#define INF 99999999
using namespace std;

int N;
vector<vector<int>> map(51, vector<int>(51, 0));
vector<vector<int>> dist(51, vector<int>(51, INF));

struct Info{
	int x;
	int y;
	int weight;
};

struct compare{
	bool operator()(Info A, Info B)
	{
		return (A.weight > B.weight);
	}
};

int dihkstra(int idx)
{
	priority_queue<Info, vector<Info>, compare> pq;
    pq.push({1, 1, 0});
    while (!pq.empty())
    {
		int x = pq.top().x;
		int y = pq.top().y;
		int weight = pq.top().weight;
        pq.pop();
		if (map[y][x] == 1 && weight < dist[y][x])
		{
			dist[y][x] = weight;
			if (x + 1 <= N)
				pq.push({x + 1, y, dist[y][x]});
			if (x - 1 > 0)
				pq.push({x - 1, y, dist[y][x]});
			if (y + 1 <= N)
				pq.push({x, y + 1, dist[y][x]});
			if (y - 1 > 0)
				pq.push({x, y - 1, dist[y][x]});
		}
		if (map[y][x] == 0 && weight + 1 < dist[y][x])
		{
			dist[y][x] = weight + 1;
			if (x + 1 <= N)
				pq.push({x + 1, y, dist[y][x]});
			if (y + 1 <= N)
				pq.push({x, y + 1, dist[y][x]});
			if (x - 1 > 0)
				pq.push({x - 1, y, dist[y][x]});
			if (y - 1 > 0)
				pq.push({x, y - 1, dist[y][x]});
		}
    }
	return dist[N][N];
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            scanf("%1d", &map[i][j]);
    cout << dihkstra(1) << endl;
}