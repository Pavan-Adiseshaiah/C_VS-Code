#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Car {
private:
    string m_licensePlate;
    string m_brand;
    
public:
    Car(const string &licensePlate, const string &brand)
        : m_licensePlate(licensePlate), m_brand(brand) {}

    virtual int getPassengerCapacity() const = 0;

    string getLicensePlate() const {
        return m_licensePlate;
    }

    string getBrand() const {
        return m_brand;
    }

};

class SUV : public Car {
private:
    bool m_hasThirdRowSeat;

public:
    SUV(const string &licensePlate, const string &brand, bool hasThirdRowSeat)
        : Car(licensePlate, brand), m_hasThirdRowSeat(hasThirdRowSeat) {}

    int getPassengerCapacity() const override {
        return m_hasThirdRowSeat ? 8 : 5;
    }
};

class Sedan : public Car {
private:
    bool m_hasSportPackage;

public:
    Sedan(const string &licensePlate, const string &brand, bool hasSportPackage)
        : Car(licensePlate, brand), m_hasSportPackage(hasSportPackage) {}

    int getPassengerCapacity() const override {
        return m_hasSportPackage ? 2 : 5;
    }
};

class CarRental {
private:
    vector<Car*> m_cars;

public:
    void addCar(Car *car) {
        m_cars.push_back(car);
    }

    void printCarInfo() const {
        for (const auto &car : m_cars) {
            cout << "License Plate: " << car->getLicensePlate() << ", Brand: " << car->getBrand()
                 << ", Passenger Capacity: " << car->getPassengerCapacity() << endl;
        }
    }
};

int main() {
    CarRental carRental;

    SUV suv1("ABC123", "BMW", true);
    SUV suv2("DEF456", "Audi", false);
    Sedan sedan1("GHI789", "Mercedes", true);
    Sedan sedan2("JKL012", "Toyota", false);

    carRental.addCar(&suv1);
    carRental.addCar(&suv2);
    carRental.addCar(&sedan1);
    carRental.addCar(&sedan2);

    carRental.printCarInfo();

    return 0;
}
