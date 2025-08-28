#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    stringstream ss(s);
    string token;
    vector<string> v;
    stack<int> st;
    while (getline(ss, token, ' ')) {
        v.push_back(token);
    }
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == "Z") st.pop();
        else st.push(stoi(v[i]));
    }
    while (!st.empty()) {
        answer += st.top();
        st.pop();
    }
    return answer;
}