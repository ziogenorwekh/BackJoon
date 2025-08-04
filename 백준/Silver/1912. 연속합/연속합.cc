#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> arr(N, 0);
    for (int i = 0; i < N; i++) cin >> arr[i];
    int current = arr[0];
    int max_curr = arr[0];
    for (int i = 1; i < N; i++) {
        current = max(arr[i], current + arr[i]);
        max_curr = max(current, max_curr);
    }
    cout << max_curr;
    return 0;
}
