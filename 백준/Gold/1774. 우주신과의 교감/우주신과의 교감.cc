#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

struct Edge {
    int u, v;
    double w;
    Edge(int u, int v, double w) : u(u), v(v), w(w) {}
    bool operator<(const Edge &rhs) const {
        return w < rhs.w;
    }
};
int parent[1001] = {0};
int findParent(int x);
bool unionParent(int a, int b);
double kruskalMST(int v, vector<Edge> &edges);
double distances(int x1, int y1, int x2, int y2);
int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> distance(N + 1);
    vector<Edge> edges;
    vector<vector<bool>> visited(N+1,vector<bool>(N+1,false));
    for (int i = 1; i < 1001; i++) parent[i] = i;
    for (int i = 1; i < N + 1; i++) {
        int x, y;
        cin >> x >> y;
        distance[i] = {x, y};
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        auto &x1 = distance[u];
        auto &x2 = distance[v];
        edges.emplace_back(u, v, distances(x1.first, x2.first, x1.second, x2.second));
        visited[u][v] = true;
        visited[v][u] = true;
        unionParent(u, v);
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = i + 1; j < N + 1; j++) {
            if(!visited[i][j]) {
                auto &x1 = distance[i];
                auto &x2 = distance[j];
                edges.emplace_back(i, j, distances(x1.first, x1.second, x2.first, x2.second));
            }
        }
    }
    cout << fixed << setprecision(2) << kruskalMST(N, edges);
    return 0;
}

int findParent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}

bool unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return false;
    parent[b] = a;
    return true;
}

double kruskalMST(int v, vector<Edge> &edges) {
    sort(edges.begin(), edges.end());
    double mst = 0;
    for (auto &e : edges) if (unionParent(e.u, e.v)) mst += e.w;
    return mst;
}

double distances(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}