//
// Created by yordan-danilo on 14/7/20.
//

#ifndef PROYECTO_EDATOS_1_NODELIST_H
#define PROYECTO_EDATOS_1_NODELIST_H
#include <iostream>

using namespace std;

class NodeList {
public:
    string palabra;
    int caracteresAnteriores, numeroDeLinea;
    NodeList *siguiente;
    NodeList *anterior;
};


#endif //PROYECTO_EDATOS_1_NODELIST_H
