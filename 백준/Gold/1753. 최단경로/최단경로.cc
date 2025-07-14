#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

typedef pair<int,int> pii;
vector<int> dijkstra(int n, int start, const vector<vector<pii>>& graph);
int main(int argc, char const *argv[])
{
    int V,E;
    cin >> V >> E;
    int start;
    cin >> start;
    vector<vector<pii>> graph(V+1);
    for (int i = 0; i < E; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
    }
    vector<int> result = dijkstra(V,start,graph);
    for(int i = 1; i < V+1; i++) {
        if(result[i] == INT32_MAX) {
            cout << "INF\n";
            continue;
        }
        cout << result[i] << "\n";
    }
    return 0;
}


vector<int> dijkstra(int n, int start, const vector<vector<pii>>& graph) {
    vector<int> dist(n+1,INT32_MAX);
    priority_queue<pii,vector<pii>,greater<>> pq;
    dist[start] = 0;

    pq.emplace(0, start);

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < cost) continue;
        for(auto& next : graph[now]) {
            int nextNode = next.first;
            int nextCost = cost + next.second;

            if(dist[nextNode] > nextCost) {
                dist[nextNode] = nextCost;
                pq.emplace(nextCost,nextNode);
            }
        }
    }
    return dist;
}
