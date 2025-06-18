#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int main(int argc, char const *argv[])
{
    
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    bool prime[M+1];
    fill_n(prime, M + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i*i <= M; i++)
    {
        for (int j = i*i; j < M +1; j += i)
        {
            prime[j] = false;
        }
    }

    for(int i = N; i< M+1;i++) {
        bool ans = prime[i];
        if (ans)
        {
            cout << i << "\n";
        }
        
    }
    
    return 0;
}
