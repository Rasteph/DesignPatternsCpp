// Observer represent different views (interest on monthly salary; yearly income based on salary only) on the subject (salary)

#include <iostream>
#include <vector>
class Subject
{
    std::vector<class Observer*> views;
    int m_salary;
    public:
        void attach(Observer *obs)
        {
            views.push_back(obs);
        }
        void setSalary(int salaryValue)
        {
            m_salary = salaryValue;
            pushChange();
        }
        int getSalary()
        {
            return m_salary;
        }
        void pushChange();
};

class Observer
{
    Subject *m_model;
    int m_value;
    public:
        Observer(Subject *model, int value)
        {
            m_model = model;
            m_value = value;
            m_model->attach(this);
        }
        virtual void update() = 0;
    protected:
        Subject* getSubject()
        {
            return m_model;
        }
        int getValue()
        {
            return m_value;
        }
};

void Subject::pushChange()
{
    for(int i = 0; i<views.size(); i++)
    {
        views[i]->update();
    }
}

class InterestObserver: public Observer
{
    public:
    InterestObserver(Subject *model, int value): Observer(model, value){};
    void update()
    {
        int salary = getSubject()->getSalary();
        int value = getValue();
        std::cout << "Interest on salary of " << salary << " with rate of " << value << "% is: " << (salary/100) * value << "." << std::endl;
    }
};

class YearlySalaryObserver: public Observer
{
    public:
    YearlySalaryObserver(Subject *model, int value): Observer(model, value){};
    void update()
    {
        int salary = getSubject()->getSalary();
        int value = getValue();
        std::cout << "Yearly salary with monthly salary of " << salary << " is: " << salary*value << "." << std::endl;  
    }
};

int main(int argc, char **argv)
{
    Subject subject;
    InterestObserver intObs(&subject, 2); 
    InterestObserver intObs2(&subject, 5);
    int m = 12; //months
    YearlySalaryObserver ySObs(&subject, m);
    subject.setSalary(40000);
}