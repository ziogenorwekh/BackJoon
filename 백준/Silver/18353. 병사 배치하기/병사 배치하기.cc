#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    vector<int> arr(N,0);
    for (int i = 0; i < N; i++) cin >> arr[i];
    vector<int> lis;
    for (int i = N-1; i >= 0; i--) {
        int x = arr[i];
        auto it = lower_bound(lis.begin(),lis.end(),x);
        if(it== lis.end()) lis.push_back(x);
        else *it = x;
    }
    cout << N - lis.size();
    return 0;
}
