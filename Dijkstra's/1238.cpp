#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 2147483647

struct compare
{
	bool operator()(pair<int, int>A, pair<int, int>B)
	{
		return (A.second > B.second);
	}
};

int N, M, X;
vector<vector<int>> dist;
vector<vector<int>> board;

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	vector<bool> visited(N + 1, false);
	pq.push({start, 0});
	dist[start][start] = 0;
	while (!pq.empty())
	{
		int now = pq.top().first;
		int now_short = pq.top().second;
		pq.pop();
		if (visited[now] == true)
			continue;
		else
			visited[now] = true;
		for (int i = 1; i < N + 1; ++i)
		{
			if (board[now][i] != -1)
			{
				if (board[now][i] + now_short < dist[start][i])
					dist[start][i] = now_short + board[now][i];
				pq.push({i, dist[start][i]});
			}
		}
	}
}

int main()
{
	cin >> N >> M >> X;
	dist.assign(N + 1, vector<int>(N + 1, MAX));
	board.assign(N + 1, vector<int>(N + 1, -1));
	for (int i = 1; i < M + 1; ++i)
	{
		int start, end, weight;
		cin >> start >> end >> weight;
		board[start][end] = weight;
	}
	for (int i = 1; i < N + 1; ++i)
		dijkstra(i);
	int ans = 0;
	for (int i = 1; i < N + 1; ++i)
	{
		int temp = dist[X][i] + dist[i][X];
		if (ans < temp)
			ans = temp;
	}
	cout << ans << endl;
}