#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <algorithm>
#include <sstream>
using namespace std;

struct compare {
    bool operator() (const pair<int,string>& a, const pair<int,string>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        } else {
            return a.first > b.first;
        }
    }
};

int main(int argc, char const *argv[]) {
    int N,M;
    cin >> N;
    map<string,int> algorithms;
    map<string,int> people;
    for (int i = 0; i < N; i++) {
        string algo; int level;
        cin >> algo >> level;   
        algorithms[algo] = level;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        string user; int level;
        cin >> user >> level;
        people[user] = level;
    }
    int query;
    cin >> query;
    string next;
    for (int i = 0; i < query + 1; i++) {
        string question;
        getline(cin,question);
        if (question.empty()) continue;
        stringstream ss(question);
        string name, hook;
        ss >> name >> hook;
        if (hook == "-") {
            cout << "hai!\n";
            next = name;
            continue;
        } else {
            priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq;
            map<string,int>::iterator it;
            for(it = algorithms.begin(); it != algorithms.end(); ++it) pq.push({abs(it->second-people[next]),it->first});
            string name = pq.top().second;
            pq.pop();
            string hook = pq.top().second;
            cout << hook << " yori mo " << name << "\n";
        }
    }
    return 0;
}