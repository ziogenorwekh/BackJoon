#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

void checkJudge(deque<pair<int,int>>& judge, int input,int i); 

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    deque<pair<int, int>> judge;
    int N, L;
    cin >> N >> L;
    int input;
    cin >> input;
    judge.push_back(make_pair(1, input));
    cout << input << " ";
    for (int i = 2; i < N + 1; i++)
    {
        cin >> input;
        if (i - L + 1 < 2)
        {
            checkJudge(judge,input,i);
        }
        else
        {
            if (judge.front().first <= i - L)
            {
                judge.pop_front();
            }
            checkJudge(judge,input,i);
        }
        cout << judge.front().second << " ";
    }

    return 0;
}

void checkJudge(deque<pair<int,int>>& judge, int input,int i)
{
    if (judge.back().second < input)
    {
        judge.push_back(make_pair(i, input));
    }
    else
    {
        while (!judge.empty() && judge.back().second > input)
        {
            judge.pop_back();
        }
        judge.push_back(make_pair(i, input));
    }
}