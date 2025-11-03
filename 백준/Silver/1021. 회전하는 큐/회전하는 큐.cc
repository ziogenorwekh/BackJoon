#include <deque>
#include <iostream>
using namespace std;

int main() {
    int N,M,num;
    int result = 0;
    cin >> N >> M;
    deque<int> dq;
    for(int i = 1; i <= N; i++) dq.push_back(i);
    for(int i = 0; i < M; i++) {
        cin >> num;
        if(num == dq[0]) {
            dq.pop_front();
        } else {
            int index = 0;
            for(int i = 0; i < dq.size(); i++) {
                if(dq[i] == num) {
                    index = i;
                    break;
                }
            }
            while (true) {
                if(dq.front() == num) {
                    dq.pop_front();
                    break;
                }
                result++;
                int value;
                if(index > dq.size() / 2) {
                    value = dq.back();
                    dq.pop_back();
                    dq.push_front(value);
                } else {
                    value = dq.front();
                    dq.pop_front();
                    dq.push_back(value);
                }
            }
        }
    }
    cout << result;
}