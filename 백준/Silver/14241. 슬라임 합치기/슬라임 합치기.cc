#include <iostream>
#include <queue>
using namespace std;

int solution(priority_queue<int> &pq) {
    int slime = pq.top();
    int answer = 0;
    pq.pop();
    while(!pq.empty()) {
        int next = pq.top();
        pq.pop();
        answer += slime * next;
        slime += next;
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }
    cout << solution(pq);
    return 0;
}

