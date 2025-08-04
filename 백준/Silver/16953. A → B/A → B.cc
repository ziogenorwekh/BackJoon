#include <iostream>
#include <map>
#include <queue>

void bfs(int start,int end) {
    std::queue<long long> q;
    std::map<long long, long long> dist;
    q.push(start);
    dist[start] = 1;
    while(!q.empty()) {
        long long node = q.front();
        q.pop();
        long long nextNode1 = node * 2;
        long long nextNode2 = node * 10 + 1;
        if(nextNode1 <= end) {
            dist[nextNode1] = dist[node] + 1;
            q.push(nextNode1);
        }
        if(nextNode2 <= end) {
            dist[nextNode2] = dist[node] + 1;
            q.push(nextNode2);
        }
    }
    std::cout << (dist[end] == 0 ? -1 : dist[end]);
}

int main(int argc, char const *argv[])
{
    long long A,B;
    std::cin >> A >> B;
    bfs(A,B);
    return 0;
}
