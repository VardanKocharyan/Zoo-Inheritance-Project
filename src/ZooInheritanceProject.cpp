#include <iostream>
#include <string>
#include <vector>
#include "ZooInheritanceProject.hpp"

        //Animal
int Animal::next_id = 1;

Animal::Animal() : name{"Unnamed"}, health{100}, hunger{0}, kind{Kind::Animal}, Id{next_id++} {}

Animal::Animal(const std::string& _name, int _health, int _hunger) 
    : name{_name}, health{_health}, hunger{_hunger}, kind{Kind::Animal}, Id{next_id++} {}

void Animal::PrintInfo() const {
    std::cout << "Name: " << name
        <<"\nHealth: " << health
        << "\nHunger: " << hunger
        << "\nId: " << getId() << "\n" << std::endl;
}

void Animal::Feed() {
    if (hunger > 0) {
        int can_health = 100 - health;
        int feed = (can_health < hunger) ? can_health : hunger;

        health += feed;
        hunger -= feed;
    }
    std::cout << "Has been feed health " << health 
        << ".Hunger now is " << hunger << std::endl;
}

Kind Animal::KindOf() const { return kind; }

int Animal::getId() const { return Id; }

//____________________________________________________________________________

        //Mammal
Mammal::Mammal() : Animal(), warmBlooded{true} {
    kind = Kind::Mammal;
}

Mammal::Mammal(const std::string& _name): Animal(_name), warmBlooded{true} {
    kind = Kind::Mammal;
}

void Mammal::MakeSound() {
        std::cout << "make a generic mammal sound!" << std::endl;
}


        //Bird
Bird::Bird() : Animal() {
    kind = Kind::Bird;
}

Bird::Bird(const std::string& _name, double _wingSpan) : Animal(_name), wingSpan(_wingSpan) {
            kind = Kind::Bird;
}

void Bird::Fly() const {
        std::cout << "The " << name << " can fly.\nWingSpace: " << wingSpan 
            << "meters." << std::endl;
}


        //Reptile
Reptile::Reptile() : Animal(), coldBlooded{true} {
    kind = Kind::Reptile;
}
    
Reptile::Reptile(const std::string& _name) : Animal(_name), coldBlooded{true} {
    kind = Kind::Reptile;
}
    
void Reptile::Sunbathe() {
        std::cout << name << "reptile warms itself in sun." << std::endl;
}

//____________________________________________________________________________
        //Lion
Lion::Lion() :Mammal(), roarPower{4} {
    kind = Kind::Lion;
}

Lion::Lion(const std::string& _name, int _roarPower) 
    : Mammal(_name), roarPower{_roarPower} {
    kind = Kind::Lion;
}

void Lion::Roar() const {
         std::cout << "Name: " << name << "\nROAR\n" 
            << "Power: " << roarPower << std::endl;
}

//____________________________________________________________________________
        //Tiger
Tiger::Tiger() : Mammal(), jumpHeight{2.6}{
    kind = Kind::Tiger;
}

Tiger::Tiger(const std::string& _name, double _jumpHeight) : Mammal(_name), jumpHeight{_jumpHeight} {
    kind = Kind::Tiger;
}

void Tiger::Jump() const {
        std::cout << "The " << name << " can jump " 
            << jumpHeight << " meter high." << std::endl;
}

void Tiger::MakeSound() const {
    std::cout << "Tiger sount: RRRRR" << std::endl;
}

//____________________________________________________________________________
        //Elephant
Elephant::Elephant() : Mammal(), trunkLength{0.8} {
    kind = Kind::Elephant;
}

Elephant::Elephant(const std::string& _name, double _trunkLength) : Mammal(_name), trunkLength{_trunkLength} {
    kind = Kind::Elephant;
}

void Elephant::MakeSound() const {
        std::cout << "Elephant sound: PXXXXXX" << std::endl;
}

void Elephant::UseTrunk() const {
    std::cout << name << " use trunk." << std::endl;
}


//____________________________________________________________________________
        //Eagle
Eagle::Eagle() : Bird(), visionRange{50} {
    kind = Kind::Eagle;
}

Eagle::Eagle(const std::string& _name, double _visionRange) : Bird(_name), visionRange{_visionRange} {
    kind = Kind::Eagle;
}

void Eagle::Fly() const{
    std::cout << "Eagle can fly." << std::endl;
}

void Eagle::Soar() const {
    std::cout << name << " is soar with vision range " 
        << visionRange << " meters!" << std::endl;
}
    
//____________________________________________________________________________
            //Parrot
Parrot::Parrot() : Bird() {
    kind = Kind::Parrot;
}

Parrot::Parrot(const std::string& _name, std::string _text) : Bird(_name) {
        kind = Kind::Parrot;
        if (_text != "q") {
                vocabulary.push_back(_text);
        }
}

void Parrot::Fly() const{
        std::cout << "Parrot can Fly" << std::endl;
}

void Parrot::Speak() const {
        if (vocabulary.size() == 0) {
                std::cout << "Parrot can't speak." << std::endl;
                return;
        }
        for(size_t i{0}; i < vocabulary.size(); ++i) {
                std::cout << "Parrot says: " << vocabulary[i] <<  std::endl;
        }
}

//____________________________________________________________________________
        //Snake
Snake::Snake() : Reptile(), poisonous{false} {
    kind = Kind::Snake;
}

Snake::Snake(const std::string& _name, bool _poisonous) : Reptile(_name), poisonous{_poisonous} {
    kind = Kind::Snake;
}

void Snake::Hiss() const {
     std::cout << name << " hisses: Ssssssss..." << std::endl;
}


//____________________________________________________________________________
        //Crocodile
Crocodile::Crocodile() : Reptile(), biteForce{4} {
    kind = Kind::Crocodile;
}

Crocodile::Crocodile(const std::string& _name, int _biteForce) : Reptile(_name), biteForce{_biteForce} {
    kind = Kind::Crocodile;
}

void Crocodile::Snap() const {
        std::cout << name << " snaps its jaws with force "
              << biteForce << "!" << std::endl;
}











