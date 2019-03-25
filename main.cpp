#include <iostream>

#include "Vector.h"

using namespace std;

int main() {
    vector<int> a = {4, 2, 1,3 , 5,7,8,9};
    Vector ab(a.size(), a);
    Vector c = ab;

    return 0;
}