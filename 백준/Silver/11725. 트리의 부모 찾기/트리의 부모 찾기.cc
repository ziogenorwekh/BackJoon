#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>>& graph, vector<bool> &visited);
vector<int> parent;
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<vector<int>> graph(N+1);
    vector<bool> visited(N+1,false);
    parent.resize(N+1,0);
    for (int i = 1; i < N + 1; i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(1,graph,visited);
    for(int i =2; i< N + 1; i++) cout << parent[i] << "\n";
    return 0;
}

void bfs(int start, vector<vector<int>>& graph, vector<bool> &visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int next : graph[node]) {
            if(!visited[next]) {
                visited[next] = true;
                parent[next] = node;
                q.push(next);
            }
        }
    }
}
