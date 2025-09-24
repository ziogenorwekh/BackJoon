#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void point(vector<int> arr,vector<int> brr) {
    int count = 0;
    int brrMin = *min_element(brr.begin(),brr.end());
    for(int i = 0;i<arr.size();i++) {
        if (arr[i] <= brrMin) continue;
        for (int j = 0; j < brr.size(); j++) {
            if(arr[i] <= brr[j]) continue;
            count++; 
        }
    }
    cout << count << "\n";
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int A,B;
        cin >> A >> B;
        vector<int> arr(A,0);
        vector<int> brr(B,0);
        for (int i = 0; i < A; i++) cin >> arr[i];
        for (int i = 0; i < B; i++) cin >> brr[i];
        point(arr,brr);
    }
    return 0;
}
