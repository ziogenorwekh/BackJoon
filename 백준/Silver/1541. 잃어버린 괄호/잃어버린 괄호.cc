#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string input;
    vector<string> v;
    cin >> input;
    string num = "";
    for (int i = 0; i < input.size(); i++)
    {
        char x = input.at(i);
        if (x == '-')
        {
            v.push_back(num);
            v.push_back(string(1,x));
            num = "";
        } else if ( x == '+')
        {
            v.push_back(num);
            num = "";
        } else
        {
            num += x;
        }
    }
    if (!num.empty())
    {
        v.push_back(num);
    }
    int value = 0;
    int result = stoi(v.at(0));
    bool isMinus = false;
    for (int i = 1; i < v.size(); i++) {
        if (v.at(i) == "-") {
            isMinus = true;
        } else {
            int val = stoi(v.at(i));
            if (isMinus) {
                result -= val;
            } else {
                result += val;
            }
        }
    }

    
    cout << result;
    return 0;
}
