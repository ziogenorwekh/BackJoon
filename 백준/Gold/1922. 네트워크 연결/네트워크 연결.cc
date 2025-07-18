#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const Edge &rhs) const {
        return w < rhs.w;
    } 
};
int parent[1001] = {0};
int findParent(int x);
bool unionParent(int a, int b);
int kruskalMST(int v,vector<Edge>& edges);
int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    vector<Edge> edges;

    for (int i = 0; i < M; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        edges.emplace_back(u,v,w);
    }
    cout << kruskalMST(N,edges);

    return 0;
}

int findParent(int x) {
    if (parent[x] == x) return x;
    return findParent(parent[x]);
}

bool unionParent(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if(a == b) return false;
    parent[b] = a;
    return true;
}

int kruskalMST(int v,vector<Edge>& edges) {
    for(int i = 1; i < 1001; i++) parent[i] = i;
    sort(edges.begin(),edges.end());

    int mst = 0;
    for(auto& e : edges) if(unionParent(e.u,e.v)) mst += e.w;
    return mst;
}