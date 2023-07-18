/// Create a 2D array of cell objects

class Cell {
    bool alive; // Binary state of Dead (F) or Alive (T)
    bool mutated; // True or False depending on if cell state changed

    public:
        Cell() {
            alive = false;
            mutated = false;
        }

        // the "this" keyword is a pointer (it points to a memory address that contains the data we want. not the data itself)
        // "*" is the dereference symbol. it means: give me the data at the memory address your variable points to
        Cell(bool alive) {
            this->alive = alive; // -> == (*).
            mutated = false;
        }

        bool getAlive() {
            return alive;
        }

        void setAlive(bool alive) {
            this->alive = alive;
        }        

        bool getMutated() {
            return mutated;
        }
        
        void setMutated(bool mutated) {
            this->mutated = mutated;
        }


};