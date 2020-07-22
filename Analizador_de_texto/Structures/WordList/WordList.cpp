//
// Created by yordan-danilo on 14/7/20.
//


#include "WordList.h"
#include "../../Helpers/Delimiters.h"
#include "../../Helpers/IsPrefix.h"

WordList::WordList() {
    this->fistNode = nullptr;
    this->lastNode = nullptr;
    this->length = 0;
    this->delimCount = 0;
    this->wordCount = 0;
    this->comparisionCount = 0;
}

//TODO insertar caracteres previos desde el primer caracter de la palabra y no el ultimo

void WordList::insert(const string& str, const list<string>& delimiters , int line) {
    string holder;
    string word;
    int prevChars = 0;
    for(char character : str){
        holder.push_back(character);

        if(character > 0 || holder.length() == 2){

            if(findDelimiter(holder,delimiters)){
                this->delimCount++;
            }

            if(!findDelimiter(holder,delimiters)){
                word += holder;
                holder = "";
            }
            else if (!word.empty()){

                auto newNode = new WordNode(word);
                auto newPos = new PositionNode(prevChars, line);
                string charHolder;
                for(char prevCharacter : word){
                    charHolder.push_back(prevCharacter);
                    if(prevCharacter > 0 || charHolder.length() == 2){
                        prevChars++;
                        charHolder = "";
                    }
                }
                if(findDelimiter(holder,delimiters)){
                    prevChars++;
                }

                if (this->fistNode == nullptr){

                    this->length++;
                    this->wordCount++;

                    this->fistNode = newNode;
                    this->lastNode = newNode;
                    newNode->nextPos = newPos;

                }
                else{
                    if(incrementSearch(word, newPos)){
                        word = "";
                        holder = "";
                        this->wordCount++;
                        continue;
                    }
                    else{

                        this->length++;
                        this->wordCount++;

                        newNode->nextPos = newPos;
                        this->lastNode->next = newNode;
                        newNode->prev = this->lastNode;
                        this->lastNode = newNode;
                    }

                }
                word = "";
                holder = "";
            }
            if(findDelimiter(holder,delimiters)){
                prevChars++;
            }
            holder = "";
        }

    }
    if(!word.empty()){

        auto newNode = new WordNode(word);
        auto newPos = new PositionNode(prevChars, line);

        if (this->fistNode == nullptr){

            this->length++;
            this->wordCount++;

            this->fistNode = newNode;
            this->lastNode = newNode;
            newNode->nextPos = newPos;
            return;

        }
        if(incrementSearch(word, newPos)){
            word = "";
            holder = "";
            this->wordCount++;
        }

        else{

            this->length++;
            this->wordCount++;

            newNode->nextPos = newPos;
            this->lastNode->next = newNode;
            newNode->prev = this->lastNode;
            this->lastNode = newNode;
        }
    }


}

bool WordList::incrementSearch(const string& word, PositionNode *newPos) {

    auto *aux = this->fistNode;
    while(aux != this->lastNode){
        if(word == aux->word){
            this->comparisionCount++;
            aux->cont++;
            if(aux->nextPos == nullptr){
                aux->nextPos = newPos;
            }
            else{
                this->comparisionCount++;
                auto *posAux = aux->nextPos;
                while(posAux != nullptr){
                    if(posAux->next == nullptr){
                        posAux->next = newPos;
                        return true;
                    }
                    posAux = posAux->next;
                }
            }

            return true;
        }
        aux = aux->next;
    }
    if(word == aux->word){
        this->comparisionCount++;
        aux->cont++;
        if(aux->nextPos == nullptr){
            aux->nextPos = newPos;
        }
        else{
            this->comparisionCount++;
            auto *posAux = aux->nextPos;
            while(posAux != nullptr){
                if(posAux->next == nullptr){
                    posAux->next = newPos;
                    return true;
                }
                posAux = posAux->next;
            }
        }
        return true;
    }
    return false;
}

void WordList::print() const {
    auto *aux = this->fistNode;

    while(aux != this->lastNode){
        cout << aux->word << " " << aux->cont << endl;
        aux = aux->next;
    }
    cout << aux->word << " " << aux->cont << endl;

}

void WordList::printPos() const {
    auto *aux = this->fistNode;

    while (aux != this->lastNode){

        cout << "Palabra: " << aux->word <<endl;

        auto *auxPos = aux->nextPos;
        while(auxPos != nullptr){
            cout << "Previous Chars: " << auxPos->pervChars << "| Line: " << auxPos->lineNum << endl;
            auxPos = auxPos->next;
        }
        cout << endl;
        aux = aux->next;
    }

    cout << "Palabra: " << aux->word <<endl;

    auto *auxPos = aux->nextPos;
    while(auxPos != nullptr){
        cout << "Previous Chars: " << auxPos->pervChars << "| Line: " << auxPos->lineNum << endl;
        auxPos = auxPos->next;
    }

}

void WordList::searchWord(const string& str) const {
    auto *aux = this->fistNode;
    while(aux != this->lastNode){
        if(aux->word == str){
            cout << "Palabra: " << aux->word << endl;

            auto *posAux = aux->nextPos;
            while(posAux != nullptr){
                cout << "Previous Chars: " << posAux->pervChars << "| Line: " << posAux->lineNum << endl;
                posAux = posAux->next;
            }

        }
        aux = aux->next;
    }
    if(aux->word == str){
        cout << "Palabra: " << aux->word << " | ";

        auto *posAux = aux->nextPos;
        while(posAux != nullptr){
            cout << "Previous Chars: " << posAux->pervChars << "| Line: " << posAux->lineNum << endl;
            posAux = posAux->next;
        }

    }
}

void WordList::searchPrefix(const string& prefix) const {
    auto *aux = this->fistNode;

    while(aux != this->lastNode){

        if(isPrefix(prefix,aux->word)){
            cout << aux->word << endl;
        }

        aux = aux->next;
    }

    if(isPrefix(prefix,aux->word)){
        cout << aux->word << endl;
    }
}

unsigned long WordList::memSize() const {
    unsigned long total = 0;
    auto *aux = this->fistNode;
    while(aux != this->lastNode){
        total += (aux->word.length()+1) + 32;

        auto *posAux = aux->nextPos;
        while(posAux != nullptr){
            total += 16;
            posAux = posAux->next;
        }

        aux = aux->next;
    }
    total += (aux->word.length()+1) + 32;
    auto *posAux = aux->nextPos;
    while(posAux != nullptr){
        total += 16;
        posAux = posAux->next;
    }

    return total;

}
