#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int X1 = 100;
    int Y1 = 100;
    int X2 = -1;
    int Y2 = -1;
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i].at(j) == '#') {
                if (X1 > i) X1 = i;
                if (Y1 > j) Y1 = j;
                if (X2 < i) X2 = i;
                if (Y2 < j) Y2 = j;
            }
        }
    }
    vector<int> answer = {X1,Y1,X2+1,Y2+1};
    return answer;
}