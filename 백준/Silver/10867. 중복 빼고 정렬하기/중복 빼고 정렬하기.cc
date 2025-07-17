#include <set>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    set<int> s;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        s.emplace(x);
    }
    for(int val : s) cout << val << " ";
    return 0;
}
