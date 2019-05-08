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


int main(){

    cout << countLine("menu.txt");

    Stock x(100);
    x.fillStock("stock.txt");



    fstream stock_out("stock.txt");
    stock_out << "Name\tType\tItemCount\tPrice\r\n";
    stock_out << x;





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