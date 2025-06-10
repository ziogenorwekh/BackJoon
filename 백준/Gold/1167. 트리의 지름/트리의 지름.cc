#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
void bfs(int node);
vector<pair<int, int>> graph[100001];
int distances[100001] = {0};
bool visited[100001] = {false};
int fasthest = 0;
int N;
int main(int argc, char const *argv[])
{
    cin >> N;
    cin.ignore();
    int j = 1;
    for (int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int from;
        ss >> from;

        while (true)
        {
            int to, weight;
            ss >> to;
            if (to == -1)
                break;
            ss >> weight;
            graph[from].push_back({to, weight});
        }
    }
    bfs(1);
    bfs(fasthest);
    int size = sizeof(distances) / sizeof(distances[0]);
    sort(distances, distances + size, greater<>());
    cout << distances[0];
    return 0;
}

void bfs(int node)
{
    fill(visited, visited + N + 1, false);
    fill(distances, distances + N + 1, 0);
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (auto edge : graph[current])
        {
            int next = edge.first;
            int weight = edge.second;

            if (!visited[next])
            {
                visited[next] = true;
                distances[next] = distances[current] + weight;
                if (distances[next] > distances[fasthest])
                {
                    fasthest = next;
                }
                q.push(next);
            }
        }
    }
}