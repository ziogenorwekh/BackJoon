#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    int lefts = 1, rights = 0;
    int blueray[N + 1] = {0};

    for (int i = 1; i < N + 1; i++)
    {
        cin >> blueray[i];
        rights += blueray[i];
        if (blueray[i] > lefts) lefts = blueray[i];
    }
    int result = rights;
    while (lefts <= rights)
    {
        int mid = (lefts + rights) / 2;

        int count = 1;
        int tmpSum = 0;
        for (int i = 1; i <= N; i++)
        {
            if (tmpSum + blueray[i] > mid)
            {
                count++;
                tmpSum = blueray[i];
            }
            else
            {
                tmpSum += blueray[i];
            }
        }

        if (count > M)
        {
            lefts = mid + 1;
        }
        else
        {
            result = mid;
            rights = mid - 1;
        }
    }
    cout << result;
    return 0;
}
