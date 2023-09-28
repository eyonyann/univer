#include "libs.h"
#include "menu.h"

int main()
{
    vector<Vehicle*> vehicles;

    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Create a military car" << endl;
        cout << "2. Show All Vehicles" << endl;
        cout << "3. Update Vehicle Information" << endl;
        cout << "4. Find a Vehicle" << endl;
        cout << "5. Exit\n" << endl;

        int choice;
        choice = GetIntNumber();

        switch (choice)
        {
        case 1:
            CreateMilitaryCar(vehicles);
            break;

        case 2:
            DisplayVehicles(vehicles);
            break;

        case 3:
            ModifyParameters(vehicles);
            break;

        case 4:
            SearchVehicle(vehicles);
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
