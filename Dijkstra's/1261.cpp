#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

#define MAX 2147483647

int M, N;
vector<vector<int>> map(101, vector<int>(101, -1));
vector<vector<int>> dist(101, vector<int>(101, MAX));
vector<vector<bool>> visited(101, vector<bool>(101, false));

struct Info
{
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

int dijstra()
{
	int x, y, weight;
	priority_queue<Info, vector<Info>, compare> pq;
	pq.push({1, 1, 0});
	dist[1][1] = 0;
	while (!pq.empty())
	{
		x = pq.top().x;
		y = pq.top().y;
		weight = pq.top().weight;
		pq.pop();
		if (visited[y][x] == true)
			continue;
		else
			visited[y][x] = true;
		if (x == M && y == N)
			return dist[y][x];
		if (x + 1 <= M && visited[y][x + 1] == false)
		{
			if (map[y][x + 1] == 1 && dist[y][x + 1] > weight + 1)
				dist[y][x + 1] = weight + 1;
			else if (map[y][x + 1] == 0 && dist[y][x + 1] > weight)
				dist[y][x + 1] = weight;
			pq.push({x + 1, y, dist[y][x + 1]});
		}
		if (y + 1 <= N && visited[y + 1][x] == false)
		{
			if (map[y + 1][x] == 1 && dist[y + 1][x] > weight + 1)
				dist[y + 1][x] = weight + 1;
			else if (map[y + 1][x] == 0 && dist[y + 1][x] > weight)
				dist[y + 1][x] = weight;
			pq.push({x, y + 1, dist[y + 1][x]});
		}
		if (x - 1 >= 1 && visited[y][x - 1] == false)
		{
			if (map[y][x - 1] == 1 && dist[y][x - 1] > weight + 1)
				dist[y][x - 1] = weight + 1;
			else if (map[y][x - 1] == 0 && dist[y][x - 1] > weight)
				dist[y][x - 1] = weight;
			pq.push({x - 1, y, dist[y][x - 1]});
		}
		if (y - 1 >= 1 && visited[y - 1][x] == false)
		{
			if (map[y - 1][x] == 1 && dist[y - 1][x] > weight + 1)
				dist[y - 1][x] = weight + 1;
			else if (map[y - 1][x] == 0 && dist[y - 1][x] > weight)
				dist[y - 1][x] = weight;
			pq.push({x, y - 1, dist[y - 1][x]});
		}
	}
	return 0;
}

int main()
{
	scanf("%d %d", &M, &N);
	for (int i = 1; i < N + 1; ++i)
		for (int j = 1; j < M + 1; ++j)
			scanf("%1d", &map[i][j]);
	cout << dijstra() << endl;
}