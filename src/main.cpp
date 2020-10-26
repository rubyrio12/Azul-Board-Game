#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <errno.h> 
#include <limits.h>
#include "Types.h"
#include "Game.h"
#include "AdvancedGame.h"
#include "Player.h"
#include "AdvancedPlayer.h"
#include "utils.h"
#include "Score.h"

[[noreturn]] void showMenu();
[[noreturn]] void showSeededMenu(int seed);
[[noreturn]] void showAdvancedMenu();
void showCredits();
void playGame();
void playAdvancedGame();
void loadGame();
void loadAdvancedGame();
void playSeededGame(int seed);
std::vector<Player *> createPlayersFromUserInput();
std::vector<AdvancedPlayer *> createAdvancedPlayersFromUserInput();
bool isNameValid(const std::string &name);
void engageTestMode(char* fileName);
int seed;

int main(int argc, char ** argv) {
    // Check number of argument
    if (argc == 1){
        // No additional arguments shows menu
        showMenu();
    }

    else if (argc == 2){
    const std::string advancedMode = "--adv";
        if (argv[1] == advancedMode){
            showAdvancedMenu();
        }

        else {
                seed = atoi(argv[2]);
                showSeededMenu(seed);
            } 
        }
    
    else if (argc == 3){
        // 2 additional arguments directs to test mode
        const std::string testFlag = "-t";
        const std::string seededFlag = "-s";
        

        // Check for Flag
        if (argv[1] == testFlag){
            // If File Exists
            if (checkIfFileExists(argv[2])){
                engageTestMode(argv[2]);
            }
            else {
                std::cout << "No such file exists!" << std::endl;
            }
        }

        // Check for Flag
        else if (argv[1] == seededFlag){
            errno = 0;
            int conv = atoi(argv[2]);

            if (errno != 0 || conv > INT_MAX) {
                std::cout << "Wrong Seed Type" << std::endl;
                std::cout << "./azul -s <int> to specify a seed to turn off randomness" << std::endl;
            } 
            else {
                seed = atoi(argv[2]);
                showSeededMenu(seed);
            } 
        }
        else {
            std::cout << "Wrong flag" << std::endl;
        }
    }
    else {
        std::cout << "Invalid number of arguments" << std::endl;
        std::cout << "./azul to run" << std::endl;
        std::cout << "./azul -t <testfile> to engage test mode" << std::endl;
        std::cout << "./azul -s <int> to specify a seed to turn off randomness" << std::endl;
    }
    return EXIT_SUCCESS;
}

/**
 * Displays Basic Menu
 */
[[noreturn]] void showMenu() {
    // Welcome message
    std::cout << "Welcome to Azul!" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << std::endl;

    while (true) {
        // Print Menu Contents
        std::cout << "Menu" << std::endl;
        std::cout << "-----" << std::endl;
        std::cout << "1. New Game" << std::endl;
        std::cout << "2. Load Game" << std::endl;
        std::cout << "3. Credits" << std::endl;
        std::cout << "4. Quit" << std::endl;

        std::cout << std::endl;
        std::cout << "> ";

        // Getting user input
        int choice;
        std::cin >> choice;

        // Check end of file
        if (std::cin.eof()) {
            quitGame();
        }

        // Check fail conditions
        else if (std::cin.fail() || choice < 0 || choice > 4) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong Input. Please enter an integer number from 1 to 4" << std::endl;
            std::cout << std::endl;

        } else {
            if (choice == 1) {
                playGame();
            } else if (choice == 2) {
                loadGame();
            } else if (choice == 3) {
                showCredits();
            } else if (choice == 4) {
                quitGame();
            }
        }
    }
}

/**
 * Displays Menu to run Advanced Azul
 */
[[noreturn]] void showAdvancedMenu() {
    // Welcome message
    std::cout << "Welcome to Azul!" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << std::endl;

    while (true) {
        // Print Menu Contents
        std::cout << "Menu" << std::endl;
        std::cout << "-----" << std::endl;
        std::cout << "1. New Advanced Game" << std::endl;
        std::cout << "2. Load Game" << std::endl;
        std::cout << "3. Credits" << std::endl;
        std::cout << "4. Quit" << std::endl;

        std::cout << std::endl;
        std::cout << "> ";

        // Getting user input
        int choice;
        std::cin >> choice;

        // Check end of file
        if (std::cin.eof()) {
            quitGame();
        }

        // Check fail conditions
        else if (std::cin.fail() || choice < 0 || choice > 4) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong Input. Please enter an integer number from 1 to 4" << std::endl;
            std::cout << std::endl;

        } else {
            if (choice == 1) {
                playAdvancedGame();
            } else if (choice == 2) {
                loadAdvancedGame();
            } else if (choice == 3) {
                showCredits();
            } else if (choice == 4) {
                quitGame();
            }
        }
    }
}

