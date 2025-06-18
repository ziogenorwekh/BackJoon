#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;

vector<bool> prime;
unordered_set<long long> seen;
int main(int argc, char const *argv[])
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M;
    cin >> N >> M;
    int limit = floor(sqrt(M));
    
    prime.resize(limit + 1);
    vector<long long> sqrts;
    fill(prime.begin(), prime.end(), true);
    prime.at(0) = prime.at(1) = false;
    for (int i = 2; i * i <= limit; i++)
    {
        if (prime.at(i))
        {
            for (long long j = i * i; j <= limit; j += i)
            {
                prime.at(j) = false;
            }
        }
    }

    for (int i = 2; i < prime.size(); i++)
    {
        if (prime.at(i))
        {
            sqrts.push_back(i);
        }
    }

    for (long long base : sqrts)
    {
        long long value = base * base;
        while (true)
        {
            if (value > M)
            {
                break;
            }
            else
            {
                if (N <= value)
                {
                    seen.insert(value);
                }
            }

            if (value > M / base) {
                break;
            }
            value *= base;

        }
    }
    cout << seen.size();
    return 0;
}
