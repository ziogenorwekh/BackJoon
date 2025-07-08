#include <iostream>
#include <algorithm>

int binarySearch(int *lan, long long max, int N, int K);

int main(int argc, char const *argv[])
{
    int N, K;
    std::cin >> K >> N;
    int lan[K];
    for (int i = 0; i < K; i++)
        std::cin >> lan[i];
    std::sort(lan, lan + K);
    long long ans = binarySearch(lan, lan[K - 1], N, K);
    std::cout << ans;
    return 0;
}

int binarySearch(int *lan, long long max, int N, int K)
{
    long long left = 1;
    long long right = max;
    long long ans = 0;
    while (left <= right)
    {
        long long count = 0;
        long long mid = (right + left) / 2;
        for (int i = 0; i < K; i++)
            count += lan[i] / mid;
        if (count >= N)
        {
            left = mid + 1;
            ans = mid;
        }
        else
            right = mid - 1;
    }
    return ans;
}