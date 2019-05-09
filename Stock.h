/* @Author
 *
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 01.05.2019
 */

#ifndef STOCK_H
#define STOCK_H
#include <string>

#include "Ingredient.h"


class Stock {
    int capacity;
    int stock_size;
    Ingredient **stock_list;
public:
    Stock(int stock_size);                                   // Constructor

    void fillStock(const string &stock_file_name);          // Reads a file and fills stock with that information.
    void addStock(const string &name, int type, int item_count, float price); //Adds a single ingredient to stock.
    bool checkStock(const string &ingredient_name, int amount) const; // Checks an ingredient supplies the wanted amount or not.
    float getStock(const string &ingredient_name, int amount); // Uses and ingredient, subtracts given amount from the stock.
    friend ostream& operator<<(ostream &, const Stock &stock);  // Gives and output that is formatted as in stock.txt
                                                                // so by this function, stock.txt can be updated.

    // Getters and Setters
    int getStockSize() const;
    void setStockSize(int stockSize);
    Ingredient **getStockList() const;
    int getCapacity() const;

    ~Stock();                                               // Destructor

};


#endif //STOCK_H
