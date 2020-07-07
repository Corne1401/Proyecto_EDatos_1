#include <iostream>
#include <fstream>
#include "Helpers/StringUtils.h"
#include "Structures/CharList/CharList.h"
using namespace std;

int main() {

//    CharList charList;
//
//    cout << "Ingrese el path del archivo a procesar" << endl;
//
//    u32string line;
//    string path;
//    cin >> path;
//    ifstream workingFile(path);
//    if(workingFile.is_open()){
//
//        cout << "Desea que el programa procese mayusculas? [y/n]" << endl;
//        char selectCapInput;
//        cin >> selectCapInput;
//
//        if(tolower(selectCapInput) == 'y'){
//            while(getline(workingFile,line){charList.insert(line);}  //TODO
//        }
//        else if (tolower(selectCapInput) == 'n'){
//            while(getline(workingFile,line)){charList.insert(ToLowerString(line));} //TODO
//        }
//        else {
//            cout << "Opcion no valida" << endl;
//        }
//
//    }







//    string s = "Este es el primer proyecto de estructuras de datos del primer semestre del dos mil veinte";
//
//    for(char c : s){
//        charList.insert(c);
//    }
//
//    charList.print();

    vector<string> prueba = StringCutter("Hola mi nombre es daniel");

    for(string s : prueba){
        cout << s << endl;
    }

    return 0;
}
