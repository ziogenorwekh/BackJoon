#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int X1,Y1,X2,Y2,X3,Y3;
    cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
    int result = (X1*Y2 + X2*Y3 + X3*Y1) - (X2*Y1 + X3*Y2 + X1*Y3);
    if(result < 0) cout << -1;
    else if(result == 0) cout << 0;
    else cout << 1;
    return 0;
}
