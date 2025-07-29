#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited;
vector<int> path;
int N,M;
void dfs(int depth);
int main(int argc, char const *argv[])
{
    cin >> N >> M;
    visited.resize(N+1,0);
    dfs(0);
    return 0;
}

void dfs(int depth)
{
    if (depth == M) {
        for (int num : path)
            cout << num << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            path.push_back(i);

            dfs(depth + 1);

            visited[i] = false;
            path.pop_back();
        }
    }
}
