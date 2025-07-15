#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 1e9;
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));

    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < N + 1; j++) {
            int w;
            cin >> w;
            if(w == 1) {
                graph[i][j] = w;
            }
        }

    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < N + 1; j++)
            for (int k = 1; k < N + 1; k++)
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            if(graph[i][j] == INF) cout << 0 << " ";
            else cout << 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
