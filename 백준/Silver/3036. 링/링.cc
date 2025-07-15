#include <iostream>
using namespace std;

long long gcd(long long a, long long b);
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int arr[N] = {0};
    
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 1; i < N; i++) cout << (arr[0] / gcd(arr[0],arr[i])) << "/" << (arr[i] / gcd(arr[0],arr[i])) << endl;
    return 0;
}

long long gcd(long long a, long long b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}