#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 1e9;

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));
    for (int i = 1; i < M + 1; i++)
    {
        int A, B;
        cin >> A >> B;
        graph[A][B] = 1;
        graph[B][A] = 1;
    }
    for (int i = 1; i < N + 1; i++) graph[i][i] = 0;

    for (int i = 1; i < N + 1; i++)
        for (int j = 1; j < N + 1; j++)
            for (int k = 1; k < N + 1; k++)
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
    int min = 1e9;
    int baconMan = 0;

    for (int i = 1; i < N + 1; i++)
    {
        int sum = 0;
        for (int j = 1; j < N + 1; j++) if(i != j) sum += graph[i][j];
        if (min > sum)
        {
            min = sum;
            baconMan = i;
        }
    }
    cout << baconMan << endl;
    return 0;
}