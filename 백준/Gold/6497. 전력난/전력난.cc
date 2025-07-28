#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> graph;
int totalDistance = 0;
int prim(int v);
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        totalDistance = 0;
        int N, M;
        cin >> N >> M;
        if(N == 0 && M == 0) return 0;
        graph.clear();
        graph.resize(N + 1);
        for (int i = 0; i < M; i++) {
            int X, Y, Z;
            cin >> X >> Y >> Z;
            graph[X].push_back({Y, Z});
            graph[Y].push_back({X, Z});
            totalDistance += Z;
        }
        cout << totalDistance - prim(N) << "\n";
    }

    return 0;
}

int prim(int v) {
    vector<bool> visited(v + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int mst_weight = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (visited[u])
            continue;
        visited[u] = true;
        mst_weight += w;
        for (auto &edge : graph[u])
        {
            int nV = edge.first;
            int weight = edge.second;
            if (!visited[nV]) pq.push({weight, nV});
        }
    }
    return mst_weight;
}
