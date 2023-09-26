#include "libs.h"
#include "classes.h"

/*void createCar(vector<Vehicle*>& vehicles)
{
    string material, model, manufacturer, engineType, bodyType, color;
    float power;

    cout << "Enter Car details:\n";
    cout << "Material: ";
    cin >> material;
    cout << "Model: ";
    cin >> model;
    cout << "Manufacturer: ";
    cin >> manufacturer;
    cout << "Engine Type: ";
    cin >> engineType;
    cout << "Body Type: ";
    cin >> bodyType;
    cout << "Color: ";
    cin >> color;
    cout << "Engine Power (HP): ";
    cin >> power;

    vehicles.push_back(new Car(material, model, manufacturer, power, engineType, bodyType, color));
}*/

void createMilitaryCar(vector<Vehicle*>& vehicles)
{
    string carType, armoredAnswer, manufacturer, model, nameOfMilitaryUnit, countryOfOrigin, 
        bodyType, bodyMaterial, colorName, engineType;

    float enginePower;
    bool isArmored;
    int brightness;

    Engine engine;
    Body body;
    Color color;
    MilitaryTransport militaryTransport;

    cout << "\nEnter Car details:\n";

    cout << "Military car type: ";
    cin >> carType;
    cout << "Is Armored(y/n): ";
    cin >> armoredAnswer;

    cout << "Manufacturer: ";
    cin >> manufacturer;
    cout << "Model: ";
    cin >> model;

    cout << "Name of military unit: ";
    cin >> nameOfMilitaryUnit;
    cout << "Country of origin: ";
    cin >> countryOfOrigin;

    cout << "Body Type: ";
    cin >> bodyType;
    cout << "Body material: ";
    cin >> bodyMaterial;

    cout << "Color: ";
    cin >> colorName;
    cout << "Brightness: ";
    cin >> brightness;

    cout << "Engine Type: ";
    cin >> engineType;
    cout << "Engine Power (HP): ";
    cin >> enginePower;

    engine.setEngineType(engineType);
    engine.setPower(enginePower);

    color.setColor(colorName);
    color.setBrightness(brightness);

    body.setBodyType(bodyType);
    body.setMaterial(bodyMaterial);

    militaryTransport.setCountryOfOrigin(countryOfOrigin);
    militaryTransport.setNameOfMilitaryUnit(nameOfMilitaryUnit);

    vehicles.push_back(new MilitaryCar(engine, body, color, manufacturer, model, carType, isArmored, militaryTransport);
}

void createPersonalCar(vector<Vehicle*>& vehicles)
{
    string ownerName, insuranceAnswer, manufacturer, model, yearOfManufacture, registrationNumber,
        bodyType, bodyMaterial, colorName, engineType;

    float enginePower;
    bool hasInsurance;
    int brightness;

    Engine engine;
    Body body;
    Color color;
    PersonalTransport personalTransport;

    cout << "\nEnter Car details:\n";

    cout << "Owner name: ";
    cin >> ownerName;
    cout << "Has insurance(y/n): ";
    cin >> insuranceAnswer;

    cout << "Manufacturer: ";
    cin >> manufacturer;
    cout << "Model: ";
    cin >> model;

    cout << "Year of manufacture: ";
    cin >> yearOfManufacture;
    cout << "Registration number: ";
    cin >> registrationNumber;

    cout << "Body Type: ";
    cin >> bodyType;
    cout << "Body material: ";
    cin >> bodyMaterial;

    cout << "Color: ";
    cin >> colorName;
    cout << "Brightness: ";
    cin >> brightness;

    cout << "Engine Type: ";
    cin >> engineType;
    cout << "Engine Power (HP): ";
    cin >> enginePower;

    engine.setEngineType(engineType);
    engine.setPower(enginePower);

    color.setColor(colorName);
    color.setBrightness(brightness);

    body.setBodyType(bodyType);
    body.setMaterial(bodyMaterial);

    militaryTransport.setCountryOfOrigin(countryOfOrigin);
    militaryTransport.setNameOfMilitaryUnit(nameOfMilitaryUnit);

    vehicles.push_back(new MilitaryCar(engine, body, color, manufacturer, model, carType, isArmored, militaryTransport);
}


void displayVehicles(const vector<Vehicle*>& vehicles)
{
    cout << "\nAll Vehicles:\n";
    for (int i = 0; i < vehicles.size(); i++)
    {
        vehicles[i]->printInformation();
    }
}

void modifyParameters(vector<Vehicle*>& vehicles)
{
    // ... (implementation as before)
}

void searchVehicle(vector<Vehicle*>& vehicles)
{
    string searchMaterial;
    cout << "Enter the material to search for: ";
    cin >> searchMaterial;

    //// Bubble sort to sort vehicles by make
    //for (size_t i = 0; i < vehicles.size() - 1; i++)
    //{
    //    for (size_t j = 0; j < vehicles.size() - i - 1; j++)
    //    {
    //        if (vehicles[j]->getMake() > vehicles[j + 1]->getMake())
    //        {
    //            swap(vehicles[j], vehicles[j + 1]);
    //        }
    //    }
    //}

    bool found = false;
    for (int i = 0; i < vehicles.size(); i++)
    {
        if (vehicles[i]->getMaterial() == searchMaterial)
        {
            cout << "Vehicle found:\n";
            vehicles[i]->printInformation();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Vehicle not found.\n";
    }
}
