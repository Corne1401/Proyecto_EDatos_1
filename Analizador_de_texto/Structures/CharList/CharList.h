//
// Created by daniel on 4/7/20.
//

#ifndef ANALIZADOR_DE_TEXTO_CHARLIST_H
#define ANALIZADOR_DE_TEXTO_CHARLIST_H

#include <iostream>
#include "CharNode.h"
using namespace std;

class CharList {
public:
    CharNode *first;
    CharNode *last;
    float charTotal;
public:
    CharList();
    void insert(const string& character);
    bool incrementSearch(const string& character) const;
    void graph() const;
    void print() const;
    static void swap (CharNode *a, CharNode *b);
    static void bubbleSort(CharNode *start);

};


#endif //ANALIZADOR_DE_TEXTO_CHARLIST_H
