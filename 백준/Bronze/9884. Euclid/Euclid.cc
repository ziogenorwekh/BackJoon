#include <iostream>
using namespace std;

long long gcd(long long a, long long b);
int main(int argc, char const *argv[])
{
    long long N, M;
    cin >> N >> M;
    cout << gcd(N, M);
    return 0;
}
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}