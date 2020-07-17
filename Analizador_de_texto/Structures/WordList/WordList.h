//
// Created by yordan-danilo on 14/7/20.
//

#ifndef PROYECTO_EDATOS_1_DOUBLYLIST_H
#define PROYECTO_EDATOS_1_DOUBLYLIST_H

#include <list>
#include "WordNode.h"





class WordList{
public:
    WordNode *fistNode;
    WordNode *lastNode;
    int length;
public:
    WordList();
    void insert(const string& str,const list<string>& delimiters, int line);
    bool incrementSearch(const string& word, PositionNode *newPos) const;
    void print() const;
    void printPos() const;

    };




#endif //PROYECTO_EDATOS_1_DOUBLYLIST_H
