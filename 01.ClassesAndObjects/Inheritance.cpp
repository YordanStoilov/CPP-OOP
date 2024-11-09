#include <iostream>

using namespace std;

class Animal
{
    private:
    string name;
    int age;

    protected:
    string sound;

    public:
    Animal(string _name, int _age)
    {
        name = _name;
        age = _age;
    }

    void setName(string newName) { name = newName; }
    string getName() { return name; }
    virtual void makeSound() { cout << sound << endl; }
};

class Dog : public Animal
{
    public:
    Dog(string name, int age) : Animal(name, age)
    {
        sound = "Woof!";
    }
};

class Cat : public Animal
{
    public:
    Cat(string name, int age) : Animal(name, age)
    {
        sound = "Meow!";
    }
};

class Cow : public Animal
{
    public:
    Cow(string name, int age) : Animal(name, age)
    {
        sound = "Moo!";
    }
};

class JackRussel : public Dog
{
    public:
    JackRussel(string name, int age) : Dog(name, age)
    {
        sound = "Woof, but smaller!";
    }
};

class Lion : public Cat
{
    public:
    Lion(string name, int age) : Cat(name, age)
    {
        sound = "Roar!";
    }
};

int main()
{
    Cat* jackie = new Cat("Jackie", 5);
    Dog* artie = new Dog("Artie", 7);
    Cow* milka = new Cow("Milka", 12);
    JackRussel* jamie = new JackRussel("Jamie", 7);
    Lion* simba = new Lion("Simba", 4);

    Animal* animals[5] = {jackie, simba, artie, jamie, milka};

    for (auto animal : animals)
    {
        animal->makeSound();
    }

    // Meow!
    // Roar!
    // Woof!
    // Woof, but smaller!
    // Moo!
}