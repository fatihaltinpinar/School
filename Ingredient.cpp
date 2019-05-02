/* @Author
 *
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 01.05.2019
 */

#include "Ingredient.h"
#include <iostream>

using namespace std;

Ingredient::Ingredient(const string name, const int type, const int item_count, const float price_per_unit) {
    this->name = name;
    this->type = type;
    this->item_count = item_count;
    this->price_per_unit = price_per_unit;
}

ostream &operator<<(ostream &os, const Ingredient &ingredient) {
    ingredient.print(os);
    return os;
}


float Ingredient::useIngredient(int amount) {
    if(amount > item_count) throw ("Not enough " + name);
    // TODO you cannot write an exception here, find a spot that you can write exception
    //  This homework's quality level is way low.
}


ostream& Type1::print(ostream &os) const {
    os << name << '\t' << 1 << '\t' << item_count << '\t' << price_per_unit;
}


ostream& Type2::print(ostream &os) const {
    os << name << '\t' << 2 << '\t' << item_count << '\t' << price_per_unit;
}


ostream& Type3::print(ostream &os) const {
    os << name << '\t' << 3 << '\t' << item_count << '\t' << price_per_unit;
}

