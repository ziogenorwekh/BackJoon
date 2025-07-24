#include <iostream>
#include <vector>
using namespace std;

vector<long long> searchPerm(long long n, long long where, vector<long long>& perms);
long long searchPermLocation(long long N, const vector<long long>& perms);
long long factorial(long long N);
int main(int argc, char const *argv[])
{
    long long N, M;
    cin >> N >> M;
    vector<long long> perms(N,0);
    if (M == 1) {
        // 1이면 N! 에 몇번째에요?
        long long search;
        cin >> search;
        for (long long i = 0; i < N; i++) perms[i] = i + 1;
        for (long long val : searchPerm(N, search,perms)) cout << val << " ";
    }
    else {
        // 2면 이 수열의 나열은 몇번째에요?
        for (long long i = 0; i < N; i++) cin >> perms[i];
        cout << searchPermLocation(N,perms);
    }
    return 0;
}

vector<long long> searchPerm(long long n, long long where, vector<long long>& perms)
{
    if (where != 0) where--;
    vector<long long> result(n);
    long long i = 0;
    long long last = n;
    while (i != n)
    {
        last -= 1;
        long long block = factorial(last);
        long long share = where / block;
        where = where % block;
        result[i++] = perms[share];
        perms.erase(perms.begin() + share);
    }
    return result;
}

long long searchPermLocation(long long N, const vector<long long>& perms) {
    long long pos = 0;
    vector<long long> index(N);
    for(long long i = 0; i < N; i++) index[i] = i+1;

    for (long long i = 0; i < N; i++) {
        long long val = perms[i];
        long long rank = 0;
        for (long long j = 0; j < index.size(); j++) {
            if (index[j] == val) {
                rank = j;
                index.erase(index.begin() + j);
                break;
            }
        }
        long long contrib = rank * factorial(N - 1 - i);
        pos += contrib;
    }
    return pos + 1;
}


long long factorial(long long N) {
    if (N == 0)
        return 1;
    long long res = 1;
    for (long long i = 2; i <= N; i++)
        res *= i;
    return res;
}