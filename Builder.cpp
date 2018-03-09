#include <iostream>
#include <string>
#include <queue>

// Product: Agenda for one day
class DayAgenda
{
    public:
       DayAgenda(){}
       ~DayAgenda(){}

       void setDayAgendaItem(std::string dayAgendaItem){
           mDayAgenda.push(dayAgendaItem);
       } 
       void printDayAgenda(){
           int i = 1;
           while(!mDayAgenda.empty()){
               std::cout << "Agenda item " << i++ << ": " << mDayAgenda.front() << std::endl;
               mDayAgenda.pop();  
           }
       }

    private:
        std::queue<std::string> mDayAgenda;
};

// Builder: general possible agenda items
class DayAgendaBuilder
{
    public:
        DayAgendaBuilder() {}
        ~DayAgendaBuilder() {}

        const DayAgenda& getDayAgenda() {return builderDayAgenda;}
        virtual void buildMorning() = 0;
        virtual void buildLunch() = 0;
        virtual void buildAfternoon() = 0;
        virtual void buildEvening() = 0;

    protected:
        DayAgenda builderDayAgenda;
};

class BusyDayAgenda : public DayAgendaBuilder
{
public:
    BusyDayAgenda(){}
    ~BusyDayAgenda(){}

    virtual void buildEvening(){builderDayAgenda.setDayAgendaItem("Go to bed early.");}
    virtual void buildMorning(){builderDayAgenda.setDayAgendaItem("Coffee and a croissant.");}
    virtual void buildAfternoon(){builderDayAgenda.setDayAgendaItem("Work, work, work, work, work, work...");}
    virtual void buildLunch(){builderDayAgenda.setDayAgendaItem("Sorry. No launch today.");}

};

class HoliDayAgenda : public DayAgendaBuilder
{
public:
    HoliDayAgenda(){}
    ~HoliDayAgenda(){}

    virtual void buildAfternoon(){builderDayAgenda.setDayAgendaItem("Read your bookmarked links or that one book you wanted to read. Alternatively go on a hike.");}
    virtual void buildLunch(){builderDayAgenda.setDayAgendaItem("Treat yourself in that magnificent restaurant around the corner.");}
    virtual void buildMorning(){builderDayAgenda.setDayAgendaItem("Coffee and a croissant and eggs and orange juice...");}
    virtual void buildEvening(){builderDayAgenda.setDayAgendaItem("Dinner party with your friends...");}
};

// Director ensuring right chronology of events
class DayAgendaGod
{   
public:
        DayAgendaGod():godDayAgenda(NULL){}
        ~DayAgendaGod() {if(godDayAgenda) delete godDayAgenda;}

    void setDayAgendaBuilder(DayAgendaBuilder *dayAgendaBuilder){
        if(godDayAgenda) delete godDayAgenda;
        godDayAgenda = dayAgendaBuilder;
    }
    const DayAgenda& getDayAgenda(){return godDayAgenda->getDayAgenda();}
    void createDayAgenda(){
        godDayAgenda->buildMorning();
        godDayAgenda->buildLunch();
        godDayAgenda->buildAfternoon();
        godDayAgenda->buildEvening();
    }

    private:
        DayAgendaBuilder *godDayAgenda;
};

int main()
{
    DayAgendaGod dAG;

    std::cout << "Set holiDay agenda." << std::endl;
    dAG.setDayAgendaBuilder(new HoliDayAgenda());
    dAG.createDayAgenda();

    DayAgenda holiDay = dAG.getDayAgenda();
    holiDay.printDayAgenda();

    std::cout << "\nSet busy day agenda." << std::endl;
    dAG.setDayAgendaBuilder(new BusyDayAgenda());
    dAG.createDayAgenda();

    DayAgenda busyDay = dAG.getDayAgenda();
    busyDay.printDayAgenda();
}
