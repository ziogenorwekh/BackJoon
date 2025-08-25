#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int maxTime = 0;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int N,M;
vector<vector<char>> graph;
vector<vector<int>> dist;
void bfs(int x,int y) {
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    visited[x][y] = true;
    while (!q.empty()) {
        int nextX = q.front().first;
        int nextY = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = nextX + dx[i];
            int ny = nextY + dy[i];
            if(nx >= 0 && ny >=0 && nx < N && ny < M) {
                if(graph[nx][ny] == 'L' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[nextX][nextY] + 1;
                    if(dist[nx][ny] > maxTime) maxTime = dist[nx][ny];
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    
}

int main(int argc, char const *argv[]) {
    cin >> N >> M;
    graph.resize(N,vector<char>(M));
    dist.resize(N,vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist.assign(N, vector<int>(M, 0));
            if (graph[i][j] == 'L') bfs(i,j);
        }
    }
    cout << maxTime;
    return 0;
}
