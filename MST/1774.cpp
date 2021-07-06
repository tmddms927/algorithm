#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>

using namespace std;

int check[1001];

struct Map
{
	int a;
	int b;
	long double dist;
};

struct compare
{
	bool operator()(Map A, Map B){
		return (A.dist > B.dist);
	}
};

int	get_parent(int start)
{
	if (check[start] == start)
		return (start);
	else
		return get_parent(check[start]);
}

bool check_circle(int start, int end)
{
	start = get_parent(start);
	end = get_parent(end);
	if (start == end)
		return (true);
	else
		return (false);
}

void set_parent(int start, int end)
{
	start = get_parent(start);
	end = get_parent(end);
	if (start > end)
		check[start] = end;
	else
		check[end] = start;
}

int main()
{
	int N, M, num = 0;
	long double ans = 0;
	cin >> N >> M;
	vector< pair<int, int> > m;
	vector< vector<bool> > w(N + 1, vector<bool>(N + 1, false));
	priority_queue<Map, vector<Map>, compare> pq;
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		m.push_back({x, y});
		check[i + 1] = i + 1;
	}
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		w[a][b] = true;
		w[b][a] = true;
		set_parent(a, b);
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (w[i + 1][j + 1] || i == j)
				continue ;
			pq.push({i + 1, j + 1, sqrt(pow(m[j].first - m[i].first, 2) + pow(m[j].second - m[i].second, 2))});
		}
	}
	while (!pq.empty())
	{
		if (!check_circle(pq.top().a, pq.top().b))
		{
			ans += pq.top().dist;
			set_parent(pq.top().a, pq.top().b);
		}
		pq.pop();
	}
	printf("%.2Lf\n", ans);
}
