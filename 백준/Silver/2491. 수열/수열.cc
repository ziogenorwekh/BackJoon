#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]) {
    int N,M;
    cin >> N;
    vector<int> arr(N,0);
    for (int i = 0; i < N; i++) cin >> arr[i];
    vector<int> upDp(N,1);
    vector<int> downDp(N,1);
    for (int i = 0; i < N - 1; i++) {
        if(arr[i] <= arr[i+1]) upDp[i + 1] = upDp[i] + 1;   
        if(arr[i] >= arr[i+1]) downDp[i + 1] = downDp[i] + 1;
    }
    int up = *max_element(upDp.begin(),upDp.end());
    int down = *max_element(downDp.begin(),downDp.end());
    int result = max(up,down);
    if(N > 1 && result < 3) cout << 2;
    else cout << result;
    return 0;
}