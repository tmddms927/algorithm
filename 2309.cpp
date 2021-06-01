#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>v;
vector<int>t;
vector<int>check;
int flag;

void cal()
{
	int ret = 0;

	for (int i = 0; i < 7; ++i)
		ret += t[i];
	if (ret == 100)
		flag = 1;
}

void set_t(int t_idx)
{
	for (int i = 0; i < 9; ++i)
	{
		if (check[i] == 0)
		{
			t[t_idx] = v[i];
			check[i] = 1;
			if (t_idx == 6)
				cal();
			else
				set_t(t_idx+1);
			check[i] = 0;
		}
		if (flag == 1)
			return ;
	}
}

int main()
{
	flag = 0;
	v.assign(9, 0);
	t.assign(7, 0);
	check.assign(9, 0);
	for (int i = 0; i < 9; ++i)
		cin >> v[i];
	set_t(0);
	sort(t.begin(), t.end());
	for (int i = 0; i < 7; i++)
		cout << t[i] <<endl;
}