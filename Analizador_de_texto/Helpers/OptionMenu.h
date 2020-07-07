//
// Created by yordan-danilo on 6/7/20.
//

#ifndef PROYECTO_EDATOS_1_OPTIONMENU_H
#define PROYECTO_EDATOS_1_OPTIONMENU_H

#include <iostream>
using namespace std;


void pause();

void MostarMenu(){
    bool bandera=false;
    char tecla;

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
                cout << "Has elejido ...\n";     //brindará el Histograma de la parte A
                pause();
                break;

            case 'b':
                system("cls");
                cout << "Has elejido ...\n";
                pause();
                break;

            case 'c':
                system("cls");
                cout << "Has elejido ...\n";
                pause();
                break;

            case 'd':
                system("cls");
                cout << "Has elejido ...\n";
                pause();
                break;

            case 'e':
            system("cls");
            cout << "Has elejido ...\n";
            pause();
            break;

            case 'f':
                system("cls");
                cout << "Has elejido ...\n";
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


