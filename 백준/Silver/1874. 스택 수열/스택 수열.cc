#include <iostream>
#include <stack>
#include <deque>
#include <stdint.h>
using namespace std;
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int check[N + 1] = {0};
    stack<int> st;
    deque<string> answer;
    for (int i = 1; i < N + 1; i++)
    {
        cin >> check[i];
    }
    int number = 1;
    int index = 1;
    
    while (index < N + 1)
    {
        if (st.empty()) {
            answer.emplace_back("+");
            st.push(number++);
        }


        if (check[index]==st.top()) {
            answer.emplace_back("-");
            st.pop();
            index++;
        } else if (check[index]>st.top()) {
            answer.emplace_back("+");
            st.push(number++);
        } else {
            cout << "NO";
            return 0;
        }




    }
    for (auto & it : answer)
    {
        cout << it << "\n";
    }

    return 0;
}