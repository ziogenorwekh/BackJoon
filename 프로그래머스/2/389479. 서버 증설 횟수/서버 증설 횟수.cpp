#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> isOn(players.size(),0);
    for (int i = 0; i < players.size(); i++) {
            if (isOn[i] * m > players[i]) {
                continue;
            }
            int need = players[i] / m;
            int shortage = need - isOn[i];
            answer += shortage;
            for (int j = i; j < min(i+k,24); j++) isOn[j] += shortage;

    }
    return answer;
}