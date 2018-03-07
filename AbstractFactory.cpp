#include <iostream>

class Bike
{
    public:
        Bike(){
            id_ = total_++;
        }
        virtual void manufactur() = 0;
    protected:
        int id_;
        static int total_;
};

int Bike::total_ = 0;

class Brakes : public Bike
{
    public:
        void manufactur(){
            std::cout << "Brakes (manufacturer id: " << id_ << ") manufactured." << std::endl;
        }
};

class Frame : public Bike
{
    public:
        void manufactur(){
            std::cout << "Frame (manufacturer id: " << id_ << ") manufactured." << std::endl;
        }
};

class Wheel : public Bike
{
    public:
        void manufactur(){
            std::cout << "Wheels (manufacturer id: " << id_ << ") manufactured." << std::endl;
        }
};

class Pedal : public Bike
{
    public:
        void manufactur(){
            std::cout << "Pedals (manufacturer id: " << id_ << ") manufactured." << std::endl;
    }
};

class Factory
{
    public:
        virtual Bike* createPartAInstance() = 0; 
        virtual Bike* createPartBInstance() = 0;
};

class BikePartsOne : public Factory
{
    public:
    Bike* createPartAInstance(){
        return new Wheel;
    }
    Bike* createPartBInstance(){
        return new Pedal;
    }
};

class BikePartsTwo : public Factory
{
    public:
    Bike* createPartAInstance(){
        return new Brakes;
    }
    Bike* createPartBInstance(){
        return new Frame;
    }
};  

int main()
{
    Factory* factory = new BikePartsOne;
    Factory* factory2 = new BikePartsTwo;

    Bike* bikeParts[4];

    bikeParts[0] = factory->createPartAInstance(); // bikeParts[0] = new Wheel;
    bikeParts[1] = factory->createPartBInstance(); // bikeParts[1] = new Pedals;
    bikeParts[2] = factory2->createPartAInstance();
    bikeParts[3] = factory2->createPartBInstance();

    for (int i = 0; i < 4; i++)
    {
        bikeParts[i]->manufactur();
    }
}