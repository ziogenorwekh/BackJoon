#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool checkSameLength(string basic, string check);
bool checkMoreLength(string basic, string check);
bool checkLessLength(string basic, string check);
int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<string> words;
    int result = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        words.push_back(s);
    }
    for (int i = 1; i < words.size(); i++) {
        if (words[0].size() == words[i].size()) {
            if (checkSameLength(words[0],words[i])) result++;
        }
        else if (words[0].size() + 1 == words[i].size()) {
            if(checkMoreLength(words[0],words[i])) result++;
        }
        else if (words[0].size() - 1 == words[i].size()) {
            if (checkLessLength(words[0],words[i])) result++;
        }
    }
    cout << result;
    return 0;
}

bool checkSameLength(string basic, string check) {
    for (int i = 0; i < basic.size(); i++) {
        for (int j = 0; j < check.size(); j++) {
            if (basic[i] == check[j]) {
                check.erase(j, 1); 
                break;           
            }
        }
    }
    return check.size() <= 1;
}

bool checkMoreLength(string basic, string check) {
    for (int i = 0; i < basic.size(); i++) {
        for(int j = 0; j < check.size(); j++) {
            if(check.at(j) == basic.at(i)) {
                check.erase(j, 1);
                break;
            }
        }
    }
    return check.size() == 1;
}

bool checkLessLength(string basic, string check) {
    for (int i = 0; i < check.size(); i++) {
        for (int j = 0; j < basic.size(); j++) {
            if(check.at(i) == basic.at(j)) {
                basic.erase(j, 1);
                break;
            }
        }
    }
    return basic.size() == 1;
}
