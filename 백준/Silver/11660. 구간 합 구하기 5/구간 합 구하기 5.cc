#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int table[N + 1][N + 1] = {0};
    int prefix[N + 1][N + 1] = {0};

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> table[i][j];
            prefix[i][j] = prefix[i - 1][j] + table[i][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    for (int i = 0; i < M; i++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum = 0;
        sum = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];

        cout << sum << '\n';
    }

    return 0;
}
