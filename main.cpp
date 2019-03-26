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


// Declaration of several functions

void read_polynomials(vector<Polynomial> &); // Reading polynomials from file
void read_vectors(vector<Vector> &);  // Reading vectors from file
void print_help(); // Printing the menu, which is the first thing you see when you run the program
void print_vectors(const vector<Vector> &); // Printing all the Vector objects in the vector
void print_polynomials(const vector<Polynomial> &); // Printing all the Polynomial objects in the vector
void polynomial_operation(const vector<Polynomial> &); // Doing an operation with polynomials
void vector_operation(const vector<Vector> &); // Doing an operation with vectors



int main() {
    cout << "Polynomial and Vector List Program! don't think you read here anymore" << endl;

    // Lists that hold our objects.
    vector<Polynomial> polynomial_list;
    vector<Vector> vector_list;

    // Reading functions called with the lists created above. Pass by reference.
    read_polynomials(polynomial_list);
    read_vectors(vector_list);


    // Printing the navigation menu which shows what user can do.
    print_help();

    //REPL for main menu
    int choice = 1;
    while (choice != 0){

        cout << endl << "Enter an option: ";
        cin >> choice;
        switch(choice) {
            case 1: // Printing all vectors and polynomials.
                print_vectors(vector_list);
                print_polynomials(polynomial_list);
                break;
            case 2: // Call function to make polynomial operations.
                polynomial_operation(polynomial_list);
                break;
            case 3: // Call function to make vector operations.
                vector_operation(vector_list);
                break;
            case 4: // Print the menu -help- again.
                print_help();
                break;
            case 0: // Exiting the program done by terminating the while loop.
                break;
            default: // Invalid entry
                cout << "Invalid choice" << endl;
        }
    }
    return 0;
}

// Function that reads polynomials from the txt file.
void read_polynomials(vector<Polynomial> &polynomial_list){
    int n;

    ifstream poly_file;
    poly_file.open("Polynomial.txt"); // Opening txt file.

    if (poly_file.is_open()){
        poly_file >> n;  // Reading txt file like it was given as input to the console (stream)
        for (int i = 0 ; i < n; i++){

            int degree;
            poly_file >> degree;

            vector<int> poly_reader;
            for (int j = 0; j <= degree; j++)
                poly_reader.push_back(0); //Creating empty space in order to start adding from highest degree coefficient.

            int tmp;
            for (int j = degree; j >= 0; j--){
                // Reading every number and adding it to corresponding place in vector that holds coefficients.
                poly_file >> tmp;
                poly_reader[j] = tmp;
            }
            polynomial_list.push_back(Polynomial(poly_reader));
        }
        cout << "Polynomial reading is completed." << endl;
    }else {
        cerr << "Can not open Polynomial.txt!" << endl;
    }
}

// Function that reads vectors from the txt file.
void read_vectors(vector<Vector> &vector_list){
    int n;

    ifstream vector_file ("Vector.txt");

    if (vector_file.is_open()){
        vector_file >> n;  // Reading txt file like it was given as input to the console (stream)
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
    }

}

// Printing the menu
void print_help(){
    cout << endl << "Possible Actions:" << endl;
    cout << "1. Print Polynomial and Vector lists" << endl;
    cout << "2. Do a polynomial operation" << endl;
    cout << "3. Do a vector operation" << endl;
    cout << "4. Help: Print possible actions" << endl;
    cout << "0. Exit the program" << endl;
}

// Prints all the vectors from vector_list onto screen
void print_vectors(const vector<Vector> &vector_list){
    cout << endl << "Vectors:" << endl;
    for(unsigned int i = 0; i < vector_list.size(); i++){
        cout << i+1 << ". " << vector_list[i] << endl;
    }
}

// Prints all the polynomials from polynomial_list onto screen
void print_polynomials(const vector<Polynomial> &polynomial_list){
    cout << endl << "Polynomials:" << endl;
    for (unsigned int i = 0; i < polynomial_list.size(); i++){
        cout << i+1 << ". " << polynomial_list[i] << endl;
    }
}

void polynomial_operation(const vector<Polynomial> &polynomial_list){
    cout << "Which polynomial operation would you like to do?((+:addition, *:multiplication):" << endl;
    int first_op, second_op;
    char operation;
    cin >> first_op >> operation >> second_op; // cin ignores spaces which allows reading int + char + int inputs
    switch(operation){
        case '+': // Addition
            cout << "(" << polynomial_list[first_op - 1] << ") + (" << polynomial_list[second_op - 1];
            cout << ") = " << polynomial_list[first_op - 1] + polynomial_list[second_op - 1] << endl;
            break;
        case '*': // Multiplication
            cout << "(" << polynomial_list[first_op - 1] << ") * (" << polynomial_list[second_op - 1];
            cout << ") = " << polynomial_list[first_op - 1] * polynomial_list[second_op - 1] << endl;
            break;
        default:
            cout << "Invalid operation!" << endl;
    }
}

void vector_operation(const vector<Vector> &vector_list){
    cout << "Which vector operation would you like to do?((+:addition, *:scalar multiplication, .:dot product):" << endl;
    int first_op, second_op;
    char operation;
    cin >> first_op >> operation >> second_op;  // cin ignores spaces which allows reading int + char + int inputs
    switch(operation){
        case '+': // Addition

            cout << vector_list[first_op - 1] << " + " << vector_list[second_op - 1];
            cout << " = " << vector_list[first_op - 1] + vector_list[second_op - 1] << endl;
            break;
        case '.': // Dot Product
            cout << vector_list[first_op - 1] << " . " << vector_list[second_op - 1];
            cout << " = " << vector_list[first_op - 1] * vector_list[second_op - 1] << endl;
            break;
        case '*': // Scalar Multiplication
            cout << vector_list[first_op - 1] << " * " << second_op;
            cout << " = " << vector_list[first_op - 1] * second_op << endl;
            break;
        default: // Invalid operation
            cout << "Invalid operation!";
    }
}

