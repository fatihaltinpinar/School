//
// Created by faati on 24.03.2019.
// Name: Fatih Altınpınar
// ID: 150180707
//
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>

using namespace std;

class Vector{

    int size; // Size of the vector

    // Vector that holds the values of the Vector object that is created.
    vector<int> values;

public:

    // todo add getters
    // Constructors
    Vector(); // Default Constructor
    Vector(int); // Constructor with just size given
    Vector(const vector<int> &); // Constructor -the real deal-
    Vector(const Vector &); // Copy Constructor

    //Getters
    int get_size() const;
    vector<int> get_values() const;


    // Operator Overloading
    const Vector& operator=(const Vector &);
    Vector operator+(const Vector &) const; // Vector addition
    Vector operator*(int) const;             // Multiplication with scalar
    int operator*(const Vector &) const;  // Dot Product
    friend ostream& operator<<(ostream &, const Vector &);

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

/* GETTERS */
int Vector::get_size() const {
    return size;
}

vector<int> Vector::get_values() const{
    return values;
}

/* OPERATORS */

// Assignment Operator Overloading
const Vector& Vector::operator=(const Vector &in_vector) {
    size = in_vector.size;
    values = in_vector.values;
    return *this;
}

// Summation Operator Overloading
Vector Vector::operator+(const Vector &in_vector) const {
    if(size == in_vector.size){ // Summing two vectors is possible only if they have the same size.
        vector<int> summed_values;
        for(int i = 0; i < size; i++){
            summed_values.push_back(values[i] + in_vector.values[i]); // Summing every value individually.
        }
        return Vector(summed_values);
    }
    cout << "Vectors are not the same size. Summation cannot be done." << endl;
    cout << "Returning a vector filled by zero" << endl;
    return Vector(size);
}

// Multiplication Operator Overloading for SCALAR MULTIPLICATION.
Vector Vector::operator*(int scalar) const {
    vector<int> scaled_results;
    for(int i = 0; i < size; i++)
        scaled_results.push_back(values[i] * scalar); // Multiplying every value individually.
    
    return Vector(scaled_results);
}


// Multiplication Operator Overloading for DOT PRODUCT
int Vector::operator*(const Vector &in_vector) const {
    if (size == in_vector.size){ // Taking dot product two vectors is possible only if they have the same size.
        int result = 0;
        for(int i = 0; i < size; i++)
            result += values[i] * in_vector.values[i]; // This is done wia summing multiplications of corresponding elements.
        return result;
    }else{
    cout << "Vectors are not the same size. Summation cannot be done." << endl;
    cout << "Returning a zero" << endl;
    return 0;
    }
}

// Insert operator overloading for printing.
// Lets users to print Vector objects such as = (1, 4, 6, 8)
ostream& operator<<(ostream &out, const Vector& in_vector) {
    out << "(";
    for (int i = 0; i < in_vector.size - 1; i++){
        out << in_vector.values[i] << ", ";
    }
    out << in_vector.values[in_vector.size - 1] << ")";
    return out;
}


/* DESTRUCTOR */
// No dynamic memory used in this class. No need for custom destructor.


#endif // VECTOR_H
