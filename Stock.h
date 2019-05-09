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
    Stock(int stock_size);

    void fillStock(const string &stock_file_name);
    void addStock(const string &name, int type, int item_count, float price);
    bool checkStock(const string &ingredient_name, int amount) const;
    float getStock(const string &ingredient_name, int amount);
    friend ostream& operator<<(ostream &, const Stock &stock);

    // Getters and Setters
    int getStockSize() const;
    void setStockSize(int stockSize);
    Ingredient **getStockList() const;
    int getCapacity() const;

    ~Stock();
    
};


#endif //STOCK_H
