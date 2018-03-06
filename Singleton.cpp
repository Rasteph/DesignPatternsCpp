//Ensure a class only has one instance, and provide a global point of access to it.


#include <string>
#include <iostream>

class PresidentOfFrance
{
    std::string m_name;
    static PresidentOfFrance *s_instance;
    PresidentOfFrance(std::string name = "Louis XIV - L'État c'est moi")
    {
        m_name = name;
    }
    public:
        std::string get_name()
        {
            return m_name;
        }
        void set_name(std::string name)
        {
            m_name = name;
        }
        static PresidentOfFrance *instance()
        {
            if(!s_instance)
            {
                s_instance = new PresidentOfFrance;
                return s_instance;
            }
        }
};

PresidentOfFrance *PresidentOfFrance::s_instance = 0;

int main()
{    
    std::cout << "The one and only president of France is: " << PresidentOfFrance::instance()->get_name() << "." << std::endl;
    PresidentOfFrance::instance()->set_name("Emmanuel Macron");
    std::cout << "The one and only president of France is: " << PresidentOfFrance::instance()->get_name() << "." << std::endl;
}