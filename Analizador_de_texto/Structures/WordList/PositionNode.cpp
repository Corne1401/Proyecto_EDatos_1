//
// Created by daniel on 16/7/20.
//

#include "PositionNode.h"

/**
 *
 * @param prevChars Ubicacion en la linea.
 * @param lineNum Ubicacio de numero de linea.
 */

PositionNode::PositionNode(int prevChars, int lineNum) {
    this->pervChars = prevChars;
    this->lineNum = lineNum;
    this->next = nullptr;
}
