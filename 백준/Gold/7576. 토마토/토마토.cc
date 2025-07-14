#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 좌 우 상 하
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(vector<vector<int>>& graph, int N, int M);
bool isZero(const vector<vector<int>>& graph, int N, int M);
int maxValue(const vector<vector<int>>& graph, int N, int M);
int main(int argc, char const *argv[]) {
    int N, M;

    cin >> N >> M;
    vector<vector<int> > graph(M + 1, vector<int>(N + 1, 0));
    for (int i = 1; i < M + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            cin >> graph[i][j];
        }
    }

    bfs(graph, N, M);

    if (!isZero(graph,N,M)) cout << maxValue(graph,N,M) - 1;
    else cout << "-1";

    return 0;

}
// i는 y면서 M이고 j는 x면서 N이야
void bfs(vector<vector<int>>& graph, const int N, const int M) {
    queue<pair<int, int> > q;
    for (int i = 1; i < M + 1; i++) for (int j = 1; j < N + 1; j++) if (graph[i][j] == 1) q.emplace(i, j);

    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
                if(graph[ny][nx] == 0) {
                    graph[ny][nx] = graph[y][x] + 1;
                    q.emplace(ny,nx);
                }
            }
        }
    }
}

bool isZero(const vector<vector<int>>& graph,const int N, const int M) {
    for (int i = 1; i < M + 1; i++) for (int j = 1; j < N + 1; j++) if (graph[i][j] == 0) return true;
    return false;
}

int maxValue(const vector<vector<int>>& graph,const int N, const int M) {
    int max = 0;
    for (int i = 1; i < M + 1; i++) for (int j = 1; j < N + 1; j++) if (graph[i][j] > max) max = graph[i][j];
    return max;
}