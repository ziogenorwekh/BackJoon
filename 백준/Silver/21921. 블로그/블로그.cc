#include <iostream>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> v(N, 0);
  map<int, int> m;
  for (int i = 0; i < N; i++) cin >> v[i];
  int init = 0;
  for (int i = 0; i < M; i++) init += v[i];
  m[init] = 1;
  for (int i = 1; i <= N - M; i++) {
      init -= v[i - 1];
      init += v[M + i - 1];
    m[init]++;
  }
  map<int, int>::iterator it;
  if(init == 0) {
    cout << "SAD";
    return 0;
  }
  int max = 0;
  int result = 0;
  for(it = m.begin(); it != m.end(); it++) {
    if(max < it->first) {
        max = it->first;
        result = it->second;
    }
  }
  cout << max << "\n" << result;
  return 0;
}