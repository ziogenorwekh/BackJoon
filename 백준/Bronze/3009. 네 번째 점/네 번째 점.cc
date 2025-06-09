#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int resultX, resultY;
    int x[3] = {0};
    int y[3] = {0};

    for (int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;
        x[i] = a;
        y[i] = b;
    }

    if (x[0] == x[1] && x[2] != x[0])
        resultX = x[2];
    else if (x[0] == x[2] && x[1] != x[0])
        resultX = x[1];
    else if (x[1] == x[2] && x[0] != x[1])
        resultX = x[0];

    if (y[0] == y[1] && y[2] != y[0])
        resultY = y[2];
    else if (y[0] == y[2] && y[1] != y[0])
        resultY = y[1];
    else if (y[1] == y[2] && y[0] != y[1])
        resultY = y[0];

    cout << resultX << " " << resultY;
    return 0;
}
