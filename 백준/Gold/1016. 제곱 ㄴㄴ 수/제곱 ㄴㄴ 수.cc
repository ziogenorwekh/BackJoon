#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    long long minN,maxN;
    cin >> minN >> maxN;
    vector<int> v(maxN - minN + 1);
    fill(v.begin(),v.end(),0);
    long long count = 0;
    for (long long i = 2; i*i <= maxN; i++)
    {
        long long sq = i*i;
        long long start = ((minN + sq - 1) / sq) * sq;
        for (long long j = start; j<= maxN; j+=sq)
        {
            v[j-minN] = 1;
        }
    }
    for (int isOk : v)
    {
        if (isOk == 0)
            count++;
    }
    cout << count;
    return 0;
}
