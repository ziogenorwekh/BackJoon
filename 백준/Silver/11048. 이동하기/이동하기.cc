#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int Y,X;
    cin >> Y >> X;
    vector<vector<int>> maze(Y+1,vector<int>(X+1,0));
    for(int i = 1; i < Y + 1; i++) {
        for(int j = 1; j < X + 1; j++) cin >> maze[i][j];
    }
    vector<vector<int>> dp(Y+1,vector<int>(X+1,0));
    dp[1][1] = maze[1][1];
    for(int y = 1; y < Y + 1; y++) {
        for(int x = 1; x < X + 1; x++) {
            if(y == 1 && x == 1) continue;
            dp[y][x] = maze[y][x] + max(dp[y-1][x], 
                max(dp[y][x-1],dp[y-1][x-1]));
        }
    }
    cout << dp[Y][X];
    return 0;
}
