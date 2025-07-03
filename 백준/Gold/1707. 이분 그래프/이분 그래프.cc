#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool bfs(int start, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &color);

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> graph(V + 1);
        vector<bool> visited(V + 1, false);
        vector<int> color(V + 1, 0);
        for (int j = 0; j < E; j++)
        {
            int X, Y;
            cin >> X >> Y;
            graph[X].push_back(Y);
            graph[Y].push_back(X);
        }
        bool result = true;
        for (int i = 1; i < V + 1; i++)
        {
            if (!visited[i])
            {
                if (!bfs(i, graph, visited, color))
                {
                    result = false;
                    break;
                }
            }
            
        }
        if (result)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

bool bfs(int start, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &color)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    color[start] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int next : graph[node])
        {
            if (!visited[next])
            {
                if (color[node] == 1) {
                    color[next] = 2;
                }
                else {
                    color[next] = 1;
                }
                visited[next] = true;
                q.push(next);
            }
            else
            {
                if (color[next] == color[node])
                {
                    return false;
                }
            }
        }
    }
    return true;
}