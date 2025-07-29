#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<int> transit;
int N, M;
void dijkstra(int start, int end);
int main(int argc, char const *argv[]) {
    cin >> N >> M;
    graph.resize(N + 1);
    transit.resize(N + 1, -1);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }
    int start, end;
    cin >> start >> end;
    dijkstra(start, end);
    return 0;
}

void dijkstra(int start, int end) {
    vector<int> dist(N + 1, INT32_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (dist[now] < cost) continue;
        for (auto &next : graph[now]) {
            int nextNode = next.first;
            int nextCost = cost + next.second;
            if (dist[nextNode] > nextCost) {
                dist[nextNode] = nextCost;
                pq.push(make_pair(nextCost, nextNode));
                transit[nextNode] = now;
            }
        }
    }
    cout << dist[end] << endl;
    vector<int> result;
    int cur = end;
    while (cur != -1) {
    result.push_back(cur);
    cur = transit[cur];
    }
    reverse(result.begin(), result.end());
    cout << result.size() << endl;
    for(int num : result) cout << num << " ";
}