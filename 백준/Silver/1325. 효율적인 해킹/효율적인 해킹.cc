#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int bfs(int start, vector<vector<int>>& graph, vector<bool>& visited);
int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    vector<int> depth(N + 1);
    vector<bool> visited(N + 1, false);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[y].push_back(x);
    }

    for (int i = 1; i < N + 1; i++)
    {
        depth[i] = bfs(i, graph, visited);
        fill(visited.begin(), visited.end(), false);
    }

    int max_value = *max_element(depth.begin(), depth.end());
    for (int i = 1; i < N + 1; i++)
    {
        if (depth[i] == max_value)
            cout << i << " ";
    }
    return 0;
}

int bfs(int start, vector<vector<int>>& graph, vector<bool>& visited)
{
    int count = 1;
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for (int next : graph[node])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return count;
}
