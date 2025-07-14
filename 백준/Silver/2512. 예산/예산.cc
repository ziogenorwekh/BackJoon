#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> &budgets, int govBudgets);
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<int> budgets(N, 0);
    for (int i = 0; i < N; i++)
        cin >> budgets[i];

    sort(budgets.begin(), budgets.end());

    int govBudgets;
    cin >> govBudgets;
    cout << binarySearch(budgets, govBudgets);
    return 0;
}

int binarySearch(vector<int> &budgets, int govBudgets)
{

    int left = 0;
    int right = budgets.back();
    int result = 0;
    while (left <= right)
    {
        int totalBudgets = 0;
        int mid = (left + right) / 2;
        for(int localBudgets : budgets) {
            if(localBudgets < mid) totalBudgets += localBudgets;
            else totalBudgets += mid;
        }
        if (totalBudgets > govBudgets) right = mid - 1;
        else {
            result = mid;
            left = mid + 1;
        }
    }
    return result;
}