#include <iostream>
using namespace std;

long long combination(long long a, long long b);
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long long x, y;
        cin >> x >> y;
        cout << combination(y, x) << "\n";
    }

    return 0;
}

long long combination(long long a, long long b)
{
    if (a == b || a == 0 || b == 0) return 1;
    long long result = 1;
    long long start = 2;
    for (long long i = a; i >= a - b + 1; i--) {
        result *= i;
        while (start <= b) {
            if(result % start != 0) break;
            result /= start++;
        } 
    }
    for (long long i = start; i <= b; i++) result /= i;
    return result;
}