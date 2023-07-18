#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "cell.h"
#include <vector>
#include <iostream>
using namespace std;

const int WIDTH = 6;
const int HEIGHT = 3;

class Gameboard {
    vector<vector<Cell>> gameBoard;
    int height;
    int width;

    // // Rreturns number of alive neighbors from previous round
    // int getNeighbors(int, int);

    public:
        Gameboard();

        // TODO: make private after testing
        // Returns number of alive neighbors from previous round
        int getNeighbors(int, int);
        Gameboard(int, int); // include height and width

        void printingTest();

        void printGameBoard();

        void initState();

        /// Get a reference to a cell at [height, width]
        Cell& getCell(int, int); // returns ref where that cell is saved on Gameboard

        void updateGame();

        bool isValidCoords(int, int); 

        int getHeight();

        int getWidth();

        void resetChange();

};


#endif
