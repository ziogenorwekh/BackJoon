#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    double D,H,W;
    double rH =0, rW =0;
    cin >> D >> H >> W;

    double result = D*D / (H*H + W*W);

    rH = H*sqrt(result);
    rW = W*sqrt(result);

    cout << (int)rH << " " << (int)rW;
    return 0;
}
