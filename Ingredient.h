/* @Author
 *
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 01.05.2019
 */

#include <string>
#include <exception>
#ifndef INGREDIENT_H
#define INGREDIENT_H

using namespace std;

class Ingredient {
protected:
    string name;
    int type;
    int item_count;
    float price_per_unit;
public:
    Ingredient(string name,int type,int itemCount, float pricePerUnit);
    friend ostream& operator<<(ostream &, const Ingredient &ingredient);
    virtual ostream& print(ostream &os) const = 0;          // Virtual function to print stocks into stock.txt

    // Function for using ingredients.
    float useIngredient(int amount);

    // Getters
    string getName(){return name;}
    int getType(){return type;}
    int getItemCount(){return item_count;}
    void setItemCount(int new_item_count);
    float getPricePerUnit(){return price_per_unit;}

    //Destructor
    virtual ~Ingredient() = 0;
};

void Ingredient::setItemCount(int new_item_count) {
    if (new_item_count < 0) throw "Item count can't be lower than 0!";
    item_count = new_item_count;
}

class Type1: public Ingredient{
public:
    Type1(const string in_name, const int in_weight, const float in_price):Ingredient(in_name, 1, in_weight, in_price){}
    ostream& print(ostream &os) const;
};

class Type2: public Ingredient{
public:
    Type2(const string in_name, const int in_weight, const float in_price):Ingredient(in_name, 2, in_weight, in_price){}
    ostream& print(ostream &os) const;
};

class Type3: public Ingredient{
public:
    Type3(const string in_name, const int in_weight, const float in_price):Ingredient(in_name, 3, in_weight, in_price){}
    ostream& print(ostream &os) const;
};


#endif //INGREDIENT_H
