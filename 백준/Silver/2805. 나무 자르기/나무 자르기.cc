#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    int result = 0;
    vector<long long> trees(N,0);
    for(int i = 0; i < N; i++) cin >> trees[i];
    if(N == 1) {
        cout << trees[0] - M;
        return 0;
    }
    long long min = 0;
    long long max = *max_element(trees.begin(),trees.end());
    while (min <= max) {
        long long mid = (min + max)/2;
        long long cutOf = 0;
        for(int i =0;i<N;i++) {
            long long cutting = trees[i] - mid;
            if(cutting >= 0) cutOf += cutting;
        }
        if(cutOf >= M) {
            min = mid+1;
            result = mid;
        } else if (cutOf < M) {
            max = mid-1;
        }
    }
    cout << result;
    return 0;
}