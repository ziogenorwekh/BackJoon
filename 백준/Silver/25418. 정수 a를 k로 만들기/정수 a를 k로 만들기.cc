#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int N,M;
    cin >> N >> M;
    vector<int> dp(M+1,1e9);
    dp[N] = 0;
    for(int i= N + 1;i<M+1;i++) {
        if(i % 2 == 0) dp[i] = min(dp[i-1] + 1, dp[i/2] + 1);
        else dp[i] = dp[i-1] + 1;
    }
    cout << dp[M];
    return 0;
}
