#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct IndexResult {
    int index;
    int result;
    IndexResult(int index, int result) : index(index), result(result) {}
};

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
IndexResult bfs(int x, int y, vector<vector<int>> &land, vector<vector<bool>> &visited) {
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    int ans = 1;
    int maxDy=0;
    if (visited[x][y]) {
        return IndexResult(0, 0);
    }
    visited[x][y] = true;
    while(!q.empty()) {
        pair<int, int> next = q.front();
        if (next.second > maxDy) maxDy=next.second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = next.first + dx[i];
            int ny = next.second + dy[i];
            if (nx >= 0 && nx < land.size() && ny >= 0 && ny < land[0].size()) {
                if (land[nx][ny] == 1 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    ans++;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return IndexResult(maxDy,ans);
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    // nx가 도달하는 최대지역까지 전부다 tmp 값으로 업데이트하고, 추가탐색 지역만 더하는거
    vector<int> result(land[0].size(), 0);
    vector<vector<bool>> visited(land.size(), vector<bool>(land[0].size(), false));
    for (int drill = 0; drill < land[0].size(); drill++) {
        for (int depth = 0; depth < land.size(); depth++) {
            if (land[depth][drill] == 1 && !visited[depth][drill]) {
                auto bfsResult = bfs(depth, drill, land, visited);
                if (bfsResult.index == drill) {
                    result[drill] += bfsResult.result;
                } else {
                    for (int i = drill; i < bfsResult.index + 1; i++) {
                        result[i] += bfsResult.result;
                    }
                }
            }

        }

    }
    return *max_element(result.begin(), result.end());
}