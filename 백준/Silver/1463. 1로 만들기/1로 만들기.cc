#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long bfs(long long start);
int main(int argc, char const *argv[])
{
    long long N;
    cin >> N;
    cout << bfs(N);
    return 0;
}

long long bfs(long long start) {
    queue<long long> q;
    vector<int> dist(start + 1, -1);
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        long long node = q.front();
        if(node == 1) return dist[1];
        q.pop();
        if(node % 3 == 0 && dist[node / 3] == -1) {
            dist[node / 3] = dist[node] + 1;
            q.push(node / 3);
        } 
        if(node % 2 == 0 && dist[node / 2] == -1) 
        {
            dist[node / 2] = dist[node] + 1;
            q.push(node / 2);
        }
        if(node -1 >= 1 && dist[node-1] == -1) {
            dist[node - 1] = dist[node] + 1;
            q.push(node -1);
        } 
    }
    return dist[1];
}
