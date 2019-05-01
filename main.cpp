// TODO: Fix this part.

/*
 *      Fatih Altınpınar
 *      150180707
 *
 */
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string x, x2;
    char t;
    ifstream inFile;
    inFile.open("stock.txt");
    int type, itemCount, price;
    if(inFile.is_open()){
        while(!inFile.eof()){
            getline(inFile, x);
            inFile >> x >> itemCount >> price;
            cout << x << " " << itemCount << " " << price << endl;
        }
    }

    return 0;
}