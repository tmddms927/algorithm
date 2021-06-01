#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int>v; //받은 정수가 들어있는 배열
vector<int>t; //조합을 만들 배열
int N;
int answer;

int cal()
{
	int ret = 0;

	for (int i = 0; i < N-1; ++i)
		ret += abs(t[i] - t[i + 1]);
	return (ret);
}

void set_v(int idx)
{
	for (int i = 0; i < N; ++i)
	{
		if (t[i] == -110)
		{
			t[i] = v[idx];
			if (idx == N-1)
				answer = max(cal(), answer);
			else
				set_v(idx+1);
			t[i] = -110;
		}
	}
}

int main()
{
	answer = 0;
	cin >> N;
	t.assign(N, -110); //t -110로 초기화
	v.assign(N, -110);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	set_v(0);
	cout << answer << endl;
	return 0;
}