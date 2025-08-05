#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    int maxRope = v[v.size() - 1];
    for(int j = 0; j < v.size(); j++) {
        int tmp = v[j] * (v.size()-j);
        if(tmp > maxRope) {
            maxRope = tmp;
        }
    }
    cout << maxRope << '\n';
    return 0;
}
