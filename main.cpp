/* @Author
 *
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 01.05.2019
 */

#include <iostream>
#include <fstream>
#include <vector>

#include "Ingredient.cpp"
#include "Stock.cpp"


using namespace std;



int main(){
    Stock x(100);
    x.fillStock("stock.txt");
    return 0;
}