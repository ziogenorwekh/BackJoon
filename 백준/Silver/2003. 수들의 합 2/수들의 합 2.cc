#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;

    cin >> N >> M;
    int table[N + 1] = {0};
    int prefix[N + 1] = {0};

    for (int i = 1; i < N + 1; i++)
    {
        cin >> table[i];
        prefix[i] = prefix[i - 1] + table[i];
    }
    int n1Pointer = 0;
    int n2Pointer = 1;
    int count = 0;
    while (n2Pointer <= N)
    {
        int result = prefix[n2Pointer] - prefix[n1Pointer];
        if (result < M) {
            n2Pointer++;
            continue;
        }
        else if (result > M) {
            n1Pointer++;
        }
        else {
            n1Pointer++;
            count++;
        }
    }
    cout << count;
    return 0;
}
