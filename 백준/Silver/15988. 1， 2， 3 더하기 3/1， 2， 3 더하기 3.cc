#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> qus(N,0);
    int maxNum = 0;
    for (int i = 0; i < N; i++) {
        cin >> qus[i];
        if (qus[i]> maxNum) maxNum = qus[i];
    }
    vector<long long> dp(max(4,maxNum + 1), 0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4; i < dp.size(); i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
    }
    for (int i = 0; i < N; i++) cout << dp[qus[i]] << "\n";
    return 0;
}