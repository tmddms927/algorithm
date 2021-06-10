#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;
#define MAX 2147483647

struct compare{
	bool operator()(pair<int, int> A, pair<int, int> B)
	{
		return (A.second, B.second);
	}
};

int N, M;
vector<vector<int>> map;
vector<int> dist;

int start, end_city;

void dijstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	int now;
	int short_now;
	vector<bool> visited(N + 1, false);
	dist[start] = 0;
	pq.push({start, 0});
	while (!pq.empty())
	{
		now = pq.top().first;
		short_now = pq.top().second;
		pq.pop();
		if (visited[now] == true)
		{
			ans.push({now, short_now});
			continue;
		}
		else
			visited[now] = true;
		for (int i = 1; i < N + 1; ++i)
		{
			if (map[now][i] != -1 && short_now + dist[now] < dist[i])
			{
				dist[i] = short_now + dist[now];
				pq.push({i, dist[i]});
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	scanf("%d", &M);
	map.assign(N + 1, vector<int>(N + 1, -1));
	dist.assign(N + 1, MAX);
	for (int i = 1; i < M + 1; ++i)
	{
		int x, y, weight;
		scanf("%d %d %d", &x, &y, &weight);
		map[x][y] = weight;
	}
	scanf("%d %d", &start, &end_city);
	dijstra();
	ans.pop();
	cout << ans.top().second << endl;
}