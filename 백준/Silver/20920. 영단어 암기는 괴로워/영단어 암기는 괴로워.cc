#include <iostream>
#include <map>
#include <queue>
using namespace std;

struct compare {
    bool operator()(const pair<int,string>& a,
                    const pair<int,string>& b) const {
        if(a.first != b.first) {
            return a.first < b.first;
        } else {
            if(a.second.length() != b.second.length()) {
                return a.second.length() < b.second.length();
            } else {
                return a.second > b.second;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N,M;
    cin >> N >> M;
    map<string,int> m;
    priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq;
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        if(word.length() >= M) {
            m[word]++;
        }
    }
    map<string,int>::iterator it;
    for(it = m.begin(); it != m.end(); ++it) {
        pq.push(make_pair(it->second,it->first));
    }
    while(!pq.empty()) {
        cout << pq.top().second << "\n";
        pq.pop();
    }
    
    return 0;
}
