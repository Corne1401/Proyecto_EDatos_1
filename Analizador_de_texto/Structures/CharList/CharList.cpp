//
// Created by daniel on 4/7/20.
//

#include <iostream>
#include "CharList.h"
using namespace std;

CharList::CharList() {
    this->first = nullptr;
    this->last = nullptr;
}

void CharList::insert(char character) {
    auto newNode = new CharNode(character);
    if(this->first == nullptr){
        this->first = newNode;
        this->last = newNode;
    }
    else{
        auto *aux = this->first;
        while(aux != this->last){
            if(aux->character == character) {
                aux->counter++;
                return;
            }
            aux = aux->next;
        }
        if (aux->character == character){
            aux->counter++;
        }
        else {
            this->last->next = newNode;
            newNode->last = this->last;
            this->last = newNode;
        }
    }
}

bool CharList::search(char) {

}

void CharList::print() const {
    auto *aux = this->first;
    while(aux != last){
        cout << "Char: " << aux->character << " Count: " << aux->counter << endl;
        aux = aux->next;
    }
    cout << "Char: " << aux->character << " Count: " << aux->counter << endl;
}
