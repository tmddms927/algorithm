#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;
#define MAX 2147483647

int V, E;
vector<int> kiosk(10);
vector<vector<int>> dist;
vector<vector<int>> board;
int my_start;

struct compare{
	bool operator()(pair<int, int> A, pair<int, int> B)
	{
		return (A.second > B.second);
	}
};

void dijkstra(int start)
{
	vector<bool> visited(V + 1, false);
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
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
		for (int i = 1; i < V + 1; ++i)
		{
			if (board[now][i] != -1)
			{
				if (board[now][i] + now_short < dist[start][i])
					dist[start][i] = board[now][i] + now_short;
				pq.push({i, dist[start][i]});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	cin >> V >> E;
	dist.assign(V + 1, vector<int>(V + 1, MAX));
	board.assign(V + 1, vector<int>(V + 1, -1));
	for (int i = 0; i < E; ++i)
	{
		int start, end, weight;
		cin >> start >> end >> weight;
		board[start][end] = weight;
		board[end][start] = weight;
	}
	for (int i = 0; i < 10; ++i)
		cin >> kiosk[i];
	cin >> my_start;
	int ans = MAX;
	int yog_time = 0;
	dijkstra(my_start);
	for (int i = 0; i < 9; ++i)
	{
		if (dist[kiosk[i]][kiosk[i + 1]] == MAX)
		{
			if (dist[kiosk[i + 1]][kiosk[i]] == MAX)
			{
				cout << kiosk[i] << ", " << kiosk[i + 1] << endl;
				dijkstra(kiosk[i]);
			}
			else
				dist[kiosk[i]][kiosk[i + 1]] = dist[kiosk[i + 1]][kiosk[i]];
		}
		if (dist[kiosk[i]][kiosk[i + 1]] != MAX)
			yog_time += dist[kiosk[i]][kiosk[i + 1]];
		else
			continue;
		if (dist[my_start][kiosk[i + 1]] <= yog_time && ans > kiosk[i + 1])
			ans = kiosk[i + 1];
	}
	if (kiosk[0] == my_start && ans > kiosk[0])
		ans = kiosk[0];
	if (ans == MAX)
		cout << "-1" << endl;
	else
		cout << ans << endl;
}