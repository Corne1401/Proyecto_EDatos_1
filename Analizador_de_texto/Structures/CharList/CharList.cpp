//
// Created by daniel on 4/7/20.
//

#include <iostream>
#include "CharList.h"
using namespace std;

CharList::CharList() {
    this->charTotal = 0;
    this->first = nullptr;
    this->last = nullptr;
}



void CharList::insert(const string& str) {
    string holder;

    for (char character : str) {

        holder.push_back(character);
        if(character > 0 || holder.length() == 2){

            switch(character){
                case '\n':
                    holder = "'Enter'";
                    break;
                case '\t':
                    holder = "'Horizontal Tab'";
                    break;
                case '\v':
                    holder = "'Vertical Tab'";
                    break;
                case '\b':
                    holder = "'Backspace'";
                    break;
                case ' ':
                    holder = "'Space'";
                    break;
                default:
                    break;
            }

            auto newNode = new CharNode(holder);
            this->charTotal++;

            if (this->first == nullptr) {
                this->first = newNode;
                this->last = newNode;
            } else {
                if(incrementSearch(holder)){
                    holder = "";
                    continue;

                } else {
                    this->last->next = newNode;
                    newNode->last = this->last;
                    this->last = newNode;
                }
            }
            holder = "";
        }
    }
}

bool CharList::search(char character) {

}
bool CharList::incrementSearch(const string& character) const {
    auto *aux = this->first;
    while (aux != this->last) {
        if (aux->character == character) {
            aux->counter++;
            return true;
        }
        aux = aux->next;
    }
    if (aux->character == character) {
        aux->counter++;
        return true;
    }
    return false;
}


void CharList::print() const {
    auto *aux = this->first;
    while(aux != last){
        cout << "Char: " << aux->character << " Count: " << aux->counter << endl;
        aux = aux->next;
    }
    cout << "Char: " << aux->character << " Count: " << aux->counter << endl;
}

