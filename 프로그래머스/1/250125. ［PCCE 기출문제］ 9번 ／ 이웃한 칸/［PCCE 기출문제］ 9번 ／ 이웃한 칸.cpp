#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dh[] = {-1,1,0,0};
int dw[] = {0,0,-1,1};
int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    for (int i = 0; i < 4; i++) {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if (nh >= 0 && nh < board[0].size() && nw >= 0 && nw < board.size()) {
            if (board[h][w] == board[nh][nw]) answer++;
        }
    }
    return answer;
}