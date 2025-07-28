#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
void oneTwoThree();
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    v.resize(12,0);
    oneTwoThree();
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        cout << v[num] << "\n";
    }
    return 0;
}

void oneTwoThree() {
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;
    for(int i = 4;i<v.size();i++) v[i] += v[i-1] + v[i-2] + v[i-3];
}
