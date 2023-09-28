#include "libs.h"
#include "classes.h"

//Engine
Engine::Engine() : power(0.0), engineType("") {}

Engine::Engine(float power, string engineType) : power(power), engineType(engineType) {}

Engine::Engine(const Engine& other) : power(other.power), engineType(other.engineType) {}

float Engine::getPower()  {
    return power;
}

void Engine::setPower(float power) {
        this->power = power;
}

string Engine::getEngineType()  {
    return engineType;
}

void Engine::setEngineType(string engineType) {
    this->engineType = engineType;
}

//Body
Body::Body() : bodyType(""), material("") {}

Body::Body(string bodyType, string material) : bodyType(bodyType), material(material) {}

Body::Body(const Body& other) : bodyType(other.bodyType), material(other.material) {}

string Body::getBodyType() {
    return bodyType;
}

void Body::setBodyType(string bodyType) {
    this->bodyType = bodyType;
}

string Body::getMaterial() {
    return material;
}

void Body::setMaterial(string material) {
    this->material = material;
}

//Color
Color::Color() : color(""), brightness(0) {}

Color::Color(string color, int brightness) : color(color), brightness(brightness) {}

Color::Color(const Color& other) : color(other.color), brightness(other.brightness) {}

string Color::getColor() {
    return color;
}

void Color::setColor(string color) {
    this->color = color;
}

int Color::getBrightness() {
    return brightness;
}

void Color::setBrightness(int brightness) {
        this->brightness = brightness;
}

//Vehicle
Vehicle::Vehicle() {}

Vehicle::Vehicle(const Engine& engine, const Body& body, const Color& color, const string& vehicleName)
    : engine(engine), body(body), color(color), vehicleName(vehicleName) {}

Engine Vehicle::getEngine() const {
    return engine;
}

void Vehicle::setEngine(const Engine& engine) {
    this->engine = engine;
}

Body Vehicle::getBody() const {
    return body;
}

void Vehicle::setBody(const Body& body) {
    this->body = body;
}

Color Vehicle::getColor() const {
    return color;
}

void Vehicle::setColor(const Color& color) {
    this->color = color;
}

string Vehicle::getVehicleName() const{
    return this->vehicleName;
}

void Vehicle::setVehicleName(const string& name) {
    this->vehicleName = name;
}


//MilitaryTransport
MilitaryTransport::MilitaryTransport() : nameOfMilitaryUnit(""), countryOfOrigin("") {}

MilitaryTransport::MilitaryTransport(string nameOfMilitaryUnit, string countryOfOrigin)
    : nameOfMilitaryUnit(nameOfMilitaryUnit), countryOfOrigin(countryOfOrigin) {}

MilitaryTransport::MilitaryTransport(const MilitaryTransport& other)
    : nameOfMilitaryUnit(other.nameOfMilitaryUnit), countryOfOrigin(other.countryOfOrigin) {}

string MilitaryTransport::getNameOfMilitaryUnit() const {
    return nameOfMilitaryUnit;
}

void MilitaryTransport::setNameOfMilitaryUnit(string nameOfMilitaryUnit) {
    this->nameOfMilitaryUnit = nameOfMilitaryUnit;
}

string MilitaryTransport::getCountryOfOrigin() const {
    return countryOfOrigin;
}

void MilitaryTransport::setCountryOfOrigin(string countryOfOrigin) {
    this->countryOfOrigin = countryOfOrigin;
}

//Car
Car::Car() : manufacturer(""), model("") {}

Car::Car(const Engine& engine, const Body& body, const Color& color, string manufacturer, string model)
    : Vehicle(engine, body, color, ""), manufacturer(manufacturer), model(model) {}

Car::Car(const Car& other)
    : Vehicle(other.getEngine(), other.getBody(), other.getColor(), ""), 
    manufacturer(other.manufacturer), model(other.model) {}

string Car::getManufacturer() const {
    return manufacturer;
}

