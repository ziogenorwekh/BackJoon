#include <iostream>
#include <vector>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    vector<vector<int> > graph(n / w + 1, vector<int>(w, 0));
    int box = 1;
    int x = 0, y = 0;
    for (int i = 0; i < graph.size(); i++) {
        int dir = (i % 2 == 0) ? 1 : -1;
        int j = (dir == 1) ? 0 : graph[i].size() - 1;
        while (j >= 0 && j < graph[i].size()) {
            if (box > n) break;
            if (box == num) x = i, y = j;
            graph[i][j] = box++;
            j += dir;
        }
    }
    for (int i = x; i < graph.size(); i++) {
        if (graph[i][y] != 0) answer++;
        else break;
    }
    return answer;
}