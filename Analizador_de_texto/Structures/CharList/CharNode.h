//
// Created by daniel on 4/7/20.
//

#ifndef ANALIZADOR_DE_TEXTO_CHARNODE_H
#define ANALIZADOR_DE_TEXTO_CHARNODE_H


class CharNode {
public:
    unsigned int character;
    CharNode *next;
    CharNode *last;
    int counter;
public:
    explicit CharNode(unsigned int character);
};


#endif //ANALIZADOR_DE_TEXTO_CHARNODE_H
