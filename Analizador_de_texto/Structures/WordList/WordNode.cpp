//
// Created by yordan-danilo on 14/7/20.
//

#include "WordNode.h"

#include <utility>


WordNode::WordNode(string word) {
    this->word = std::move(word);
    this->cont = 1;
    this->next = nullptr;
    this->prev = nullptr;
    this->nextPos = nullptr;

}

WordNode::~WordNode() = default;
