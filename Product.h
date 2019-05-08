/* @Author
 * 
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 07.05.2019
 *
 */

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include "Ingredient.h"
#include "Stock.h"


class Product {
    int ingredient_count;
    float total_price;  // TODO fix or remove this
    Ingredient** ingredients;
    string name;
public:
    Product(const string& name);
    void addIngredient(const string &ingredient_info);
    bool checkAvaibility(const Stock &stock);
    float serveProduct(Stock &stock);
    ~Product();
};


#endif //PRODUCT_H
