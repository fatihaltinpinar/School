//
// Created by faati on 24.03.2019.
// Name: Fatih Altınpınar
// ID: 150180707
//

#include <iostream>
#include <fstream>
#include <vector>

#include "Vector.h"
#include "Polynomial.h"
using namespace std;

void read_polynomials(vector<Polynomial> &);
void read_vectors(vector<Vector> &);
void print_help();
void print_vectors(const vector<Vector> &);
void print_polynomials(const vector<Polynomial> &);
void polynomial_operation(const vector<Polynomial> &);
void vector_operation(const vector<Vector> &);



int main() {
    cout << "Polynomial and Vector List Program! don't think you read here anymore" << endl;

    vector<Polynomial> polynomial_list;
    vector<Vector> vector_list;

    read_polynomials(polynomial_list);
    read_vectors(vector_list);


    print_help();


    int choice = 1;
    while (choice != 0){

        cout << endl << "Enter an option: ";
        cin >> choice;
        switch(choice) {
            case 1:
                print_vectors(vector_list);
                print_polynomials(polynomial_list);
                break;
            case 2:
                polynomial_operation(polynomial_list);
                break;
            case 3:
                vector_operation(vector_list);
            case 4:
                print_help();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
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
        cout << "Polynomial reading is completed." << endl;
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
        cout << "Vector reading is completed." << endl;
    }else{
        cerr << "Can not open Vector.txt!" << endl;
        exit(EXIT_FAILURE);
    }

}


void print_help(){
    cout << endl << "Possible Actions:" << endl;
    cout << "1. Print Polynomial and Vector lists" << endl;
    cout << "2. Do a polynomial operation" << endl;
    cout << "3. Do a vector operation" << endl;
    cout << "4. Help: Print possible actions" << endl;
    cout << "0. Exit the program" << endl;
}

void print_vectors(const vector<Vector> &vector_list){
    cout << endl << "Vectors:" << endl;
    for(int i = 0; i < vector_list.size(); i++){
        cout << i+1 << ". " << vector_list[i] << endl;
    }
}
void print_polynomials(const vector<Polynomial> &polynomial_list){
    cout << endl << "Polynomials:" << endl;
    for (int i = 0; i < polynomial_list.size(); i++){
        cout << i+1 << ". " << polynomial_list[i] << endl;
    }
}

void polynomial_operation(const vector<Polynomial> &polynomial_list){
    cout << "Which polynomial operation would you like to do?((+:addition, *:multiplication):" << endl;
    int first_op, second_op;
    char operation;
    cin >> first_op >> operation >> second_op;
    switch(operation){
        case '+':
            cout << "(" << polynomial_list[first_op - 1] << ") + (" << polynomial_list[second_op - 1];
            cout << ") = " << polynomial_list[first_op - 1] + polynomial_list[second_op - 1] << endl;
            break;
        case '*':
            cout << "(" << polynomial_list[first_op - 1] << ") * (" << polynomial_list[second_op - 1];
            cout << ") = " << polynomial_list[first_op - 1] * polynomial_list[second_op - 1] << endl;
            break;
        default:
            cout << "Invalid operation!";
    }
}

void vector_operation(const vector<Vector> &vector_list){
    cout << "Which polynomial operation would you like to do?((+:addition, *:multiplication):" << endl;
    int first_op, second_op;
    char operation;
    cin >> first_op >> operation >> second_op;
    switch(operation){
        case '+':

            cout << vector_list[first_op - 1] << " + " << vector_list[second_op - 1];
            cout << " = " << vector_list[first_op - 1] + vector_list[second_op - 1] << endl;
            break;
        case '.':
            cout << vector_list[first_op - 1] << " . " << vector_list[second_op - 1];
            cout << " = " << vector_list[first_op - 1] * vector_list[second_op - 1] << endl;
            break;
        case '*':
            cout << vector_list[first_op - 1] << " * " << second_op;
            cout << " = " << vector_list[first_op - 1] * second_op << endl;
            break;
        default:
            cout << "Invalid operation!";
    }
}


// todo remove these
//cout << "TEST " << vector_list[0] << endl;
//cout << "TEST 2 " << vector_list[0] + vector_list[1] << endl;
//cout << "TEST 3" << vector_list[0] * 4 << endl;
//cout << "TEST 4 " << vector_list[0] * vector_list[0] << endl;

//cout << "TEST " << polynomial_list[5] << endl;
//cout << "TEST 2 " << polynomial_list[0] + polynomial_list[1] << endl;
//cout << "TEST 3 " << polynomial_list[1] * polynomial_list[1] << endl;
//cout << "TEST 4 " << vector_list[0] * vector_list[0] << endl;