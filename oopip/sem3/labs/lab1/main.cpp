#include "libs.h"
#include "menu.h"

int main()
{
    vector<Vehicle*> vehicles;

    while (true)
    {
        cout << "\nMenu:\n";
        cout << "1. Create Car\n";
        cout << "2. Create Airplane\n";
        cout << "3. Display All Vehicles\n";
        cout << "4. Modify Vehicle Parameters\n";
        cout << "5. Search for Vehicle (Bubble Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            createCar(vehicles);
            break;

        case 2:
            createAirplane(vehicles);
            break;

        case 3:
            displayVehicles(vehicles);
            break;

        case 4:
            modifyParameters(vehicles);
            break;

        case 5:
            searchVehicle(vehicles);
            break;

        case 6:
            for (int i = 0; i < vehicles.size(); i++)
            {
                vehicles[i]->writeToFile(FILENAME);
                delete vehicles[i];
            }
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    }

    return 0;
}
