#include <iostream>
#include <fstream>
#include <vector>

#include "Vector.h"
#include "Polynomial.h"
using namespace std;

void read_polynomials(vector<Polynomial> &);
void read_vectors(vector<Vector> &);


int main() {
    vector<Polynomial> polynomial_list;
    vector<Vector> vector_list;
    read_polynomials(polynomial_list);

    return 0;
}

void read_polynomials(vector<Polynomial> &polynomial_list){
    int n;

    ifstream poly_file;
    poly_file.open("Polynomial.txt");

    poly_file >> n;
    for (int i = 0 ; i << n; i++){
        int degree;
        poly_file >> degree;

        vector<int> readVector;
        for (int j = 0; j <= degree; j++)
            readVector.push_back(0);

        int tmp;
        for (int j = degree; j >= 0; j++){
            cin >> tmp;
            readVector[j] = tmp;
        }
        polynomial_list.push_back(Polynomial(readVector));
    }
}


void read_vectors(vector<Polynomial> &vector_list){

}
