#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    if ((N & 1) == 0) cout << "Duck";
    else cout << "Goose"; 
    
    return 0;
}
