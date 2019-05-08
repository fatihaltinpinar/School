/* @Author
 *
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 01.05.2019
 */

#include <iostream>
#include <fstream>
#include <vector>

const int MAX_INGREDIENT_COUNT = 10;

#include "Ingredient.cpp"
#include "Stock.cpp"
#include "Product.cpp"

using namespace std;

int countLine(const string &file_name);
void readMenu(string menu_file_name, Product* menu[]);

int main(){

    int product_count = countLine("menu.txt") - 1;
    Product* menu[product_count];
    readMenu("menu.txt", menu);

    Stock x(100);
    x.fillStock("stock.txt");

    if (menu[0]->isAvailable(x))
        cout << "test = " << menu[0]->serveProduct(x);


    fstream stock_out("stock.txt", ios::out);
    stock_out << "Name\tType\tItemCount\tPrice\n";
    stock_out << x;

    for (int i = 0; i < product_count; i++)
        delete menu[i];

    return 0;
}

int countLine(const string &file_name){
    int line_count = 0;
    string tmp;
    fstream file(file_name, ios::in);
    while (!file.eof()){
        getline(file, tmp);
        line_count++;
    }
    return line_count;
}

void readMenu(string menu_file_name, Product** menu){
    fstream menu_file(menu_file_name, ios::in);

    int product_count = 0;
    stringstream ss;
    string line;
    string product_name;
    string ingredient_info;
    getline(menu_file, line);

    while (!menu_file.eof()){
        getline(menu_file, line);
        ss.clear();
        ss.str(line);
        getline(ss, product_name, '\t');

        menu[product_count] = new Product(product_name);

        while (!ss.eof()){
            getline(ss, ingredient_info, ',');
            if (ingredient_info[0] == ' ')
                ingredient_info.erase(0, 1);
            if (ingredient_info[ingredient_info.length() - 1] == '\r')
                ingredient_info.erase(ingredient_info.length() - 1, 1);
            menu[product_count]->addIngredient(ingredient_info);
        }
        product_count++;
    }



}