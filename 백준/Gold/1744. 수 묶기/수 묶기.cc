#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int result = 0;
    priority_queue<long, vector<long>> plusPq;
    priority_queue<long, vector<long>, greater<int>> minusPq;
    bool hasZero = false;
    for (int i = 0; i < N; i++)
    {
        int x = 0;
        cin >> x;
        if (x < 0)
        {
            minusPq.push(x);
        }
        else if (x == 1)
        {
            result += 1;
        }
        else if (x == 0)
        {
            hasZero = true;
        }
        else
        {
            plusPq.push(x);
        }
    }

    while (plusPq.size() > 1)
    {
        int x = plusPq.top();
        plusPq.pop();
        int y = plusPq.top();
        plusPq.pop();
        result += (x * y);
    }

    if (!plusPq.empty())
    {
        result += plusPq.top();
        plusPq.pop();
    }

    while (minusPq.size() > 1)
    {
        int x = minusPq.top();
        minusPq.pop();
        int y = minusPq.top();
        minusPq.pop();
        result += (x * y);
    }
    
    if (minusPq.size() == 1)
    {
        if (!hasZero)
        {
            result += minusPq.top();
            minusPq.pop();
        }
        
    }
    cout << result << endl;

    return 0;
}
