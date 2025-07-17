#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int primMST(int v, vector<vector<pair<int, int>>> &edges);
int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> edges(N+1);
    for (int i = 1; i < M + 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(v, w));
        edges[v].push_back(make_pair(u,w));
    }
    cout << primMST(N,edges);
    return 0;
}

int primMST(int v, vector<vector<pair<int, int>>> &edges)
{
    vector<bool> visited(v+1,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    int mst = 0;
    pq.push({0,1});

    while (!pq.empty())
    {
        int w = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if(visited[v]) continue;
        visited[v] = true;
        mst += w;
        for (auto &edge : edges[v])
        {
            int nextV = edge.first;
            int weight = edge.second;
            if(!visited[nextV]) pq.push({weight,nextV});
        }
        
    }
    return mst;
    
}