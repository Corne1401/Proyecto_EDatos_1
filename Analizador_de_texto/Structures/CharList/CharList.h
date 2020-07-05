//
// Created by daniel on 4/7/20.
//

#ifndef ANALIZADOR_DE_TEXTO_CHARLIST_H
#define ANALIZADOR_DE_TEXTO_CHARLIST_H

#include "CharNode.h"

class CharList {
public:
    CharNode *first;
    CharNode *last;
public:
    CharList();
    void insert(char character);
    bool search(char character);
    void print() const;
};


#endif //ANALIZADOR_DE_TEXTO_CHARLIST_H
