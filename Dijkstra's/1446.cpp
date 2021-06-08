#include <iostream>
#include <vector>

using namespace std;

int N; // 지름길의 개수
int D; // 고속도로의 길이
Graph graph;

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
    graph = new Graph[N];
    for (int i = 0; i < N; ++i)
        cin >> graph[i].start >> graph[i].end >> graph[i].length;
	for (int i = 0; i < N; ++i)
		cout << graph[i].start;
}