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
public:
    Product(const string& name);                                // Constructor

    void addIngredient(const string &ingredient_info);          // Adds ingredient to product object.
    bool isAvailable(const Stock &stock);                       // Checks ingredients if they are available in stock
    float makeFood(Stock &stock);                               // Uses ingredients from the stock

    // Getters and Setters
    string getName() const;
    int getIngredientCount() const;
    void setIngredientCount(int ingredientCount);
    void setName(const string &name);

    ~Product();                                                 // Destructor
};


#endif //PRODUCT_H
