#include <vector>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

vector<string> chess;
stack<char> s;
int solution(int N, int M);
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    chess.resize(N);
    for (int i = 0; i < N; i++) cin >> chess[i];
    cout << solution(N, M);
    return 0;
}
int solution(int N, int M)
{
    int min = INT32_MAX;

    for (int i = 0; i < N - 7; i++)
    {
        for (int j = 0; j < M - 7; j++)
        {
            while (!s.empty()) s.pop();
            s.push('W');
            s.push('B');
            for (int l = 0; l < 2; l++) {
                char chk = s.top();
                s.pop();
                char reversechk = s.top();
                s.pop();
                int count = 0;
                for (int k = i; k < 8 + i; k++) {
                    for (int r = j; r < 8 + j; r++)
                    {
                        if(k % 2 == 0) {
                            if(r % 2 == 0 && chk != chess[k].at(r)) count++;
                            if(r % 2 == 1 && reversechk != chess[k].at(r)) count++;
                        } else {
                            if(r % 2 == 1 && chk != chess[k].at(r)) count++;
                            if(r % 2 == 0 && reversechk != chess[k].at(r)) count++;
                        }
                    }
                }
                s.push('B');
                s.push('W');
                if(min > count) min = count;
            }
        }
    }
    return min;
}