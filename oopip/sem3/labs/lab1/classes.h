#pragma once

#include "libs.h"

class Engine
{
private:
    float power;
    string engineType;

public:
    Engine();
    Engine(float power, string engineType);
    Engine(const Engine& other);

    float getPower() const;
    void setPower(float power);
    string getEngineType() const;
    void setEngineType(string engineType);
};

class Body
{
private:
    string bodyType;
    string material;

public:
    Body();
    Body(string bodyType, string material);
    Body(const Body& other);

    string getBodyType() const;
    void setBodyType(string bodyType);
    string getMaterial() const;
    void setMaterial(string material);
};

class Color
{
private:
    string color;
    int brightness;

public:
    Color();
    Color(string color, int brightness);
    Color(const Color& other);

    string getColor() const;
    void setColor(string color);
    int getBrightness() const;
    void setBrightness(int brightness);
};

class Vehicle
{
private:
    Engine engine;
    Body body;
    Color color;

public:
    Vehicle();
    Vehicle(const Engine& engine, const Body& body, const Color& color);

    Engine getEngine() const;
    void setEngine(const Engine& engine);
    Body getBody() const;
    void setBody(const Body& body);
    Color getColor() const;
    void setColor(const Color& color);

    virtual void writeToFile(string filename) = 0;
    virtual void printInformation() = 0;
};

class PublicTransport
{
private:
    string cityName;
    int passengerCapacity;

public:
    PublicTransport();
    PublicTransport(string cityName, int passengerCapacity);
    PublicTransport(const PublicTransport& other);

    string getCityName() const;
    void setCityName(string cityName);
    int getPassengerCapacity() const;
    void setPassengerCapacity(int passengerCapacity);
};

class PersonalTransport
{
private:
    string ownerName;
    bool hasInsurance;

public:
    PersonalTransport();
    PersonalTransport(string ownerName, bool hasInsurance);
    PersonalTransport(const PersonalTransport& other);

    string getOwnerName() const;
    void setOwnerName(string ownerName);
    bool getHasInsurance() const;
    void setHasInsurance(bool hasInsurance);
};

class MilitaryTransport
{
private:
    string nameOfMilitaryUnit;
    string countryOfOrigin;

public:
    MilitaryTransport();
    MilitaryTransport(string nameOfMilitaryUnit, string countryOfOrigin);
    MilitaryTransport(const MilitaryTransport& other);

    string getNameOfMilitaryUnit() const;
    void setNameOfMilitaryUnit(string nameOfMilitaryUnit);
    string getCountryOfOrigin() const;
    void setCountryOfOrigin(string countryOfOrigin);
};

class Car : public Vehicle
{
private:
    string manufacturer;
    string model;

public:
    Car();
    Car(const Engine& engine, const Body& body, const Color& color, string manufacturer, string model);
    Car(const Car& other);

    string getManufacturer() const;
    void setManufacturer(string manufacturer);
    string getModel() const;
    void setModel(string model);
};

class MilitaryCar : public Car, MilitaryTransport
{
private:
    string militaryCarType;
    bool isArmored;

public:
    MilitaryCar();
    MilitaryCar(const Engine& engine, const Body& body, const Color& color, string manufacturer, string model, string militaryCarType, bool isArmored, const MilitaryTransport& militaryTransport);
    MilitaryCar(const MilitaryCar& other);

    string getMilitaryCarType() const;
    void setMilitaryCarType(string militaryCarType);
    bool getIsArmored() const;
    void setIsArmored(bool isArmored);

    void writeToFile(string filename) override;
    void printInformation() override;
};

class PublicCar : public Car, PublicTransport
{
private:
    int routeNumber;
    string operatorName;

public:
    PublicCar();
    PublicCar(const Engine& engine, const Body& body, const Color& color, string manufacturer, string model, int routeNumber, string operatorName, const PublicTransport& publicTransport);
    PublicCar(const PublicCar& other);

    int getRouteNumber() const;
    void setRouteNumber(int routeNumber);
    string getOperatorName() const;
    void setOperatorName(string operatorName);

    void writeToFile(string filename) override;
    void printInformation() override;
};

class PersonalCar : public Car, PersonalTransport
{
private:
    int yearOfManufacture;
    string registrationNumber;

public:
    PersonalCar();
    PersonalCar(const Engine& engine, const Body& body, const Color& color, string manufacturer, string model, int yearOfManufacture, string registrationNumber, const PersonalTransport& personalTransport);
    PersonalCar(const PersonalCar& other);

    int getYearOfManufacture() const;
    void setYearOfManufacture(int yearOfManufacture);
    string getRegistrationNumber() const;
    void setRegistrationNumber(string registrationNumber);

    void writeToFile(string filename) override;
    void printInformation() override;
};