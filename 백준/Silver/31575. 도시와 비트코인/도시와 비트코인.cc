#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {0,1};
int dy[] = {1,0};
vector<vector<int>> graph;
vector<vector<bool>> visited;
void bfs(int endX, int endY) {
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = true;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(graph[y][x] == 1) {
            for(int i = 0;i<2;i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && ny >=0 && nx < endX && ny < endY) {
                    if(!visited[ny][nx]) {
                        visited[ny][nx] = true;
                        q.push({ny,nx});
                    }
                }
            }
        }
    }
    if(visited[endY-1][endX-1]) cout << "Yes";
    else cout << "No";
}

int main(int argc, char const *argv[])
{
    int x,y;
    cin >> x >> y;
    graph.resize(y,vector<int>(x,0));
    visited.resize(y,vector<bool>(x,false));
    for(int i = 0; i < y; i++) {
        for(int j =0; j < x ;j++) {
            cin >> graph[i][j];
        }
    }
    bfs(x,y);
    return 0;
}
