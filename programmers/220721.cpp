// https://school.programmers.co.kr/learn/courses/30/lessons/43165

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define PLUS	true
#define MINUS	false

int ans;
int arr[2] = {1, -1};

void cal(vector<int> const & numbers, vector<bool> & plus, int const & target) {\
	int temp = 0;

	for (int i = 0; i < numbers.size(); ++i) {
		if (plus[i] == PLUS)
			temp = temp + numbers[i];
		else
			temp = temp - numbers[i];
	}
	if (temp == target)
		ans++;
}

void set_comb(vector<int> const & numbers, vector<bool> & plus, int const & default_num, int my_num, int const & target, int index) {
	if (default_num == my_num) {
		cal(numbers, plus, target);
		return ;
	}
	for (int i = index; i < plus.size(); ++i) {
			plus[i] = MINUS;
			set_comb(numbers, plus, default_num, my_num + 1, target, i + 1);
			plus[i] = PLUS;
	}
}

int solution(vector<int> numbers, int target) {
	vector<bool> plus(numbers.size(), PLUS);
	ans = 0;
	for (int i = 0; i < numbers.size() + 1; ++i) {
		set_comb(numbers, plus, i, 0, target, 0);
	}
	return ans;
}

int main() {
	vector<int> numbers{ 1, 1, 1, 1, 1 };
	cout << solution(numbers, 3) << endl;
}
