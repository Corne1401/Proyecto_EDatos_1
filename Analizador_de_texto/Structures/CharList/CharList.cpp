


//
// Created by daniel on 4/7/20.
//

#include "../../Helpers/Round.h"
#include "CharList.h"
using namespace std;

/**
 * @brief Constructor de la lista de caracteres
 */

CharList::CharList() {
    this->charTotal = 0;
    this->first = nullptr;
    this->last = nullptr;
}

/**
 *
 * @param str Caracter.
 * @brief Inserta un nuevo caracter en la estructura "CharList" para los caracteres.
 */

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

/**
 *
 * @param character
 * @return Aumento en el contador de un caracter si solo si existe en la Estructura "CharList".  ¿True/False?
 */

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

/**
 * @brief Histograma con los porcentajes de aparicion de cada caracter en la estructura "CharList".
 */

void CharList::graph() const {

    auto *aux = this->first;
    float percent;

    CharList::bubbleSort(aux);
    while(aux != last){
        percent = ((aux->counter * 100) / this->charTotal);
        cout << "Char: " << aux->character << "> %" << round(percent);
        for(int i = 0; i < (int)round(percent); i ++){
            cout << "|";
        }
        cout << endl;
        aux = aux->next;

    }
    percent = ((aux->counter * 100) / this->charTotal);
    cout << "Char: " << aux->character << "> %" << round(percent);
    for(int i = 0; i < (int)round(percent); i ++){
        cout << "|";
    }
    cout << endl;
}

/**
 * @return imprime el contenido de la Estructura CharList
 */

void CharList::print() const {
    CharList::bubbleSort(this->first);
    auto *aux = this->first;
    while(aux != last){
        cout << "Char: " << aux->character << " Count: " << aux->counter << endl;
        aux = aux->next;
    }
    cout << "Char: " << aux->character << " Count: " << aux->counter << endl;
}

/**
 *
 * @param start Primer Nodo
 * @return Ordenamiento en la estructura "CharList".
 */

void CharList::bubbleSort(CharNode *start) {
    int swapped, i;
    CharNode *ptr1;
    CharNode *lptr = nullptr;

    /* Checking for empty list */
    if (start == nullptr)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->counter > ptr1->next->counter)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

/**
 *
 * @param caracter Nodo a
 * @param caracter Nodo b
 *@brief Intercambio de datos de dos elementos en la estructura "CharList".
 *
 * @return Evitar el intercambio de punteros.
 */

void CharList::swap(CharNode *a, CharNode *b) {
    float tempC = a->counter;
    string tempS = a->character;

    a->counter = b->counter;
    a->character = b->character;

    b->counter = tempC;
    b->character = tempS;
}

unsigned long CharList::memSize() const {
    unsigned long total = 0;
    auto *aux = this->first;
    while(aux != this->last){
        total += (aux->character.length()+1) + 24;
        aux = aux->next;
    }
    total += (aux->character.length()+1) + 24;
    return total;
}

