// Subject is a simple smart home system.
// The views represent the different devices connected to the smart home system. They listen to the event of the system calling for their current status.

#include <iostream>
#include <vector>

class EventListener
{
    public:
        virtual void currentState() = 0;
};

class SmartHomeSystem
{
    std::vector<EventListener*> listeners;
    public:
        void attach(EventListener *eListener)
        {
            listeners.push_back(eListener);
        }
        void callEvent()
        {
            for (int i; i<listeners.size(); i++)
            {
                listeners[i]->currentState();
            }
        }
};

class Wifi: public EventListener
{
    public:
        virtual void currentState()
        {
            std::cout << "Wifi is activated." << std::endl;
        }
};

class LightBulbs: public EventListener
{
    public:
        void currentState()
        {
            std::cout << "6 Lightbulbs currently switched on." << std::endl;
        }
};

class WashingMachine: public EventListener
{
    public:
        void currentState()
        {
            std::cout << "Washing machine finishes in 17 minutes." << std::endl;
        }
};

class Fridge
{
    virtual void beverageStatus()
    {
        std::cout << "To buy: 2 bottles of milk.\n" << "Orange juice best-before 06.03.18" << std::endl;
    }
    virtual void foodStatus()
    {
        std::cout << "To buy: This smelly but delicious cheese.\n" << std::endl;
    }
    public:
    void groceriesList()
    {
        beverageStatus();
        foodStatus();
    }
};

class Surveillance: public Fridge, public EventListener
{
    void foodStatus()
    {
        std::cout << "Buy this smelly but delicious cheese and put away the salmon (best-before date is overdue)." << std::endl;
    }
    public:
    void currentState()
    {
        groceriesList();
    }
};

int main(int argc, char **argv)
{
    LightBulbs lightbulbs;
    Wifi wifi;
    WashingMachine washingMachine;
    Surveillance surveillance;
    SmartHomeSystem sHS;
    sHS.attach(&lightbulbs);
    sHS.attach(&wifi);
    sHS.attach(&washingMachine);
    sHS.attach(&surveillance);
    sHS.callEvent();

}