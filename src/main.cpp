#include <iostream>
#include <vector>
#include "ZooInheritanceProject.hpp"

int main() {
    // 1️⃣ Create dynamic animal objects
    Lion* simba = new Lion("Simba", 7);
    Tiger* tony = new Tiger("Tony", 3.5);
    Elephant* dumbo = new Elephant("Dumbo", 1.2);
    Eagle* aquila = new Eagle("Aquila", 50.0);
    Parrot* polly = new Parrot("Polly", "Hello!");
    Snake* sly = new Snake("Sly", true);
    Crocodile* crunch = new Crocodile("Crunch", 5);

    // 2️⃣ Store them in a vector of Animal*
    std::vector<Animal*> zoo;
    zoo.push_back(simba);
    zoo.push_back(tony);
    zoo.push_back(dumbo);
    zoo.push_back(aquila);
    zoo.push_back(polly);
    zoo.push_back(sly);
    zoo.push_back(crunch);

    // 3️⃣ Loop over the vector and call base methods
    for (Animal* a : zoo) {
        std::cout << "---------------------------" << std::endl;
        a->PrintInfo();  // Dispatches to the correct derived PrintInfo()
        a->Feed();       // Base method works for all
    }

    // 4️⃣ Clean up dynamic memory
    for (Animal* a : zoo) {
        delete a;
    }
    zoo.clear();

    return 0;
}

