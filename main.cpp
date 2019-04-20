#include <iostream>
#include "assignment2.cpp"


using namespace std;

int main() {
    OperatorGrid a(10,7);
    ArithmeticOperator *x = new ArithmeticOperator(2,2,1,'x');
    ArithmeticOperator *y = new ArithmeticOperator(2,4,1,'+');
    ArithmeticOperator *z = new ArithmeticOperator(2,6,1,'x');
    ArithmeticOperator *t = new ArithmeticOperator(2,1,9,'/');
    ArithmeticOperator *w = new ArithmeticOperator(9,4,3,'-');
    ArithmeticOperator *xx = new ArithmeticOperator(5,4,3,'/');
    ArithmeticOperator *yy = new ArithmeticOperator(5,4,3,'-');
    ArithmeticOperator *zz = new ArithmeticOperator(5,2,1,'-');
    ArithmeticOperator *tt = new ArithmeticOperator(7,6,1,'/');
    ArithmeticOperator *ww = new ArithmeticOperator(5,6,1,'+');
    a.place_operator(x);
    a.place_operator(y);
    a.place_operator(z);
    a.place_operator(t);
    a.place_operator(w);
    a.place_operator(xx);
    a.place_operator(yy);
    a.place_operator(zz);
    a.place_operator(tt);
    a.place_operator(ww);
    a.move_operator(1,1,'D',2);
    a.move_operator(5,1,'D',5);
    a.move_operator(1,1,'D',2);
    a.move_operator(2,4,'L',1);
    a.move_operator(2,4,'L',2);
    a.move_operator(8,5,'L',3);
    a.move_operator(1,7,'D',5);
    a.move_operator(10,1,'R',7);
    a.move_operator(5,4,'U',3);
    a.print_operators();
    return 0;



    /*SUCCESS: Operator x with size 1 is placed on (2,2).
SUCCESS: Operator + with size 1 is placed on (2,4).
SUCCESS: Operator x with size 1 is placed on (2,6).
BORDER ERROR: Operator / with size 9 can not be placed on (2,1).
SUCCESS: Operator - with size 3 is placed on (9,4).
SUCCESS: Operator / with size 3 is placed on (5,4).
CONFLICT ERROR: Operator - with size 3 can not be placed on (5,4).
SUCCESS: Operator - with size 1 is placed on (5,2).
SUCCESS: Operator / with size 1 is placed on (7,6).
SUCCESS: Operator + with size 1 is placed on (5,6).
CONFLICT ERROR: x can not be moved from (2,2) to (4,2).
SUCCESS: - moved from (5,2) to (10,2).
SUCCESS: x moved from (2,2) to (4,2).
CONFLICT ERROR: + can not be moved from (2,4) to (2,3).
SUCCESS: + moved from (2,4) to (2,2).
SUCCESS: / moved from (7,6) to (7,3).
SUCCESS: x moved from (2,6) to (7,6).
BORDER ERROR: - can not be moved from (10,2) to (10,9).
BORDER ERROR: / can not be moved from (5,4) to (2,4).
CONFLICT ERROR: / can not be moved from (5,4) to (2,4).
ARITHMETIC_OPERATOR[x], CENTER_LOCATION[4,2], SIZE[1]
ARITHMETIC_OPERATOR[+], CENTER_LOCATION[2,2], SIZE[1]
ARITHMETIC_OPERATOR[x], CENTER_LOCATION[7,6], SIZE[1]
ARITHMETIC_OPERATOR[-], CENTER_LOCATION[9,4], SIZE[3]
ARITHMETIC_OPERATOR[/], CENTER_LOCATION[5,4], SIZE[3]
ARITHMETIC_OPERATOR[-], CENTER_LOCATION[10,2], SIZE[1]
ARITHMETIC_OPERATOR[/], CENTER_LOCATION[7,3], SIZE[1]
ARITHMETIC_OPERATOR[+], CENTER_LOCATION[5,6], SIZE[1]
DESTRUCTOR: GIVE BACK[10,7] chars.
DESTRUCTOR: GIVE BACK[8] Operators.*/
}