#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    long long N;
    long long A;
    cin >> N >> A;
    long long first = 1, last = N * N;
    long long result = last;
    while (first <= last)
    {
        long long mid = (last + first) / 2;
        long long count = 0;
        for (int i = 1; i <= N; i++)
        {
            count += min(mid / i, N);
        }

        if (A > count)
        {
            first = mid + 1;
        }
        else
        {
            result = mid;
            last = mid - 1;
        }
    }
    cout << result;

    return 0;
}
