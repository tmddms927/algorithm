#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int N, M, X;
int maxtime;
vector<int> shortcut;

class Info
{
public:
	int start;
	int end;
	int length;

	Info(int _start, int _end, int _length)
	{
		start = _start;
		end = _end;
		length = _length;
	}
	Info (int _start)
	{
		start = _start;
		length = numeric_limits<int>::max();
	}
	bool operator >(const Info& info) const
	{
		return end > info.end;
	}
	bool operator <(const Info& info) const
	{
		return end < info.end;
	}
};

int main()
{
	priority_queue<Info> pq;
	cin >> N >> M >> X;
	Info info[M];
	maxtime = 0;
	shortcut.assign(N, numeric_limits<int>::max());
	for (int i = 0; i < M; ++i)
		cin >> info[i].start >> info[i].end >> info[i].length;
}