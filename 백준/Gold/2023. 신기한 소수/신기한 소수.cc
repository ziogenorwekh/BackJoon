#include <iostream>
#include <vector>
using namespace std;

void dfs(int currentValue, int depth);
bool isprime(int number);
int decimals[10] = {1,2,3,5,7,9};
int N;
int main(int argc, char const *argv[])
{
    cin >> N;
    for (int d : {1,2,3,5,7,9})
    {
        dfs(d, 1);
    }

    return 0;
}

void dfs(int currentValue, int depth)
{

    if (!isprime(currentValue))
    {
        return;
    }
    if (depth == N)
    {
        cout << currentValue << endl;
        return;
    }
    for (int next : decimals )
    {
        dfs(currentValue * 10 + next, depth + 1);
    }
}

bool isprime(int number)
{
    if (number < 2)
        return false;
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}