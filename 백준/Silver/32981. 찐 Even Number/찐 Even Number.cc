#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<long long> qe(N,0);
    for (int i = 0; i < N; i++) {
        cin >> qe[i];
    }
    vector<long long> dp(10000001,0);
    dp[1] = 4;
    for (int i = 2; i < dp.size(); i++) dp[i] = dp[i-1]*5%(1000000007);
    for (int i = 0; i < N; i++) {
        if(qe[i] == 1) cout << 5 << "\n";
        else cout << dp[qe[i]] << "\n";
    }
    return 0;
}
