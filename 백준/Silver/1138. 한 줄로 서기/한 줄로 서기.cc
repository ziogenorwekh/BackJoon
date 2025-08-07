#include <map>
#include <deque>
#include <iostream>
using namespace std;


void insertBetweenPeople(deque<int> &people, int person, int tallerThan) {
    if(tallerThan== people.size()) people.push_back(person);
    else if(tallerThan < people.size()) people.insert(people.begin() + tallerThan, person);
    
}

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    map<int,int> record;
    deque<int> people;
    for(int i = 1; i < N + 1; i++) cin >> record[i];
    for(int i = N; i >= 1; i--) {
        int tallerThan = record[i];
        if(tallerThan == 0) people.push_front(i);
        else insertBetweenPeople(people,i,tallerThan);
    }
    for(int val : people) cout << val << " ";
    return 0;
}
