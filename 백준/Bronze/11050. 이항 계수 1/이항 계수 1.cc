#include <iostream>
using namespace std;

int combination(int a,int b);
int main(int argc, char const *argv[])
{
    int N,M;
    cin >> N >> M;
    cout << combination(N,M);

    return 0;
}
int combination(int a,int b) {
    if(b == 0) return 1;
    int result = 1;
    for(int i = a; i > a-b; i--) result *= i;
    for(int i = b; i >= 1; i--) result /= i;
    return result; 
}