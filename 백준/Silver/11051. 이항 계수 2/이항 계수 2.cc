#include <iostream>
using namespace std;

int combination(int a,int b);
int mod_pow(int base, int exp, int mod);
int mod_inverse(int a, int m);
int main(int argc, char const *argv[])
{
    int N,M;
    cin >> N >> M;
    cout << combination(N,M);

    return 0;
}
int combination(int a,int b) {
    if(b == 0) return 1;
    int result = 1;
    for(int i = a; i > a-b; i--) {
        result *= i;
        if(result > 10000) result %= 10007;
    }
    for(int i = b; i >= 1; i--) {
        int inv = mod_inverse(i,10007);
        result = (result * inv) % 10007;
    } 
    return result; 
}

int mod_pow(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int mod_inverse(int a, int m) {
    return mod_pow(a, m - 2, m);
}