/// Create a 2D array of cell objects
#include "cell.h"

// Cell:: means to use the namespace Cell. Because we declared these methods 
// in cell.h we are able to implement them under the correct namespace 
Cell::Cell() {
    alive = false;
    mutated = false;
}

// the "this" keyword is a pointer (it points to a memory address that contains the data we want. not the data itself)
// "*" is the dereference symbol. it means: give me the data at the memory address your variable points to
Cell::Cell(bool alive) {
    this->alive = alive; // -> == (*).
    mutated = false;
}

bool Cell::getAlive() {
    return alive;
}

void Cell::setAlive(bool alive) {
    this->alive = alive;
}        

bool Cell::getMutated() {
    return mutated;
}

void Cell::setMutated(bool mutated) {
    this->mutated = mutated;
}

void Cell::killCell() {
    setAlive(false);
    setMutated(true);
}

void Cell::reviveCell() {
    setAlive(true);
    setMutated(true);
}

