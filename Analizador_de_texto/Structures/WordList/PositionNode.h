//
// Created by daniel on 16/7/20.
//

#ifndef ANALIZADOR_DE_TEXTO_POSITIONNODE_H
#define ANALIZADOR_DE_TEXTO_POSITIONNODE_H


class PositionNode {
public:
    int pervChars;
    int lineNum;
    PositionNode *next;
public:
    PositionNode(int prevChars, int lineNum);
};


#endif //ANALIZADOR_DE_TEXTO_POSITIONNODE_H
