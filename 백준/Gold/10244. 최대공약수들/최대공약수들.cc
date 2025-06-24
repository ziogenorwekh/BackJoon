#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void searchForGcd(int size, int *sqs, bool *result);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (1)
    {
        int x;
        cin >> x;
        bool check[101] = {false};
        int sequences[x];
        if (x == 0)
            break;
        for (int i = 0; i < x; i++)
        {
            int sequence;
            cin >> sequence;
            check[sequence] = true;
            sequences[i] = sequence;
        }
        searchForGcd(x, sequences, check);
        int count = 0;
        for (int i = 0; i < 101; i++)
        {
            if (check[i])
                count++;
        }
        cout << count << "\n";
    }
    return 0;
}
void searchForGcd(int size, int *sqs, bool *result)
{
    bool prev[101] = {false};
    for (int i = 0; i < size; i++)
    {
        bool curr[101] = {false};
        curr[sqs[i]] = true;

        for (int g = 0; g < 101; g++)
        {
            if (prev[g])
            {
                int new_gcd = __gcd(g, sqs[i]);
                curr[new_gcd] = true;
            }
        }

        for (int g = 0; g < 101; g++)
        {
            if (curr[g])
            {
                result[g] = true;
            }
        }

        copy(curr, curr+101, prev);
    }
}
