#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		if(s.size() == 1) {
			cout << s[0] << s[0] << "\n";
			continue;
		}
		cout << s[0] << s[s.size()-1] << "\n";
	}
}