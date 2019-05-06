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
    int stock_size;
    Ingredient **stock_list;

public:
    Stock(int stock_size);
    void fillStock(string stock_file_name);
    void addStock(string name, int type, int item_count, float price);
    bool checkStock(string stock_name, int amount) const;
    void getStock(string stock_name, int amount);
    ~Stock();
    
};


#endif //STOCK_H
