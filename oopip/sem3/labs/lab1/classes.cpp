#include "libs.h"
#include "classes.h"

//Engine
Engine::Engine() : power(0.0), engineType("") {}

Engine::Engine(float power, string engineType) : power(power), engineType(engineType) {}

Engine::Engine(const Engine& other) : power(other.power), engineType(other.engineType) {}

float Engine::getPower() const {
    return power;
}

void Engine::setPower(float power) {
        this->power = power;
}

string Engine::getEngineType() const {
    return engineType;
}

void Engine::setEngineType(string engineType) {
    this->engineType = engineType;
}

//Body
Body::Body() : bodyType(""), material("") {}

Body::Body(string bodyType, string material) : bodyType(bodyType), material(material) {}

Body::Body(const Body& other) : bodyType(other.bodyType), material(other.material) {}

string Body::getBodyType() const {
    return bodyType;
}

void Body::setBodyType(string bodyType) {
    this->bodyType = bodyType;
}

string Body::getMaterial() const {
    return material;
}

void Body::setMaterial(string material) {
    this->material = material;
}

//Color
Color::Color() : color(""), brightness(0) {}

Color::Color(string color, int brightness) : color(color), brightness(brightness) {}

Color::Color(const Color& other) : color(other.color), brightness(other.brightness) {}

string Color::getColor() const {
    return color;
}

void Color::setColor(string color) {
    this->color = color;
}

int Color::getBrightness() const {
    return brightness;
}

void Color::setBrightness(int brightness) {
        this->brightness = brightness;
}

//Vehicle
Vehicle::Vehicle() {}

Vehicle::Vehicle(const Engine& engine, const Body& body, const Color& color)
    : engine(engine), body(body), color(color) {}

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

//PublicTransport
PublicTransport::PublicTransport() : cityName(""), passengerCapacity(0) {}

PublicTransport::PublicTransport(string cityName, int passengerCapacity)
    : cityName(cityName), passengerCapacity(passengerCapacity) {}

PublicTransport::PublicTransport(const PublicTransport& other)
    : cityName(other.cityName), passengerCapacity(other.passengerCapacity) {}

string PublicTransport::getCityName() const {
    return cityName;
}

void PublicTransport::setCityName(string cityName) {
    this->cityName = cityName;
}

int PublicTransport::getPassengerCapacity() const {
        return passengerCapacity;
}

void PublicTransport::setPassengerCapacity(int passengerCapacity) {
        this->passengerCapacity = passengerCapacity;
}

//PersonalTransport
PersonalTransport::PersonalTransport() : ownerName(""), hasInsurance(false) {}

PersonalTransport::PersonalTransport(string ownerName, bool hasInsurance)
    : ownerName(ownerName), hasInsurance(hasInsurance) {}

PersonalTransport::PersonalTransport(const PersonalTransport& other)
    : ownerName(other.ownerName), hasInsurance(other.hasInsurance) {}

string PersonalTransport::getOwnerName() const {
    return ownerName;
}

void PersonalTransport::setOwnerName(string ownerName) {
    this->ownerName = ownerName;
}

bool PersonalTransport::getHasInsurance() const {
    return hasInsurance;
}

