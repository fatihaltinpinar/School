/* @Author
 *
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 01.05.2019
 */


#ifndef INGREDIENT_H
#define INGREDIENT_H
#include <string>

using namespace std;

class Ingredient {
protected:
    string name;
    int type;
    int item_count;
    float price_per_unit;
public:
    Ingredient(string name,int type,int itemCount, float pricePerUnit);     // Constructor

    friend ostream& operator<<(ostream &, const Ingredient &ingredient);    // << overloading for writing file.
    virtual ostream& print(ostream &os) const = 0;          // Virtual function to print stocks into stock.txt

    // Function for using ingredients.
    float useIngredient(int amount);

    // Getters
    string getName();
    int getType();
    int getItemCount();
    void setItemCount(int new_item_count);
    float getPricePerUnit();
    void setName(const string &name);
    void setType(int type);
    void setPricePerUnit(float pricePerUnit);

};



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
