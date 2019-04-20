#include <iostream>
#include "assignment2.cpp"
#define MAX_OPERATOR_SIZE 40

using namespace std;
int main() {
    char a;
    char *b = new char();

    cout << a << endl << b << endl;
    cout << ('\0' == *b) << endl;
    return 0;
}