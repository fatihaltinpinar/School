/* @Author
 *
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 07.05.2019
 */

#include <vector>
#include <string>
#include <sstream>
#include "Product.h"

Product::Product(const string &name) {
    this->name = name;
    ingredient_count = 0;
    total_price = 0; // TODO fix or remove this
    ingredients = new Ingredient*[MAX_INGREDIENT_COUNT];
}

void Product::addIngredient(const string &ingredient_info){
    if (ingredient_info == "N/A"){
        ingredients[ingredient_count] = new Type2(name, 1, 0);
    }else{
        stringstream ss;
        string tmp;
        vector<string> separated_info;


        ss.str(ingredient_info);

        getline(ss, tmp, ' ');
        separated_info.push_back(tmp);

        getline(ss, tmp, ' ');
        separated_info.push_back(tmp);

        getline(ss, tmp);
        if (tmp[tmp.length() - 1] == '\r')
            tmp.erase(tmp.length() - 1, 1);
        separated_info.push_back(tmp);

        if (separated_info[1] == "gram")
            ingredients[ingredient_count] = new Type1(separated_info[2], stoi(separated_info[0]), 0);
        else if (separated_info[1] == "ml")
            ingredients[ingredient_count] = new Type3(separated_info[2], stoi(separated_info[0]), 0);
        else
            ingredients[ingredient_count] = new Type2(separated_info[1], stoi(separated_info[0]), 0);
    }
    ingredient_count++;
}

bool Product::checkAvaibility(const Stock &stock) {
    bool is_avaible = true;
    int i = 0;
    while (is_avaible && i < ingredient_count){
        is_avaible = stock.checkStock(ingredients[i]->getName(), ingredients[i]->getItemCount());
        i++;
    }
    return is_avaible;
}

float Product::serveProduct(Stock &stock) {
    float total = 0;
    for (int i = 0; i < ingredient_count; i++){
        total += stock.getStock(ingredients[i]->getName(), ingredients[i]->getItemCount());
    }
    return total;
}

Product::~Product() {
    for (int i = 0; i < ingredient_count; i++)
        delete ingredients[i];
    delete [] ingredients;
}