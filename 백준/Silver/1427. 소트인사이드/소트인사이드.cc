#include <iostream>
#include <algorithm>

using namespace std;

struct compare
{
    bool operator()(int a, int b) const {
        return a > b;
    }
};

int main(int argc, char const *argv[])
{
    string N;
    cin >> N;
    int arr[N.length()] = {0};
    for (int i = 0; i < N.length(); i++)
    {
        char chr = N.at(i);
        arr[i] = chr - '0';
    }
    sort(arr, arr + N.length(), compare());
    
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        cout << arr[i];
    }
    
    return 0;
}


