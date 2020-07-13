//
// Created by daniel on 13/7/20.
//

#ifndef ANALIZADOR_DE_TEXTO_ROUND_H
#define ANALIZADOR_DE_TEXTO_ROUND_H

#include <iostream>
using namespace std;


// Funcion para redondear floats a dos decimales

float round(float var){
    float value = (int) (var * 100 + 0.5);
    return (float)value/100;

}

#endif //ANALIZADOR_DE_TEXTO_ROUND_H
