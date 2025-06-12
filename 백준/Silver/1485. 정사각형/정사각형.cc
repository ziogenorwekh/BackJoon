#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct compare
{
    bool operator()(const long long x, const long long y) const
    {
        return x > y;
    }
};

long long calcSide(int x1, int y1, int x2, int y2)
{
    long long dx = (long long)x1 - x2;
    long long dy = (long long)y1 - y2;
    return dx * dx + dy * dy;
}

int main(int argc, char const *argv[])

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int xArr[4] = {0};
        int yArr[4] = {0};

        bool issquare = true;
        vector<long long> v;
        for (int i = 0; i < 4; i++)
        {
            cin >> xArr[i] >> yArr[i];
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                long long side = calcSide(xArr[i], yArr[i], xArr[j], yArr[j]);
                v.push_back(side);
            }
        }
        sort(v.begin(),v.end());
        long long first = v.at(0);
        
        for (int i = 1; i < 4; i++)
        {
            long long check = v.at(i);
            if (first != check)
            {
                issquare = false;
            }
        }
        if (v.at(4) != v.at(5))
        {
            issquare= false;
        }

        if (first == v.at(4))
        {
            issquare= false;
        }
        
        
        long long diagonal = 2*first;
        if (diagonal == v.at(4)*v.at(4))
        {
            issquare = false;
        }

        if (issquare)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }

    return 0;
}
