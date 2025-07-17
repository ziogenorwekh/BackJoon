#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool checkBracket(stack<char> &s, char check);
int main(int argc, char const *argv[])
{
    vector<string> v;
    while (true)
    {
        string line;
        getline(cin, line);
        if (line.length() == 1 && line.at(0) == '.') break;
        v.emplace_back(line);
    }

    for (string ch : v)
    {
        stack<char> s;
        bool isBalance = true;
        for (int i = 0; i < ch.length(); i++) {
            char check = ch.at(i);
            isBalance = checkBracket(s, check);
            if (!isBalance) break;
        }
        if (isBalance && s.empty()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}

bool checkBracket(stack<char> &s, const char check)
{
    switch (check)
    {
        case '[':
        case '(':
            s.push(check);
            break;
        case ']':
            if (s.empty() || s.top() != '[') return false;
            s.pop();
            break;
            case ')':
            if (s.empty() || s.top() != '(') return false;
            s.pop();
            break;
        default:
            break;
    }
    return true;
}