#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    for (int i = 0; i < t.length(); i++) {
        string check = t.substr(i,p.size());
        if (check.length() != p.size()) continue;
        if (stoll(check) <= stoll(p)) answer++;
    }
    return answer;
}
