#include <iostream>
#include <string>
#include <vector>
#include "ZooInheritanceProject.hpp"

        //Animal
int Animal::next_id = 1;

Animal::Animal() 
    : name{"Unnamed"}, health{100}, hunger{0}, kind{Kind::Animal}, Id{next_id++} {}

Animal::Animal(const std::string& _name, int _health, int _hunger, Kind _k) 
    : name{_name}, health{_health}, hunger{_hunger}, kind{_k}, Id{next_id++} {}

void Animal::PrintInfo() const {
    switch(kind) {
            case Kind::Lion:
                static_cast<const Lion*>(this)->PrintInfo();
                break;
            case Kind::Tiger:
                static_cast<const Tiger*>(this)->PrintInfo();
                break;
            case Kind::Elephant:
                static_cast<const Elephant*>(this)->PrintInfo();
                break;
            case Kind::Eagle:
                static_cast<const Eagle*>(this)->PrintInfo();
                break;
            case Kind::Parrot:
                static_cast<const Parrot*>(this)->PrintInfo();
                break;
            case Kind::Snake:
                static_cast<const Snake*>(this)->PrintInfo();
                break;
            case Kind::Crocodile:
                static_cast<const Crocodile*>(this)->PrintInfo();
                break;
            case Kind::Mammal:
            case Kind::Bird:
            case Kind::Reptile:
            case Kind::Animal:
                PrintInfo();
                break;
    }
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
Mammal::Mammal() 
    : Animal("Unnamed", 100, 0, Kind::Mammal), warmBlooded{true} {}

Mammal::Mammal(const std::string& _name, Kind _k) 
    : Animal(_name,100, 0, _k), warmBlooded{true} {}

void Mammal::PrintInfo() const {
     std::cout << "Name: " << name
        <<"\nHealth: " << health
        << "\nHunger: " << hunger
        << "\nId: " << getId() << "\n" << std::endl;

    std::cout << "warmBlooded: True.\n";
}


        //Bird
Bird::Bird() 
    : Animal("Unnamed", 100, 0, Kind::Bird), wingSpan{0.6} {}

Bird::Bird(const std::string& _name, double _wingSpan, Kind _k) 
    : Animal(_name, 100, 0, _k), wingSpan(_wingSpan) {}

void Bird::PrintInfo() const {
     std::cout << "Name: " << name
        <<"\nHealth: " << health
        << "\nHunger: " << hunger
        << "\nId: " << getId() << "\n" << std::endl;

    std::cout << "wingSpan: " << wingSpan << std::endl;
}

void Bird::Fly() const {
        std::cout << "The " << name << " can fly.\nWingSpace: " << wingSpan 
            << "meters." << std::endl;
}


        //Reptile
Reptile::Reptile() 
    : Animal("Unnamed", 100, 0, Kind::Reptile), coldBlooded{true} {}
    
Reptile::Reptile(const std::string& _name, Kind _k) 
    : Animal(_name, 100, 0, _k), coldBlooded{true} {}
    
void Reptile::PrintInfo() const {
     std::cout << "Name: " << name
        <<"\nHealth: " << health
        << "\nHunger: " << hunger
        << "\nId: " << getId() << "\n" << std::endl;

        std::cout << "coldBlooded: " << coldBlooded << std::endl;
}

void Reptile::Sunbathe() {
        std::cout << name << "reptile warms itself in sun." << std::endl;
}

//____________________________________________________________________________
        //Lion
Lion::Lion() 
    : Mammal("Unnamed", Kind::Lion), roarPower{4} {}

Lion::Lion(const std::string& _name, int _roarPower, Kind _k) 
    : Mammal(_name, _k), roarPower{_roarPower} {}

void Lion::walk() const {
    std::cout << "It walk to hunting." << std::endl;
}

void Lion::voice() const {
     std::cout << "Name: " << name << "\nROAR\n" 
        << "Power: " << roarPower << std::endl;
}


void Lion::feedable() const {
    std::cout << "Lion is eating PLAV." << std::endl;
}

void Lion::PrintInfo() const {
    Mammal::PrintInfo();
    walk();
    voice();
    feedable();

}

void Lion::Roar() const {
         std::cout << "Name: " << name << "\nROAR\n" 
            << "Power: " << roarPower << std::endl;
}

//____________________________________________________________________________
        //Tiger
Tiger::Tiger() 
    : Mammal("Unnamed", Kind::Tiger), jumpHeight{2.6} {}

Tiger::Tiger(const std::string& _name, double _jumpHeight, Kind _k) 
    : Mammal(_name, _k), jumpHeight{_jumpHeight} {
    kind = Kind::Tiger;
}

void Tiger::PrintInfo() const {
        voice();
        walk();
        feedable();
        Jump();
        Mammal::PrintInfo();
}

void Tiger::Jump() const {
        std::cout << "The " << name << " can jump " 
            << jumpHeight << " meter high." << std::endl;
}

void Tiger::voice() const {
    std::cout << "Tiger sount: RRRRR" << std::endl;
}

void Tiger::walk() const {
    std::cout << "Tiger is walking in Mall and dooing shoping." << std::endl;
}

void Tiger::feedable() const {
    std::cout << "The " << name << " is eating pizza in SushiiPizza." << std::endl;
}

//____________________________________________________________________________
        //Elephant
Elephant::Elephant() 
    : Mammal("Unnamed", Kind::Elephant), trunkLength{0.8} {}

Elephant::Elephant(const std::string& _name, double _trunkLength, Kind _k) 
    : Mammal(_name, _k), trunkLength{_trunkLength} {}

void Elephant::PrintInfo() const {
        voice();
        walk();
        feedable();
        UseTrunk();
        Mammal::PrintInfo();
}

void Elephant::voice() const {
    std::cout << "Elephant sound: PXXXXXX" << std::endl;
}

void Elephant::walk() const {
    std::cout << "The " << name << " goes to fitness to lose weight." << std::endl;
}

void Elephant::feedable() const {
        std::cout << "After training " << name << " ususly eating brocoly whith eags." << std::endl;
}

void Elephant::UseTrunk() const {
    std::cout << name << " use trunk." << std::endl;
}


//____________________________________________________________________________
        //Eagle
Eagle::Eagle() 
    : Bird("Unnamed", 3.2, Kind::Eagle), visionRange{50} {}

Eagle::Eagle(const std::string& _name, double _visionRange, Kind _k) 
    : Bird(_name, 3.2, _k), visionRange{_visionRange} {}

void Eagle::PrintInfo() const {
        walk();
        fly();
        feedable();
        voice();
        Soar();
        Bird::PrintInfo();
}

void Eagle::fly() const {
    std::cout << "The " << name << " flew to a date." << std::endl;
}

void Eagle::walk() const {
    std::cout << name << " is walking to get a bouquet of flowers for a date." << std::endl;
}

void Eagle::voice() const {
    std::cout <<  "Voice: Tsuuuu" << std::endl;
}

void Eagle::feedable() const {
    std::cout << "On a date, thay ordered braiced lamb with red wine." << std::endl;
}

void Eagle::Soar() const {
    std::cout << name << " is soar with vision range " 
        << visionRange << " meters!" << std::endl;
}
    
//____________________________________________________________________________
            //Parrot
Parrot::Parrot() 
    : Bird("Unnamed", 0.3, Kind::Parrot) {}

Parrot::Parrot(const std::string& _name, std::string _text, Kind _k) 
    : Bird(_name, 0.4, _k) {
        if (_text != "q") {
                vocabulary.push_back(_text);
        }
}

void Parrot::PrintInfo() const {
        fly();
        voice();
        walk();
        feedable();
        Bird::PrintInfo();
}

void Parrot::fly() const{
        std::cout << "Parrot can Fly" << std::endl;
}

void Parrot::voice() const {
        if (vocabulary.size() == 0) {
                std::cout << "Parrot can't speak." << std::endl;
                return;
        }
        for(size_t i{0}; i < vocabulary.size(); ++i) {
                std::cout << "Parrot says: " << vocabulary[i] <<  std::endl;
        }
}

void Parrot::walk() const {
    std::cout << "Walk to eating." << std::endl;
}

void Parrot::feedable() const {
    std::cout << "Eating his food." << std::endl;
}

//____________________________________________________________________________
        //Snake
Snake::Snake() 
    : Reptile("Unnamed", Kind::Reptile), poisonous{false} {}

Snake::Snake(const std::string& _name, bool _poisonous, Kind _k) 
    : Reptile(_name, _k), poisonous{_poisonous} {}

void Snake::PrintInfo() const {
        feedable();
        voice();
        Reptile::PrintInfo();
}

void Snake::feedable() const {
    std::cout << "Eating a rat." << std::endl;
}

void Snake::voice() const {
     std::cout << name << " hisses: Ssssssss..." << std::endl;
}


//____________________________________________________________________________
        //Crocodile
Crocodile::Crocodile() 
    : Reptile("Unnamed", Kind::Crocodile), biteForce{4} {}

Crocodile::Crocodile(const std::string& _name, int _biteForce, Kind _k) 
    : Reptile(_name, _k), biteForce{_biteForce} {}

void Crocodile::PrintInfo() const {
        swim();
        feedable();
        voice();
        Snap();
        Reptile::PrintInfo();
}

void Crocodile::swim() const {
    std::cout << name << " is swiming in milk jacuse." << std::endl;
}

void Crocodile::voice() const {
    std::cout << "Crocodile sound: SSSSSS." << std::endl;
}

void Crocodile::feedable() const {
    std::cout << name << " eating xinkali whit rabbit and wolf." << std::endl;
}

void Crocodile::Snap() const {
        std::cout << name << " snaps its jaws with force "
              << biteForce << "!" << std::endl;
}











