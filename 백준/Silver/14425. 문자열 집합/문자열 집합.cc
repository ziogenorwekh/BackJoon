#include <iostream>
#include <unordered_set>
using namespace std;

int main(int argc, char const *argv[])
{
    int N,M;
    cin >> N >> M;
    string input;
    int count = 0;
    unordered_set<string> s;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        s.emplace(input);
    }
    for(int i =0; i< M; i++) {
        cin >> input;
        if (s.find(input) != s.end()) count++;
    }
    cout << count;
    
    return 0;
}
