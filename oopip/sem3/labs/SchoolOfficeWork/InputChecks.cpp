#include "libs.h"

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