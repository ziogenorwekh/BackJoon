#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

class Data {
    public:
    int x;
    int s;

    Data(const int x, const int s): x(x),s(s) {
    }
};

struct compare {
    bool operator()(const pair<string, Data>& a, const pair<string, Data>& b) const {
        if (a.second.x != b.second.x)
            return a.second.x < b.second.x;
        return a.second.s < b.second.s;    
    }
};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<string,Data>> ageNames;
    int N; cin >> N;
    string input;
    for (int i = 0; i < N; i++)
    {
        int age; string name;
        cin >> age >> name;
        ageNames.emplace_back(name, Data(age,i));
    }
    sort(ageNames.begin(), ageNames.end(), compare());

    for (auto& ageName : ageNames)
        cout << ageName.second.x << " " << ageName.first << "\n";

    return 0;
}
