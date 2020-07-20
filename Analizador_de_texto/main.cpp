#include <iostream>
#include <fstream>
#include <ctime>
#include "Helpers/OptionMenu.h"
#include "Helpers/StringUtils.h"
#include "Structures/CharList/CharList.h"
#include "Structures/WordList/WordList.h"
using namespace std;


int main() {


    //Parte final del main NO BORRAR//

    //ESTRUCTURAS//
    CharList charList;
    WordList wordList;

    //DELIMITERS//
    list<string> delimiters = {" ", ".", ",", "?", "!", "\n"};

    //TIME//
    unsigned t1 = 0;
    unsigned t2 = 0;
    double execTime = 0;

    //VARIABLES//
    unsigned long fileSize = 0;
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
        fileSize = sizeof(processFile);

        if(processFile.is_open()){

            char capitalization;
            string line;

            cout << "Desea procesar mayusculas? [y/n]" << endl;

            cin >> capitalization;

            if(tolower(capitalization) == 'y'){
                int lineNum = 1;
                t1 = clock();
                while(getline(processFile,line)){
                    //Se agrega el salto de linea porque getline() lo elimina
                    line += "\n";

                    // Se procesan las lineas del archivo para meterlas en las estrucuras
                    charList.insert(line);
                    wordList.insert(line, delimiters, lineNum);
                    lineNum++;

                }
                t2 = clock();
            }
            else if(tolower(capitalization) == 'n'){
                int lineNum = 1;
                t1 = clock();
                while(getline(processFile,line)){
                    //Se agrega el salto de linea porque getline() lo elimina
                    line += "\n";

                    // Se procesan las lineas del archivo para meterlas en las estrucuras
                    charList.insert(ToLowerString(line));
                    wordList.insert(line, delimiters, lineNum);
                    lineNum++;
                }
                t2 = clock();
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
        fileSize = stdInput.size()+1;

        char capitalization;
        cout << "Desea procesar las mayusculas? [y/n]" << endl;
        cin >> capitalization;

        if(tolower(capitalization) == 'y'){

            // Se procesan las lineas de la entrada para meterlas en las estrucuras
            t1 = clock();
            charList.insert(stdInput);
            wordList.insert(stdInput, delimiters, 1);
            t2 = clock();

        }
        else if (tolower(capitalization) == 'n'){

            // Se procesan las lineas de la entrada para meterlas en las estrucuras
            t1 = clock();
            charList.insert(ToLowerString(stdInput));
            wordList.insert(ToLowerString(stdInput), delimiters, 1);
            t2 = clock();

        }

    }
    else cout << "opcion no valida" << endl;

    execTime = (double (t2-t1)/CLOCKS_PER_SEC);






    MostarMenu(charList, wordList, execTime, fileSize);



    // Pruebas //
//    string prueba = "Hola. mi nombre és x? corne es mi referencia";
//
//
//    wordList.insert(prueba, delimiters, 1);
//    wordList.printPos();



    return 0;
}
