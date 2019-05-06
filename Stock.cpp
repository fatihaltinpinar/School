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

using namespace std;

Stock::Stock(int stock_size) {
    this->stock_size = stock_size;
    stock_list = new Ingredient*[stock_size];
}


void Stock::fillStock(string stock_file_name) {

    fstream stock_file(stock_file_name, ios::in);
    string name;
    int type, item_count;
    float price;

    getline(stock_file, name);                      // For ignoring first line.
    while (!stock_file.eof()){  // Do until end of the file.
        char k = stock_file.peek();
        getline(stock_file, name, '\t');
        while (name[0] == '\n' || name[0] == '\r')
            name.erase(0,1);
        if (name.length() > 0){
        stock_file >> type >> item_count >> price;
        cout << name << type << item_count << price;
        }
    }

}


void Stock::addStock(string name, int type, int item_count, float price) {    // Adding stock based on type.
    if (type == 1){
        stock_list[stock_size] = new Type1(name, item_count, price);
    }else if (type == 2){
        stock_list[stock_size] = new Type2(name, item_count, price);
    }else if (type == 3){
        stock_list[stock_size] = new Type2(name, item_count, price);
    }else throw "Wrong type while adding stock";
    stock_size++;
}


Stock::~Stock() {
    for(int i = 0; i < stock_size; i++){
        delete stock_list[i];
    }
    delete [] stock_list;
}