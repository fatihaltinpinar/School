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

Product::Product(const string &name) {                          // Constructor
    this->name = name;
    ingredient_count = 0;
    ingredients = new Ingredient*[MAX_INGREDIENT_COUNT];
}

void Product::addIngredient(const string &ingredient_info){     // Adds ingredient to product object.
    if (ingredient_info == "N/A"){
        ingredients[ingredient_count] = new Type2(name, 1, 0);  // If product is not something that is cooked,
                                                                // it adds itself as an ingredient.
    }else{
        stringstream ss;
        string tmp;
        vector<string> separated_info;
        ss.clear();
        ss.str(ingredient_info);

        getline(ss, tmp, ' ');
        separated_info.push_back(tmp);

        getline(ss, tmp, ' ');
        separated_info.push_back(tmp);

        getline(ss, tmp);
        if (tmp[tmp.length() - 1] == '\r')
            tmp.erase(tmp.length() - 1, 1);
        separated_info.push_back(tmp);

        if (separated_info[1] == "gram")                    // Adding ingredients depending on the type.
            ingredients[ingredient_count] = new Type1(separated_info[2], stoi(separated_info[0]), 0);
        else if (separated_info[1] == "ml")
            ingredients[ingredient_count] = new Type3(separated_info[2], stoi(separated_info[0]), 0);
        else
            ingredients[ingredient_count] = new Type2(separated_info[1], stoi(separated_info[0]), 0);
    }
    ingredient_count++;
}

bool Product::isAvailable(const Stock &stock) {             // Checks ingredients if they are available in stock
    bool is_avaible = true;
    int i = 0;
    while (is_avaible && i < ingredient_count){ // Goes over every ingredient and checks if they is enough in the stock
        is_avaible = stock.checkStock(ingredients[i]->getName(), ingredients[i]->getItemCount());
        i++;
    }
    return is_avaible;
}

float Product::makeFood(Stock &stock) {                 // Uses ingredients from the stock
    float total = 0;
    for (int i = 0; i < ingredient_count; i++){         // Goes over every ingredient and removes them from the stack.
        try{
            total += stock.getStock(ingredients[i]->getName(), ingredients[i]->getItemCount());
        } catch (const char *error){
            cout << error << endl;
        }
    }
    return total;
}


/*                                  GETTERS AND SETTERS                                         */
string Product::getName() const {
    return name;
}

int Product::getIngredientCount() const {
    return ingredient_count;
}

void Product::setIngredientCount(int ingredientCount) {
    ingredient_count = ingredientCount;
}

void Product::setName(const string &name) {
    this->name = name;
}


Product::~Product() {                       // Destructor
    for (int i = 0; i < ingredient_count; i++)
        delete ingredients[i];
    delete [] ingredients;
}

