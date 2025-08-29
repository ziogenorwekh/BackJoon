#include <string>
#include <vector>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int card1Index = 0;
    int card2Index = 0;
    int goalIndex = 0;
    bool isComplete = true;
    while (goalIndex < goal.size()) {
        string goalWord = goal[goalIndex++];
        if(goalWord == cards1[card1Index]) {
            card1Index++;
        } else if (goalWord == cards2[card2Index]) {
            card2Index++;
        } else {
            isComplete = false;
            break;
        }
    }
    if (isComplete) return "Yes";
    else return "No";
}