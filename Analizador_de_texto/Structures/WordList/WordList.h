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
    int delimCount;
    int wordCount;
    int comparisionCount;
    int memAccess;
public:
    WordList();
    void insert(const string& str,const list<string>& delimiters, int line);
    bool incrementSearch(const string& word, PositionNode *newPos);
    void print() const;
    void printPos() const;
    void searchWord(const string& str) const;
    void searchPrefix(const string& prefix) const;
    unsigned long memSize() const;

    };




#endif //PROYECTO_EDATOS_1_DOUBLYLIST_H
