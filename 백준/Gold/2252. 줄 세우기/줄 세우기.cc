#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> topology_sort(int n, vector<vector<int>> &graph);

int main(int argc, char const *argv[])
{
    int N,M;
    cin >> N >> M;
    vector<vector<int>> graph(N+1);
    for (int i = 0; i < M; i++)
    {
        int x,y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    vector<int> result = topology_sort(N,graph);
    
    for(int value : result) cout << value << " ";

    return 0;
}

vector<int> topology_sort(int n, vector<vector<int>> &graph)
{
    vector<int> inDegree(n + 1, 0);
    queue<int> q;
    vector<int> result;
    for (int i = 1; i < n + 1; i++) for (int node : graph[i]) inDegree[node]++;
    for (int i = 1; i < n + 1; i++) if (inDegree[i] == 0) q.push(i);
    
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        result.push_back(now);
        for(int next : graph[now]) {
            inDegree[next]--;
            if (inDegree[next] == 0) q.push(next);
        }
    }

    if (result.size() != n) return vector<int> {};
    return result;
}