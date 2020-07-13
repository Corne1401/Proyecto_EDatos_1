//
// Created by daniel on 4/7/20.
//

#ifndef ANALIZADOR_DE_TEXTO_STRINGUTILS_H
#define ANALIZADOR_DE_TEXTO_STRINGUTILS_H

#include <iostream>
#include <list>
#include "Delimiters.h"

using namespace std;

// Procesa una string y la devuelve en mayusculas
string ToUpperString(const string& str){
    string returnString;
    for (auto c : str){
        returnString += toupper(c);
    }
    return returnString;
}

// Procesa una string y la devuelve en mayusculas minusculas
string ToLowerString(const string& str){
    string returnString;
    for(auto c : str){
        returnString += tolower(c);
    }
    return returnString;
}

// Procesa una string y la devuelve con mayusculas despues de un punto o salto de linea
string SmartCapitalization(const string& str){
    string returnString;
    char buffer = '\0';
    for (int i = 0; i < str.length(); i++){
        if(i == 0){
            returnString += toupper(str[i]);
            continue;
        }
        if(str[i] == '.' || str[i] == '\n' || str[i] == '!' || str[i] == '?'){
            buffer = str[i];
            returnString += str[i];
            continue;
        }
        if( (buffer == '.' || buffer == '\n' || buffer == '!' || buffer == '?') && str[i] != ' '){
            returnString += toupper(str[i]);
            buffer = '\0';
            continue;
        }
        returnString += str[i];
    }
    return returnString;
}

// Recibe una lista de delimitadores y un string, luego lee cada carcter del string y revisa si es
// igual a un delimitador, si son diferentes agrega el caracter a holder para al final agregar la palabra entera
// a la returnLiss y devolver la lista de pablabras
list<string> StringCutter(const list<char>& delimiters, const string& str){
    list<string> returnList;
    string holder;
    for (char c : str){
        if(!findDelimiter(c, delimiters)){
            holder += c;
        }
        else{
            returnList.push_back(holder);
            holder = "";
        }
    }
    returnList.push_back(holder);
    returnList.remove("");
    return returnList;
}


#endif //ANALIZADOR_DE_TEXTO_STRINGUTILS_H
