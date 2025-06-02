#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, M, input;

    cin >> N >> M;
    long long remain[M] = {0};
    long long inputBefore = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        long long remainder = ((inputBefore + input) % M + M) % M;
        remain[remainder]++;
        inputBefore = inputBefore + input;
    }
    long long result = 0;
    for (int i = 0; i < M; i++)
    {
        result += ((remain[i] * (remain[i] - 1)) / 2);
    }

    cout << result + remain[0];
    return 0;
}