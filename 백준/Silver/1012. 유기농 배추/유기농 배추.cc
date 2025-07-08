#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int Y, int X, int xSize, int ySize);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int X, Y, K;
        cin >> X >> Y >> K;
        int count = 0;
        vector<vector<int>> graph(Y, vector<int>(X, 0));
        vector<vector<bool>> visited(Y, vector<bool>(X, false));
        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[y][x] = 1;
        }

        for (int i = 0; i < Y; i++)
        {
            for (int j = 0; j < X; j++)
            {
                if (!visited[i][j] && graph[i][j] == 1)
                {
                    count++;
                    bfs(graph, visited, i, j, X, Y);
                }
            }
        }
        cout << count << "\n";
    }
    return 0;
}

void bfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int Y, int X, int xSize, int ySize)
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
            if (nx >= 0 && ny >= 0 && nx < xSize && ny < ySize)
            {
                if (!visited[ny][nx] && graph[ny][nx] == 1)
                {
                    visited[ny][nx] = true;
                    q.push(make_pair(ny,nx));
                }
            }
        }
    }
}