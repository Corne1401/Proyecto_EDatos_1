//
// Created by yordan-danilo on 7/7/20.
//

#ifndef PROYECTO_EDATOS_1_TRIE_H
#define PROYECTO_EDATOS_1_TRIE_H

#include <iostream>
#include <string>


using namespace std;

class Trie {
public:
    Trie *children[26];
    bool isEndOfWord;
public:
    Trie();
    void insert(string word);
    bool startsWith(string prefix);
    bool search(string word);
    };

#endif //PROYECTO_EDATOS_1_TRIE_H
