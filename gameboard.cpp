#include "gameboard.h"

// NOTE: implicit "this->" (ie, this->getHeight() == getHeight())

// Gameboard::Gameboard(): height(HEIGHT), width(WIDTH) {}
Gameboard::Gameboard() {
    height = HEIGHT;
    width = WIDTH;
    gameBoard.resize(height, vector<Cell>(width)); // resize function of vector, second arg initializes the type and uses vector constructor with width
    
}
// Gameboard::Gameboard(int h, int w): height(h), width(w) {}
Gameboard::Gameboard(int h, int w) {
    height = h;
    width = w;
    gameBoard.resize(height, vector<Cell>(width));
}

int Gameboard::getHeight() {
    return height;
}

int Gameboard::getWidth() {
    return width;
}

void Gameboard::printingTest() {
    for(vector<Cell> innerVec : gameBoard) {
        for(Cell cell : innerVec) {
            cout << "(" << cell.getAlive() << "," << cell.getMutated() << ")";
        }
        cout << endl;
    }
}

void Gameboard::printGameBoard() {
    for(vector<Cell> innerVec : gameBoard) {
        for(Cell cell : innerVec) {
            // cout << (cell.getAlive() ? "@" : " ");
            if (cell.getAlive()) {
                cout << "@";
            } 
            else {
                cout << " ";
            }    
        }
        cout << endl;
    }
}

void Gameboard::initState() {
    /*   
    the top left @ is (5, 5)

    [     
        
        
        
        
          @   @@@                  
          @@@  @                   
           @   
        ...                    
    ]                       
    */
    gameBoard[5][5].setAlive(true);
    gameBoard[6][5].setAlive(true);
    gameBoard[6][6].setAlive(true);
    gameBoard[6][7].setAlive(true);
    gameBoard[7][6].setAlive(true);


    gameBoard[5][9].setAlive(true);
    gameBoard[5][10].setAlive(true);
    gameBoard[5][11].setAlive(true);
    gameBoard[6][10].setAlive(true);
}

Cell& Gameboard::getCell(int y, int x) {  // returns ref where that cell is saved on Gameboard
    return this->gameBoard[y][x]; // start with height, which will take you to correct row (aka vector of vector cells)
} 

void Gameboard::resetChange() {
    //O(height * width)
    for(vector<Cell> v : gameBoard) {
        for(Cell& c : v) {
            c.setMutated(false);
        }
    }
}

// What is big oh of updateGame if the forloop is O(nm) and resetChange is O(nm) = 2 * O(nm) = O(nm)
void Gameboard::updateGame() {
    // Loop over every cell, check all neighbors in 8 directions (if alive and if changed), and update cell state. 
    // O(height * width)
    for (int h=0; h < getHeight(); h++) {
        for (int w=0; w < getWidth(); w++) {
            int aliveNeighbors = getNeighbors(h,w);
            Cell& cell = getCell(h, w);
            // implement rules
            if (cell.getAlive()) {
                if (aliveNeighbors < 2) {
                    cell.killCell();
                }
                if (aliveNeighbors > 3) {
                    cell.killCell();
                }

            }
            else {
                if (aliveNeighbors == 3) {
                    cell.reviveCell();
                }
            }
        }
    }
    resetChange();
}

// #region neighbors 
int Gameboard::getNeighbors(int y, int x) {
    int neighbors = 0;

    // create matrix of positional values
    vector<vector<int>> dirMap =
     {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1}, {1, 0}, {1, 1}
     };

     for (vector<int> dir: dirMap) {
        // dir = {int , int}
        int nY = y + dir[0];
        int nX = x + dir[1];
        if (isValidCoords(nY, nX)) {
            Cell c = getCell(nY, nX);
            if ((!c.getAlive() && c.getMutated()) || (c.getAlive() && !c.getMutated())) {
                neighbors++;
            }
        }
     }

    return neighbors;
}
// #endregion neighbors

//  #pragma region 
// // int Gameboard::getNeighbors(int y, int x) {
// //     // try making a map 
// //     // (x-1, y-1) (x, y-1) (x+1, y-1)
// //     //  (x-1, y)   (x, y)   (x+1, y)
// //     // (x-1, y+1) (x, y+1) (x+1, y+1)

// //     //FUNCTIONS BELOW should be inverted: (x,y) to (y,x)

// //     int count = 0;
    
// //     if (this->isValidCoords(y-1, x-1)) {
// //         if (getCell(y-1, x-1).getAlive()) {
// //             if (!getCell(y-1, x-1).getMutated()) {
// //                 count++;
// //             }
// //         }
// //     }
// //     if (this->isValidCoords(y, x-1)) {
// //         if (getCell(y, x-1).getAlive()) {
// //             if (!getCell(y, x-1).getMutated()) {
// //                 count++;
// //             }
// //         }
// //     }
// //     if (this->isValidCoords(y+1, x-1)) {
// //         if (getCell(y+1, x-1).getAlive()) {
// //             if (!getCell(y+1, x-1).getMutated()) {
// //                 count++;
// //             }
// //         }
// //     }
// //     if (this->isValidCoords(y-1, x)) {
// //         if (getCell(y-1, x).getAlive()) {
// //             if (!getCell(y-1, x).getMutated()) {
// //                 count++;
// //             }
// //         }
// //     }
// //     if (this->isValidCoords(y+1, x)) {
// //         if (getCell(y+1, x).getAlive()) {
// //             if (!getCell(y+1, x).getMutated()) {
// //                 count++;
// //             }
// //         }
// //     }
// //     if (this->isValidCoords(y-1, x+1)) {
// //         if (getCell(y-1, x+1).getAlive()) {
// //             if (!getCell(y-1, x+1).getMutated()) {
// //                 count++;
// //             }
// //         }
// //     }
// //     if (this->isValidCoords(y, x+1)) {
// //         if (getCell(y, x+1).getAlive()) {
// //             if (!getCell(y, x+1).getMutated()) {
// //                 count++;
// //             }
// //         }
// //     }
// //     if (this->isValidCoords(y+1, x+1)) {
// //         if (getCell(y+1, x+1).getAlive()) {
// //             if (!getCell(y+1, x+1).getMutated()) {
// //                 count++;
// //             }
// //         }
// //     }
// //     return count;
// // }
//  #pragma endregion

// returns true if x and y fit in our vector
bool Gameboard::isValidCoords(int y, int x) {
    return (x < getWidth() && x >=0 && y < getHeight() && y >= 0);
}