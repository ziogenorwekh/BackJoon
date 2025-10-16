#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    int N,M;
    cin >> N >> M;
    priority_queue<int,vector<int>,greater<int>> q;
    for (int i = 1; i*i <= M; i++) {
        int value = i*i;
        if (value >= N) q.push(value);
    }
    if(q.empty()) {
        cout << -1;
        return 0;
    }
    int min = q.top();
    int sum = 0;
    while (!q.empty()) {
        int var = q.top();
        q.pop();
        sum += var;
    }
    cout << sum << "\n" << min;

    return 0;
}
