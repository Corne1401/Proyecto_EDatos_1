//
// Created by daniel on 4/7/20.
//

#ifndef ANALIZADOR_DE_TEXTO_CHARLIST_H
#define ANALIZADOR_DE_TEXTO_CHARLIST_H

#include <istream>
#include "CharNode.h"
using namespace std;

class CharList {
public:
    CharNode *first;
    CharNode *last;
    static int charTotal;
public:
    CharList();
    void insert(char character);
    void insert(const u32string& str);
    bool search(char character);
    bool incrementSearch(unsigned int character) const;
    void print() const;
};


#endif //ANALIZADOR_DE_TEXTO_CHARLIST_H
