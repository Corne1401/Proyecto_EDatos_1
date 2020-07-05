#include <iostream>
#include <fstream>
#include "Helpers/StringUtils.h"
#include "Structures/CharList/CharList.h"
using namespace std;

int main() {
    string s = "Este es el primer proyecto de estructuras de datos del primer semestre del dos mil veintiuno";
    CharList charList;
    for(char c : s){
        charList.insert(c);
    }

    charList.print();

    return 0;
}
