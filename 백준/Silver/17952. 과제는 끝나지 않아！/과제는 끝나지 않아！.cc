#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    stack<pair<int,int>> s;
    int answer = 0;
    for (int i = 0; i < N; i++) {
        int homework , score, minute;
        cin >> homework;
        if (homework == 1) {
            cin >> score >> minute;
            if(minute == 1) answer += score;
            else s.push(make_pair(score,minute - 1));
        } else {
            if (!s.empty()) {
                auto nowWork = s.top();
                s.pop();
                nowWork.second -= 1;
                if(nowWork.second == 0) answer += nowWork.first;
                else s.push(nowWork);
            }
        }
    }
    cout << answer;
    return 0;
}
