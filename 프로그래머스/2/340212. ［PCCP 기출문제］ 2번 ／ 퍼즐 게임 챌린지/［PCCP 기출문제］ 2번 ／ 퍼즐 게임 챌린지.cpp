#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {

    int max = *max_element(diffs.begin(), diffs.end()) + 1;
    int min = 1;
    int answer = max;
    while (min <= max) {
        int mid = min + (max - min) / 2;
        long long total = 0;
        for (int i =0; i < diffs.size(); i++) {
            if (diffs[i] <= mid) {
                total += times[i];
            } else {
                if (i == 0) total += times[i]*(diffs[i] - mid) + times[i];
                else total += (times[i] + times[i - 1]) * (diffs[i] - mid) + times[i];
            }
        }
        if (total <= limit) {
            answer = mid;
            max = mid - 1;
        } else min = mid + 1;
    }
    return answer;
}