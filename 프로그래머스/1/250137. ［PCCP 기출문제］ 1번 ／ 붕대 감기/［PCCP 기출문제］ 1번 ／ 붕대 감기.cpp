#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int> > attacks) {
    const int maxHealth = health;
    map<int, int> attacksMap;
    for (const auto &attack: attacks) {
        attacksMap[attack[0]] = attack[1];
    }
    const int maxTime = attacks[attacks.size() - 1][0];
    int count = 0;
    for (int i = 1; i < maxTime + 1; i++) {
        if (attacksMap[i] != 0) {
            health -= attacksMap[i];
            count = 0;
            if (health <= 0) {
                return -1;
            }
        } else {
            count++;
            health += bandage[1];
            if (count == bandage[0]) {
                health += bandage[2];
                count = 0;
            }
        }
        if (health > maxHealth) {
            health = maxHealth;
        }
    }
    return health <= 0 ? -1 : health;
}