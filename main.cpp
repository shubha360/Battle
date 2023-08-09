#include <iostream>
#include <random>
#include <string>
#include <ctime>

using namespace std;

const int HEALTH = 100;
const int DAMAGE = 20;

void startBattle(int numberOfHumans, int numberOfZombies) {
    cout << "<Combat noises>\n\n";

    int humans = numberOfHumans;
    int zombies = numberOfZombies;

    int currentHumanHealth = HEALTH;
    int currentZombieHealth = HEALTH;

    static default_random_engine randomEngine(time(0));
    uniform_int_distribution<int> nextTurnGenerator(1, 2);
    uniform_int_distribution<int> attackIntensityGenerator(1, 5);

    while (humans > 0 && zombies > 0) {

        int nextTurn = nextTurnGenerator(randomEngine);
        int attackIntensity = attackIntensityGenerator(randomEngine);

        switch (nextTurn) {

            case 1: // Human Attack
            currentZombieHealth -= DAMAGE * attackIntensity;
            if (currentZombieHealth <= 0) {
                zombies--;
                currentZombieHealth = HEALTH;
            }
            break;

            case 2: // Zombie Attack
            currentHumanHealth -= DAMAGE * attackIntensity;
            if (currentHumanHealth <= 0) {
                humans--;
                currentHumanHealth = HEALTH;
            }
            break;
        }
    }
    cout << "Combat ended!\n\n";

    string winner;
    int left;

    if (humans > 0) {
        winner = "Humans";
        left = humans;
    } else {
        winner = "Zombies";
        left = zombies;
    }

    cout << winner << " win!\n";
    cout << "There are " << left << " " << winner << " left.\n";
    cout << numberOfHumans - humans << " humans and " << numberOfZombies - zombies << " zombies lost their lives.\n";
}

int main() {
    cout << "*** Humans vs Zombies ***\n\n";

    int numberOfHumans;
    int numberOfZombies;

    cout << "Input the number of Humans: ";
    cin >> numberOfHumans;

    cout << "Input the number of Zombies: ";
    cin >> numberOfZombies;

    cout << "\nBeginning combat!\n\n";

    startBattle(numberOfHumans, numberOfZombies);

    return 0;
}
