#ifndef CELL_H
#define CELL_H
/// Create a 2D array of cell objects

class Cell {
    bool alive; // Binary state of Dead (F) or Alive (T)
    bool mutated; // True or False depending on if cell state changed
    
    public:
        Cell();

        // the "this" keyword is a pointer (it points to a memory address that contains the data we want. not the data itself)
        // "*" is the dereference symbol. it means: give me the data at the memory address your variable points to
        Cell(bool);

        bool getAlive();

        void setAlive(bool);        

        bool getMutated();
        
        void setMutated(bool);

        void killCell();

        void reviveCell();

};
#endif