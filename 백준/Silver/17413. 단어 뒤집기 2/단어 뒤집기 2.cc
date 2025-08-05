#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char const *argv[]) {
    string input;
    getline(cin, input);
    stack<char> s;
    vector<char> result;
    bool inTag = false;
    for(char c : input) {
        if (c == '<') {
            while(!s.empty()) {
                result.push_back(s.top());
                s.pop();
            }
            inTag = true;
            result.push_back(c);    
            continue;
        }
        if (inTag) {
            result.push_back(c);
            if (c == '>') inTag = false;
            continue;
        }
        if (c == ' ') {
            while(!s.empty()) {
                result.push_back(s.top());
                s.pop();
            }
            result.push_back(c);
        } else {
            s.push(c);
        }
    }
    while(!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    for (int i = 0; i < result.size(); i++) cout << result[i];
    
    return 0;
}
