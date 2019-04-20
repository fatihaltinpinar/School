//
// Created by   150180707
//              Fatih Altınpınar
//              on 20.04.2019.
//

#include <iostream>
using namespace std;

// TODO remove start
const int MAX_OPERATOR_SIZE = 30;

// TODO remove end



/*                                  Operator Class Declarations             */
class Operator {
    int center_x;
    int center_y;
    int op_size;

public:
    Operator(int x, int y, int size);

    void reset(int new_x, int new_y, int new_size);

    void set_x(int new_x);

    int get_x();

    void set_y(int new_y);

    int get_y();

    void set_size(int new_size);

    int get_size();
};

/*                               Operator Function Definitions                  */

// Constructor
Operator::Operator(int x, int y, int size) {
    center_x = x;
    center_y = y;
    op_size = size;
}

// Reset Function which does not resets anything. It just re-sets. Nice naming btw.
void Operator::reset (int new_x, int new_y, int new_size){
    center_x = new_x;
    center_y = new_y;
    op_size = new_size;
}

// Setters and Getters
void Operator::set_x(int new_x){ center_x = new_x; }
int Operator::get_x(){ return center_x; }

void Operator::set_y(int new_y){ center_y = new_y; }
int Operator::get_y(){ return center_y; }

void Operator::set_size(int new_size){ op_size = new_size; }
int Operator::get_size() { return op_size; }






/*                              ArithmeticOperator Class Declarations                   */
class ArithmeticOperator: public Operator{
    char sign;

public:
    ArithmeticOperator(int x, int y, int size, char sign);

    char get_sign();

    // Prints out operator's center location, size and sign character
    void print_operator();
};



/*                          ArithmeticOperator Function Definitions                     */

// Constructor
ArithmeticOperator::ArithmeticOperator(int x, int y, int size, char sign):Operator(x,y,size){
    this->sign = sign;
}

// Getters
char ArithmeticOperator::get_sign() { return sign; }


// Prints the operator in following format:
// ARITHMETIC_OPERATOR[sign], CENTER_LOCATION[center_x,center_y], SIZE[op_size]
void ArithmeticOperator::print_operator() {
    cout << "ARITHMETIC_OPERATOR[" << get_sign() << "], CENTER_LOCATION["<< get_x() << "," << get_y() << "], SIZE[op_size]" << endl;
}




/*                          OperatorGrid Class Declarations                        */
class OperatorGrid{
    int grid_rows;
    int grid_cols;
    char **grid;

    int num_operators;
    ArithmeticOperator *operators[MAX_OPERATOR_SIZE];

public:
    OperatorGrid(int rows, int cols);
    ~OperatorGrid();


    bool place_operator (ArithmeticOperator *);
    bool move_operator (int x, int y, char direction, int move_by);
    void print_operators();

};
/*                          OperatorGrid Class Definitions                    */

// Constructor
OperatorGrid::OperatorGrid(int rows, int cols) : grid_rows(rows), grid_cols(cols) {
    num_operators = 0;

    // Opening memory for grid and filling it with \0
    grid = new char*[rows];
    for(int i = 0; i < rows; i++){
        // By putting parenthesis we set all elements to '\0';
        grid[i] = new char[cols]();

    }
}

// Destructor
OperatorGrid::~OperatorGrid() {
    // TODO add other delete
    cout << "DESTRUCTOR: GIVE BACK[" << grid_rows << "," << grid_cols << "] chars." << endl;
    for(int i = 0; i < grid_rows ; i++){
        delete[] grid[i];
    }
    delete[] grid;

    cout << "DESTRUCTOR: GIVE BACK[" << num_operators << "] Operators." << endl;
    delete[] operators;
}

int main(){
    cout << "hi" << endl;
    return 0;
}