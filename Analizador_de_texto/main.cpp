#include <iostream>
#include <fstream>
#include <list>
#include "Helpers/StringUtils.h"
#include "Structur es/CharList/CharList.h"
using namespace std;

int main() {
    // Lista de delimitadores: hay que inicializarla en el main para poder utilizarla en el resto del programa
    list<char> delimiters = {' ', '.', ',', '!', '?', '\n'};



    // Prueba para los delimitadores
    list<string> prueba = StringCutter(delimiters,"Hola. los! delimitadores? ya funcionan,");


    for(const string& s : prueba){
        cout << s << endl;
    }

    return 0;
}
