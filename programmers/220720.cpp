// https://school.programmers.co.kr/learn/courses/30/lessons/81301

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
	vector<string> numbers;
	numbers.push_back("zero");
	numbers.push_back("one");
	numbers.push_back("two");
	numbers.push_back("three");
	numbers.push_back("four");
	numbers.push_back("five");
	numbers.push_back("six");
	numbers.push_back("seven");
	numbers.push_back("eight");
	numbers.push_back("nine");

	for (int i = 0; i < s.length(); ++i) {
		if (!isdigit(s[i])) {
			for (int j = 0; j < 10; ++j) {
				if (s[i] == numbers[j][0] && s[i + 1] == numbers[j][1]) {
					answer = answer * 10 + j;
					i += numbers[j].length() - 1;
					break;
				}
			}
		}
		else
			answer = answer * 10 + s[i] - 48;
	}
    return answer;
}

int main() {
	cout << solution("one4seveneight") << endl;
}