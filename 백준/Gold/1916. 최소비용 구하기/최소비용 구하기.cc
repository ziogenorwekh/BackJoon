#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dijkstra(int n, int start, int end, vector<vector<pair<int, int>>> &graph);
int main(int argc, char const *argv[])
{
    int N, M, start, end;
    cin >> N >> M;
    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
    }
    cin >> start >> end;
    cout << dijkstra(N,start,end,graph);
    return 0;
}

int dijkstra(int n, int start, int end, vector<vector<pair<int, int>>> &graph)
{
    vector<int> distance(n + 1, INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, start);
    distance[start] = 0;

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (distance[now] < cost) continue;
        for (auto &next : graph[now])
        {
            int nextCost = next.first + cost;
            int nextNode = next.second;
            if (distance[nextNode] > nextCost)
            {
                distance[nextNode] = nextCost;
                pq.emplace(nextCost, nextNode);
            }
        }
    }
    return distance[end];
}