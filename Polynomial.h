//
// Created by faati on 24.03.2019.
// Name: Fatih Altınpınar
// ID: 150180707
//
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>

using namespace std;

class Polynomial{
    int degree;
    vector<int> coefficients;
public:
    // Constructors
    Polynomial();
    Polynomial(const vector<int> &);
    Polynomial(const Polynomial &);

    //Getters
    int get_degree() const;
    vector<int> get_coefficients() const;

    // Operator overloading
    const Polynomial& operator=(const Polynomial &);    // Assignment
    Polynomial operator+(const Polynomial &) const;     // Summation
    Polynomial operator*(const Polynomial &) const;     // Multiplication
    friend ostream& operator<<(ostream &, const Polynomial &);  // Printing

    //Destructor
    //~Polynomial();  // No need since this object is not created with dynamic memory allocation.
};


/* CONSTRUCTORS */

//Default Constructor
Polynomial::Polynomial() {
    degree = 0;
    coefficients.push_back(0);
}

// Constructor
Polynomial::Polynomial(const vector<int> &in_vector) {
    coefficients = in_vector;
    degree = int(in_vector.size()) - 1;
}

// Copy Constructor
Polynomial::Polynomial(const Polynomial &in_poly) {
    degree = in_poly.degree;
    coefficients = in_poly.coefficients;
}
/* GETTERS */
int Polynomial::get_degree() const {
    return degree;
}

vector<int> Polynomial::get_coefficients() const {
    return coefficients;
}

/* OPERATOR OVERLOADING*/
// Assignment Operator
const Polynomial& Polynomial::operator=(const Polynomial &in_poly) {
    degree = in_poly.degree;
    coefficients = in_poly.coefficients;
    return *this;
}

// Summation operator
Polynomial Polynomial::operator+(const Polynomial &in_poly) const {
    vector<int> result;

    // Whichever vector is smaller coefficients are summed upon that degree. Rest is added directly.

    if (degree < in_poly.degree){

        for (int i = 0; i <= degree; i++)
            result.push_back(coefficients[i] + in_poly.coefficients[i]);

        for (int i = degree + 1; i <= in_poly.degree; i++)
            result.push_back(in_poly.coefficients[i]);
    }

    else{
        for (int i = 0; i <= in_poly.degree; i++)
            result.push_back(coefficients[i] + in_poly.coefficients[i]);

        for (int i = in_poly.degree + 1; i <= degree; i++)
            result.push_back(in_poly.coefficients[i]);
    }
    return Polynomial(result);
}

// Multiplication of two polynomials.
Polynomial Polynomial::operator*(const Polynomial &in_poly) const {
    int result_degree = degree + in_poly.degree;
    vector<int> result;
    for (int i = 0; i <= result_degree; i++) // Creating a space in order to add multiplications.
        result.push_back(0);

    for (int i = 0; i <= degree; i++){
        for (int j = 0; j <= in_poly.degree; j++){
            result[i + j] += coefficients[i] * in_poly.coefficients[j];
        }
    }
    return Polynomial(result);
}

// Overloading printing operator
ostream& operator<<(ostream &out, const Polynomial &in_poly) {
    int first_element = in_poly.coefficients[in_poly.degree];
    if (first_element < 0) // Taking absolute since I wan't it to work both ways. Negative
        first_element *= -1;
    // Decides how first element will look like.
    if (first_element == 1 && in_poly.degree > 1){
        out << "x^" << in_poly.degree;
    }else if(first_element > 1 && in_poly.degree > 1){
        out << in_poly.coefficients[in_poly.degree] << "x^" << in_poly.degree;
    }

    // For most of the coefficients between 1 and maximum degree.
    for (int i = in_poly.degree - 1; i > 1; i--){
        if (in_poly.coefficients[i] == 1){
            out << " + x^" << i;
        }else if (in_poly.coefficients[i] == -1){
            out << " - x^" << i;
        }else if (in_poly.coefficients[i] > 1){
            out << " + " << in_poly.coefficients[i] << "x^" << i;
        }else if (in_poly.coefficients[i] < 1){
            out << " - " << in_poly.coefficients[i] << "x^" << i;
        }
    }

    // How the x^1 will behave. If it's degree is greater than 1 then there will be + or - sign before the
    // coefficient with degree 1.
    if (in_poly.degree > 1){
        if (in_poly.coefficients[1] == 1){
            out << " + x";
        }else if (in_poly.coefficients[1] == -1){
            out << " - x";
        }else if (in_poly.coefficients[1] > 1){
            out << " + " << in_poly.coefficients[1] << "x";
        }else if (in_poly.coefficients[1] < 1){
            out << " - " << in_poly.coefficients[1] << "x";
        }
    }

    // How the x^1 will behave. If polynomial's degree is equal to 1 then there will not be + or - sign before
    // coefficient of x^1.
    if (in_poly.degree == 1){
        if (in_poly.coefficients[1] == 1){
            out << "x";
        }else if (in_poly.coefficients[1] == -1){
            out << "x";
        }else if (in_poly.coefficients[1] > 1){
            out << in_poly.coefficients[1] << "x";
        }else if (in_poly.coefficients[1] < 1){
            out << in_poly.coefficients[1] << "x";
        }
    }

    // How x^0 behaves while printing.
    if (in_poly.degree >= 0){
        if (in_poly.coefficients[0] > 0)
            out << " + " << in_poly.coefficients[0];
        else
            out << " - " << in_poly.coefficients[0];
    }

    if (in_poly.degree == 0){
        if (in_poly.coefficients[0] > 0)
            out << in_poly.coefficients[0];
        else
            out << in_poly.coefficients[0];
    }

    return out;
}


#endif //POLYNOMIAL_H

