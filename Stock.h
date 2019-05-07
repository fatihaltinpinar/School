/* @Author
 *
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 01.05.2019
 */
#ifndef STOCK_H
#define STOCK_H

#include "Ingredient.h"
#include <string>

class Stock {
    int capacity;
private:
    int stock_size;
    Ingredient **stock_list;
public:
    Stock(int stock_size);
    void fillStock(const string &stock_file_name);
    void addStock(const string &name, int type, int item_count, float price);
    bool checkStock(const string &ingredient_name, int amount) const;
    float getStock(const string &ingredient_name, int amount);
    int getCapacity() const;
    friend ostream& operator<<(ostream &, const Stock &stock);
    int getStockSize() const;
    Ingredient **getStockList() const;
    void setStockSize(int stockSize);
    ~Stock();
    
};


#endif //STOCK_H
