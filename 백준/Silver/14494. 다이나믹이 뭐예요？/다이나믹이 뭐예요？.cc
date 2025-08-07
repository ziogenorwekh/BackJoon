#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int Y,X;
    cin >> X >> Y;
    vector<vector<long long>> dp(Y+1,vector<long long>(X+1,0));
    dp[1][1] = 1;
    for(int y = 1; y < Y + 1; y++) {
        for(int x = 1; x < X + 1; x++) {
            if(x == 1 && y == 1) continue;
            dp[y][x] = dp[y][x] + (dp[y-1][x] + dp[y][x-1] + dp[y-1][x-1]) % 1000000007;
        }
    }
    cout << dp[Y][X];
    return 0;
}