void Car::setManufacturer(string manufacturer) {
    this->manufacturer = manufacturer;
}

string Car::getModel() const {
    return model;
}

void Car::setModel(string model) {
    this->model = model;
}

//MilitaryCar
MilitaryCar::MilitaryCar() : Car(), militaryCarType(""), isArmored(false) {}

MilitaryCar::MilitaryCar(const string& vehicleName, const Engine& engine, const Body& body, const Color& color,
    string manufacturer, string model, string militaryCarType, bool isArmored, 
    string countryOfOrigin, string nameOfMilitaryUnit)
    : Vehicle(engine, body, color, vehicleName), Car(engine, body, color, manufacturer, model),
    MilitaryTransport(nameOfMilitaryUnit, countryOfOrigin),
    militaryCarType(militaryCarType), isArmored(isArmored) {}

MilitaryCar::MilitaryCar(const MilitaryCar& other)
    : Vehicle(other.getEngine(), other.getBody(), other.getColor(), other.getVehicleName() + " copied"),
    Car(other.getEngine(), other.getBody(), other.getColor(), other.getManufacturer(), other.getModel()), 
    MilitaryTransport(other.getNameOfMilitaryUnit(), other.getCountryOfOrigin()),
    militaryCarType(other.militaryCarType), isArmored(other.isArmored) {}

string MilitaryCar::getMilitaryCarType() const{
    return militaryCarType;
}

void MilitaryCar::setMilitaryCarType(string militaryCarType) {
    this->militaryCarType = militaryCarType;
}

bool MilitaryCar::getIsArmored() const {
    return isArmored;
}

void MilitaryCar::setIsArmored(bool isArmored) {
    this->isArmored = isArmored;
}

void MilitaryCar::writeToFile(string filename) {
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << "Vehicle name: " << this->getVehicleName() << endl;

        outFile << "Military car type: " << this->getMilitaryCarType() << endl;
        outFile << "Is Armored: " << (this->getIsArmored() ? "Yes" : "No") << endl;

        outFile << "Manufacturer: " << this->getManufacturer() << endl;
        outFile << "Model: " << this->getModel() << endl;

        outFile << "Name of military unit: " << this->getNameOfMilitaryUnit() << endl;
        outFile << "Country of origin: " << this->getCountryOfOrigin() << endl;

        outFile << "Body Type: " << this->getBody().getBodyType() << endl;
        outFile << "Body material: " << this->getBody().getMaterial() << endl;

        outFile << "Color: " << this->getColor().getColor() << endl;
        outFile << "Brightness: " << this->getColor().getBrightness() << endl;

        outFile << "Engine type: " << this->getEngine().getEngineType() << endl;
        outFile << "Engine power: " << this->getEngine().getPower() << endl;
        outFile.close();
        cout << "Data written to file: " << filename << endl;
    }
    else
    {
        cout << "Error: Unable to open file." << endl;
    }
}

void MilitaryCar::printInformation() {
        cout << "\nVehicle name: " << this->getVehicleName() << endl;
        
        cout << "Military car type: " << this->getMilitaryCarType() << endl;
        cout << "Is Armored: " << (this->getIsArmored() ? "Yes" : "No") << endl;

        cout << "Manufacturer: " << this->getManufacturer() << endl;
        cout << "Model: " << this->getModel() << endl;

        cout << "Name of military unit: " << this->getNameOfMilitaryUnit() << endl;
        cout << "Country of origin: " << this->getCountryOfOrigin() << endl;

        cout << "Body Type: " << this->getBody().getBodyType() << endl;
        cout << "Body material: " << this->getBody().getMaterial() << endl;

        cout << "Color: " << this->getColor().getColor() << endl;
        cout << "Brightness: " << this->getColor().getBrightness() << endl;

        cout << "Engine type: " << this->getEngine().getEngineType() << endl;
        cout << "Engine power: " << this->getEngine().getPower() << endl << endl;
}
