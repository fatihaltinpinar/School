/* @Author
 * 
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 07.05.2019
 */

#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
#include "Ingredient.h"
#include "Stock.h"


class Food {
    int ingredient_count;
    Ingredient** ingredients;
    string name;
    float total_price;
public:
    Food(string& name);
    void addIngredient(Ingredient &ingredient);
    float makeFood(int countity);

};


#endif //FOOD_H
