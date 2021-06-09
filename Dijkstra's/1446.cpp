#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int N; // 지름길의 개수
int D; // 고속도로의 길이
vector<int> shortest;

class Graph
{
public:
	int start;
	int end;
	int length;
};

int main()
{
	cin >> N >> D;
	Graph graph[N];
	shortest.assign(10001, -1);
	shortest[0] = 0;
	for (int i = 0; i < N; ++i)
		cin >> graph[i].start >> graph[i].end >> graph[i].length;
	for (int i = 0; i < D + 1; ++i)
	{
		if (shortest[i] == -1 || shortest[i - 1] + 1 < shortest[i])
			shortest[i] = shortest[i - 1] + 1;
		for (int j = 0; j < N; ++j)
		{
			if (graph[j].start == i)
			{
				if ((graph[j].length + shortest[i] < shortest[graph[j].end]) ||
					(shortest[graph[j].end] == -1 && graph[j].length < graph[j].end - i))
					shortest[graph[j].end] = graph[j].length + shortest[i];
			}
		}
	}
	cout << shortest[D] << "\n";
}