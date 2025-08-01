#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> house;
vector<vector<int>> dp;
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    dp.resize(N,vector<int>(3,0));
    house.resize(N,vector<int>(3,0));
    for (int i = 0; i < N; i++)
    {
        int r,g,b;
        cin >> r >> g >> b;
        house[i][0] = r;
        house[i][1] = g;
        house[i][2] = b;
    }
    int i = 1;
    dp[0][0] = house[0][0], dp[0][1] = house[0][1], dp[0][2] = house[0][2];
    while(i < N) {
        dp[i][0] = house[i][0] + min(dp[i-1][1],dp[i-1][2]);
        dp[i][1] = house[i][1] + min(dp[i-1][0],dp[i-1][2]);
        dp[i][2] = house[i][2] + min(dp[i-1][0],dp[i-1][1]);
        i++;
    }    
    cout << *min_element(dp[i-1].begin(),dp[i-1].end());
    return 0;
}

