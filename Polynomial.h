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
    // todo add getters
    Polynomial();
    Polynomial(const vector<int> &);
    Polynomial(const Polynomial &);

    const Polynomial& operator=(const Polynomial &);

    Polynomial operator+(const Polynomial &) const;
    Polynomial operator*(const Polynomial &) const;
    friend ostream& operator<<(ostream &, const Polynomial &);

};

Polynomial::Polynomial() {
    degree = 0;
    coefficients.push_back(0);
}

Polynomial::Polynomial(const vector<int> &in_vector) {
    coefficients = in_vector;
    degree = int(in_vector.size()) - 1;
}

Polynomial::Polynomial(const Polynomial &in_poly) {
    degree = in_poly.degree;
    coefficients = in_poly.coefficients;
}

const Polynomial& Polynomial::operator=(const Polynomial &in_poly) {
    degree = in_poly.degree;
    coefficients = in_poly.coefficients;
}

// TODO add comment

Polynomial Polynomial::operator+(const Polynomial &in_poly) const {
    vector<int> result;
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


Polynomial Polynomial::operator*(const Polynomial &in_poly) const {
    int result_degree = degree + in_poly.degree;
    vector<int> result;
    for (int i = 0; i <= result_degree; i++)
        result.push_back(0);

    for (int i = 0; i <= degree; i++){
        for (int j = 0; j <= in_poly.degree; j++){
            result[i + j] += coefficients[i] * in_poly.coefficients[j];
        }
    }

    return Polynomial(result);
}

ostream& operator<<(ostream &out, const Polynomial &in_poly) {
    int first_element = in_poly.coefficients[in_poly.degree];

    if (first_element == 1 && in_poly.degree > 1){
        out << "x^" << in_poly.degree;
    }else if(abs(first_element) > 1 && in_poly.degree > 1){
        out << first_element << "x^" << in_poly.degree;
    }

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

