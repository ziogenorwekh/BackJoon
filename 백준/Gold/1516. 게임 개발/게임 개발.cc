#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

vector<int> topology_sort(const int n, const vector<vector<int>> &graph);
map<int, int> builderTimer;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<int>> graph(N + 1);
    for (int i = 1; i < N + 1; i++)
    {
        int buildingTime;
        cin >> buildingTime;
        builderTimer.emplace(i, buildingTime);
        while (true)
        {
            int x;
            cin >> x;
            if (x == -1) break;
            graph[x].push_back(i);
        }
    }

    vector<int> result = topology_sort(N, graph);
    for (int i = 1; i < N + 1; i++) cout << result.at(i) << "\n";
    return 0;
}

vector<int> topology_sort(const int n, const vector<vector<int>> &graph)
{
    queue<int> q;
    vector<int> result(n + 1, 0);
    vector<int> inDegree(n + 1, 0);

    for (int i = 1; i < n + 1; i++) for (int v : graph[i]) inDegree[v]++;
    for (int i = 1; i < n + 1; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
            result[i] += builderTimer.at(i);
        }
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int next : graph[now])
        {
            result[next] = max(result[next], result[now] + builderTimer.at(next));
            inDegree[next]--;
            if (inDegree[next] == 0) q.push(next);
        }
    }
    return result;
}
