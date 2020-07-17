//
// Created by daniel on 16/7/20.
//

#include "PositionNode.h"

PositionNode::PositionNode(int prevChars, int lineNum) {
    this->pervChars = prevChars;
    this->lineNum = lineNum;
    this->next = nullptr;
}
