#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct compare
{
    bool operator()(int a, int b)
    {
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    priority_queue<int, vector<int>, compare> pq;

    int table[N] = {0};
    for (int i = 0; i < N; i++)
    {
        cin >> table[i];
    }
    int index = 0;
    for (int i = 0; i < N; i++)
    {
        if (table[i] == 0)
        {
            if (pq.empty())
            {
                cout << "0" << "\n";
            }
            else
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
        {
            pq.push(table[i]);
        }
    }

    return 0;
}