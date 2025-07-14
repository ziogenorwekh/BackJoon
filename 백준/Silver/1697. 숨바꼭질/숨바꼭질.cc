#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int bfs(int sister, int brother);
int main(int argc, char const *argv[])
{
    cin >> N >> M;
    cout << bfs(N, M) << '\n';
    return 0;
}

int bfs(int sister, int brother)
{
    vector<int> distance(100001, -1);
    queue<int> q;
    q.push(sister);
    distance[sister] = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        int candidates[3] = {now * 2, now - 1, now + 1};

        for (int next : candidates)
        {
            if (next >= 0 && next <= 100000 && distance[next] == -1)
            {
                distance[next] = distance[now] + 1;
                if (next == brother) return distance[next];
                q.push(next);
            }
        }
    }
    return distance[brother];
}