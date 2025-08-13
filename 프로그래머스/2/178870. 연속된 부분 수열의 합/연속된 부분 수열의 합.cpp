#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int first = 0;
    int second = 0;
    int sum = sequence[0];
    int min = sequence.size() + 1;
    int minStart = 0;
    int minEnd = 0;
    while (first < sequence.size() && second < sequence.size()) {
        if (sum > k) {
            sum -= sequence[first];
            first++;
        } else if (sum == k) {
            int tmp = second - first + 1;
            if (tmp < min) {
                min = tmp;
                minStart = first;
                minEnd = second;
            }
            sum -= sequence[first];
            first++;
        } else {
            second++;
            if (second < sequence.size()) {
                sum += sequence[second];
            }
        }
    }
    answer.push_back(minStart);
    answer.push_back(minEnd);
    return answer;
}