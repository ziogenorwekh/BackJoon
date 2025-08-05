#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string input, check;
    cin >> input >> check;
    string tmp;
    for (char c : input) {
        tmp.push_back(c);
        if (tmp.size() >= check.size()) {
            if(tmp.compare(tmp.size() - check.size(), check.size(), check) == 0) {
                tmp.erase(tmp.size() - check.size(), check.size());
            }
        }

    }
    if(tmp.empty()) {
        cout << "FRULA";
        return 0;
    }
    cout << tmp;
    return 0;
}
