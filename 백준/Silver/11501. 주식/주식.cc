#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long calcMaxProfit(vector<long long> &stock) {
    // 떨어지면 nothing
    // 올라가거나 같으면 buy
    // 올라가다 떨어지면 sell
    long long profit = 0;
    int max = stock[stock.size()-1];
    for (int i = stock.size()-2; i >= 0; i--) {
        int nowPrice = stock[i];
        if(nowPrice <= max) profit += max - nowPrice;
        else max = nowPrice;

    }
    return profit;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    for(int i = 0;i<N;i++) {
        int M;
        cin >> M;
        vector<long long> stock(M,0);
        for(int j = 0; j< M;j++) {
            cin >> stock[j];
        }
        cout << calcMaxProfit(stock) << "\n";
    }
    return 0;
}
