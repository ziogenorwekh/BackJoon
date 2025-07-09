#include <iostream>
#include <vector>
using namespace std;

void unionSets(int x, int y);
int finds(int x);

vector<int> parent, ranks, knows;
vector<vector<int>> parties;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    parent.resize(N + 1);
    ranks.resize(N + 1,0);
    for (int i = 1; i < N + 1; i++) parent[i] = i;
    int K;
    cin >> K;
    knows.resize(K, 0);
    if (K == 0) {
        cout << M;
        return 0;
    } else {
        for (int i = 0; i < K; i++) cin >> knows[i];
        for (int i = 1; i < K; i++) unionSets(knows[0], knows[i]);
    }
    parties.resize(M);
    for (int i = 0; i < M; i++)
    {
        int people;
        cin >> people;
        bool isGrouped = false;
        parties[i] = vector<int>(people,0);
        for (int j = 0; j < people; j++) {
            cin >> parties[i][j];
            if (finds(knows[0]) == finds(parties[i][j])) isGrouped = true;
        }
        for (int j = 1; j < parties[i].size(); j++) unionSets(parties[i][0], parties[i][j]);
        if (isGrouped) for (int k = 0; k < parties[i].size(); k++) unionSets(knows[0],parties[i][k]);
    }
    int count = M;
    for (vector<int> v : parties)
    {
        for (int person : v)
        {
            if (finds(knows[0]) == finds(person)) {
                count--;
                break;
            }
        }
    }
    cout << count;
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
    if (parent[x] != x)
        parent[x] = finds(parent[x]);
    return parent[x];
}