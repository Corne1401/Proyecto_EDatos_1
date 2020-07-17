#include <iostream>
#include <fstream>
#include "Helpers/StringUtils.h"
#include "Helpers/OptionMenu.h"
#include "Structures/CharList/CharList.h"
#include "Structures/Lista/DoublyList.h"
using namespace std;


int main() {


    //Parte final del main NO BORRAR//

    //ESTRUCTURAS//

    //<Lista enlazada de caracteres (Punto A)>//
    CharList charList;


    int comparaciones = 0;

    //MENU//
    char opcion;
    cout << "a. Leer archivo" << endl;
    cout << "b. Introducir texto" << endl;

    cin >> opcion;

    if(tolower(opcion) == 'a'){

        string fileName;
        cout << "Escriba el nombre del archivo a procesar" << endl;
        cin >> fileName;
        ifstream processFile("../InputFile/"+fileName+".txt");

        if(processFile.is_open()){

            char capitalization;
            string line;

            cout << "Desea procesar mayusculas? [y/n]" << endl;

            cin >> capitalization;

            if(tolower(capitalization) == 'y'){
                while(getline(processFile,line)){
                    //Se agrega el salto de linea porque getline() lo elimina
                    line += "\n";

                    // Se procesan las lineas del archivo para meterlas en las estrucuras
                    charList.insert(line);

                }
            }
            else if(tolower(capitalization) == 'n'){
                while(getline(processFile,line)){
                    //Se agrega el salto de linea porque getline() lo elimina
                    line += "\n";

                    // Se procesan las lineas del archivo para meterlas en las estrucuras
                    charList.insert(ToLowerString(line));

                }
            }
            else cout << "Opcion no valida" << endl;

        }
        else cout << "Archivo no encontrado" << endl;

    }
    else if(tolower(opcion) == 'b'){
        // codigo de introduccion de datos por stdin
        cin.ignore();

        string stdInput;
        cout << "Ingrese el texto que desea procesar" << endl;
        getline(cin, stdInput);

        char capitalization;
        cout << "Desea procesar las mayusculas? [y/n]" << endl;
        cin >> capitalization;

        if(tolower(capitalization) == 'y'){

            // Se procesan las lineas de la entrada para meterlas en las estrucuras
            charList.insert(stdInput);

        }
        else if (tolower(capitalization) == 'n'){

            // Se procesan las lineas de la entrada para meterlas en las estrucuras
            charList.insert(ToLowerString(stdInput));

        }

    }
    else cout << "opcion no valida" << endl;

    MostarMenu(charList);



    // Pruebas //



    return 0;
}
