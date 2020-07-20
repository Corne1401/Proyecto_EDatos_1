//
// Created by yordan-danilo on 14/7/20.
//

#ifndef PROYECTO_EDATOS_1_NODELIST_H
#define PROYECTO_EDATOS_1_NODELIST_H
#include <iostream>
#include "PositionNode.h"

using namespace std;

/**
 * @brief Estructura auxiliar de la extructura "WordList" y de sí misma.
 */

class WordNode {
public:
    string word;
    int cont;

    WordNode *next;
    WordNode *prev;
    PositionNode *nextPos;

public:
    explicit WordNode(string word);
    ~WordNode();
};


#endif //PROYECTO_EDATOS_1_NODELIST_H
