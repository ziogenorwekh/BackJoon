#include <iostream>
#include <vector>
using namespace std;

vector<long long> dp(101,0);
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> arr(N,0);
    for(int i = 0; i< N; i++) cin >> arr[i];
    dp[0] = 1; dp[1] = 1; dp[2] = 1;
    for(int i = 3; i < 101; i++) dp[i] = dp[i-3] + dp[i-2];
    for(int i =0; i<N;i++) cout << dp[arr[i] - 1] << "\n";
    return 0;
}
