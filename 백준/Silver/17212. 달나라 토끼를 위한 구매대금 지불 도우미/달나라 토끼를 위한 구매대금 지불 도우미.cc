#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> dp(N + 1,1e9);
    dp[0] = 0; dp[1] = 1; dp[2] = 1; dp[3] = 2; dp[4] =2; dp[5] = 1; dp[6]= 2; dp[7] = 1;
    if(N <= 7) {
        cout << dp[N];
        return 0;
    }
    for(int i = 8; i <= N; i++) dp[i] = min(min(dp[i-1] + 1,dp[i-2] + 1),min(dp[i-5]+1,dp[i-7] + 1));
    cout << dp[N];
    return 0;
}
