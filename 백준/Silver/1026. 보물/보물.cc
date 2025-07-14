#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<vector<int>> v(2,vector<int>(N));
    for (int i = 0; i < 2; i++) for(int j=0;j<N;j++) cin >> v[i][j];
    
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end(),greater<int>());
    int result =0;
    for (int i = 0; i < N; i++) result += v[0][i]*v[1][i];
    
    cout << result;
    return 0;
}
