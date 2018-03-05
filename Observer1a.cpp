// Observer represent different views (interest on monthly salary; yearly income based on salary only) on the subject (salary)

#include <vector>
#include <iostream>

class Observer
{
    public:
        virtual void update(int value) = 0;
};

class Subject
{
    int m_salary;
    std::vector<Observer*> m_views;
    public:
        void attach(Observer *observer)
        {
            m_views.push_back(observer);
        }
        void set_salary(int salary)
        {
            m_salary = salary;
            pushChange();
        }
        void pushChange()
        {
            for (int i = 0; i<m_views.size(); i++)
            {
                m_views[i]->update(m_salary);
            }
        }
}; 

class InterestObserver: public Observer
{
    int m_interest;
    public:
        InterestObserver(Subject *model, int interest)
        {
            model->attach(this);
            m_interest = interest;
        }
        void update(int salary)
        {
            std::cout << "Interest on salary of " << salary << " with rate of " << m_interest << "% is: " << (salary/100) * m_interest << "." << std::endl;
        }
};

class YearlySalaryObserver: public Observer
{
    int m_months = 12;
    public:
        YearlySalaryObserver(Subject *model)
        {
            model->attach(this);
        }
        void update(int salary)
        {
            std::cout << "Yearly salary with monthly salary of " << salary << " is: " << salary*m_months << "." << std::endl;  
        }

};    

int main(int argc, char **argv)
{
    Subject salary;
    InterestObserver intObs(&salary, 2);
    InterestObserver intObs2(&salary, 3);    
    InterestObserver intObs3(&salary, 5);
    YearlySalaryObserver ySObs(&salary);
    salary.set_salary(40000);
}

// Output:
// Interest on salary of: 40000 with rate of 2is: 800.
// Interest on salary of: 40000 with rate of 3is: 1200.
// Interest on salary of: 40000 with rate of 5is: 2000.
// Yearly salary with montly salary of 40000 is: 480000.
