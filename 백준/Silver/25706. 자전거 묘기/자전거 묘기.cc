#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
    int N;
    cin >> N;
    vector<int> show(N,0);
    vector<int> dp(N,1);
    for(int i=0;i<N;i++) cin >> show[i];
    for(int i = N-2; i>= 0;i--) {
        if(i + show[i] + 1 < N) dp[i] = dp[i+show[i] + 1] + 1; 
    }
    for(int var : dp) cout << var << " ";
    return 0;
}