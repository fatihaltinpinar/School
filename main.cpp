/* @Author
 *
 * Student Name: Fatih Altınpınar
 * Student ID: 150180707
 * Date: 01.05.2019
 */

#include <iostream>
#include <fstream>
#include <vector>


// Defining constants
const int MAX_INGREDIENT_COUNT = 10;
const int taxRate = 8;
const int tipRate = 15;

#include "Ingredient.cpp"
#include "Stock.cpp"
#include "Product.cpp"

using namespace std;

/*                                    Helper Function Declarations                                                    */

// Checks the products ability to be served and serves it if it is available.
float serveProduct(Product **menu, const int product_count, Stock &stock, const string &product_name);
int countLine(const string &file_name);                    // Counts how many lines a file has.
void readMenu(string menu_file_name, Product* menu[]);     // Reads menu file and fills menu array with product objects.
void removeNewline(string &text);           // Removes '\r' and '\n' characters from beginning and the end of a string.


/*                                  Main Program                                                                      */
int main(){

    int product_count = countLine("menu.txt") - 1;          // Counting how many products there are.
    Product* menu[product_count];
    readMenu("menu.txt", menu)                          // Filling menu array with dynamically created product objects.

    int stock_count = countLine("stock.txt") - 1;       // Counting how many ingredients exist in the stock.
    Stock stock(stock_count);
    stock.fillStock("stock.txt");                       // Loading ingredients from "stock.txt"


    fstream order_file("order.txt", ios::in);

    string table_name, order, order_name;
    int order_count, order_amount;
    while (!order_file.eof()){

        getline(order_file, table_name);
        removeNewline(table_name);

        cout << table_name << " ordered:" << endl;

        getline(order_file, order);
        removeNewline(order);

        order_count = stoi(order);

        float total_cost = 0, product_cost;
        for (int i = 0; i < order_count; ++i) {
            getline(order_file, order, ' ');
            order_amount = stoi(order);

            getline(order_file, order_name);
            removeNewline(order_name);

            int k = 0, served = 0;
            product_cost = 0;
            bool isAvaliable = true;
            while (k < order_amount && isAvaliable){

                // Error handling. Rest of the homework always expected to work as intended.
                // Only this place seem to fit right in.
                try{
                    product_cost += serveProduct(menu, product_count, stock, order_name);
                    served++;
                }catch (const char *error){
                    if (error == "Not enough ingredients"){
                        cout << "We don't have enough " << order_name << endl;
                        isAvaliable = false;
                    }
                }
                k++;
            }
            total_cost += product_cost;
            if(served != 0)
                cout << served << " " << order_name << " cost: " << product_cost << "\r\n";

        }
        float tip = (total_cost * tipRate) / 100;
        float tax = (total_cost * taxRate) / 100;

        total_cost = total_cost + tip + tax;
        cout << "Tip is " << tip << "\r\n";
        cout << "Total cost: " << total_cost << "\r\n";
        cout << "***************************" << "\r\n";
    }

    fstream stock_out("stock.txt", ios::out);
    stock_out << "Name\tType\tItemCount\tPrice\n";
    stock_out << stock;

    for (int i = 0; i < product_count; i++)
        delete menu[i];

    return 0;
}


/*                                     Helper Function Definitions                                                    */
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

float serveProduct(Product **menu, const int product_count, Stock &stock, const string &product_name){
    int i = 0;
    while (i < product_count && menu[i]->getName() != product_name)
        i++;
    
    if (i == product_count) throw "This product does not exist!";
    if (!menu[i]->isAvailable(stock)) throw "Not enough ingredients";
    
    return menu[i]->makeFood(stock);
}

void removeNewline(string &text){
    int length = text.length();
    while (text[0] == '\r' || text[0] == '\n')
        text.erase(0, 1);
    while (text[length - 1] == '\r' || text[length - 1] == '\n')
        text.erase(length - 1, 1);
}