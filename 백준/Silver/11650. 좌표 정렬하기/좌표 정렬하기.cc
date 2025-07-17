#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct compare {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if (a.first != b.first) 
            return a.first < b.first;
        return a.second < b.second;
    }
};

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<pair<int,int>> v;
    for (int i = 0; i < N; i++)
    {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),compare());
    for (auto &p : v) cout << p.first << " " << p.second << "\n";

    return 0;
}
