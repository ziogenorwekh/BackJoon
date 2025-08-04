#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    vector<int> dp(N + 1,0);
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= N; i++) dp[i] = (dp[i-2] + dp[i-1]) % 15746;
    cout << dp[N];
    return 0;
}
