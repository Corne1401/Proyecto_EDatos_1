//
// Created by daniel on 17/7/20.
//

#ifndef ANALIZADOR_DE_TEXTO_ISPREFIX_H
#define ANALIZADOR_DE_TEXTO_ISPREFIX_H

#include <iostream>
using namespace std;

bool isPrefix(string prefix, string word){
    return mismatch(prefix.begin(),prefix.end(),word.begin(),word.end()).first == prefix.end();
}

#endif //ANALIZADOR_DE_TEXTO_ISPREFIX_H
