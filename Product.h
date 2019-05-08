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
    Ingredient** ingredients;
    string name;
    float total_price;
public:
    Product(const string& name);
    void addIngredient(const string &ingredient_info);
    bool checkAvaibility();
    float serveProduct();
    ~Product();
};


#endif //PRODUCT_H
