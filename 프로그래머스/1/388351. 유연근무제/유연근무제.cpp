#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    vector<map<int,int>> v;
    map<int,int> m;
    for(int j = 0; j < schedules.size(); j++) {
        for(int i = startday; i < startday + 7; i++) {
            m[(i % 7) == 0 ? 7 : (i%7)] = timelogs[j][i-startday];
        }
        v.push_back(m);
    }
    map<int,int>::iterator it;
    m.clear();
    for(int i =0; i < v.size(); i++) {
        for (it = v[i].begin(); it != v[i].end(); it++) {
            if(it->first == 6 || it->first == 7) continue;
            int minute = (schedules[i] % 100) + 10;
            int hour = schedules[i] / 100;
            if (minute > 59) { 
                minute -= 60; 
                hour += 1; 
            }
            if(hour*100 + minute >= it->second) m[i]++;
        }
    }
    for(it = m.begin(); it != m.end(); it++) {
        if(it->second == 5) answer++;
    }
    return answer;
}
