#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[2001];
int N, M;
bool visited[2001] = {false};
bool isOk = false;
void dfs(int node, int depth);
// 간선은 4개가 나오면 됨, 노드 5개
int main(int argc, char const *argv[])
{
    cin >> N >> M;
    for (int i = 1; i < M + 1; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i < N + 1; i++)
    {
        dfs(i, 1);

        if (isOk) {
            cout << "1";
            return 0;
        }
    }

    cout << "0";

    return 0;
}

void dfs(int node, int depth)
{
    if (depth == 5)
    {
        isOk = true;
        return;
    }

    visited[node] = true;
    for (int next : graph[node])
    {
        if (!visited[next])
        {
            dfs(next, depth + 1);
        }
    }
    visited[node] = false;
}