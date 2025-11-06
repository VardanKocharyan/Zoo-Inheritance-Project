#include <iostream>
#include "ZooInheritanceProject.hpp"
#include <string>
#include <vector>

int main(void) {

        std::cout << "\tIN TASK\n\n";
        Lion *Simba = new Lion("Simba", 7);
        Tiger *Tony_Montana = new Tiger("Tony Montana", 4.5);
        Eagle *Aquila = new Eagle("Aquila", 3.2);
        Snake *Anastasia = new Snake("Anastasia");

        std::vector<Animal*> animal;

        animal.push_back(Simba);
        animal.push_back(Tony_Montana);
        animal.push_back(Aquila);
        animal.push_back(Anastasia);

        for(size_t i{0}; i < animal.size(); ++i) {
                animal[i]->PrintInfo();
        }

        for(size_t i{0}; i < animal.size(); ++i) {
                delete animal[i];
        }
        std::cout << "\tEND TASK\n\n\tGPT MAIN\n\n";

        std::vector<Animal*> animals;

            // 🦁 Create animals
        animals.push_back(new Lion("Simba", 7));
        animals.push_back(new Tiger("Shere Khan", 3.2));
        animals.push_back(new Elephant("Dumbo", 1.5));
        animals.push_back(new Eagle("Sky", 120.0));
        animals.push_back(new Parrot("Polly", "Hello!"));
        animals.push_back(new Snake("Nagini", true));
        animals.push_back(new Crocodile("Snappy", 9));

            // 🧾 Display info for all animals
        std::cout << "===== Zoo Animals =====" << std::endl;
        for (auto a : animals) {
            a->PrintInfo();

            // Perform specific actions depending on animal kind
            switch (a->KindOf()) {
                case Kind::Lion:
                    dynamic_cast<Lion*>(a)->Roar();
                    break;
                case Kind::Tiger:
                    dynamic_cast<Tiger*>(a)->Jump();
                    break;
                case Kind::Elephant:
                    dynamic_cast<Elephant*>(a)->UseTrunk();
                    break;
                case Kind::Eagle:
                    dynamic_cast<Eagle*>(a)->Soar();
                    break;
                case Kind::Parrot:
                    dynamic_cast<Parrot*>(a)->Speak();
                    break;
                case Kind::Snake:
                    dynamic_cast<Snake*>(a)->Hiss();
                    break;
                case Kind::Crocodile:
                    dynamic_cast<Crocodile*>(a)->Snap();
                    break;
                default:
                    std::cout << "Unknown animal type.\n";
            }

            std::cout << std::endl;
    }

        // 🍽️ Feed all animals
        std::cout << "Feeding all animals..." << std::endl;
        for (auto a : animals) {
            a->Feed();
        }

            // 🧹 Free memory
        for (auto a : animals)
            delete a;
        animals.clear();

        std::cout << "\nAll animals deleted successfully 🐾" << std::endl;

    return 0;
}
