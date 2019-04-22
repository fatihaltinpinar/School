#include <iostream>
#define MAX_OPERATOR_SIZE 100
#include "assignment2.cpp"

using namespace std;

int main() {
    ArithmeticOperator plus(3,3,1,'+');

    OperatorGrid grid(10, 10);

    grid.place_operator(&plus);
    plus.set_y(5);
    grid.move_operator(3,2,'L',1);
    return 0;
}