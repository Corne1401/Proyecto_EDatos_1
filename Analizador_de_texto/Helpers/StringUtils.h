//
// Created by daniel on 4/7/20.
//

#ifndef ANALIZADOR_DE_TEXTO_STRINGUTILS_H
#define ANALIZADOR_DE_TEXTO_STRINGUTILS_H

#include <iostream>
#include <list>


using namespace std;
/**
 *
 * @param str Procesa una string.
 * @return La devuelve en mayusculas.
 */

string ToUpperString(const string& str){
    string returnString;
    for ( c : str){
        returnString += toupper(c);
    }
    return returnString;
}

/**
 *
 * @param str Palabra a procesar.
 * @return //  Mayusculas a minusculas.
 */

string ToLowerString(const string& str){
    string returnString;
    for(auto c : str){
        returnString += tolower(c);
    }
    return returnString;
}

/**
 *
 * @param str Palabra a procesar.
 * @return // Mayusculas despues de un punto o salto de linea.
 */

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


#endif //ANALIZADOR_DE_TEXTO_STRINGUTILS_H
