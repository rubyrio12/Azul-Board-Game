#include "AdvancedPlayer.h"

AdvancedPlayer::AdvancedPlayer() {
    name = DEFAULT_NAME;
}

AdvancedPlayer::AdvancedPlayer(std::string name, int id, bool f)
{
    //Declare Variables
    this->name = name;
    this->score = 0;
    this->first = false;
    this->brokenRowCount = 0;
    this->id = id;
    this->first = f;

    // Declare grid
    grid = new Tile*[ADV_MOSAIC_DIM];
    for (int i = 0; i < ADV_MOSAIC_DIM; ++i) {
        grid[i] = new Tile[ADV_MOSAIC_DIM];
    }

    // Index of board color
    int count = 0;
    // Initialize Grid
    for (int i = 0; i < ADV_MOSAIC_DIM; ++i) {
        for (int j = 0; j < ADV_MOSAIC_DIM; ++j) {
            grid[i][j] = *new Tile(ADV_MOSAIC_BOARD[count]);
            count++;
        }
    }

    // Declare unlaid row
    unlaidRow = new Tile*[ADV_MOSAIC_DIM];
    rowCount = 1;
    for (int i = 0; i < ADV_MOSAIC_DIM; ++i) {
        unlaidRow[i] = new Tile[rowCount];
        rowCount++;
    }

    // Initialize unlaid row
    rowCount = 1;
    for (int i = 0; i < ADV_MOSAIC_DIM; ++i) {
        for (int j = 0; j < rowCount; ++j) {
            unlaidRow[i][j] = *new Tile('.');
        }
        rowCount++;
    }

    // Initilize broken row
    for (int i = 0; i < ADV_BROKEN_ROW_SIZE; ++i) {
        brokenRow[i] = *new Tile(' ');
    }
}

AdvancedPlayer::AdvancedPlayer(AdvancedPlayer &other) : name(other.name){
}

AdvancedPlayer::~AdvancedPlayer()
{
    // Delete grid
    for (int i = 0; i < ADV_MOSAIC_DIM; ++i) {
        delete grid[i];
    }
    delete [] grid;

    // Delete unlaidrow
    for (int i = 0; i < ADV_MOSAIC_DIM; ++i) {
        delete unlaidRow[i];
    }
    delete [] unlaidRow;
}

std::string AdvancedPlayer::getName(){
    return name;
}

void AdvancedPlayer::addScore(int s) {
    score += s;
}

void AdvancedPlayer::setScore(int s) {
    if (s < 0){
        // Score cannot go below zero
        score = 0;
    }
    else {
        score = s;
    }
}

int AdvancedPlayer::getScore() {
    return score;
}

void AdvancedPlayer::resetScore() {
    score = 0;
}

void AdvancedPlayer::printMosaic() {
    rowCount = 1;
    for (int i = 0; i < ADV_MOSAIC_DIM; ++i) {
        std::cout << i + 1 << ":";
        
        // Print whitespaces
        for (int k = 0; k < ADV_MOSAIC_DIM - rowCount + 1; ++k) {
            std::cout << DOUBLE_WHITESPACE;
        }
        // Print unlaid row
        for (int j = 0; j < rowCount; ++j) {
            std::cout << unlaidRow[i][rowCount - 1 - j].getName() << WHITESPACE;
        }
        std::cout << "|| ";
        // Print grid
        for (int m = 0; m < ADV_MOSAIC_DIM; ++m) {
            if (i == 5){
                std::cout << ORANGE_COLOUR << grid[i][m].getName() << RESET << WHITESPACE;
            }
            else{
                std::cout << grid[i][m].getName() << WHITESPACE;
            }
        }

        

        //Increment Count
        rowCount++;
        std::cout << std::endl;
    }
}
void AdvancedPlayer::printBrokenRow() {
    std::cout << "broken: ";
    
    for (int i = 0; i < ADV_BROKEN_ROW_SIZE; ++i) {
        if(i == 7){
            std::cout << ORANGE_COLOUR << brokenRow[i].getName() << RESET << WHITESPACE;
        }
        else{
            std::cout << brokenRow[i].getName() << WHITESPACE;
        }
        
    }
    std::cout << std::endl;
}

void AdvancedPlayer::addToBrokenRow(char tile) {
    if (brokenRowCount < ADV_BROKEN_ROW_SIZE){
        brokenRow[brokenRowCount].setName(tile);
        brokenRowCount++;
    }
}

Tile **AdvancedPlayer::getUnlaidRow() {
    return unlaidRow;
}

Tile **AdvancedPlayer::getGrid() {
    return grid;
}

Tile* AdvancedPlayer::getBrokenRow() {
    return brokenRow;
}

int AdvancedPlayer::getBrokenRowCount() {
    return brokenRowCount;
}

void AdvancedPlayer::setBrokenRowCount(int count) {
    brokenRowCount = count;
}

bool AdvancedPlayer::isFirst() {
    return first;
}

void AdvancedPlayer::setFirst(bool f) {
    this->first = f;
}

int AdvancedPlayer::getId() {
    return id;
}
