#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<pair<int,int>> v(6);
    int totalExtent = 1;
    int subExtent = 0;
    map<int,pair<int,int>> m;
    for(int i = 0; i< 6; i++) {
        int direction, length;
        cin >> direction >> length;
        v[i] = make_pair(direction,length);
        m[direction].first++;
        m[direction].second = length;
    }
    map<int,pair<int,int>>::iterator it;
    for(it = m.begin(); it != m.end(); ++it) {
        if(it->second.first == 1) totalExtent *= it->second.second; 
    }
    for (int i = 0; i < 12; i++) {
        if(v[i % 6].first == v[(i+2) % 6].first && v[(i+1)%6].first == v[(i+3) % 6].first) {
            subExtent = (v[(i+1)%6].second * v[(i+2)%6].second);
        }
    }
    cout << N*(totalExtent - subExtent);
    return 0;
}
