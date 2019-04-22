//
// Created by   150180707
//              Fatih Altınpınar
//              on 20.04.2019.
//

#include <iostream>

#ifndef MAX_OPERATOR_SIZE
#define MAX_OPERATOR_SIZE 100
#endif


using namespace std;

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
    center_x = x - 1;
    center_y = y - 1;
    op_size = size;
}

// Reset Function which does not resets anything. It just re-sets. Nice naming btw.
void Operator::reset(int new_x, int new_y, int new_size) {
    center_x = new_x - 1;
    center_y = new_y - 1;
    op_size = new_size;
}

// Setters and Getters
void Operator::set_x(int new_x) { center_x = new_x - 1; }

int Operator::get_x() { return center_x; }

void Operator::set_y(int new_y) { center_y = new_y - 1; }

int Operator::get_y() { return center_y; }

void Operator::set_size(int new_size) { op_size = new_size; }

int Operator::get_size() { return op_size; }


/*                              ArithmeticOperator Class Declarations                   */
class ArithmeticOperator : public Operator {
    char sign;

public:
    ArithmeticOperator(int x, int y, int size, char sign);

    char get_sign();

    // Prints out operator's center location, size and sign character
    void print_operator();
};

/*                          ArithmeticOperator Function Definitions                     */

// Constructor
ArithmeticOperator::ArithmeticOperator(int x, int y, int size, char sign) : Operator(x, y, size) {
    if (sign == '+' || sign == '/' || sign == 'x' || sign == '-') // Checking for invalid sign.
        this->sign = sign;
    else {
        sign = 'q';
        cout << "SIGN parameter is invalid!" << endl;
    }
}

// Getters
char ArithmeticOperator::get_sign() { return sign; }


// Prints the operator in following format:
// ARITHMETIC_OPERATOR[sign], CENTER_LOCATION[center_x,center_y], SIZE[op_size]
void ArithmeticOperator::print_operator() {
    cout << "ARITHMETIC_OPERATOR[" << get_sign() << "], CENTER_LOCATION[" << get_x() + 1 << "," << get_y() + 1
         << "], SIZE[" << get_size() << "]" << endl;
}


/*                          OperatorGrid Class Declarations                        */
class OperatorGrid {
    int grid_rows;
    int grid_cols;
    char **grid;

    int num_operators;
    ArithmeticOperator *operators[MAX_OPERATOR_SIZE];

public:
    OperatorGrid(int rows, int cols);

    ~OperatorGrid();


    bool place_operator(ArithmeticOperator *new_operator);

    bool move_operator(int x, int y, char direction, int move_by);

    void print_operators();

    // Helper functions
    bool is_conflict(int x, int y, int size, char sign);

    bool is_bordererror(int x, int y, int size, char sign);

    bool is_in_grid(int x, int y);

    void fill_grid(int x, int y, int size, char sign, bool fill_sign);

};

/*                           OperatorGrid Class Definitions                                  */

// Constructor
OperatorGrid::OperatorGrid(int rows, int cols) : grid_rows(rows), grid_cols(cols) {
    num_operators = 0;

    // Opening memory for grid and filling it with \0
    grid = new char *[rows];
    for (int i = 0; i < rows; i++) {
        // By putting parenthesis we set all elements to '\0';
        grid[i] = new char[cols]();

    }
}


