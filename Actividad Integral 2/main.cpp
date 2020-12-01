//
//  main.cpp
//  proyecto 1 tc1031
//
//  AVANCE 2:
//
//  Created by Manolo Medina on 9/16/20. A0170212
//  Copyright © 2020 Manolo Medina. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "sorts.h"
#include "list.h"

using namespace std;

// Funcion para desplegar los contenidos del vector

void displayV(vector <int> const &tmpVec){
    for(int i=0; i < tmpVec.size(); i++){
        cout << tmpVec.at(i) << ", ";
        if ((i == 6) || (i == 13) || (i == 20) || (i == 27)){
            cout << ' ' << endl;
        }
    }
}

int main() {

    //Se crea objeto sorts para trabajar con este
    Sorts<int> sorts;
    List<int> list;
    List<int> testList;
    string testAns;

    ifstream inFile;
    ofstream output;
    string fileName, line;
    string nLine [27] = { };
    string semana [4] = { };
    string mes;
    //Se crea vector de trabajo
    vector<int> tmpVec;
    bool fileCheck = false;
    bool testCheck = true;
    
    bool exit = false;
    while(exit == false){
        vector<vector <int>> data;
        int j = 0;
        int option;
        cout << "Selecciona una opción: "<< endl;
        cout << "(1) Leer archivo"<< endl;
        cout << "(2) Ordenar Datos"<< endl;
        cout << "(3) Buscar por rangos"<<endl;
        cout << "(4) Generar Archivo" << endl;
        cout << "(5) Modificar Lista" << endl;
        cout << "(6) Casos de Prueba" << endl;
        cout << "(7) Salir" << endl;
        cin>> option;
        if (option == 1){
          fileCheck = true;
        }
        switch(option){
            case 1:
                // Por el curioso caso de Xcode, se decidio permitir al usuario escribir el nombre del archivo
                // Aqui tambien se almacenan los datos leidos separados por comas y se meten a un array
                // despues ese array es convertido a integer y se llena el vector con estos datos con push_back
                cout << "Introduzca ruta o nombre del archivo: "<< endl;
                cin >> fileName;
                inFile.open(fileName);
                j = 0;
                while(getline(inFile, line)){
                    stringstream ss(line);
                    getline(ss, semana[j], ':');
                    j++;
                    getline(ss, mes, ':');
                    for(int i = 0; i <= 6; i++){
                        int num = 0;
                        getline(ss, nLine[i], ',');
                        cout << nLine[i];
                        
                        if ((i == 6) || (i == 13) || (i == 20) || (i == 27)){
                            cout << ' ' << endl;
                        }
                        num = stoi(nLine[i]);
                        tmpVec.push_back(num);
                        list.add(num); //Aquí se genera la lista con los datos del num, que recordemos es el array nLine convertido con stoi
                    }
                    
                }
                inFile.close();
                cout << "Success... "<<endl;
                cout << '\n';

                break;
                
            case 2:
                if (fileCheck == false){
                  cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
                  cout << '\n';
                  break;
                }
                // Ordenamiento y depsliegue de datos ordenados
                cout << "N. de Temperaturas: " << tmpVec.size()<< endl;
                sorts.ordenaBurbuja(tmpVec);
                displayV(tmpVec);
                cout << '\n';
                
                break;
            
            case 3:
                if (fileCheck == false){
                  cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
                  cout << '\n';
                  break;
                }
                // Busqueda por rangos, en este caso las temperaturas existentes en ese rango
                int inicio, fin;
                cout << "Rango Inicial: " << endl;
                cin >> inicio;
                inicio = sorts.busqBinaria(tmpVec, inicio);
                cout<< "Rango Final: " << endl;
                cin >> fin;
                fin = sorts.busqBinaria(tmpVec, fin);
                
                for (int i = inicio; i <= fin; i++) {
                    cout << tmpVec.at(i) << ", ";
                }
                cout << '\n';
                break;
                
            case 4:
                if (fileCheck == false){
                  cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
                  cout << '\n';
                  break;
                }
                // Almacenamiento de datos ordenados en archivo
                j = 0;
                cout << "Generando bitacora ordenada de temperaturas: " << endl;
                cout << '\n';
                output.open("orden.txt");
                if (output.is_open()){
                    output << "Bitacora ordenada de temperaturas: " << endl;
                    for (int i = 0; i < tmpVec.size(); i++){
                        output << tmpVec.at(i) << ", ";
                        cout << tmpVec.at(i) << ", ";
                        if ((i == 6) || (i == 13) || (i == 20) || (i == 27)){
                            output << ' ' << endl;
                            cout << ' ' << endl;
                        }
                    }
                }
                output.close();
                cout << '\n';
                cout << "Archivo Generado Exitosamente"<<endl;
                cout << '\n';
                break;
            
            case 5:
                // Todo el caso 5 está dedicado a la entrega integral 2, pues es el uso de listas ligadas,
                // recordemos que la lista fue generada con los datos que recibió del archivo al principo,
                // en éste menú están las operaciones que podemos hacer con la lista, igualmente debemos
                // recordar que la mayor ventaja de la lista ligada sobre el array es que al utilizar
                // apuntadores, no requiere de un valor limitante en su tamaño por lo que es mucho más
                // versatil
                if (fileCheck == false){
                  cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
                  cout << '\n';
                  break;
                }
                bool extOpt;
                extOpt = false;
                while(extOpt == false){
                    int opt;
                    int pos;
                    int val;
                    cout << "Seleccionar operación: " << endl;
                    cout << "(1) Añadir nuevo elemento" << endl;
                    cout << "(2) Actualizar elemento" << endl;
                    cout << "(3) Eliminar elemento" << endl;
                    cout << "(4) Desplegar lista" << endl;
                    cout << "(5) Buscar posición de valor" << endl;
                    cout << "(6) Generar archivo de lista" << endl;
                    cout << "(7) Regresar al menú" << endl;
                    cin >> opt;
                    
                    switch(opt){
                        case 1:
                            cout << "Ingrese valor que desea añadir: " << endl;
                            cin >> val;
                            list.add(val); // Método para añadir nuevos elementos
                            break;
                            
                        case 2:
                            cout << "Ingrese posición que desea modificar: " << endl;
                            cin >> pos;
                            cout << "Ingrese valor que desea modificar: " << endl;
                            cin >> val;
                            list.update(pos, val); // Método para modificar elementos existentes
                            break;
                        
                        case 3:
                            cout << "Ingrese posición del valor que desea eliminar: " << endl;
                            cin >> pos;
                            list.remove(pos); // Método para eliminar elementos
                            break;
                        
                        case 4:
                            cout << list.toString() << endl; // Método para desplegar
                            break;
                        
                        case 5:
                            cout << "Ingrese valor del que desea conocer la posición: " << endl;
                            cin >> val;
                            cout << "La posición del valor es: " << endl;
                            cout << list.find(val) << endl; // Método para encontrar la posición de un elemento  (ojo, en caso de repetición despliega el primero)
                            break;
                            
                        case 6:
                            // Generación de nuevo archivo esta vez con la lista de temperaturas, a diferencia del del vector ordenado
                            
                            cout << "Generando bitacora de lista de temperaturas: " << endl;
                            cout << '\n';
                            output.open("lista.txt");
                            if (output.is_open()){
                                output << list.toString();
                                cout << list.toString()<<endl;
                            }
                            output.close();
                            break;
                            
                        case 7:
                            extOpt = true;
                            break;
                    }
                }
                break;

            case 6:
            if (testCheck == false){
                  cout << "Los casos de prueba ya fueron ejecutados, correrlos de nuevo causarían sesgo" << endl;
                  cout << '\n';
                  break;
                }
              testList.add(5);
              testAns = "[5]";
              cout << " 1 " <<	(!testAns.compare(testList.toString()) ? "success\n" : "fail\n");

              testList.add(7);
              testList.add(14);
              testList.add(21);
              testAns = "[5, 7, 14, 21]";
              cout << " 2 " <<	(!testAns.compare(testList.toString()) ? "success\n" : "fail\n");

              cout << " 3 " <<	(3 == testList.find(21) ? "success\n" : "fail\n");

              cout << " 4 " <<	(-1 == testList.find(1) ? "success\n" : "fail\n");

              testList.update(0, 3);
              testAns = "[3, 7, 14, 21]";
              cout << " 5 " <<	(!testAns.compare(testList.toString()) ? "success\n" : "fail\n");

              testList.remove(2);
              testAns = "[3, 7, 21]";
              cout << " 6 " <<	(!testAns.compare(testList.toString()) ? "success\n" : "fail\n");
              testCheck = false;
              break;

            case 7:
                cout << "FIN DE SESIÓN\n";
                exit = true;
            
        }
    }
    
}
