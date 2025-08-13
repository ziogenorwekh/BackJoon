#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;
vector<vector<bool>> graph;
void fillTrue(int startRow,int startCol, int endRow,int endCol) {
    for (int i = startRow; i < endRow; i++) 
        for(int j = startCol; j < endCol; j++)
            graph[i][j] = true;
}
int main(int argc, char const *argv[])
{
    int N,M,O;
    cin >> N >> M >> O;
    dp.resize(N+1,vector<int>(M+1,0));
    graph.resize(N+1,vector<bool>(M+1,false));
    int row = (O - 1) / M; 
    int col = (O - 1) % M;
    fillTrue(1,1,row+2,col+2);
    fillTrue(row+1,col+1,N+1,M+1);
    dp[1][1] = 1;
    for(int i = 1; i < N + 1; i++) {
        for(int j = 1; j < M + 1; j++) {
            if(graph[i][j]) {
                dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    cout << dp[N][M];
    return 0;
}
