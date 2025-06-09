#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    int a[3] = {0};
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    
    sort(a,a+3,greater<int>());    

    while (a[0] >= a[1] + a[2])
    {
        a[0] -= 1;
    }
    
    
    cout << a[0] + a[1] + a[2];
    return 0;

}