bool OperatorGrid::place_operator(ArithmeticOperator *new_operator) {
    // Checking the sign of the given ArithmeticOperator
    if (new_operator->get_sign() == '+'
        || new_operator->get_sign() == '/'
        || new_operator->get_sign() == 'x'
        || new_operator->get_sign() == '-') {

        // Creating temporary variables.
        int center_x = new_operator->get_x();
        int center_y = new_operator->get_y();
        int op_size = new_operator->get_size();
        char sign = new_operator->get_sign();

        // Checking if there is a border error or not.
        bool border_error = is_bordererror(center_x, center_y, op_size, sign);

        // Checking if there is a conflict.
        bool conflict_error = is_conflict(center_x, center_y, op_size, sign);

        // Printing corresponding outputs depending on the errors.
        // If there is not an error, this code puts ArithmeticOperator into the grid.
        if (!border_error && !conflict_error) {

            fill_grid(center_x, center_y, op_size, sign, true);

            cout << "SUCCESS: Operator " << sign << " with size " << op_size << " is placed on (" << center_x + 1 << ","
                 << center_y + 1 << ")." << endl;

            operators[num_operators] = new ArithmeticOperator(*new_operator);
            // Copying the operator in order to prevent user interaction with operators already implemented.
            num_operators++;


            return true;
        } else if (border_error && !conflict_error) {
            cout << "BORDER ERROR: Operator " << sign << " with size " << op_size << " can not be placed on ("
                 << center_x + 1 << "," << center_y + 1 << ")." << endl;
            return false;
        } else if (conflict_error && !border_error) {
            cout << "CONFLICT ERROR: Operator " << sign << " with size " << op_size << " can not be placed on ("
                 << center_x + 1 << "," << center_y + 1 << ")." << endl;
            return false;
        } else {
            cout << "BORDER ERROR: Operator " << sign << " with size " << op_size << " can not be placed on ("
                 << center_x + 1 << "," << center_y + 1 << ")." << endl;
            cout << "CONFLICT ERROR: Operator " << sign << " with size " << op_size << " can not be placed on ("
                 << center_x + 1 << "," << center_y + 1 << ")." << endl;
            return false;
        }
    }

    return false;
}

// Moving ArithmeticOperators over the grid.
bool OperatorGrid::move_operator(int x, int y, char direction, int move_by) {
    // Decreasing the given x, y values since arrays starts at 0 in c++.
    x--;
    y--;
    // Checking if given point is in the grid or not since it might cause segmentation fault.
    if (is_in_grid(x, y)) {
        // Finding the moved object.
        ArithmeticOperator *moved_operator;
        bool found_operator = false;

        char sign = grid[x][y];

        int center_x = 0;
        int center_y = 0;
        int size = 0;

        // Finding the ArithmeticOperator object from the operators array going over one by one and checking some
        // conditions. This allows us to identify given x, y coordinates are belonging to an ArithmeticOperator object
        // or not.
        for (int i = 0; i < num_operators; i++) {
            if (operators[i]->get_sign() == sign) {
                center_x = operators[i]->get_x();
                center_y = operators[i]->get_y();
                size = operators[i]->get_size();
                if (sign == '+') {

                    // Horizontal control
                    if ((x == center_x) && (abs(y - center_y) <= size)) {
                        moved_operator = operators[i];
                        found_operator = true;
                        break;
                    }

                    // Vertical control
                    if ((y == center_y) && (abs(x - center_x) <= size)) {
                        moved_operator = operators[i];
                        found_operator = true;
                        break;
                    }
                } else if (sign == '-') {
                    if ((x == center_x) && (abs(y - center_y) <= size)) {
                        moved_operator = operators[i];
                        found_operator = true;
                        break;
                    }
                } else if (sign == 'x') {
                    if ((center_x - x) == (center_y - y) || (center_x - x) == -1 * (center_y - y)) {
                        if (abs(center_x - x) <= size) {
                            moved_operator = operators[i];
                            found_operator = true;
                            break;
                        }
                    }
                } else if (sign == '/') {
                    if (((center_x - x) == -1 * (center_y - y)) && abs(center_x - x) <= size) {
                        moved_operator = operators[i];
                        found_operator = true;
                        break;
                    }
                }
            }
        }

        // New coordinates are determined by the direction and move_by value.
        int new_x = 0;
        int new_y = 0;
        if (direction == 'U') {
            new_x = center_x - move_by;
            new_y = center_y;
        } else if (direction == 'D') {
            new_x = center_x + move_by;
            new_y = center_y;
        } else if (direction == 'R') {
            new_x = center_x;
            new_y = center_y + move_by;
        } else if (direction == 'L') {
            new_x = center_x;
            new_y = center_y - move_by;
        }

        // If x, y cell that user wants to move belongs to an object
        if (found_operator) {
            // Deleting the operator from the grid.
            fill_grid(center_x, center_y, size, sign, false);

            // Checking if new place causes any errors.
            bool border_error = is_bordererror(new_x, new_y, size, sign);
            bool conflict_error = is_conflict(new_x, new_y, size, sign);

            // Printing the outputs depending on the errors.
            // If there is no error operator's values are changed accordingly then filling the grid by required size and
            // sign.
            if (!border_error && !conflict_error) {
                cout << "SUCCESS: " << sign << " moved from (" << moved_operator->get_x() + 1 << ","
                     << moved_operator->get_y() + 1 << ") to (" << new_x + 1 << "," << new_y + 1 << ")." << endl;

                moved_operator->set_x(new_x + 1);
                moved_operator->set_y(new_y + 1);

                fill_grid(new_x, new_y, size, sign, true);
                return true;
            } else if (border_error && !conflict_error) {
                cout << "BORDER ERROR: " << sign << " can not be moved from (" << moved_operator->get_x() + 1 << ","
                     << moved_operator->get_y() + 1 << ") to (" << new_x + 1 << "," << new_y + 1 << ")." << endl;
                fill_grid(center_x, center_y, size, sign, true);
                return false;
            } else if (!border_error && conflict_error) {
                cout << "CONFLICT ERROR: " << sign << " can not be moved from (" << moved_operator->get_x() + 1 << ","
                     << moved_operator->get_y() + 1 << ") to (" << new_x + 1 << "," << new_y + 1 << ")." << endl;
                fill_grid(center_x, center_y, size, sign, true);
                return false;
            } else if (border_error && conflict_error) {
                cout << "BORDER ERROR: " << sign << " can not be moved from (" << moved_operator->get_x() + 1 << ","
                     << moved_operator->get_y() + 1 << ") to (" << new_x + 1 << "," << new_y + 1 << ")." << endl;
                cout << "CONFLICT ERROR: " << sign << " can not be moved from (" << moved_operator->get_x() + 1 << ","
                     << moved_operator->get_y() + 1 << ") to (" << new_x + 1 << "," << new_y + 1 << ")." << endl;
                fill_grid(center_x, center_y, size, sign, true);
                return false;
            }
        }
    }
    return false;
}

