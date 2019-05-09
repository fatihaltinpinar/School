/* @Author
 *
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 01.05.2019
 */

#include <iostream>

#include "Ingredient.h"


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



void Ingredient::setItemCount(int new_item_count) {
    if (new_item_count < 0) throw "Item count can't be lower than 0!";
    item_count = new_item_count;
}

void Ingredient::setName(const string &name) {
    this->name = name;
}

void Ingredient::setType(int type) {
    this->type = type;
}

void Ingredient::setPricePerUnit(float pricePerUnit) {
    price_per_unit = pricePerUnit;
}


// Polymorphism is used here
// Polymorphic functions to print stock.txt
ostream& Type1::print(ostream &os) const {
    os << name << '\t' << 1 << '\t' << item_count << '\t' << price_per_unit << "\n";
}


ostream& Type2::print(ostream &os) const {
    os << name << '\t' << 2 << '\t' << item_count << '\t' << price_per_unit << "\n";
}


ostream& Type3::print(ostream &os) const {
    os << name << '\t' << 3 << '\t' << item_count << '\t' << price_per_unit << "\n";
}

