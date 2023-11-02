#include "libs.h"

bool GetBoolAnswer(string answer) {
    bool isTrue = false;
    while (true) {
        try {
            if (answer == "Y" || answer == "y") {
                isTrue = true;
                break;
            }
            else if (answer == "N" || answer == "n") {
                isTrue = false;
                break;
            }
            else {
                throw std::invalid_argument("Invalid answer. Please try again.");
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            cin >> answer;
            cin.ignore();
        }
    }
    return isTrue;
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
                throw std::invalid_argument("Invalid answer. Please try again.");
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return num;
}
