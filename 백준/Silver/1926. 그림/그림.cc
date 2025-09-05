#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N,M;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
vector<int> result;
vector<vector<int>> graph;
vector<vector<bool>> visited;
void bfs(int x,int y) {
    queue<pair<int,int>> q;
    visited[x][y] = true;
    int count = 1;
    q.push({x,y});
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + node.first;
            int ny = dy[i] + node.second;
            if(nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (graph[nx][ny] == 1) {
                    if (!visited[nx][ny]) {
                        visited[nx][ny] = true;
                        count++;
                        q.push({nx,ny});
                    }
                }
            }
        }
    }
    result.push_back(count);
}

int main(int argc, char const *argv[]) {
    cin >> N >> M;
    graph.resize(N,vector<int>(M,0));
    visited.resize(N,vector<bool>(M,false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) cin >> graph[i][j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) {
                bfs(i,j);
            }
        }
    }
    cout << result.size() << "\n";
    if (!result.empty()) cout << *max_element(result.begin(), result.end()) << "\n";
    else cout << 0 << "\n";
    return 0;
}