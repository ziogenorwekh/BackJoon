#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct compare
{
    bool operator()(const pair<int,int> &x, const pair<int,int> &y) {
        return x.second < y.second || (x.second == y.second && x.first < y.first);
    }
};


int main(int argc, char const *argv[])
{
    int N;
    int count = 1;
    cin >> N;
    vector<pair<int,int>> v;

    for (int i = 0; i < N; i++)
    {
        int x,y;
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(),v.end(),compare());

    int index = 0;
    int currentEndTime = v.at(index++).second;
    
    while (index < v.size())
    {
        if (v.at(index).first >= currentEndTime)
        {
            currentEndTime = v.at(index).second;
            count++;
        }
        index++;
    }
    

    cout << count;
    return 0;
}
