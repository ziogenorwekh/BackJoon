#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <unordered_map>
using namespace std;

const unordered_map<string, double> maps = {
    {"A+", 4.3}, {"A0", 4.0}, {"A-", 3.7},
    {"B+", 3.3}, {"B0", 3.0}, {"B-", 2.7},
    {"C+", 2.3}, {"C0", 2.0}, {"C-", 1.7},
    {"D+", 1.3}, {"D0", 1.0}, {"D-", 0.7},
    {"F", 0.0}
};
int main(int argc, char const *argv[])
{
    double N;
    cin >> N;
    double totalScore = 0;
    double totalGrade = 0;
    for (int i = 0; i < N; i++)
    {
        string subject, grade; double score;
        cin >> subject >> score >> grade;
        totalScore += maps.at(grade)*score;
        totalGrade += score;
    }
    double avg = (round((totalScore/totalGrade)* 100) / 100);
    cout << fixed << setprecision(2) << avg;
    return 0;
}
