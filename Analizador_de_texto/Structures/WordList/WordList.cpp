//
// Created by yordan-danilo on 14/7/20.
//


#include "WordList.h"
#include "../../Helpers/Delimiters.h"

WordList::WordList() {
    this->fistNode = nullptr;
    this->lastNode = nullptr;
    this->length = 0;
}

//TODO insertar caracteres previos desde el primer caracter de la palabra y no el ultimo

void WordList::insert(const string& str, const list<string>& delimiters , int line) {
    string holder;
    string word;
    int prevChars = 0;
    for(char character : str){
        holder.push_back(character);

        if(character > 0 || holder.length() == 2){

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

                    this->fistNode = newNode;
                    this->lastNode = newNode;
                    newNode->nextPos = newPos;

                }
                else{
                    if(incrementSearch(word, newPos)){
                        word = "";
                        holder = "";
                        continue;
                    }
                    else{
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

        if(incrementSearch(word, newPos)){
            word = "";
            holder = "";
        }

        else{
            newNode->nextPos = newPos;
            this->lastNode->next = newNode;
            newNode->prev = this->lastNode;
            this->lastNode = newNode;
        }
    }


}

bool WordList::incrementSearch(const string& word, PositionNode *newPos) const {

    auto *aux = this->fistNode;
    while(aux != this->lastNode){
        if(word == aux->word){
            aux->cont++;
            if(aux->nextPos == nullptr){
                aux->nextPos = newPos;
            }
            else{
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
        aux->cont++;
        if(aux->nextPos == nullptr){
            aux->nextPos = newPos;
        }
        else{
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
