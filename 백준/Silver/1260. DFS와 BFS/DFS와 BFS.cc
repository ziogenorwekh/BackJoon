#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void bfs(int node);
void dfs(int node);
struct compare
{
    bool operator()(int x, int y) const
    {
        return x > y;
    }
};

bool visitedDFS[1001] = {false};
bool visitedBFS[1001] = {false};
priority_queue<int, vector<int>, compare> dgraph[1001];
priority_queue<int, vector<int>, compare> bgraph[1001];

int main(int argc, char const *argv[])
{
    int N, M, start;

    cin >> N >> M >> start;
    for (int i = 1; i < M + 1; i++)
    {
        int x, y;
        cin >> x >> y;
        dgraph[x].push(y);
        dgraph[y].push(x);
        bgraph[x].push(y);
        bgraph[y].push(x);
    }

    dfs(start);
    cout << endl;
    bfs(start);

    return 0;
}

void dfs(int node)
{
    cout << node << " ";
    visitedDFS[node] = true;
    while (!dgraph[node].empty())
    {
        int next = dgraph[node].top();
        dgraph[node].pop();
        if (!visitedDFS[next])
        {
            dfs(next);
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    visitedBFS[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        while (!bgraph[node].empty())
        {
            int next = bgraph[node].top();
            bgraph[node].pop();

            if (!visitedBFS[next])
            {
                visitedBFS[next] = true;
                q.push(next);
            }
        }
    }
}