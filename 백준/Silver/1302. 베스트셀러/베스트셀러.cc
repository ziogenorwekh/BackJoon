#include <iostream>
#include <map>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    map<string,int> m;
    int max = 0;
    priority_queue<string,vector<string>,greater<string>> pq;
    for (int i = 0; i < N; i++) {
        string sell;
        cin >> sell;
        m[sell]++;
        if(m[sell] > max) {
            max = m[sell];
        }
    }
    map<string,int>::iterator it;
    for(it = m.begin(); it != m.end(); ++it) {
        if(it->second == max) {
            pq.push(it->first);
        }
    }
    cout << pq.top();
    return 0;
}
