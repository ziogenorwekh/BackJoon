#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    long long N;

    vector<long long> v;
    cin >> N;
    long long tmp = N;
    
    for (long long i = 2; i*i <= N; i++)
    {
        if (tmp % i == 0)
        {
            v.push_back(i);
            while (tmp % i == 0)
            {
                tmp /= i;
            }
        }
    }
    if (tmp > 1)
    {
        v.push_back(tmp);
    }
    
    long long result = N;
    for (long long val : v)
    {
        result = result / val * (val - 1);
    }
    cout << result;
    return 0;
}
