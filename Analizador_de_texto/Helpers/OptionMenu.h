//
// Created by yordan-danilo on 6/7/20.
//

#ifndef PROYECTO_EDATOS_1_OPTIONMENU_H
#define PROYECTO_EDATOS_1_OPTIONMENU_H

#include <iostream>
#include "../Structures/CharList/CharList.h"
#include "../Structures/WordList/WordList.h"
using namespace std;


void pause();

/**
 *
 * @param charList
 * @param wordList
 * @param execTime
 * @param fileSize
 * @return Mostrará al usuario un menú de opciones:
 * a. brindará el Histograma de la parte A del programa.
 * b. brindará la lista ordenada de todo el diccionario de palabras y los valores asociados con la cantidad de cada una.
 * c. presentara las ubicaciones(# de línea y posición absoluta) de todas las ocurrencias de las palabras del diccionario.
 * d. Consultará al usuario por una palabra o token en particular
 * e. Permitirá buscar palabras o tokens que inicien con un prefijo que el usuario indique.
 * f .Mostrará de forma clara la cantidad de tiempo en la duro la ejecución con dichas operaciónes
 * g. Fin del programa.
 */

void MostarMenu(CharList &charList, WordList &wordList, double &execTime, unsigned long &fileSize){
    bool bandera=false;
    char tecla;
    string word;
    string prefix;

    do
    {
        system("cls");
        cin.clear();
        cout << "Análisis de Textos" << endl;
        cout << "-----------" << endl << endl;
        cout << "\ta. Ver Histograma" << endl;
        cout << "\tb. Ver Diccionario de Palabras/Tokens" << endl;
        cout << "\tc. Ver Diccionario de Palabras/Tokens con posiciones" << endl;
        cout << "\td. Buscar Palabra" << endl;
        cout << "\te. Buscar Prefijo" << endl;
        cout << "\tf. Ver Estadísticas" << endl;
        cout << "\tg. Salir" << endl << endl;

        cout << "Elije una opcion: ";

        cin >> tecla;

        switch(tecla)
        {
            case 'a':
                system("cls");
                cout << "Histograma\n";
                charList.graph();
                pause();
                break;

            case 'b':
                system("cls");
                cout << "Diccionario\n";
                wordList.print();
                pause();
                break;

            case 'c':
                system("cls");
                cout << "Diccionarion y posiciones\n";
                wordList.printPos();
                pause();
                break;

            case 'd':
                system("cls");
                cout << "Buscar palabra\n";
                cin.ignore();


                getline(cin,word);
                wordList.searchWord(word);

                pause();
                break;

            case 'e':
                system("cls");
                cout << "Buscar prefijo\n";
                cin.ignore();

                getline(cin,prefix);
                wordList.searchPrefix(prefix);

                pause();
                break;

            case 'f':
                system("cls");
                cout << "Estadisticas\n";

                cout << "Caracteres totales: " << charList.charTotal << endl;
                cout << "Delimitadores totales: " << wordList.delimCount << endl;
                cout << "Palabras totales: " << wordList.wordCount << endl;
                cout << "Palabras unicas totales: " << wordList.length << endl;
                cout << "Cantidad de comparaciones en diccionario: " << wordList.comparisionCount << endl;
                cout << "Tamaño de las estructuras: " << wordList.memSize() + charList.memSize() << " bytes" <<endl;
                cout << "Tamaño de los datos de entrada: " << fileSize << "bytes" << endl;
                cout << "Tiempo de ejecucion: " << execTime << endl;

                pause();
                break;

            case 'g':
            bandera=true;
            //exit(1);
            break;

            default:
                system("cls");
                cout << "Opcion no valida.\a\n";
                pause();
                break;
        }
    }while(!bandera);
}

void pause()
{
    cout << "Pulsa una tecla para continuar...";
    getwchar();
    getwchar();
}


#endif //PROYECTO_EDATOS_1_OPTIONMENU_H


