#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
    int N, M;
    cin >> N >> M;
    cin.ignore();
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        int var = (int)s.at(i);
        if (var >= 65 && var <= 90) {
            int encode = var + (N % 26);
            if(encode > 90) cout << (char)(encode - 26);
            else cout << (char) encode;
        } else if (var >= 97 && var <= 122) {
            int encode = var + (N % 26);
            if(encode > 122) cout << (char)(encode - 26);
            else cout << (char) encode;
        }
        else cout << s.at(i);  
    }
    return 0;
}