/**
 * Displays Menu that incorporates user's seed
 */
[[noreturn]] void showSeededMenu(int seed) {
    // Welcome message
    std::cout << "Welcome to Azul!" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << std::endl;

    while (true) {
        // Print Menu Contents
        std::cout << "Menu" << std::endl;
        std::cout << "-----" << std::endl;
        std::cout << "1. New Game" << std::endl;
        std::cout << "2. Load Game" << std::endl;
        std::cout << "3. Credits" << std::endl;
        std::cout << "4. Quit" << std::endl;

        std::cout << std::endl;
        std::cout << "> ";

        // Getting user input
        int choice;
        std::cin >> choice;

        // Check end of file
        if (std::cin.eof()) {
            quitGame();
        }

        // Check fail conditions
        else if (std::cin.fail() || choice < 0 || choice > 4) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong Input. Please enter an integer number from 1 to 4" << std::endl;
            std::cout << std::endl;

        } else {
            if (choice == 1) {
                playSeededGame(seed);
            } else if (choice == 2) {
                loadGame();
            } else if (choice == 3) {
                showCredits();
            } else if (choice == 4) {
                quitGame();
            }
        }
    }
}
/**
 * Display the information of the authors of this program
 */
void showCredits() {
    std::cout << "--------------------------" << std::endl;
    std::cout << "Name: Anh Nguyen" << std::endl;
    std::cout << "Student ID: s3616128" << std::endl;
    std::cout << "Email: s3616128@rmit.edu.vn" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Name: Mitchell Gust" << std::endl;
    std::cout << "Student ID: s3782095" << std::endl;
    std::cout << "Email: s3782095@student.rmit.edu.au" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Name: Ruby Rio" << std::endl;
    std::cout << "Student ID: s3786695" << std::endl;
    std::cout << "Email: s3786695@student.rmit.edu.au" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << std::endl;
}

/**
 * This function will initialize an Azul game
 */
void playGame() {
    std::cout << std::endl;
    std::cout << "Starting a new Azul game" << std::endl;
    std::cout << std::endl;

    // Game Initialization
    auto game = new Game();
    int seed = (time(NULL));
    game->addPlayers(createPlayersFromUserInput());
    game->setTileBagSeeded(seed);

    std::cout << "Let's Play!" << std::endl;
    std::cout << std::endl;

    // Play the game
    game->play();

    std::cout << "=== Game Over ===" << std::endl;
    std::cout << "=== Scoreboard ===" << std::endl;

    // Print Scores
    game->printFinalResults();

}

/**
 * This function will initialize an Advanced Azul game
 */
void playAdvancedGame() {
    std::cout << std::endl;
    std::cout << "Starting a new Azul game" << std::endl;
    std::cout << std::endl;

    // Game Initialization
    auto game = new AdvancedGame();
    int seed = (time(NULL));
    game->addPlayers(createAdvancedPlayersFromUserInput());
    game->setTileBagSeeded(seed);

    std::cout << "Let's Play!" << std::endl;
    std::cout << std::endl;

    // Play the game
    game->play();

    std::cout << "=== Game Over ===" << std::endl;
    std::cout << "=== Scoreboard ===" << std::endl;

    // Print Scores
    game->printFinalResults();

}

/**
 * This function will initialize a Seeded Azul game
 */
void playSeededGame(int seed) {
    std::cout << std::endl;
    std::cout << "Starting a new Azul game" << std::endl;
    std::cout << std::endl;

    // Game Initialization
    auto game = new Game();
    game->addPlayers(createPlayersFromUserInput());
    game->setTileBagSeeded(seed);

    std::cout << "Let's Play!" << std::endl;
    std::cout << std::endl;

    // Play the game
    game->play();

    std::cout << "=== Game Over ===" << std::endl;
    std::cout << "=== Scoreboard ===" << std::endl;

    // Print Scores
    game->printFinalResults();

}

