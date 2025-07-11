#include <iostream>
#include <map>
using namespace std;

long long combination(long long N, long long R)
{
    if (R == 0)
        return 1;
    map<int, int> keys;
    long long result = 1;
    for (long long k = 2; k <= R; k++)
        keys.emplace(k, k);
    for (long long j = N; j >= N - R + 1; j--)
    {
        result *= j;
        for (int j = 2; j <= R; j++)
        {
            auto it = keys.find(j);
            if (it != keys.end() && result % it->second == 0)
            {
                result /= it->second;
                keys.erase(it);
            }
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    long long N, R;
    cin >> N >> R;
    cout << combination(N - 1, R - 1);
    return 0;
}
