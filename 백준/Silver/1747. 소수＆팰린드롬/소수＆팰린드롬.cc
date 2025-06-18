#include <iostream>
#include <string>
using namespace std;


bool isprime(int i);
bool ispalindrome(string x);
int main(int argc, char const *argv[])
{
    
    int N;
    cin >> N;
    for (int i = N; i < 1100000 ; i++)
    {
        string palindrome = to_string(i);
        if(isprime(i)) {
            if(ispalindrome(palindrome)) {
                cout << palindrome;
                return 0;
            }
        }
    }
    
    return 0;
}

bool isprime(int x) {
    if (x < 2) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) return false;
    }
    return true;
}

bool ispalindrome(string x) {
    int size = x.length();
    int first = 0;
    int end = size-1;
    
    while (first < end)
    {
        if (x.at(first) == x.at(end))
        {
            first++; end--;
        } else
        {
            return false;
        }
    }
    return true;
}