#include <iostream>
#include <vector>
using namespace std;

void f(int n);
vector<pair<int,int>> v;
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    v.resize(41);
    f(41);
    for(int i=0;i<N;i++) {
        int num;
        cin >> num;
        cout << v[num].first << " " << v[num].second << "\n";
    }
    return 0;
}

void f(int n) {
    v[0].first = 1;
    v[0].second = 0;
    v[1].first = 0;
    v[1].second = 1;

    for(int i = 2;i<v.size();i++) {
        v[i].first = v[i-1].second;
        v[i].second = v[i-1].first + v[i-1].second;
    }
}