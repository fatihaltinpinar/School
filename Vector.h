//
// Created by faati on 24.03.2019.
//
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>

using namespace std;

class Vector {

    int size; // Size of the vector

    // Vector that holds the values of the Vector object that is created.
    vector<int> values;

public:
    // Constructors
    Vector(); // Default Constructor
    Vector(int); // Constructor with just size given
    Vector(const vector<int> &); // Constructor -the real deal-
    Vector(const Vector &); // Copy Constructor

    // Operator Overloading
    const Vector &operator=(const Vector &);

    Vector operator+(const Vector &) const; // Vector addition
    Vector operator*(int) const;             // Multiplication with scalar
    Vector operator*(const Vector &) const;  //
    //    ~Vector();   No need since we don't use dynamic memory allocation.
};

/* CONSTRUCTORS */

// Default Constructor
Vector::Vector() {
    size = 3;
    for (int i = 0; i < size; i++) {
        values.push_back(0);
    }
}

// Constructor just with size given.
// Creates a vector that has 3 values and all of them are zero.
Vector::Vector(int in_size) : size(in_size) {
    for (int i = 0; i < size; i++) {
        values.push_back(0);
    }
}

// Constructor
Vector::Vector(const vector<int> &in_values) {
    size = int(in_values.size());
    values = in_values;
}

// Copy Constructor
Vector::Vector(const Vector &in_vector) {
    size = in_vector.size;
    values = in_vector.values;
}

const Vector &Vector::operator=(const Vector &in_vector) {
    size = in_vector.size;
    values = in_vector.values;
    return *this;
}

Vector Vector::operator+(const Vector &in_vector) const {
    if(size == in_vector.size){
        vector<int> summed_values;
        for(int i = 0; i < size; i++){
            summed_values[i] = values[i] + in_vector.values[i];
        }
        return Vector(summed_values);
    }else{
        cout << "Vectors are not the same size cant sum." << endl;
        cout << "Returning a vector filled by zero" << endl;
        return Vector(size);
    }
}



/* OPERATORS */



/* DESTRUCTOR */

#endif // VECTOR_H
