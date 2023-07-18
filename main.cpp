#include <iostream>
#include <vector>
#include "cell.h"

using namespace std;

const int WIDTH = 50;
const int HEIGHT = 25;


void testCell() {
    cout << "Hello World!" << endl;

    vector<Cell> vc;
    Cell cell_1;
    Cell cell_2;
    Cell cell_3(true);
    Cell cell_4(true);

    vc.push_back(cell_1);
    vc.push_back(cell_2);
    vc.push_back(cell_3);
    vc.push_back(cell_4);

    for(Cell cell : vc) {
        cout << cell.getAlive() << " " << cell.getMutated() << endl;
    }
    
    
}


// & = reference
// we are passing by reference, not value
void initGameBoard(vector<vector<Cell>> &vec) { 
    for (int i = 0; i < HEIGHT; i++) {
        vector<Cell> v1;
        
        for (int j = 0; j < WIDTH; j++) {
            v1.push_back(Cell());
        }
        vec.push_back(v1);

    }
    // vec.push_back(Cell());
    // vec.push_back(Cell(true));
}

// pass by value
// vec is a new vector that is copied from the caller's vector
// when this method ends, vec gets garbage collected and any changes to it are gone
// the original vector never was changed becasue vec is just a copy of its values
void initGameBoard2(vector<Cell> vec) {
    // ...
}

void printing(const vector<vector<Cell>> &vec) {
    //vector<Cell>
    for(vector<Cell> innerVec : vec) {
        for(Cell cell : innerVec) {
            cout << "(" << cell.getAlive() << "," << cell.getMutated() << ")";
        }
        cout << endl;
    }
}

void printGameBoard(const vector<vector<Cell>> &vec) {
    for(vector<Cell> innerVec : vec) {
        for(Cell cell : innerVec) {
            if (cell.getAlive()) {
                cout << "@";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<Cell>> gameBoard;
    initGameBoard(gameBoard);
    // printing(gameBoard);
    // printGameBoard(gameBoard);


    return 0;

}



