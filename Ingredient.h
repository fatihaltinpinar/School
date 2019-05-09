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

    // This is a trick that is used for implementing << to act like it is a virtual function.
    // Friend functions cannot be virtualized. A polymorphic member function is created and called from
    // friend function.
    friend ostream& operator<<(ostream &, const Ingredient &ingredient);    // << overloading for writing file.
    virtual ostream& print(ostream &os) const = 0;   // Virtual function to print stocks into stock.txt

    // Function for using ingredients.
    float useIngredient(int amount);

    // Getters
    string getName();
    void setItemCount(int new_item_count);
    void setName(const string &name);
    void setType(int type);
    void setPricePerUnit(float pricePerUnit);
    int getType();
    int getItemCount();
    float getPricePerUnit();

};



class Type1: public Ingredient{
public:
    // Constructor
    Type1(const string &in_name, const int in_weight, const float in_price):Ingredient(in_name, 1, in_weight, in_price){}
    ostream& print(ostream &os) const;
};

class Type2: public Ingredient{
public:
    // Constructor
    Type2(const string &in_name, const int in_weight, const float in_price):Ingredient(in_name, 2, in_weight, in_price){}
    ostream& print(ostream &os) const;
};

class Type3: public Ingredient{
public:
    // Constructor
    Type3(const string &in_name, const int in_weight, const float in_price):Ingredient(in_name, 3, in_weight, in_price){}
    ostream& print(ostream &os) const;
};


#endif //INGREDIENT_H
