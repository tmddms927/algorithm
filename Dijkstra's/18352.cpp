#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define Max 2147483647

int N, M, K, X;

struct compare
{
	bool operator()(pair<int, int>A, pair<int, int>B)
	{
		return (A.second > B.second);
	}
};

int main()
{
	cin >> N >> M >> K >> X;
	vector<int> shortest(N, Max);
	vector<vector<int>> node(M, vector<int>(2));
	priority_queue<pair<int, int>, vector<pair<int, int>>,compare> pq;
	priority_queue<int, vector<int>, greater<int>> ans;
	for (int i = 0; i < M; ++i)
		cin >> node[i][0] >> node[i][1];
	pq.push({X - 1, 0});
	shortest[X - 1] = 0;
	int now;
	int now_short;
	while (!pq.empty())
	{
		now = pq.top().first;
		now_short = pq.top().second;
		pq.pop();
		if (now_short >= shortest[now] && now_short != Max)
		{
			for (int i = 0; i < M; ++i)
			{
				if (node[i][0] - 1 == now && (shortest[node[i][1] - 1] > now_short + 1 ||
					shortest[node[i][1] - 1] == Max) && now_short + 1 <= K)
				{
					if (now_short + 1 == K)
						ans.push(node[i][1]);
					shortest[node[i][1] - 1] = now_short + 1;
					pq.push({node[i][1] - 1, now_short + 1});
				}
			}
		}
	}
	if (ans.empty())
		cout << "-1" << endl;
	int size = ans.size();
	for (int i = 0; i < size; ++i)
	{
		cout << ans.top() << endl;
		ans.pop();
	}
}