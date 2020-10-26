#ifndef COSC_ASSIGN_TWO_ADV_PLAYER
#define COSC_ASSIGN_TWO_ADV_PLAYER

#include <string>
#include "Tile.h"
#include "Types.h"
#include <iostream>

class AdvancedPlayer
{
public:

    /**
    * Default Constructor
    */
    AdvancedPlayer();

    /**
    * Copy Constructor
    * @param name : Player name to be copied
    * @id : an unique id
    * @f : true if the player will play first
    */
    AdvancedPlayer(std::string name, int id, bool f);

    /*
    * Deconstructor
    */
    ~AdvancedPlayer();

    /**
    * Copy Constructor for Player Saving
    * @param other : Player to be saved
    */
    AdvancedPlayer(AdvancedPlayer &other);

    /**
    * Add current round score to previous score
    * @param s : value to be added
    */
    void addScore(int s);

    /**
    * Set current round score
    * @param s : value to be set
    */
    void setScore(int s);

    /**
    * Return current player's score
    * @return int score
    */
    int getScore();

    /*
    * Set score back to initial value
    */
    void resetScore();

    /**
    * Return current player's name
    * @return : std::string name
    */
    std::string getName();

    /*
    * Return and Print Mosaic to Console
    */
    void printMosaic();

    /*
    * Return and Print Broken Row to Console
    */
    void printBrokenRow();

    /**
    * Add tile to player's broken row
    * @param tile : char to be added to broken row
    */
    void addToBrokenRow(char tile);

    /**
    * Fetch Player's Unlaid Row
    * @return : Tile
    */
    Tile ** getUnlaidRow();

    /**
    * Fetch Player's Grid
    * @return : Tile
    */
    Tile ** getGrid();

    /**
    * Fetch Player's Broken Row
    * @return : Tile
    */
    Tile* getBrokenRow();

    /**
    * Return number of Tile's in Player's Broken Row
    * @return : int brokenRowCount
    */
    int getBrokenRowCount();

    /**
    * Set players broken row
    * @param count : length broken row it to be set to
    */
    void setBrokenRowCount(int count);

    /**
     * Return whether or not the player will play first in a round
     * @return true if first, false if second
     */
    bool isFirst();

    /**
     * Set first value
     * @param f
     */
    void setFirst(bool f);

    /**
     * Return unique if of a player
     * @return
     */
    int getId();

private:
    std::string name;
    int score;
    int rowCount;
    bool first;
    int id;
    Tile ** grid;
    Tile ** unlaidRow;
    Tile brokenRow[ADV_BROKEN_ROW_SIZE];
    int brokenRowCount;
}; 
#endif