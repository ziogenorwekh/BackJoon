#include <vector>
#include <iostream>
using namespace std;

vector<int> dp;
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    dp.resize(N + 1, 0);
    dp[0] = 0;
    dp[1] = -1;
    dp[2] = 1;
    dp[3] = -1;
    dp[4] = 2;
    dp[5] = 1;
    for (int i = 6; i <= N; i++) {
        if (dp[i-2] != -1 && dp[i-5] != -1) dp[i] = min(dp[i-2], dp[i-5]) + 1;
        else if (dp[i-2] != -1) dp[i] = dp[i-2] + 1;
        else if (dp[i-5] != -1) dp[i] = dp[i-5] + 1;
        else dp[i] = -1;
    }
    cout << dp[N];
    return 0;
}
