#include <iostream>
#include <fstream>
#include "Helpers/OptionMenu.h"
#include "Helpers/StringUtils.h"
#include "Structures/CharList/CharList.h"
#include "Structures/WordList/WordList.h"
using namespace std;


int main() {


    //Parte final del main NO BORRAR//

    //ESTRUCTURAS//

    //<WordList enlazada de caracteres (Punto A)>//
    CharList charList;
    WordList wordList;

    //DELIMITERS//
    list<string> delimiters = {" ", ".", ",", "?", "!", "\n"};


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
                int lineNum = 1;
                while(getline(processFile,line)){
                    //Se agrega el salto de linea porque getline() lo elimina
                    line += "\n";

                    // Se procesan las lineas del archivo para meterlas en las estrucuras
                    charList.insert(line);
                    wordList.insert(line, delimiters, lineNum);
                    lineNum++;

                }
            }
            else if(tolower(capitalization) == 'n'){
                int lineNum = 1;
                while(getline(processFile,line)){
                    //Se agrega el salto de linea porque getline() lo elimina
                    line += "\n";

                    // Se procesan las lineas del archivo para meterlas en las estrucuras
                    charList.insert(ToLowerString(line));
                    wordList.insert(line, delimiters, lineNum);
                    lineNum++;
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

    MostarMenu(charList, wordList);



    // Pruebas //
//    string prueba = "Hola. mi nombre és daniel? corne es mi referencia";
//
//
//    wordList.insert(prueba, delimiters, 1);
//    wordList.printPos();



    return 0;
}
