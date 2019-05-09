/* @Author
 *
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 01.05.2019
 */

#include <iostream>
#include <fstream>
#include <sstream>

#include "Ingredient.h"
#include "Stock.h"

using namespace std;

Stock::Stock(int capacity) {                // Constructor
    this->capacity = capacity;
    stock_size = 0;
    stock_list = new Ingredient*[capacity];
}


void Stock::fillStock(const string &stock_file_name) {          // Reads a file and fills stock with that information.

    fstream stock_file(stock_file_name);

    string line, name;
    int type, item_count;
    float price;

    stringstream ss;
    getline(stock_file, line);

    while (!stock_file.eof() && line != ""){                    // Reading to the end of the file.
        getline(stock_file, line);
        while (line[0] == '\r' || line[0] == '\n')              // Clearing the string from '\r' and '\n'
            line.erase(0, 1);
        if (line != "") {
            ss.clear();
            ss.str(line);                               // Loads the line into a string stream, then reads the values
            getline(ss, name, '\t');                    // from there. This method is not so efficient but it shortens
            ss >> type >> item_count >> price;          // the code and the program does not require that much of speed.

            try{
                addStock(name, type, item_count, price);
            }catch (const char *error) {
                cout << error << endl;
            }
        }

    }
}


void Stock::addStock(const string &name, int type, int item_count, float price) {    // Adding stock based on type.
    if (stock_size > capacity) throw "Stock at max capacity!";
        if (type == 1){                                     // Adding ingredient objects depending on their type.
        stock_list[stock_size] = new Type1(name, item_count, price);
        stock_size++;
    }else if (type == 2){
        stock_list[stock_size] = new Type2(name, item_count, price);
        stock_size++;
    }else if (type == 3){
        stock_list[stock_size] = new Type3(name, item_count, price);
        stock_size++;
    }else throw "Wrong type while adding stock";

}

bool Stock::checkStock(const string &ingredient_name, int amount) const {   // Checks an ingredient supplies the
    int i = 0;                                                              // wanted amount or not
    while (i < stock_size && stock_list[i]->getName() != ingredient_name) i++;
    if (i == stock_size) throw "There is no" + ingredient_name + "in stock!";

    return (stock_list[i]->getItemCount() >= amount);
}


float Stock::getStock(const string &ingredient_name, int amount) {  // Uses and ingredient, subtracts
    int i = 0;                                                      // given amount from the stock.
    while (i < stock_size && stock_list[i]->getName() != ingredient_name) i++;
    if (i == stock_size) throw "Not enough stock!";

    stock_list[i]->setItemCount(stock_list[i]->getItemCount() - amount);
    return (stock_list[i]->getPricePerUnit() * amount);
}


ostream& operator<<(ostream &out, const Stock &stock){  // Gives and output that is formatted as in stock.txt
    int size = stock.getStockSize();                    // so by this function, stock.txt can be updated.
    Ingredient **list = stock.getStockList();
    for (int i = 0; i < size; i++){
        out << *list[i];
    }
    return out;
}


/*                                          Getters and Setters                                                     */
int Stock::getStockSize() const {
    return stock_size;
}

void Stock::setStockSize(int stockSize) {
    stock_size = stockSize;
}

Ingredient **Stock::getStockList() const {
    return stock_list;
}

int Stock::getCapacity() const {
    return capacity;
}

Stock::~Stock() {                       // Destructor
    for(int i = 0; i < stock_size; i++){
        delete stock_list[i];
    }
    delete [] stock_list;
}