void PersonalTransport::setHasInsurance(bool hasInsurance) {
    this->hasInsurance = hasInsurance;
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
    : Vehicle(engine, body, color), manufacturer(manufacturer), model(model) {}

Car::Car(const Car& other)
    : Vehicle(other.getEngine(), other.getBody(), other.getColor()),
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
MilitaryCar::MilitaryCar() : militaryCarType(""), isArmored(false) {}

MilitaryCar::MilitaryCar(const Engine& engine, const Body& body, const Color& color,
    string manufacturer, string model,
    string militaryCarType, bool isArmored,
    const MilitaryTransport& militaryTransport)
    : Car(engine, body, color, manufacturer, model),
    militaryCarType(militaryCarType), isArmored(isArmored),
    MilitaryTransport(militaryTransport) {}

MilitaryCar::MilitaryCar(const MilitaryCar& other)
    : Car(other.getEngine(), other.getBody(), other.getColor(),
        other.getManufacturer(), other.getModel()),
    militaryCarType(other.militaryCarType), isArmored(other.isArmored),
    MilitaryTransport(other) {}

string MilitaryCar::getMilitaryCarType() const {
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
        cout << "\nMilitary car type: " << this->getMilitaryCarType() << endl;
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

//PublicCar
PublicCar::PublicCar() : routeNumber(0), operatorName("") {}

PublicCar::PublicCar(const Engine& engine, const Body& body, const Color& color,
    string manufacturer, string model,
    int routeNumber, string operatorName,
    const PublicTransport& publicTransport)
    : Car(engine, body, color, manufacturer, model),
    routeNumber(routeNumber), operatorName(operatorName),
    PublicTransport(publicTransport) {}

PublicCar::PublicCar(const PublicCar& other)
    : Car(other.getEngine(), other.getBody(), other.getColor(),
        other.getManufacturer(), other.getModel()),
    routeNumber(other.routeNumber), operatorName(other.operatorName),
    PublicTransport(other) {}

int PublicCar::getRouteNumber() const {
        return routeNumber;
}

void PublicCar::setRouteNumber(int routeNumber) {
        this->routeNumber = routeNumber;
}

string PublicCar::getOperatorName() const {
    return operatorName;
}

void PublicCar::setOperatorName(std::string operatorName) {
    this->operatorName = operatorName;
}

void PublicCar::writeToFile(string filename) {
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << "City name: " << this->getCityName() << endl;
        outFile << "Passenger capacity: " << this->getPassengerCapacity() << endl;

        outFile << "Manufacturer: " << this->getManufacturer() << endl;
        outFile << "Model: " << this->getModel() << endl;

        outFile << "Route number: " << this->getRouteNumber() << endl;
        outFile << "Operator name: " << this->getOperatorName() << endl;

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

void PublicCar::printInformation() {
    cout << "\nCity name: " << this->getCityName() << endl;
    cout << "Passenger capacity: " << this->getPassengerCapacity() << endl;

    cout << "Manufacturer: " << this->getManufacturer() << endl;
    cout << "Model: " << this->getModel() << endl;

    cout << "Route number: " << this->getRouteNumber() << endl;
    cout << "Operator name: " << this->getOperatorName() << endl;

    cout << "Body Type: " << this->getBody().getBodyType() << endl;
    cout << "Body material: " << this->getBody().getMaterial() << endl;

    cout << "Color: " << this->getColor().getColor() << endl;
    cout << "Brightness: " << this->getColor().getBrightness() << endl;

    cout << "Engine type: " << this->getEngine().getEngineType() << endl;
    cout << "Engine power: " << this->getEngine().getPower() << endl << endl;
}

//PersonalCar
PersonalCar::PersonalCar() : yearOfManufacture(0), registrationNumber("") {}

PersonalCar::PersonalCar(const Engine& engine, const Body& body, const Color& color,
    string manufacturer, string model,
    int yearOfManufacture, string registrationNumber,
    const PersonalTransport& personalTransport)
    : Car(engine, body, color, manufacturer, model),
    yearOfManufacture(yearOfManufacture), registrationNumber(registrationNumber),
    PersonalTransport(personalTransport) {}

PersonalCar::PersonalCar(const PersonalCar& other)
    : Car(other.getEngine(), other.getBody(), other.getColor(),
        other.getManufacturer(), other.getModel()),
    yearOfManufacture(other.yearOfManufacture), registrationNumber(other.registrationNumber),
    PersonalTransport(other) {}

int PersonalCar::getYearOfManufacture() const {
    return yearOfManufacture;
}

void PersonalCar::setYearOfManufacture(int yearOfManufacture) {
        this->yearOfManufacture = yearOfManufacture;
}

string PersonalCar::getRegistrationNumber() const {
    return registrationNumber;
}

void PersonalCar::setRegistrationNumber(string registrationNumber) {
    this->registrationNumber = registrationNumber;
}

void PersonalCar::writeToFile(string filename) {
    ofstream outFile(filename);
    if (outFile.is_open())
    {
        outFile << "Owner name: " << this->getOwnerName() << endl;
        outFile << "Has insurance: " << (this->getHasInsurance() ? "Yes" : "No") << endl;

        outFile << "Manufacturer: " << this->getManufacturer() << endl;
        outFile << "Model: " << this->getModel() << endl;

        outFile << "Year of manufacture: " << this->getYearOfManufacture() << endl;
        outFile << "Registration number: " << this->getRegistrationNumber() << endl;

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

void PersonalCar::printInformation() {
    cout << "\nOwner name: " << this->getOwnerName() << endl;
    cout << "Has insurance: " << (this->getHasInsurance() ? "Yes" : "No") << endl;

    cout << "Manufacturer: " << this->getManufacturer() << endl;
    cout << "Model: " << this->getModel() << endl;

    cout << "Year of manufacture: " << this->getYearOfManufacture() << endl;
    cout << "Registration number: " << this->getRegistrationNumber() << endl;

    cout << "Body Type: " << this->getBody().getBodyType() << endl;
    cout << "Body material: " << this->getBody().getMaterial() << endl;

    cout << "Color: " << this->getColor().getColor() << endl;
    cout << "Brightness: " << this->getColor().getBrightness() << endl;

    cout << "Engine type: " << this->getEngine().getEngineType() << endl;
    cout << "Engine power: " << this->getEngine().getPower() << endl << endl;
}