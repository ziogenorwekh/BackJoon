#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct compare {
    bool operator() (const string &a, const string &b) const {
        if(a.size() != b.size()) {
            return a.size() < b.size();
        } else {
            return a < b;
        }
    }
};

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    set<string> words;
    for(int i = 0; i < N; i++) {
        string word;
        cin >> word;
        words.insert(word);
    }
    vector<string> newWords(words.begin(), words.end());
    sort(newWords.begin(), newWords.end(), compare());
    for(const string &word : newWords) cout << word << '\n';
    return 0;
}
