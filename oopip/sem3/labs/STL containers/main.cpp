#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <fstream>
#include <algorithm>

class Game {
public:
    std::string title;
    std::string genre;
    int releaseYear;

    Game(const std::string& t, const std::string& g, int year) : title(t), genre(g), releaseYear(year) {}

    Game() : releaseYear(0) {}

    void displayInfo() const {
        std::cout << "Title: " << title << "\tGenre: " << genre << "\tRelease Year: " << releaseYear << std::endl;
    }

    bool operator<(const Game& other) const {
        return title < other.title;
    }

    bool operator==(const Game& other) const {
        return title == other.title;
    }
};

template<typename Container>
void displayContainer(const Container& container) {
    for (const auto& item : container) {
        item.displayInfo();
    }
}

template<typename Container>
void saveToFile(const Container& container, const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& item : container) {
        file << item.title << "," << item.genre << "," << item.releaseYear << "\n";
    }
    file.close();
}

template<typename Container>
void addGame(Container& container) {
    std::string title, genre;
    int releaseYear;
    std::cout << "Enter game title: ";
    std::cin >> title;
    std::cout << "Enter game genre: ";
    std::cin >> genre;
    std::cout << "Enter release year: ";
    std::cin >> releaseYear;

    container.emplace_back(title, genre, releaseYear);
    std::cout << "Game added successfully!\n";
}

template<typename Container>
void deleteGame(Container& container) {
    std::string title;
    std::cout << "Enter the title of the game to delete: ";
    std::cin >> title;

    auto it = std::find_if(container.begin(), container.end(), [&title](const Game& game) {
        return game.title == title;
        });

    if (it != container.end()) {
        container.erase(it);
        std::cout << "Game deleted successfully!\n";
    }
    else {
        std::cout << "Game not found!\n";
    }
}

template<typename Container>
void searchGame(const Container& container) {
    std::string title;
    std::cout << "Enter the title of the game to search: ";
    std::cin >> title;

    auto it = std::find_if(container.begin(), container.end(), [&title](const Game& game) {
        return game.title == title;
        });

    if (it != container.end()) {
        it->displayInfo();
    }
    else {
        std::cout << "Game not found!\n";
    }
}

template<typename Container>
void sortGames(Container& container) {
    container.sort([](const Game& a, const Game& b) {
        return a.title < b.title;
        });
    std::cout << "Games sorted successfully!\n";
}


int main() {
    std::list<Game> gameList;
    std::vector<Game> gameVector;
    std::array<Game, 10> gameArray;

    int choice;

    do {
        std::cout << "\n=== Game Management System ===\n";
        std::cout << "1. Add Game\n";
        std::cout << "2. Delete Game\n";
        std::cout << "3. Display Games\n";
        std::cout << "4. Save to File\n";
        std::cout << "5. Search Game\n";
        std::cout << "6. Sort Games\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addGame(gameList);
            break;
        case 2:
            deleteGame(gameList);
            break;
        case 3:
            displayContainer(gameList);
            break;
        case 4:
            saveToFile(gameList, "games.txt");
            std::cout << "Games saved to file successfully!\n";
            break;
        case 5:
            searchGame(gameList);
            break;
        case 6:
            sortGames(gameList);
            break;
        case 7:
            std::cout << "Exiting program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
