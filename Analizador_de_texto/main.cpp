#include <iostream>
#include <fstream>
#include <list>
#include "Helpers/StringUtils.h"
#include "Structures/CharList/CharList.h"
#include "Structures/Trie/Trie.h"
using namespace std;

int main() {
//    // Lista de delimitadores: hay que inicializarla en el main para poder utilizarla en el resto del programa
//    list<char> delimiters = {' ', '.', ',', '!', '?', '\n'};
//
//
//
//    // Prueba para los delimitadores
//    list<string> prueba = StringCutter(delimiters,"Hola. los! delimitadores? ya funcionan,");
//
//
//    for(const string& s : prueba){
//        cout << s << endl;
//    }

    CharList charList;
    string s="aéíóúéú\naá\b \n sumama";
    charList.insert(s);
    cout << charList.charTotal << endl;
    charList.print();

//    string c = "á";
//    cout << c.length() << endl;
//    string holder;
//    int count = 0;
//    for (char a : c){
//        if (count == 2){
//            cout << holder << endl;
//            if(holder == "á"){
//                cout << "Si se puede comparar" << endl;
//            }
//            holder = "";
//            count = 0;
//        }
//        if(a > 0) {
//            cout << a << " es ascii" << endl;
//            continue;
//        }
//        holder.push_back(a);
//        count++;
//    }
//    cout << holder << endl;


    return 0;
}
