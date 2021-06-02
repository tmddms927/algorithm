#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//(a+b)(a-b)
//x = a + b
//G/x = a - b
//a = x - b
//b = a - x
//a = (G/x) - b
//a = (G/x) - a + x
//2a = (G/x) + x
//a = ((G/x) + x) / 2
//a = ((a+b)+(a-b)) / 2

int main()
{
	int G;
	vector<int>v;
	vector<int>ans;

	cin >> G;
	for (int i=1;i<=sqrt(G);++i)
	{
		if (G%i==0 && G/i!=i)
			v.push_back(i);
	}
	for (int i=0;i<v.size();++i)
	{
		int a_plus_b = G / v[i];
		if ((a_plus_b + v[i]) % 2 == 0)
			ans.push_back((a_plus_b + v[i]) / 2);
	}
	sort(ans.begin(), ans.end());
	if (ans.size()==0)
		cout << "-1" << endl;
	for (int i=0;i<ans.size();++i)
		cout << ans[i] << endl;
}