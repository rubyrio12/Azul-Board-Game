
#ifndef COSC_ASSIGN_TWO_TYPES
#define COSC_ASSIGN_TWO_TYPES

#include "Tile.h"
#include <vector>

#define FIRST_TILE 'F'
#define RED 'R'
#define YELLOW 'Y'
#define DARK_BLUE 'B'
#define LIGHT_BLUE 'L'
#define BLACK 'U'
#define ORANGE 'O'

#define ORANGE_COLOUR "\033[48;2;255;165;0m"
#define RESET "\033[0m"

#define NUM_OF_PLAYERS 2
#define MAX_GAME_ROUNDS 6
#define MOSAIC_DIM 5
#define MOSAIC_BOARD_SIZE (MOSAIC_DIM * MOSAIC_DIM)
#define NUM_OF_FACTORIES 5
#define FACTORY_SIZE 4
#define BROKEN_ROW_SIZE 7
#define MOSAIC_BOARD_COLOR "byrullbyruulbyrrulbyyrulb"
#define FIRST_FACTORY 0
#define LAST_FACTORY 5
#define FIRST_STORAGE_ROW 0
#define LAST_STORAGE_ROW 5
#define INVALID_COORDINATE -2
#define MAX_TILE_NUM 20
#define VALID_CHARS "RYBLUO"
#define TILE_BAG_VALID_CHARS "RYBLUFO"
#define MAX_DIRECTIONS 4
#define MAX_UP 0
#define MAX_DOWN 4
#define MAX_RIGHT 4
#define MAX_LEFT 0
#define NUM_OF_TILES_IN_TILE_BAG 100
#define WHITESPACE ' '
#define DOUBLE_WHITESPACE "  "
#define NO_TILE '.'
#define END_OF_FILE '\0'

#define DEFAULT_NAME "default"

#define ADV_FACTORY_SIZE 5
#define ADV_MOSAIC_DIM 6
#define ADV_MOSAIC_BOARD "...................................."
#define SIXTH_ROW "......"
#define ADV_BROKEN_ROW_SIZE 8
#define ADV_LAST_FACTORY 6
#define ADV_LAST_STORAGE_ROW 6
#define FIRST_ROW 0
#define ADV_LAST_ROW 6
#define ADV_MAX_DOWN 5
#define ADV_MAX_RIGHT 5


#define PLAYER_ONE 0
#define PLAYER_TWO 1


#endif // COSC_ASSIGN_TWO_TYPES
