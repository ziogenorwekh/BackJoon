#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string decToBinary(int num) {
    if (num == 0) return "0";
    string result;
    while (num > 0) {
        result = (num % 2 == 0 ? "0" : "1") + result;
        num /= 2;
    }
    return result;
}
auto safe_stoi = [](const string &s) {
    return stoi(s.empty() ? "0" : s, nullptr, 2);
};

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    vector<vector<char>> graph(N, vector<char>(N, 0));
    vector<vector<string>> dp(N, vector<string>(N, ""));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int var; 
            cin >> var;
            graph[i][j] = var + '0';
        }
    }
    dp[0][0] = string(1, graph[0][0]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i - 1 >= 0) {
                dp[i][j] = decToBinary(
                    max(
                        safe_stoi(dp[i-1][j] + string(1, graph[i][j])),
                        safe_stoi(dp[i][j])
                    )
                );
            }
            if (j - 1 >= 0) {
                dp[i][j] = decToBinary(
                    max(
                        safe_stoi(dp[i][j-1] + string(1, graph[i][j])),
                        safe_stoi(dp[i][j])
                    )
                );
            }
        }
    }
    cout << safe_stoi(dp[N-1][N-1]) << "\n";
    return 0;
}
