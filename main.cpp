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
    read_vectors(vector_list);


    return 0;
}

void read_polynomials(vector<Polynomial> &polynomial_list){
    int n;

    ifstream poly_file;
    poly_file.open("Polynomial.txt");

    if (poly_file.is_open()){
        poly_file >> n;
        for (int i = 0 ; i < n; i++){

            int degree;
            poly_file >> degree;

            vector<int> poly_reader;
            for (int j = 0; j <= degree; j++)
                poly_reader.push_back(0);

            int tmp;
            for (int j = degree; j >= 0; j--){
                poly_file >> tmp;
                poly_reader[j] = tmp;
            }
            polynomial_list.push_back(Polynomial(poly_reader));
        }
        clog << "Polynomial reading is completed." << endl;
    }else {
        cerr << "Can not open Polynomial.txt!" << endl;
        exit(EXIT_FAILURE);
    }
}


void read_vectors(vector<Vector> &vector_list){
    int n;

    ifstream vector_file ("Vector.txt");

    if (vector_file.is_open()){
        vector_file >> n;
        for(int i = 0; i < n; i++){
            int size;
            vector_file >> size;
            vector<int> vector_reader;


            int tmp;
            for (int j = 0; j < size; j++){

                vector_file >> tmp;
                vector_reader.push_back(tmp);
            }


            vector_list.push_back(vector_reader);
        }
        clog << "Vector reading is completed." << endl;
    }else{
        cerr << "Can not open Vector.txt!" << endl;
        exit(EXIT_FAILURE);
    }

}
