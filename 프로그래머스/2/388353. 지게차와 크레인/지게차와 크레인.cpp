#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool bfs(int startX, int startY, vector<vector<char> > &storages) {
    int endX = 0, endY = 0;
    int n = storages.size();
    int m = storages[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int> > q;
    q.push(make_pair(startX, startY));
    while (!q.empty()) {
        pair<int, int> p = q.front();
        if (p.first == endX && p.second == endY) return true;
        
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (storages[nx][ny] == '0' && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    int n = storage.size();
    int m = storage[0].size();
    vector<vector<char>> storages(n + 2, vector<char>(m + 2, '0'));
    vector<pair<int,int>> memories;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            storages[i+1][j+1] = storage[i].at(j);
        }
    }

    for (int i =0; i<requests.size(); i++) {
        int lan = requests[i].length();
        const char deleteAlphabet = requests[i].at(0);
        if (lan > 1) {
            for (int j = 1; j <= n; j++) for (int k = 1; k <= m; k++) if (deleteAlphabet == storages[j][k]) storages[j][k] = '0';
        } else {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= m; k++) {
                    if (deleteAlphabet == storages[j][k]) {
                        // 값을 바꾸지마. true가 나오면 좌표 기억하는 벡터에 넣었다가 끝나면 지우셈
                        if (bfs(j,k,storages)) {
                            memories.push_back(make_pair(j, k));
                        }
                    }
                }
            }
            for (int i = 0; i < memories.size(); i++) {
                storages[memories[i].first][memories[i].second] = '0';
            }
        }
    }
    for (int i = 0; i < n + 2; i++) for (int j = 0; j < m + 2; j++) if (storages[i][j] != '0') answer++;
    return answer;
}