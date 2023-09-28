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

    float getPower();
    void setPower(float power);
    string getEngineType();
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

    string getBodyType();
    void setBodyType(string bodyType);
    string getMaterial();
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

    string getColor();
    void setColor(string color);
    int getBrightness();
    void setBrightness(int brightness);
};

class Vehicle
{
private:
    string vehicleName;
    Engine engine;
    Body body;
    Color color;

public:
    Vehicle();
    Vehicle(const Engine& engine, const Body& body, const Color& color, const string& vehicleName);

    string getVehicleName() const;
    void setVehicleName(const string& name);
    Engine getEngine() const;
    void setEngine(const Engine& engine);
    Body getBody() const;
    void setBody(const Body& body);
    Color getColor() const;
    void setColor(const Color& color);

    virtual void writeToFile(string filename) = 0;
    virtual void printInformation() = 0;
};

class MilitaryTransport : public virtual Vehicle
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

class Car : public virtual Vehicle
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

class MilitaryCar : public Car, public MilitaryTransport
{
private:
    string militaryCarType;
    bool isArmored;

public:
    MilitaryCar();
    MilitaryCar(const string& vehicleName, const Engine& engine, const Body& body, const Color& color,
        string manufacturer, string model, string militaryCarType, bool isArmored,
        string countryOfOrigin, string nameOfMilitaryUnit);
    MilitaryCar(const MilitaryCar& other);

    string getMilitaryCarType() const;
    void setMilitaryCarType(string militaryCarType);
    bool getIsArmored() const;
    void setIsArmored(bool isArmored);

    void writeToFile(string filename) override;
    void printInformation() override;
};