// Printing all the operators which are place into grid.
void OperatorGrid::print_operators() {
    for (int i = 0; i < num_operators; i++)
        operators[i]->print_operator();
}



/*                                      Helper Functions                                */

// This function checks if there are any conflict errors.
bool OperatorGrid::is_conflict(int x, int y, int size, char sign) {

    // Checking center
    if (is_in_grid(x, y))
        if (grid[x][y] != '\0')
            return true;

    // Checking other parts one by one. Checking algorithm changes depending on the sign.
    if (sign == '+') {
        for (int i = 1; i <= size; i++) {
            //Checking UP
            if (is_in_grid(x - i, y))
                if (grid[x - i][y] != '\0')
                    return true;

            //Checking RIGHT
            if (is_in_grid(x, y + i))
                if (grid[x][y + i] != '\0')
                    return true;

            //Checking DOWN

            if (is_in_grid(x + i, y))
                if (grid[x + i][y] != '\0')
                    return true;

            //Checking RIGHT
            if (is_in_grid(x, y - i))
                if (grid[x][y - i] != '\0')
                    return true;
        }
    } else if (sign == '/') {
        for (int i = 1; i <= size; i++) {
            //Checking RIGHT-UP
            if (is_in_grid(x - i, y + i))
                if (grid[x - i][y + i] != '\0')
                    return true;

            //Checking DOWN-LEFT
            if (is_in_grid(x + i, y - i))
                if (grid[x + i][y - i] != '\0')
                    return true;
        }
    } else if (sign == 'x') {

        for (int i = 1; i <= size; i++) {
            //Checking UP-RIGHT
            if (is_in_grid(x - i, y + i))
                if (grid[x - i][y + i] != '\0')
                    return true;

            //Checking DOWN-RIGHT
            if (is_in_grid(x + i, y + i))
                if (grid[x + i][y + i] != '\0')
                    return true;

            //Checking DOWN-LEFT
            if (is_in_grid(x + i, y - i))
                if (grid[x + i][y - i] != '\0')
                    return true;

            //Checking UP-LEFT
            if (is_in_grid(x - i, y - i))
                if (grid[x - i][y - i] != '\0')
                    return true;
        }
    } else if (sign == '-') {

        for (int i = 1; i <= size; i++) {
            //Checking RIGHT
            if (is_in_grid(x, y + i))
                if (grid[x][y + i] != '\0')
                    return true;

            //Checking LEFT
            if (is_in_grid(x, y - i))
                if (grid[x][y - i] != '\0')
                    return true;
        }
    }
    return false;
}


