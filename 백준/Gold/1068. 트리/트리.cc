#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int result = 0;
void bfs(int start);
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    graph.resize(N, vector<int>{});
    vector<int> v(N,0);
    vector<int> start;
    for (int i = 0; i < N; i++) cin >> v[i];
    int except;
    cin >> except;
    for (int i = 0; i < N; i++)
    {
        if(v[i] == except) continue;
        if(v[i] == -1) {
            start.push_back(i);
            continue;
        } 
        graph[v[i]].push_back(i);
    }
    visited.resize(N, false);
    visited[except] = true;
    for (int i = 0; i < start.size(); i++)
    {
        if(!visited[start[i]]) bfs(start[i]);
    }
    cout << result;
    return 0;
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        bool hasChild = false;
        for (int next : graph[node])
        {
            if(!visited[next]) {
                visited[next] = true;
                q.push(next);
                hasChild = true;
            }
        }
        if(!hasChild) result++;
    }
}