//
// Created by yordan-danilo on 7/7/20.
//

#include "Trie.h"
#include <string>
using namespace std;

Trie::Trie() {
    isEndOfWord = false;
    for (int i = 0; i < 26; ++i) {
        children[i] = nullptr;
    }
}

//Insertar una palabra en el trie
void Trie::insert(string word) {
    cout<<"Funcion insert";
    Trie *curr = this;
    for (char c : word) {
        if (!(curr->children[c - 'a'])) {
            curr->children[c - 'a'] = new Trie;
        }
        curr = curr->children[c - 'a'];
    }
    curr->isEndOfWord = true;
}

bool Trie::search(string word){
    cout<<"Funcion search";
    Trie* curr = this;
    for (char c : word) {
        curr = curr->children[c - 'a'];
        if (!curr){
            return false;
        }
    }
    if (curr->isEndOfWord){
        return true;
    }
    return false;
}

//Devuelve si hay alguna palabra en el trie comienza con el prefijo dado
bool Trie::startsWith(string prefix){
    cout<<"Funcion startsWith";
    Trie* curr = this;
    for( char c : prefix){
        curr = curr->children[c - 'a'];
        if (!curr)
            return false;
    }
    return true;
}