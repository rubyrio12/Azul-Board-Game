#include "AdvancedPlayer.h"
#include "LinkedList.h"
#include <vector>
#include "utils.h"
#include <iostream>
#include "Types.h"
#include <algorithm>
#include "Score.h"

class AdvancedGame
{
public:
    
    /*
    * Default Constructor
    */
    AdvancedGame();

    /*
    *  Deconstructor
    */
    ~AdvancedGame();

    /*
    * The initilisation of the Game.
    * This method aims to set up the physicals of the game, such as the Factories and Mosaics.
    */
    void play();

    /*
    * Translates up-to-date information from the user into a file which can be recalled from main to
    * continue playing where left off
    */
    void save(const std::string & fileName, std::vector<std::string> vector);

    /*
    * Reads file previously saved, and translates information in to resume an old game from where it
    * was left off
    */
    void load(const std::string & fileName);

    /*
    * Adds inserted player names into the initialised Vector to hold them as players of the current game
    */
    void addPlayers(std::vector<AdvancedPlayer*> p);

    /**
    * Returns all players in the current game
    * @return : vector of players
    */
    std::vector<AdvancedPlayer*> getPlayers();

    /*
    * Fills Tile Bag with predefined list of tiles
    */
    void setTileBagRandomly();

    /**
    * Returns contents of Tile Bag
    * @return : tile bag
    */
    LinkedList<Tile *> * getTileBag();

    /**
    * Returns contents of Box Lid
    * @return : box lid
    */
    LinkedList<Tile *> * getBoxLid();

    /*
    * Places 'F' Tile to the centre factory
    */
    void addFirstTileToCenter();

    /**
    * Fills Tile Bag with a list of tiles determined by a String input
    * @param line : string to be parsed
    */
    void setTileBagFromString(const std::string & line);

    /*
    * Administers the turn dependent on what the User has entered in the command line
    */
    void execute(const std::string & command, AdvancedPlayer * player);

    /*
    * Fills factories dependent on the Tile Bag Content
    */
    void fillFactories();

    /*
    * Amends factories and rows back to their state at the beginning of the game
    */
    void reset(LinkedList<Tile *> *tileBag);

    /*
    * Returns and Prints list of all factories to the Terminal
    */
    void printFactories();

    /**
    * Checks the status of Centre factory
    * @return true if empty, false if not;
    */
    bool isCenterEmpty();

    /**
    * Checks the status of all factories.
    * @return true if empty, false if not;
    */
    bool areFactoriesEmpty();

    /**
    * Checks the status of a particular factory. 
    * @return true if empty, false if not;
    */
    bool isAFactoryEmpty(int factory);

    /**
     * Reads the input provided by the User into Terminal; Boundary and type validation
     * @param input : input string to be checked
     * @return : a vector containing errors of the player's input
     */
    std::vector<std::string> checkInput(std::string input, AdvancedPlayer * player);

    /**
    * Checks whether a particular tile exsists in a particular factory
    * @return true if it exists, false if not
    */
    bool tileExistsInAFactory(const char & tile, int factory);

    /*
    * Returns a char relating to the colour assigned to a particular Mosaic row
    */
    char getColorOfaRow(int row, AdvancedPlayer * player);

    /*
    * Returns a string containing the colour of the grid
    */
    std::string getGridColor(int row, AdvancedPlayer * player);

    /**
    * Checks whether a row has been filled.
    * @return true if full, false if not;
    */
    bool isRowFull(int row, AdvancedPlayer * player);

    /**
    * Checks whether the end of a round is reached.
    * @return true if round is over, false if not;
    */
    bool endRound();

    /**
    * Checks whether a tile is marked to be removed.
    * @return true if marked, false if not;
    */
    bool markedToBeDeleted(Tile* tile, char color);

    /*
    * Testing method to review the status of the load game functionality
    */
    void testLoadGame(char* fileName);

    /*
    * Prints out the status of the game at execution
    */
    void printGameState();

    /**
    * Removes point from Player's score depending on their number of broken tiles
    * @param player : Us
    */
    void deductBrokenTile(AdvancedPlayer * player);

    /**
     * Print final result of the game
     */
    void printFinalResults();

    /**
     * Print players' score
     */
    void printScores();

    /**
    * Files tile bag and then calles shuffle algorithm 
    * depending on a number generated or received on run time from the Main class
    * @param tileBag : Linked List structure to be shuffled
    * @param n : seed which to be shuffled by
    */
    void seedTileBag(LinkedList<Tile *> *tileBag, int n);

    /**
    * Swaps two positions within the Linked List
    * @param a : First Position
    * @param b : Second Position
    */
    void swap(Tile* a, Tile* b);

    /**
     * Checks whether Tile Bag contents have hit 0
     */
    bool isTileBagEmpty();

    /**
    * Adds F tile to the Tile Bag
    * @param tileBag : Tile Bag to be manipulated
    */
    void addFirstPlayerTile(LinkedList<Tile *> *tileBag);

    /**
    * Sets contents of Tile Bag based on a number
    * @param seed : seed in question
    */
    void setTileBagSeeded(int seed);

    /**
    * Refills the Tile Bag from the Box Lid when its contents have reached 0
    * @param tileBag : Tile Bag to be filled
    * @param seed : number by which the contents are shuffled
    */
    void fillTileBagFromBoxLid(LinkedList<Tile *> *tileBag, int seed);

    /**
    * Places Tiles down on board via human entry at end of round
    * @param command : instruction from user
    * @param player : user in question
    */
    void placeTiles(const std::string & command, AdvancedPlayer * player);

    /**
    * Checks instruction entered by user to assure a valid entry
    * @param input : instruction from user
    * @param player : user in question
    * @return string containing errors (if present)
    */
    std::vector<std::string> checkPlacement(std::string input, AdvancedPlayer * player);

    /**
    * Checks whether a colour is present in a row
    * @param tile : Colour in question
    * @param row : Row in question
    * @param player: Player whos grid is in question
    * @return true if it exists, false if no
    */
    bool tileExistsInARow(const char & tile, int row, AdvancedPlayer *player);

    /**
    * Prints the final scores
    * @param player1 : First Player
    * @param player2 : Second Player
    */
    void printAdvancedScores(AdvancedPlayer * player1, AdvancedPlayer * player2);




private:
    // Stores all game players
    std::vector<AdvancedPlayer*> players;

    // Structure of Tile Bag
    LinkedList<Tile*> * tileBag;

    //Structure of Box Lid
    LinkedList<Tile*> * boxLid;

    // Factories
    Tile ** factories;

    // Stores Tiles assigned to Centre Factory
    std::vector<Tile*> center;

    // Coordinates of Rcently Placed Tile
    int placedTileX;
    int placedTileY;
};

