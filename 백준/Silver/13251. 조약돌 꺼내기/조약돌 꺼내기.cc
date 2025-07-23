#include <iostream>
#include <iomanip>
using namespace std;

double nCr(int n,int r);
int main(int argc, char const *argv[])
{
    int M, K;
    cin >> M;
    int arr[M];
    for(int i=0; i<M;i++) cin >> arr[i];
    cin >> K;
    double result = 0;
    long long sum = 0;
    for(int i =0; i<M;i++) {
        result += nCr(arr[i],K);
        sum += arr[i];
    } 
    cout << fixed << setprecision(18) << (double)result / nCr(sum,K);

    return 0;
}

double nCr(int n,int r) {
    if (r > n) return 0.0;
    if(r > n-r) r= n-r;
    double res = 1.0;
    for(int i = 1; i<= r ; i++) {
        res *= (n-i+1);
        res /= i;
    }
    return res;
}
