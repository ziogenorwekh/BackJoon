#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct compare
{
    bool operator()(int x, int y)
    {
        return x > y;
    }
};

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    long result = 0;

    priority_queue<long, vector<long>, compare> pq;

    if (N == 1)
    {
        long value;
        cin >> value;
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        long value;
        cin >> value;
        pq.push(value);
    }

    while (pq.size() > 1)
    {
        long x = pq.top();
        pq.pop();
        long y = pq.top();
        pq.pop();
        result += (x + y);
        pq.push(x+y);
    }

    cout << result << endl;
    return 0;
}
