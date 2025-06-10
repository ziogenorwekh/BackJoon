#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

bool isCrossProjectZero(int x1, int y1, int x2, int y2, int x3, int y3);
int main(int argc, char const *argv[])
{

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if (isCrossProjectZero(x1, y1, x2, y2, x3, y3))
    {
        cout << "-1.0";
        return 0;
    }

    // x1 - x2
    double side1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    double side2 = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
    double side3 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

    double rad[3] = {0};

    rad[0] = 2 * side1 + 2 * side2;
    rad[1] = 2 * side2 + 2 * side3;
    rad[2] = 2 * side3 + 2 * side1;

    sort(rad, rad + 3);
    double result = rad[2] - rad[0];
    const double EPS = 1e-9;

    cout << fixed;
    if (abs(result - round(result)) < EPS) {
        cout << setprecision(1) << round(result) << endl;
    } else {
        cout << setprecision(15) << result << endl;
    }

}

bool isCrossProjectZero(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if (((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) == 0)
    {
        return true;
    }
    return false;
}