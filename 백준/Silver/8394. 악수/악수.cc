#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    vector<long long> dp(10000001,0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < dp.size(); i++) dp[i] = (dp[i-2] + dp[i-1])%10;
    string result = to_string(dp[N]);
    cout << result.at(result.size()-1);
    return 0;
}
