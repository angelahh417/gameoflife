#include "gameboard.h"
#include <assert.h>

#define ASSERT(x, msg) assert(((void) msg, x))

int main() {

    Gameboard gb = Gameboard(20, 30);
    gb.initState();
    gb.printGameBoard();

    ASSERT((gb.getNeighbors(5, 5) == 2), "Neighbors: south, south-east");
    ASSERT((gb.getNeighbors(6, 5) == 3), "Neighbors: north, east, south-east");
    ASSERT((gb.getNeighbors(6, 6) == 4), "Neighbors: north-west, west, east, south");
    
    gb.updateGame();  // could update upgateGame to return true here and keep a while loop running this main -- while updateGame == true, keep looping and updating. when false, end loop (end game).
    gb.printGameBoard();

    return 0;
}



