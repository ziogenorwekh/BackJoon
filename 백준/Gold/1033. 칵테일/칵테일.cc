#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class MRatio
{
public:
    int x, y;
    MRatio(int initial_x, int initial_y) : x(initial_x), y(initial_y) {}
};

int N;
vector<pair<long long, long long>> amounts;
vector<vector<pair<int, MRatio>>> graph;
vector<bool> visited;
void dfs(const int v);

int main(int argc, char const *argv[])
{
    cin >> N;
    amounts.resize(N, {0, 0});
    graph.resize(N);
    visited.resize(N, false);
    for (int i = 0; i < N - 1; i++)
    {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        graph[x].push_back({y, MRatio(p, q)});
        graph[y].push_back({x, MRatio(q, p)});
    }
    amounts[0] = {1,1};

    dfs(0);
    long long lcm = 1;
    for (auto &value : amounts)
    {
        long long gcd = __gcd(lcm, value.second);
        lcm = (lcm / gcd) * value.second;
    }
    
    for (auto &value : amounts)
    {
        cout << (value.first * lcm) / value.second << " ";    
    }
    
    

    return 0;
}

void dfs(const int v)
{
    visited[v] = true;
    for (auto &edge : graph[v])
    {
        int next = edge.first;
        long long p = static_cast<long long>(edge.second.x) * amounts[v].second;
        long long q = static_cast<long long>(edge.second.y) * amounts[v].first;

        long long g = __gcd(p, q);
        p /= g;
        q /= g;

        amounts[next] = {q, p};
        if (!visited[next])
        {
            dfs(next);
        }
    }
}
