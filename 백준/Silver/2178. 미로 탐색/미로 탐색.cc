#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<vector<int>> graph;
void bfs(vector<vector<int>> &graph, int X, int Y,
         vector<vector<int>> &distance, vector<vector<bool>> &visited);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int N, M;
// N -> Y
// M -> X
int main(int argc, char const *argv[])
{
    cin >> N >> M;
    vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));
    vector<vector<int>> graph(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> distance(N + 1, vector<int>(M + 1, 1));
    for (int i = 1; i < N + 1; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
            graph[i][j + 1] = s.at(j) - '0';
    }

    bfs(graph, 1, 1, distance, visited);
    cout << distance[N][M];

    return 0;
}

void bfs(vector<vector<int>> &graph, int X, int Y,
         vector<vector<int>> &distance, vector<vector<bool>> &visited)
{

    queue<pair<int, int>> q;
    q.push(make_pair(Y, X));
    visited[Y][X] = true;

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx > M || ny > N)
                continue;
            if (!visited[ny][nx] && graph[ny][nx] == 1)
            {
                visited[ny][nx] = true;
                distance[ny][nx] += distance[y][x];
                q.push(make_pair(ny,nx));
            }
        }
    }
}