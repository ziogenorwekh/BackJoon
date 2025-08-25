#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    map<int,int> m;
    int result = 0;
    int count = 0;
    int max = 0;
    for (int i = 0; i < N; i++) {
        int vote;
        cin >> vote;
        if(vote == 0) continue;
        m[vote]++;
        if(m[vote] > max) max = m[vote];
    }
    map<int,int>::iterator it;
    for(it = m.begin(); it != m.end(); ++it) {
       if(it->second == max) {
            count++;
            result = it->first;
       }
    }
    
    if (count > 1) cout << "skipped";
    else cout << result;   
    return 0;
}