// https://school.programmers.co.kr/learn/courses/30/lessons/72410
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";

    for (int i = 0; i < new_id.length(); ++i) {
        //1
        new_id[i] = tolower(new_id[i]);
        //2
        if (!isalpha(new_id[i]) && !isdigit(new_id[i]) && new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.') {
            new_id = new_id.substr(0, i) + new_id.substr(i-- + 1);
        }
    }
    //3
    for (int i = 1; i < new_id.length(); ++i) {
        if (new_id[i - 1] == '.' && new_id[i] == '.')
            new_id = new_id.substr(0, i) + new_id.substr(i-- + 1);
    }
    //4
    if (new_id[0] == '.')
        new_id = new_id.substr(1);
    if (new_id[new_id.length() - 1] == '.')
        new_id = new_id.substr(0, new_id.length() - 1);
    //5
    if(new_id.length() == 0)
        new_id = "a";
    //6
    if (new_id.length() > 15) {
        new_id = new_id.substr(0, 15);
        if (new_id[new_id.length() - 1] == '.')
            new_id = new_id.substr(0, new_id.length() - 1);
    }
    //7
    while(new_id.length() < 3)
        new_id += new_id[new_id.length() - 1];
    answer = new_id;
    return answer;
}
