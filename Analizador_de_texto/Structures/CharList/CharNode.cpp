//
// Created by daniel on 4/7/20.
//

#include "CharNode.h"

CharNode::CharNode(unsigned int character) {
    this->character = character;
    this->next = nullptr;
    this->last = nullptr;
    this->counter = 1;
}
