#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    vector<string> v(N);
    vector<bool> visited(26, false);
    for (int i = 0; i < N; i++) getline(cin, v[i]);
    for (string chk : v)
    {
        transform(chk.begin(), chk.end(), chk.begin(), ::tolower);
        for (int i = 0; i < chk.length(); i++)
        {
            int index = chk.at(i) - 'a';
            if (index >= 0 && index < 26) visited[index] = true;
        }
        bool isPangram = all_of(visited.begin(), visited.end(), [](bool b) { return b; });
        if (isPangram) cout << "pangram\n";
        else
        {
            cout << "missing ";
            for (int i = 0; i < 26; i++) if (!visited[i]) cout << (char)(i + 'a');
            cout << "\n";
        }
        fill(visited.begin(), visited.end(), false);
    }
    return 0;
}
