#include <iostream>

class PersonalChef
{
    public:
        bool available()
        {
            return 0;
        }

        void prepareFood(std::string foodName)
        {
            m_foodName = foodName;
            std::cout << foodName << " is being prepared by the chef." << std::endl;
        }
        
        void serveFood()
        {
            std::cout << m_foodName << " is served." << std::endl;
        }
    
    private:
        std::string m_foodName;

};

class DeliveryService
{
    public:
        void automaticOrderPlacing(std::string foodName)
        {
            m_foodName = foodName;
            std::cout << foodName << " has been ordered at your favourite delivery service." << std::endl;
        }
        void doorBellRobot()
        {
            std::cout << "Door Bell Robot has answered the door bell and serves the delivered " << m_foodName << " in the dining room." << std::endl;
        }
    private:
        std::string m_foodName;
};

// Facade 
// Hides different options for dinner preparations. Gets the job done.
class DinnerDish
{
    public:
        void getDinnerReady(std::string foodName)
        {
            PersonalChef* pc = new PersonalChef();
            DeliveryService* ds = new DeliveryService();
            if (pc->available())
            {
                pc->prepareFood(foodName);
                pc->serveFood();
            }
            else
            {
                ds->automaticOrderPlacing(foodName);
                ds->doorBellRobot();
            }
            delete pc, ds;
        }

};

int main()
{
    DinnerDish* dd = new DinnerDish();
    dd->getDinnerReady("Pizza");
    delete dd;
}