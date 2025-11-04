#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  int maxSize = 1;
  cin >> N >> M;
  vector<vector<int>> v(N, vector<int>(M, 0));
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      v[i][j] = s.at(j);
    }
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int k = j+1; k < M; k++) {
        if(v[i][j] == v[i][k] && i+k-j < N) {
          if (v[i][j] == v[i+k-j][j] && v[i][j] == v[i+k-j][k]) {
            if(maxSize < k-j + 1) {
              maxSize = k-j + 1;
            }
          }
        }
      }
    }
  }
  cout << maxSize*maxSize;
}