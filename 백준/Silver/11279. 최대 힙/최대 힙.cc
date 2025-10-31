#include <iostream>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    priority_queue<long long> pq;
    for(int i = 0; i< N; i++) {
        long long num;
        cin >> num;
        if(num == 0) {
            if(!pq.empty()) {
                cout << pq.top() << "\n";
                pq.pop();
            } else {
                cout << num << "\n";
            }
        } else {
            pq.push(num);
        }
    }
    return 0;
}