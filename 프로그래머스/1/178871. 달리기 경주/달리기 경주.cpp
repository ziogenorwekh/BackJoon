#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string,int> nScore;
    map<int, string> rScore;
    for (int i = 0; i < players.size(); i++) {
        nScore[players[i]] = i;
        rScore[i] = players[i];
    }
    for (int i = 0; i < callings.size(); i++) {
        int now = nScore[callings[i]];
        string willDown = rScore[now-1];
        nScore[callings[i]] = now - 1;
        nScore[willDown] = now;
        rScore[now] = willDown;
        rScore[now-1] = callings[i];
    }

    for (int i = 0; i < nScore.size(); i++) answer.push_back(rScore[i]);
    return answer;
}