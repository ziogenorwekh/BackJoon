#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<int> jump;
void bfs(int start,int N) {
    vector<int> distance(N + 1,0);
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int next = q.front();
        q.pop();
        for(int i = 1; i <= jump[next]; i++) {
            if(next + i <= N && distance[next+i] == 0) {
                distance[next + i] = distance[next] + 1;
                q.push(next + i);
            }
        }
    }
    if(distance[N] == 0 && start != N) cout << -1;
    else cout << distance[N];
}

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    jump.resize(N + 1,0);
    for(int i=1; i <= N; i++) cin >> jump[i];
    bfs(1,N);
    return 0;
}