#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    cout << fixed << setprecision(6);
    double result = 0;
    for (int i = 0; i < N; i++)
    {
        double x;
        cin >> x;
        result = (1 - (1 - result) * (1 - (x / 100.0)));
        cout << result * 100.0 << "\n";
    }
    return 0;
}
