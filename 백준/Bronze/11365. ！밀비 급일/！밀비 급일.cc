#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {

	vector<string> v;
	string s;
	while (true) {
		getline(cin,s);
		if(s == "END") {
			break;
		}
		v.push_back(s);
	}
	for(int i = 0; i < v.size(); i++) {
		for(int j = v.at(i).size() - 1; j >= 0; j--) {
			cout << v.at(i).at(j);
		}
		cout << "\n";
	}
}