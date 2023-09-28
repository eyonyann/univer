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

bool GetBoolAnswer(string answer);
int GetIntNumber();
float GetFloatNumber();
bool IsElementInVehicles(vector<Vehicle*>& vehicles, string vehicleName);
string GetUniqueVehicleName(vector<Vehicle*>& vehicles, string vehicleName);

void CreateMilitaryCar(vector<Vehicle*>& vehicles)
{
    string vehicleName, carType, armoredAnswer, manufacturer, model, nameOfMilitaryUnit, countryOfOrigin, 
        bodyType, bodyMaterial, colorName, engineType;

    float enginePower;
    bool isArmored = false;
    int brightness;

    Engine engine;
    Body body;
    Color color;

    cout << "\nEnter Car details:\n";
    cin.ignore();

    cout << "Vehicle unique name: ";
    getline(cin, vehicleName);
    vehicleName = GetUniqueVehicleName(vehicles, vehicleName);

    cout << "Military car type: ";
    getline(cin, carType);
    cout << "Is Armored(y/n): ";
    getline(cin, armoredAnswer);
    isArmored = GetBoolAnswer(armoredAnswer);

    cout << "Manufacturer: ";
    getline(cin, manufacturer);
    cout << "Model: ";
    getline(cin, model);

    cout << "Name of military unit: ";
    getline(cin, nameOfMilitaryUnit);

    cout << "Country of origin: ";
    getline(cin, countryOfOrigin);

    cout << "Body Type: ";
    getline(cin, bodyType);

    cout << "Body material: ";
    getline(cin, bodyMaterial);

    cout << "Color: ";
    getline(cin, colorName);
    cout << "Brightness(0-100): ";
    brightness = GetIntNumber();
    cin.ignore();

    cout << "Engine Type: ";
    getline(cin, engineType);
    cout << "Engine Power (HP): ";
    enginePower = GetFloatNumber();

    engine.setEngineType(engineType);
    engine.setPower(enginePower);

    color.setColor(colorName);
    color.setBrightness(brightness);

    body.setBodyType(bodyType);
    body.setMaterial(bodyMaterial);

    MilitaryCar* militaryCar = new MilitaryCar(vehicleName, engine, body, color, manufacturer, 
        model, carType, isArmored, countryOfOrigin, nameOfMilitaryUnit);

    vehicles.push_back(militaryCar);
}


void DisplayVehicles(const vector<Vehicle*>& vehicles)
{
    cout << "\nAll Vehicles:\n";
    for (int i = 0; i < vehicles.size(); i++)
    {
        vehicles[i]->printInformation();
    }
}

void ModifyParameters(vector<Vehicle*>& vehicles)
{
    string name = "";
    int vehicleIndex;

    if (vehicles.empty()) {
        cout << "\nNo vehicles to modify." << endl;
        return;
    }

    cout << "\nEnter name of a vehicle to modify: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;
    for (int i = 0; i < vehicles.size(); i++)
    {
        if (vehicles[i]->getVehicleName() == name)
        {
            vehicleIndex = i;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nVehicle not found.\n";
        return;
    }

    while (true)
    {
        cout << "\nWhat you want to change:" << endl;
        cout << "1. Vehicle name" << endl;
        cout << "2. Body" << endl;
        cout << "3. Engine" << endl;
        cout << "4. Color" << endl;
        cout << "5. Come back\n" << endl;

        int choice;
        choice = GetIntNumber();

        switch (choice)
        {
        case 1:
        {
            cout << "Enter new vehicle name: ";
            cin.ignore();
            string newName;
            getline(cin, newName);
            vehicles[vehicleIndex]->setVehicleName(newName);
            cout << "Vehicle name updated.\n";
        }
        break;

        case 2:
        {
            string newBodyType, newMaterial;
            cout << "Enter new body type: ";
            cin.ignore();
            getline(cin, newBodyType);

            cout << "Enter new material: ";
            getline(cin, newMaterial);

            vehicles[vehicleIndex]->setBody(Body(newBodyType, newMaterial));

            cout << "Body Type updated.\n";
        }
        break;

        case 3:
        {
            string newEngineType;
            float newEnginePower;
            cout << "Enter new engine type: ";
            cin.ignore();
            getline(cin, newEngineType);

            cout << "Enter new engine power: ";
            newEnginePower = GetFloatNumber();
            cin.ignore();

            vehicles[vehicleIndex]->setEngine(Engine(newEnginePower, newEngineType));

            cout << "Engine updated.\n";
        }
        break;

        case 4:
        {
            string newColor;
            int newBrightness;
            cout << "Enter new color name: ";
            cin.ignore();
            getline(cin, newColor);

            cout << "Enter new brightness: ";
            newBrightness = GetIntNumber();
            cin.ignore();

            vehicles[vehicleIndex]->setColor(Color(newColor, newBrightness));

            cout << "Color updated.\n";
        }
        break;

        case 5:
            return;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }
}


void SearchVehicle(vector<Vehicle*>& vehicles)
{
    string searchName;
    cout << "\nEnter the the name of the vehicle to search for: ";
    cin >> searchName;

    bool found = false;
    for (int i = 0; i < vehicles.size(); i++)
    {
        if (vehicles[i]->getVehicleName() == searchName)
        {
            cout << "\nVehicle found:\n";
            vehicles[i]->printInformation();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nVehicle not found.\n";
    }
}

bool GetBoolAnswer(string answer)
{
    bool isArmored = false;
    while (true)
    {
        if (answer == "Y" || answer == "y")
        {
            isArmored = true;
            break;
        }
            
        else if (answer == "N" || answer == "n")
        {
            isArmored = false;
            break;
        }
        else
        {
            cout << "\nInvalid answer. Please try again.\n";
            cin >> answer;
            cin.ignore();
        }
    }
    return isArmored;
}

int GetIntNumber() {
    int num;
    string numStr;

    while (true) {
        cin >> numStr;

        try {
            num = stoi(numStr);
            if (num >= 0 && num <= 100) {
                break; 
            }
            else {
                cout << "Invalid answer. Please try again.\n";
            }
        }
        catch (const exception& e) {
            cout << "Invalid answer. Please try again.\n";
        }
    }

    return num;
}

float GetFloatNumber() {
    float num;
    string numStr;

    while (true) {
        cin >> numStr;

        try {
            num = stof(numStr);
            break;
        }
        catch (const exception& e) {
            cout << "Invalid answer. Please try again.\n";
        }
    }

    return num;
}

string GetUniqueVehicleName(vector<Vehicle*>& vehicles, string vehicleName)
{
    while (IsElementInVehicles(vehicles, vehicleName))
    {
        cout << "\nThis name already exists. Please try again.\n";
        getline(cin, vehicleName);
    }

    return vehicleName;
}

bool IsElementInVehicles(vector<Vehicle*>& vehicles, string vehicleName) {
    for (int i = 0; i < vehicles.size(); i++)
    {
        if (vehicles[i]->getVehicleName() == vehicleName)
        {
            return true;
        }
    }
    return false;
}