// This function checks ability of causing BORDER ERROR by the given values
// of a temporary Arithmetic Operator.
bool OperatorGrid::is_bordererror(int x, int y, int size, char sign) {
    if (sign == '-') {

        // Checks if - ArithmeticOperator is in the grid on x axis.
        if (x >= grid_rows || x < 0)
            return true;
            // Checking if - operator exceeds the grid size on y axis.
        else if (y + size >= grid_cols || y - size < 0)
            return true;
        else
            return false;

    } else {
        // All operators but '-' behaves the same.
        // If their 'x/y + size + 1 >= grid_cols/rows' and 'x/y - size < 0' must be checked for all directions

        if (x + size >= grid_rows || x - size < 0) // Checking if the operator causes any conflict errors on x axis.
            return true;
        else if (y + size >= grid_cols || y - size < 0)// Checking if the operator causes any conflict errors on y.
            return true;
        else
            return false;
    }
}


// This function checks a point is inside the grid or outside.
// Returns true if the point is inside the grid, otherwise returns false.
bool OperatorGrid::is_in_grid(int x, int y) {
    return (x >= 0 && x < grid_rows && y >= 0 && y < grid_cols);
}

// This function draws a ArithmeticOperator onto grid or removes it from the grid by filling
// corresponding places with  sign or '\0' depending on fill_sign.
void OperatorGrid::fill_grid(int x, int y, int size, char sign, bool fill_sign) {
    char brush;
    if (fill_sign)
        brush = sign;
    else
        brush = 0;

    if (sign == '+') {
        // Fills a + shape on x,y coordinates that have given size, with brush.
        grid[x][y] = brush;
        for (int i = 1; i <= size; i++) {
            grid[x - i][y] = brush; // Up
            grid[x][y + i] = brush; // Right
            grid[x + i][y] = brush; // Down
            grid[x][y - i] = brush; // Left
        }
    } else if (sign == '/') {
        // Fills a / shape on x,y coordinates that have given size, with brush.
        grid[x][y] = brush;
        for (int i = 1; i <= size; i++) {
            grid[x - i][y + i] = brush; // Goes right up
            grid[x + i][y - i] = brush; // Goes down left
        }
    } else if (sign == 'x') {
        // Fills a x shape on x,y coordinates that have given size, with brush.
        grid[x][y] = brush;
        for (int i = 1; i <= size; i++) {
            grid[x - i][y + i] = brush; // Up Right
            grid[x + i][y + i] = brush; // Down Right
            grid[x + i][y - i] = brush; // Down Left
            grid[x - i][y - i] = brush; // Up Left
        }
    } else if (sign == '-') {
        // Fills a - shape on x,y coordinates that have given size, with brush.
        grid[x][y] = brush;
        for (int i = 1; i <= size; i++) {
            grid[x][y + i] = brush; // Right
            grid[x][y - i] = brush; // Left
        }
    }
}


// Destructor
OperatorGrid::~OperatorGrid() {
    // Deleting dynamically allocated memories.
    cout << "DESTRUCTOR: GIVE BACK[" << grid_rows << "," << grid_cols << "] chars." << endl;
    for (int i = 0; i < grid_rows; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    cout << "DESTRUCTOR: GIVE BACK[" << num_operators << "] Operators." << endl;
    for (int i = 0; i < num_operators; i++)
        delete operators[i];
}

