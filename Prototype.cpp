#include <iostream>

// base class
class AmericanFootballPlayer
{
    public:
        virtual ~AmericanFootballPlayer(){}
        virtual AmericanFootballPlayer* clone() = 0;

        virtual int getSpeed() = 0;
};

// concrete class implementing virtual functions and clone()
class DefensePlayer : public AmericanFootballPlayer
{
    public:
        DefensePlayer(int stamina, int weight)
        : c_stamina(stamina),
        c_weight(weight){}

        virtual AmericanFootballPlayer* clone(){
            return new DefensePlayer(c_stamina,c_weight);
        }
        virtual int getSpeed(){
            return 0;
        }
    private:
        int c_stamina, c_weight;
};

// concrete class implementing virtual functions and clone()
class OffensePlayer : public AmericanFootballPlayer
{
    public:
        OffensePlayer(int speed, int height)
        : c_speed(speed),
        c_height(height){}

        virtual AmericanFootballPlayer* clone(){
            return new OffensePlayer(c_speed,c_height);
        }
        int getSpeed()
        {
            return c_speed;
        }
    private:
        int c_speed, c_height;
};

// Factory for offensive and defensive american footbal players
class PlayerSpawner
{
    public:
        PlayerSpawner(AmericanFootballPlayer* prototype)
        : c_prototype(prototype){}

        AmericanFootballPlayer* spawnPlayer()
        {
            return c_prototype->clone();
        }
    private:
        AmericanFootballPlayer* c_prototype;
};

int main()
{
    AmericanFootballPlayer* player[4];
    AmericanFootballPlayer* oPlayer = new OffensePlayer(40,180);
    PlayerSpawner* oPlayerSpawner = new PlayerSpawner(oPlayer); 
    AmericanFootballPlayer* dPlayer = new DefensePlayer(10,120);
    PlayerSpawner* dPlayerSpawner = new PlayerSpawner(dPlayer); 
    
    player[0] = oPlayerSpawner->spawnPlayer();
    player[1] = dPlayerSpawner->spawnPlayer();
    player[2] = oPlayerSpawner->spawnPlayer();
    player[3] = dPlayerSpawner->spawnPlayer();
    player[4] = oPlayerSpawner->spawnPlayer();

    for(int i = 0; i<sizeof(player);i++)
    {
        std::cout << player[i]->getSpeed() << std::endl; 
    }
}