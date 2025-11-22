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

        //IFly
class IFly {
        public:
                virtual void fly() const = 0;
                virtual ~IFly() = default;
};
        //ISwim
class ISwim{
        public:
                virtual void swim() const = 0;
                virtual ~ISwim() = default;
};
        //IWalk
class IWalk{
        public:
                virtual void walk() const= 0;
                virtual~IWalk() = default;
};
        //IVoice
class IVoice{
        public:
                virtual void voice() const = 0;
                virtual ~IVoice() = default;
};
        //IFeedable
class IFeedable{
        public:
                virtual void feedable() const = 0;
                virtual ~IFeedable() = default;
};

        //Animal
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
        Animal(const std::string& _name = "Unnamed", int _health = 100, int _hunger = 0, Kind _k = Kind::Animal);
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
        Mammal(const std::string& _name, Kind _k = Kind::Mammal);
        virtual ~Mammal() = default;

        void PrintInfo() const;
        void MakeSound() const;
};

class Bird : public Animal {
    protected:
        double wingSpan;
    public:
        Bird();
        Bird(const std::string& _name, double _wingSpan = 0.6, Kind _k = Kind::Bird);
        virtual ~Bird() = default;

        void PrintInfo() const;
        void Fly() const;
};

class Reptile : public Animal {
    protected:
        bool coldBlooded;
    public:
        Reptile();
        Reptile(const std::string& _name, Kind _k = Kind::Reptile);
        virtual ~Reptile() = default;

        void PrintInfo() const;
        void Sunbathe();
};

class Lion : public Mammal, public IWalk, public IVoice, IFeedable {
    private:
        int roarPower;      // 1..10
    public:
        Lion();
        Lion(const std::string& _name, int _roarPower = 4, Kind _k = Kind::Lion);

        virtual void walk() const override;
        virtual void voice() const override;
        virtual void feedable() const override;

        void PrintInfo() const;
        void Roar() const;        // print "Lion roars with power X"
};

class Tiger : public Mammal, public IWalk, public IVoice, IFeedable {
        private:
            double jumpHeight;
        public:
            Tiger();
            Tiger(const std::string& _name, double _jumpHeight = 2.6, Kind _k = Kind::Tiger);
            
            virtual void walk() const override;
            virtual void voice() const override;
            virtual void feedable() const override;

            void PrintInfo() const;
            void Jump() const;
};


class Elephant : public Mammal, public IWalk, public IVoice, IFeedable {
        private:
            double trunkLength;
        public:
            Elephant();
            Elephant(const std::string& _name, double _trunkLength = 0.8, Kind _k = Kind::Elephant);

            virtual void walk() const override;
            virtual void voice() const override;
            virtual void feedable() const override;

            void PrintInfo() const;
            void MakeSound() const;
            void UseTrunk() const;
};

class Eagle : public Bird, public IFly, public IWalk, public IVoice, public IFeedable {
        private:
            double visionRange;
        public:
            Eagle();
            Eagle(const std::string& _name, double _visionRange = 50.0, Kind _k = Kind::Eagle);

            virtual void fly() const override;
            virtual void walk() const override;
            virtual void voice() const override;
            virtual void feedable() const override;

            void PrintInfo() const;
            void Soar() const;
};

class Parrot : public Bird, public IFly, public IWalk, public IVoice, public IFeedable {
    private:
        std::vector<std::string> vocabulary;
    public:
        Parrot();
        Parrot(const std::string& _name, std::string _text = "q", Kind _k = Kind::Parrot);

        virtual void fly() const override;
        virtual void walk() const override;
        virtual void voice() const override;
        virtual void feedable() const override;

        void PrintInfo() const;
        void Speak() const;
};

class Snake : public Reptile, public IVoice, public IFeedable {
    private:
        bool poisonous;
    public:
        Snake();
        Snake(const std::string& _name, bool _poisonous = false, Kind _k = Kind::Snake);

        virtual void voice() const override;
        virtual void feedable() const override;

        void PrintInfo() const;
};

class Crocodile : public Reptile, public ISwim, public IVoice, public IFeedable {
        private:
            int biteForce;
        public:
            Crocodile();
            Crocodile(const std::string& _name, int _biteForce = 4, Kind _k = Kind::Crocodile);

            virtual void swim() const override;
            virtual void voice() const override;
            virtual void feedable() const override;

            void PrintInfo() const;
            void Snap() const;
};

#endif
