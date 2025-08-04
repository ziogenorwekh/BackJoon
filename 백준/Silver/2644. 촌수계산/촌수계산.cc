#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
void dfs(int start,int end) {
    queue<int> q;
    q.push(start);
    vector<int> dist(graph.size() + 1, -1);
    dist[start] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node == end) {
            cout << dist[node];
            return;
        }
        for(int nextNode : graph[node]) {
            if(dist[nextNode] == -1) {
                dist[nextNode] = dist[node] + 1;
                q.push(nextNode);
            }
        }
    }
    cout << -1;
}
int main(int argc, char const *argv[])
{
    int N,sX,sY,M;
    cin >> N >> sX >> sY >> M;
    graph.resize(N+1);
    for(int i = 0; i < M; i++) {
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(sX, sY);

    return 0;
}