/**
 * This functional will load an Azul game from a file
 */
void loadGame() {

    bool valid = false;
    std::string fileName;
    
    // Clear input
    std::cin.clear();
    std::cin.ignore(10000, '\n');

    std::cout << "Enter the name of save file: " << std::endl;
    while (!valid){

        std::cout << "> ";

        // Grab file name
        getline(std::cin, fileName);

        // Check EOF
        if (!std::cin){
            quitGame();
        }
        // Check if file exists
        if (checkIfFileExists(fileName.c_str())){
            // Break loop
            valid = true;
        }
        else {
            // Display error message
            std::cout << "No such file exists. Please try again!" << std::endl;
        }
    }

    // Initialize New Game
    auto game = new Game();
    // Load game from file
    game->load(fileName);
}

/**
 * This function will load an Advanced Azul game from a file
 */
void loadAdvancedGame() {

    bool valid = false;
    std::string fileName;
    
    // Clear input
    std::cin.clear();
    std::cin.ignore(10000, '\n');

    std::cout << "Enter the name of save file: " << std::endl;
    while (!valid){

        std::cout << "> ";

        // Grab file name
        getline(std::cin, fileName);

        // Check EOF
        if (!std::cin){
            quitGame();
        }
        // Check if file exists
        if (checkIfFileExists(fileName.c_str())){
            // Break loop
            valid = true;
        }
        else {
            // Display error message
            std::cout << "No such file exists. Please try again!" << std::endl;
        }
    }

    // Initialize New Game
    auto game = new AdvancedGame();
    // Load game from file
    game->load(fileName);
}
/**
 * Check if a player's name is valid
 * @param name
 * @return valid: true if valid, false if invalid
 */
bool isNameValid(const std::string &name) {
    bool valid = true;
    if (name.empty()) {
        valid = false;
    }
    return valid;
}

/**
 * Create a player vector based on stdin
 * @return a vector of player objects
 */
std::vector<Player *> createPlayersFromUserInput() {
    // A vector to store player objects
    std::vector<Player *> players;

    // Player counter
    int playerCount = 1;
    // Clear input
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    // End loop when num of players exceeds the ceiling
    while (playerCount <= NUM_OF_PLAYERS) {
        std::string name;
        std::string savedName;
        std::cout << "Enter a name for player " << playerCount << std::endl;
        std::cout << "> ";

        getline(std::cin, name);
        std::cout << std::endl;

        // Check end of file
        if (std::cin.eof()) {
            quitGame();
        }
        // Validate input
        else if (isNameValid(name)) {
            // Increase count by one

            // Initialize and add player object to the vector
            if (playerCount == 1){
                players.push_back(new Player(name, playerCount, true));
            }
            else {
                players.push_back(new Player(name, playerCount, false));
            }
            playerCount++;
        } else {
            std::cout << "Invalid name. Please try again" << std::endl;
        }
    }
    return players;
}

std::vector< AdvancedPlayer *> createAdvancedPlayersFromUserInput() {
    // A vector to store player objects
    std::vector<AdvancedPlayer *> players;

    // Player counter
    int playerCount = 1;
    // Clear input
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    // End loop when num of players exceeds the ceiling
    while (playerCount <= NUM_OF_PLAYERS) {
        std::string name;
        std::string savedName;
        std::cout << "Enter a name for player " << playerCount << std::endl;
        std::cout << "> ";

        getline(std::cin, name);
        std::cout << std::endl;

        // Check end of file
        if (std::cin.eof()) {
            quitGame();
        }
        // Validate input
        else if (isNameValid(name)) {
            // Increase count by one

            // Initialize and add player object to the vector
            if (playerCount == 1){
                players.push_back(new AdvancedPlayer(name, playerCount, true));
            }
            else {
                players.push_back(new AdvancedPlayer(name, playerCount, false));
            }
            playerCount++;
        } else {
            std::cout << "Invalid name. Please try again" << std::endl;
        }
    }
    return players;
}

void engageTestMode(char* fileName){
    // Initialize New Game
    auto game = new Game();
    // Load game from file
    game->testLoadGame(fileName);

}
