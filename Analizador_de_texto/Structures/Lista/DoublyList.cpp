//
// Created by yordan-danilo on 14/7/20.
//

#include "DoublyList.h"

DoublyList::DoublyList(){
    this->fistNode = nullptr;
    this->lastNode = nullptr;
    this->tamano = 0;
}


void DoublyList::insertar(DoublyList *doublyList, NodeList *nodeList){
    if (doublyList->fistNode == nullptr){
        doublyList->fistNode = nodeList;
        doublyList->lastNode = nodeList;
        tamano++;
    } else{
        lastNode->siguiente = nodeList;
        doublyList->lastNode = nodeList;
        tamano++;
    }
}

//Para Probar
void DoublyList::recorrer(DoublyList *doublyList){
    NodeList *aux = doublyList->fistNode;
    for (int i = 0; i < doublyList->tamano; ++i) {
        cout<<aux->palabra<<endl;
        aux = aux->siguiente;
    }
}
