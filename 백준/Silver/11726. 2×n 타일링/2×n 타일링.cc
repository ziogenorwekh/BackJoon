#include <iostream>
#include <vector>
using namespace std;

vector<long long> v(1001, 0);
void tiling();
int main(int argc, char const *argv[]) {
    tiling();
    int N;
    cin >> N;
    cout << v[N];
    return 0;
}

void tiling() {
    v[1] = 1; v[2] = 2; v[3] = 3;
    for (int i = 4; i < v.size(); i++) v[i] = (v[i - 1] + v[i - 2]) % 10007;
}