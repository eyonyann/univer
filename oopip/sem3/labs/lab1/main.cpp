#include "libs.h"
#include "menu.h"

int main()
{
    vector<Vehicle*> vehicles;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Create a Vehicle (Public, Personal, Military)" << endl;
        cout << "2. Show All Vehicles" << endl;
        cout << "3. Update Vehicle Information" << endl;
        cout << "4. Find a Vehicle" << endl;
        cout << "5. Exit\n" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1: {
            cout << "\nChoose the type of vehicle:" << endl;
            cout << "1. Public Transport" << endl;
            cout << "2. Personal Transport" << endl;
            cout << "3. Military Transport\n" << endl;

            int vehicleType;
            cin >> vehicleType;

            if (vehicleType == 1) {

            }
            else if (vehicleType == 2) {

            }
            else if (vehicleType == 3) {
                createMilitaryCar(vehicles);
            }
            else {
                cout << "Invalid choice." << endl;
            }
            break;
        }

        case 2:
            displayVehicles(vehicles);
            break;

        case 3:
            modifyParameters(vehicles);
            break;

        case 4:
            searchVehicle(vehicles);
            break;

        case 6:
            for (int i = 0; i < vehicles.size(); i++){
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
