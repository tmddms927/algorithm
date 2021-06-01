#include <iostream>
#include <vector>

using namespace std;

vector<int>v; //받은 정수가 들어있는 배열
vector<int>t; //조합을 만들 배열

int cal()
{

}

int set_v(int idx)
{
	
}

int main()
{
	int ans = 0, N;
	cin >> N;
	t.assign(N, -110); //t -110로 초기화
	v.assign(N, -110);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	// set_v(v, t, 0);
	cout << ans << endl;
	return 0;
}