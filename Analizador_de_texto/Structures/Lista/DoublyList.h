//
// Created by yordan-danilo on 14/7/20.
//

#ifndef PROYECTO_EDATOS_1_DOUBLYLIST_H
#define PROYECTO_EDATOS_1_DOUBLYLIST_H
#include "NodeList.h"


class DoublyList{
public:
    NodeList *fistNode;
    NodeList *lastNode;
    int tamano;
public:
    DoublyList();
    void insertar(DoublyList *doublyList, NodeList *nodeList);
    void recorrer(DoublyList *doublyList);

    };




#endif //PROYECTO_EDATOS_1_DOUBLYLIST_H
