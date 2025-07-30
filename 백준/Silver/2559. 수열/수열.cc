#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int N,M;
    cin >> N >> M;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    int first = 0, tmp = 0;
    int second = M;
    for(int i = first; i < second; i++) tmp += v[i];
    int max = tmp;
    while (second < N) {
        tmp = tmp - v[first] + v[second];
        first++;
        second++;
        if(max < tmp) max = tmp;
    }
    cout << max;
    return 0;
}
