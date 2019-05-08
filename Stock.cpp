/* @Author
 *
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 01.05.2019
 */


#include <iostream>
#include <fstream>

#include "Ingredient.h"
#include "Stock.h"
#include <sstream>

using namespace std;

Stock::Stock(int capacity) {
    this->capacity = capacity;
    stock_size = 0;
    stock_list = new Ingredient*[capacity];
}


void Stock::fillStock(const string &stock_file_name) {

    fstream stock_file(stock_file_name);
    string line, name;
    int type, item_count;
    float price;

    stringstream ss;


    getline(stock_file, line);
    while (!stock_file.eof() && line != ""){
        getline(stock_file, line);
        if (line != "") {
            ss.clear();
            ss.str(line);
            name = ss.str(); // TODO what is this for?
            getline(ss, name, '\t');
            ss >> type >> item_count >> price;

            addStock(name, type, item_count, price);
        }

    }
}


void Stock::addStock(const string &name, int type, int item_count, float price) {    // Adding stock based on type.
    if (stock_size > capacity) throw "Stock at max capacity!";
        if (type == 1){
        stock_list[stock_size] = new Type1(name, item_count, price);
    }else if (type == 2){
        stock_list[stock_size] = new Type2(name, item_count, price);
    }else if (type == 3){
        stock_list[stock_size] = new Type3(name, item_count, price);
    }else throw "Wrong type while adding stock";
    stock_size++;
}

bool Stock::checkStock(const string &ingredient_name, int amount) const {
    int i = 0;
    while (i < stock_size && stock_list[i]->getName() != ingredient_name) i++;
    if (i == stock_size) throw "There is no" + ingredient_name + "in stock!";

    return (stock_list[i]->getItemCount() >= amount);
}


float Stock::getStock(const string &ingredient_name, int amount) {
    int i = 0;
    while (i < stock_size && stock_list[i]->getName() != ingredient_name) i++;
    if (i == stock_size) throw "Not enough stock!";

    stock_list[i]->setItemCount(stock_list[i]->getItemCount() - amount);
    return (stock_list[i]->getPricePerUnit() * amount);
}


ostream& operator<<(ostream &out, const Stock &stock){
    int size = stock.getStockSize();
    Ingredient **list = stock.getStockList();
    for (int i = 0; i < size; i++){
        out << *list[i];
    }
    return out;
}

Stock::~Stock() {
    for(int i = 0; i < stock_size; i++){
        delete stock_list[i];
    }
    delete [] stock_list;
}

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
