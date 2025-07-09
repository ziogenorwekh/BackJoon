#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void unionSets(int x, int y);
int finds(int x);
vector<int> parent, ranks, journey;
int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    parent.resize(N + 1, 0);
    ranks.resize(N + 1, 0);
    journey.resize(M + 1, 0);
    for (int i = 1; i < N + 1; i++) parent[i] = i;

    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            int x;
            if (cin >> x && x == 1) unionSets(i, j);
        }
    }

    for (int i = 1; i < M + 1; i++) cin >> journey[i];
    bool result = true;
    for (int i = 1; i < M + 1; i++) if(finds(journey[1]) != finds(journey[i])) result = false;
    if (result) cout << "YES";
    else cout << "NO";
    return 0;
}
void unionSets(int x, int y)
{
    x = finds(x);
    y = finds(y);
    if (x == y) return;
    if (ranks[x] < ranks[y]) parent[x] = y;
    else {
        parent[y] = x;
        if (ranks[x] == ranks[y]) ranks[x]++;
    }
}
int finds(int x)
{
    if (parent[x] != x) parent[x] = finds(parent[x]);
    return parent[x];
}
