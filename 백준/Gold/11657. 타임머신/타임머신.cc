#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
const long long INF = 1e15;
vector<tuple<int,int,int>> edges;
vector<long long> dist;
bool bellman_ford(int start,int N);
int main(int argc, char const *argv[])
{
    int N,M;
    cin >> N >> M;
    dist.resize(N+1,INF);
    for (int i = 0; i < M; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    if(!bellman_ford(1,N)) {
         cout << -1;
         return 0;
    }
    for (int i = 2; i < N + 1; i++) {
        if(dist[i] == INF) {
            cout << -1 << "\n";
            continue;
        }
        cout << dist[i] << "\n";
    }

    return 0;
}

bool bellman_ford(int start,int N) {
    dist[start] = 0;
    for(int i = 1 ; i < N; i++) {
        for(const auto& e : edges) {
            int u, v, w;
            tie(u, v, w) = e;
            if(dist[u] != INF && dist[v] > dist[u] + w) dist[v] = dist[u] + w;
        }
    }

    for(const auto& e : edges) {
        int u, v, w;
        tie(u, v, w) = e;
        if(dist[u] != INF && dist[v] > dist[u] + w) return false;
    }

    return true;
}