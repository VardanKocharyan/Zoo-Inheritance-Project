#ifndef ZOO_INHERITANCE_PROJECT_HPP
#define ZOO_INHERITANCE_PROJECT_HPP

#include <vector>
#include <string>

enum class Kind {
  Animal, Mammal, Bird, Reptile,
    Lion, Tiger, Elephant,
    Eagle, Parrot,
    Snake, Crocodile      
};

class Animal {
    protected:
        std::string name;
        int health; //0-100
        int hunger; //0-100
        Kind kind;
        int Id;
        static int next_id;

    public:
        Animal();
        Animal(const std::string& _name, int _health = 100, int _hunger = 0);
        virtual ~Animal() = default;

        void PrintInfo() const;
        void Feed();
        Kind KindOf() const;
        int getId() const;
};

class Mammal : public Animal{
    protected:
        bool warmBlooded;
    public:
        Mammal();
        Mammal(const std::string& _name);
        virtual ~Mammal() = default;

        void MakeSound();
};

class Bird : public Animal {
    protected:
        double wingSpan;
    public:
        Bird();
        Bird(const std::string& _name, double _wingSpan = 0.2);
        virtual ~Bird() = default;

        void Fly() const;
};

class Reptile : public Animal {
    protected:
        bool coldBlooded;
    public:
        Reptile();
        Reptile(const std::string& _name);
        virtual ~Reptile() = default;

        void Sunbathe();
};

class Lion : public Mammal {
    private:
        int roarPower;      // 1..10
    public:
        Lion();
        Lion(const std::string& _name, int _roarPower = 4);

        void Roar() const;        // print "Lion roars with power X"
};

class Tiger : public Mammal {
        private:
            double jumpHeight;
        public:
            Tiger();
            Tiger(const std::string& _name, double _jumpHeight = 2.6);
            void MakeSound() const;
            void Jump() const;
};


class Elephant : public Mammal {
        private:
            double trunkLength;
        public:
            Elephant();
            Elephant(const std::string& _name, double _trunkLength = 0.8);

            void MakeSound() const;
            void UseTrunk() const;
};

class Eagle : public Bird {
        private:
            double visionRange;
        public:
            Eagle();
            Eagle(const std::string& _name, double _visionRange = 50.0);

            void Fly() const;
            void Soar() const;
};

class Parrot : public Bird {
    private:
        std::vector<std::string> vocabulary;
    public:
        Parrot();
        Parrot(const std::string& _name, std::string _text = "q");

        void Fly() const;
        void Speak() const;
};

class Snake : public Reptile {
    private:
        bool poisonous;
    public:
        Snake();
        Snake(const std::string& _name, bool _poisonous = false);

        void Hiss() const;
};

class Crocodile : public Reptile {
        private:
            int biteForce;
        public:
            Crocodile();
            Crocodile(const std::string& _name, int _biteForce = 4);

            void Snap() const;
};

#endif
