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
    string getEngineType() const;
    void setPower(float power);
    void setEngineType(string engineType);
};

class Body
{
private:
    string bodyType;

public:
    Body();
    Body(string bodyType);
    Body(const Body& other);

    string getBodyType() const;
    void setBodyType(string bodyType);
};

class Color
{
private:
    string color;

public:
    Color();
    Color(string color);
    Color(const Color& other);

    string getColor() const;
    void setColor(string color);
};

class Vehicle : public Engine, public Body, public Color
{
private:
    string material;
    string model;

public:
    Vehicle();
    Vehicle(string material, string model);
    Vehicle(const Vehicle& other);

    string getMaterial() const;
    string getModel() const;
    void setMaterial(string material);
    void setModel(string model);

    virtual void writeToFile(string filename);
    virtual void printInformation();
};

class Car : public Vehicle
{
private:
    string manufacturer;

public:
    Car();
    Car(string material, string model, string manufacturer, float power, string engineType, string bodyType, string color);
    string getManufacturer() const;
    void setManufacturer(string manufacturer);

    void writeToFile(string filename) override;
    void printInformation() override;
};

class MilitaryCar : public Car
{
private:
    bool isArmored;

public:
    MilitaryCar();
    MilitaryCar(string material, string model, string manufacturer, float power, string engineType, string bodyType, string color, bool isArmored);
    bool getIsArmored() const;
    void setIsArmored(bool isArmored);

    void writeToFile(string filename) override;
    void printInformation() override;
};

class Airplane : public Vehicle
{
private:
    string manufacturer;
    float wingspan;
    float maxSpeed;

public:
    Airplane();
    Airplane(string material, string model, string manufacturer, float wingspan, float maxSpeed);
    string getManufacturer() const;
    float getWingspan() const;
    float getMaxSpeed() const;
    void setManufacturer(string manufacturer);
    void setWingspan(float wingspan);
    void setMaxSpeed(float maxSpeed);

    void writeToFile(string filename) override;
    void printInformation() override;
};
