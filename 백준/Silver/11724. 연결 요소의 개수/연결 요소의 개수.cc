#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[1001];
bool visited[1001] = {false};
int counter = 0;

void dfs(int node);

int main(int argc, char const *argv[])
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int X,Y;
        cin >> X >> Y;
        graph[X].push_back(Y);
        graph[Y].push_back(X);
    }
    
    for (int i = 1; i < N + 1; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            counter++;
        }
        
    }
    
    cout << counter;

    return 0;
}

void dfs(int node)
{
    visited[node] = true;
    for (int next : graph[node])
    {
        if (!visited[next])
        {
            dfs(next);
        }
    }
}