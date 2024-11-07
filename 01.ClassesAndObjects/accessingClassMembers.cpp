#include <iostream>

using namespace std;

class Player
{
public:
    // attributes
    string name;
    int health;
    int xp;

    // methods
    void talk(string text) {cout << name << " says: " << text << endl;};
    bool is_dead() {return health <= 0;}
};

int main()
{
    // Creating player1 on stack:
    Player player1;

    // Assigning values to player1's attributes ising the "." operator:
    player1.name = "Frank";
    player1.health = 100;
    player1.xp = 12;

    // Calling player1's methods:
    player1.talk("Hi, how are you!");
    cout << player1.is_dead() << endl; // False

    // Creating player2 on heap:
    Player* player2 = new Player();

    // To access the attributes from a pointer, use the "->" operator:
    player2->name = "Jim";
    player2->health = 0;
    player2->xp = 34;

    player2->talk("I am dead!");
    cout << player2->is_dead() << endl; // True
}