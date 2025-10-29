#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[8] = {0, 0, -1, 1, 1, -1, 1, -1};
int dy[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
bool bfs(vector<vector<int>> &graph, int w, int h, int sw, int sh) {
  bool count = false;
  queue<pair<int, int>> q;
  q.push({sh, sw});
  while (!q.empty()) {
    int nh = q.front().first;
    int nw = q.front().second;
    q.pop();
    for (int i = 0; i < 8; i++) {
      int gh = nh + dy[i];
      int gw = nw + dx[i];
      if (gh > 0 && gw > 0 && gh <= h && gw <= w) {
        if (graph[gh][gw] == 1) {
          count = true;
          graph[gh][gw] = 0;
          q.push({gh, gw});
        }
      }
    }
  }
  return count;
}

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0) break;
    vector<vector<int>> graph(h + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        cin >> graph[i][j];
      }
    }
    int count = 0;
    for (int i = 0; i <= h; i++) {
      for (int j = 0; j <= w; j++) {
        if (bfs(graph, w, h, j, i)) {
          count++;
        }
      }
    }
    cout << count << "\n";
  }

  return 0;
}