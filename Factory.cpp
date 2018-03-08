#include <iostream>
#include <string>
#include <memory>

// Product
class Vehicle
{
};

// concrete product
class Car : public Vehicle
{
    public:
        Car(){
            std::cout << "Car is being manufactured. "<< std::endl;
        }
};

// concrete product
class Bike : public Vehicle
{
    public:
        Bike(const std::string marking){
            std::cout << "Bike is being manufactured. " << std::endl;
            if(!marking.empty()){
                std::cout << marking << "will be lasered on the frame." << std::endl;
            }
        }
};

// concrete product
class Submarine : public Vehicle
{
    public:
        Submarine(){
            std::cout << "Submarine is being manufactured. " << std::endl;
        }
};

// Factory
class VehicleManufacturerCompany
{

    protected:
        virtual void manufacturVehicle() = 0; // Factory Method
        virtual void takerOrder(){
            std::cout << "Your order please." << std::endl;
        }
        virtual void orderDelivery(){
            std::cout << "Thank you for your trust in our manufacturer company." << std::endl; 
        }
    public:
        void orderingProcess(){
            takerOrder();
            manufacturVehicle();
            orderDelivery();
        }
    std::shared_ptr<Vehicle> vehicle;    
};

// customization of factory method
class CarManufacturer : public VehicleManufacturerCompany
{
    protected:
        virtual void manufacturVehicle(){
            vehicle = std::make_shared<Car>();
        }
};

// customization of factory method
class BikeManufacturer : public VehicleManufacturerCompany
{
    protected:
        virtual void manufacturVehicle(){
            vehicle = std::make_shared<Bike>("Emperor of the Tour de France");
        }
};

class SubmarineManufacturer : public VehicleManufacturerCompany
{
    protected:
        virtual void manufacturVehicle(){
            vehicle = std::make_shared<Submarine>();
        }
};

int main(){
    BikeManufacturer bM;
    CarManufacturer cM;
    SubmarineManufacturer sM;

    bM.orderingProcess();
    cM.orderingProcess();
    sM.orderingProcess();
}
