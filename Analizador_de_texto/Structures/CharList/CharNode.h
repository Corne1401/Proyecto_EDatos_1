//
// Created by daniel on 4/7/20.
//

#ifndef ANALIZADOR_DE_TEXTO_CHARNODE_H
#define ANALIZADOR_DE_TEXTO_CHARNODE_H

#include <iostream>
using namespace std;

/**
 * @brief Estructura auxiliar de la extructura "CharList" y de sí misma.
 */

class CharNode {
public:
    string character;
    float counter;
    CharNode *next;
    CharNode *last;
public:
    explicit CharNode(string character);
};


#endif //ANALIZADOR_DE_TEXTO_CHARNODE_H
