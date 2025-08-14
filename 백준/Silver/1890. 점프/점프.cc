#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<vector<long long>> graph(N+1,vector<long long>(N+1,0));
    vector<vector<long long>> dp(N+1,vector<long long>(N+1,0));
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            cin >> graph[i][j];
        }
    }
    dp[1][1] = 1;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if(graph[i][j] == 0) continue;
            if(i+graph[i][j] <= N) dp[i+graph[i][j]][j] += dp[i][j];
            if(j+graph[i][j] <= N) dp[i][j+graph[i][j]] += dp[i][j];
        }
    }
    cout << dp[N][N];
    return 0;
}
