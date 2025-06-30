#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void bfs(vector<vector<int>> &graph, vector<int> &distance, int current);
int N, M, K, X;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K >> X;
    vector<vector<int>> graph(N + 1);
    vector<int> distance(N + 1, -1);
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    bfs(graph, distance, X);
    bool notfound = true;
    for (int i = 1; i < distance.size(); i++)
    {

        if (distance[i] == K)
        {
            notfound = false;
            cout << i << "\n";
        }
    }
    if (notfound)
    {
        cout << -1 << " ";
    }

    return 0;
}

void bfs(vector<vector<int>> &graph, vector<int> &distance, int current)
{
    queue<int> q;
    q.push(current);
    distance[current] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int next : graph[node])
        {
            if (distance[next] == -1)
            {
                distance[next] = distance[node] + 1;
                q.push(next);
            }
        }
    }
}