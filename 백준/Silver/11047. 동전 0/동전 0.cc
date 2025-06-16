#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int N,M;
    cin >> N >> M;
    vector<int> v;
    
    for (int i = 0; i < N; i++)
    {
        int input = 0;
        cin >> input;
        v.push_back(input);
    }
    int index = v.size() - 1;
    int count = 0;

    while (M != 0)
    {
        if (M < v.at(index))
        {
            index--;
            continue;
        } else
        {
            M = M - v.at(index);
            count++;
        }
    }

    cout << count;
    
    
    return 0;
}
