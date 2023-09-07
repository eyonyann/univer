#include "libs.h"
#include "classes.h"

void createCar(vector<Vehicle*>& vehicles)
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
}

void createAirplane(vector<Vehicle*>& vehicles)
{
    string material, model, manufacturer;
    float wingspan, maxSpeed;

    cout << "Enter Airplane details:\n";
    cout << "Material: ";
    cin >> material;
    cout << "Model: ";
    cin >> model;
    cout << "Manufacturer: ";
    cin >> manufacturer;
    cout << "Wingspan (meters): ";
    cin >> wingspan;
    cout << "Max Speed (km/h): ";
    cin >> maxSpeed;

    vehicles.push_back(new Airplane(material, model, manufacturer, wingspan, maxSpeed));
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
