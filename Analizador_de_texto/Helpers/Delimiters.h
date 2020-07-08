//
// Created by daniel on 7/7/20.
//

#ifndef ANALIZADOR_DE_TEXTO_DELIMITERS_H
#define ANALIZADOR_DE_TEXTO_DELIMITERS_H

#include <iostream>
#include <list>
using namespace std;

bool findDelimiter(char delimiter, const list<char>& delimiters){
    for(char c : delimiters){
        if(c == delimiter) return true;
    }
    return false;
}



#endif //ANALIZADOR_DE_TEXTO_DELIMITERS_H
