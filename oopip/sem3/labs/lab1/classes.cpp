#include "libs.h"
#include "classes.h"

// Engine methods
Engine::Engine() : power(0), engineType("-") {}
Engine::Engine(float power, string engineType) : power(power), engineType(engineType) {}
Engine::Engine(const Engine& other) : power(other.power), engineType(other.engineType) {}

float Engine::getPower() const { return power; }
string Engine::getEngineType() const { return engineType; }
void Engine::setPower(float power) { this->power = power; }
void Engine::setEngineType(string engineType) { this->engineType = engineType; }

// Body methods
Body::Body() : bodyType("-") {}
Body::Body(string bodyType) : bodyType(bodyType) {}
Body::Body(const Body& other) : bodyType(other.bodyType) {}

string Body::getBodyType() const { return bodyType; }
void Body::setBodyType(string bodyType) { this->bodyType = bodyType; }

// Color methods
Color::Color() : color("-") {}
Color::Color(string color) : color(color) {}
Color::Color(const Color& other) : color(other.color) {}

string Color::getColor() const { return color; }
void Color::setColor(string color) { this->color = color; }

// Vehicle methods
Vehicle::Vehicle() : material("-"), model("-") {}
Vehicle::Vehicle(string material, string model) : material(material), model(model) {}
Vehicle::Vehicle(const Vehicle& other) : material(other.material), model(other.model) {}

string Vehicle::getMaterial() const { return material; }
string Vehicle::getModel() const { return model; }
void Vehicle::setMaterial(string material) { this->material = material; }
void Vehicle::setModel(string model) { this->model = model; }

void Vehicle::writeToFile(string filename)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << "Material: " << this->getMaterial() << endl;
        outFile << "Model: " << this->getModel() << endl;
        outFile.close();
        cout << "Data written to file: " << filename << endl;
    }
    else
    {
        cout << "Error: Unable to open file." << endl;
    }
}

void Vehicle::printInformation()
{
    cout << "\nMaterial: " << this->getMaterial() << endl;
    cout << "Model: " << this->getModel() << endl;
}

// Car methods
Car::Car() : manufacturer("-") {}
Car::Car(string material, string model, string manufacturer, float power, string engineType, string bodyType, string color)
    : Vehicle(material, model), Engine(power, engine), Body(bodyType), Color(color), manufacturer(manufacturer) {}

string Car::getManufacturer() const { return manufacturer; }
void Car::setManufacturer(string manufacturer) { this->manufacturer = manufacturer; }

void Car::writeToFile(string filename)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << "Material: " << this->getMaterial() << endl;
        outFile << "Model: " << this->getModel() << endl;
        outFile << "Manufacturer: " << this->getManufacturer() << endl;
        outFile << "Engine Power: " << this->getPower() << " HP" << endl;
        outFile << "Engine Type: " << this->getEngineType() << endl;
        outFile << "Body Type: " << this->getBodyType() << endl;
        outFile << "Color: " << this->getColor() << endl;
        outFile.close();
        cout << "Data written to file: " << filename << endl;
    }
    else
    {
        cout << "Error: Unable to open file." << endl;
    }
}

void Car::printInformation()
{
    cout << "\nMaterial: " << this->getMaterial() << endl;
    cout << "Model: " << this->getModel() << endl;
    cout << "Manufacturer: " << this->getManufacturer() << endl;
    cout << "Engine Power: " << this->getPower() << endl;
    cout << "Engine Type: " << this->getEngineType() << endl;
    cout << "Body Type: " << this->getBodyType() << endl;
    cout << "Color: " << this->getColor() << endl;
}

// MilitaryCar methods
MilitaryCar::MilitaryCar() : isArmored(false) {}
MilitaryCar::MilitaryCar(string material, string model, string manufacturer, float power, string engineType, string bodyType, string color, bool isArmored)
    : Car(material, model, manufacturer, power, engineType, bodyType, color), isArmored(isArmored) {}

bool MilitaryCar::getIsArmored() const { return isArmored; }
void MilitaryCar::setIsArmored(bool isArmored) { this->isArmored = isArmored; }

void MilitaryCar::writeToFile(string filename)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << "Material: " << this->getMaterial() << endl;
        outFile << "Model: " << this->getModel() << endl;
        outFile << "Manufacturer: " << this->getManufacturer() << endl;
        outFile << "Engine Power: " << this->getPower() << " HP" << endl;
        outFile << "Engine Type: " << this->getEngineType() << endl;
        outFile << "Body Type: " << this->getBodyType() << endl;
        outFile << "Color: " << this->getColor() << endl;
        outFile << "Is Armored: " << (this->getIsArmored() ? "Yes" : "No") << endl;
        outFile.close();
        cout << "Data written to file: " << filename << endl;
    }
    else
    {
        cout << "Error: Unable to open file." << endl;
    }
}

void MilitaryCar::printInformation()
{
    cout << "\nMaterial: " << this->getMaterial() << endl;
    cout << "Model: " << this->getModel() << endl;
    cout << "Manufacturer: " << this->getManufacturer() << endl;
    cout << "Engine Power: " << this->getPower() << endl;
    cout << "Engine Type: " << this->getEngineType() << endl;
    cout << "Body Type: " << this->getBodyType() << endl;
    cout << "Color: " << this->getColor() << endl;
    cout << "Is Armored: " << (this->getIsArmored() ? "Yes" : "No") << endl;
}

// Airplane methods
Airplane::Airplane() : manufacturer("-"), wingspan(0.0f), maxSpeed(0.0f) {}
Airplane::Airplane(string material, string model, string manufacturer, float wingspan, float maxSpeed)
    : Vehicle(material, model), manufacturer(manufacturer), wingspan(wingspan), maxSpeed(maxSpeed) {}

string Airplane::getManufacturer() const { return manufacturer; }
float Airplane::getWingspan() const { return wingspan; }
float Airplane::getMaxSpeed() const { return maxSpeed; }

void Airplane::setManufacturer(string manufacturer) { this->manufacturer = manufacturer; }
void Airplane::setWingspan(float wingspan) { this->wingspan = wingspan; }
void Airplane::setMaxSpeed(float maxSpeed) { this->maxSpeed = maxSpeed; }

void Airplane::writeToFile(string filename)
{
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << "Material: " << this->getMaterial() << endl;
        outFile << "Model: " << this->getModel() << endl;
        outFile << "Manufacturer: " << this->getManufacturer() << endl;
        outFile << "Wingspan: " << this->getWingspan() << " meters" << endl;
        outFile << "Max Speed: " << this->getMaxSpeed() << " km/h" << endl;
        outFile.close();
        cout << "Data written to file: " << filename << endl;
    }
    else
    {
        cout << "Error: Unable to open file." << endl;
    }
}

void Airplane::printInformation()
{
    cout << "\nMaterial: " << this->getMaterial() << endl;
    cout << "Model: " << this->getModel() << endl;
    cout << "Manufacturer: " << this->getManufacturer() << endl;
    cout << "Wingspan: " << this->getWingspan() << endl;
    cout << "Max Speed: " << this->getMaxSpeed() << endl;
}

