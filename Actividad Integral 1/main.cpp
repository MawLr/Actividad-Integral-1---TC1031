//
//  main.cpp
//  proyecto 1 tc1031
//
//  Created by Manolo Medina on 9/16/20.
//  Copyright © 2020 Manolo Medina. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "sorts.h"

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
    
    ifstream inFile;
    ofstream output;
    string fileName, line;
    string nLine [27] = { };
    string semana [4] = { };
    string mes;
    //Se crea vector de trabajo
    vector<int> tmpVec;
    
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
        cout << "(5) Salir" << endl;
        cin>> option;
        
        switch(option){
            case 1:
                // Por el curioso caso de Xcode, se decidio permitir al usuario escrivir el nombre del archivo
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
                        
                    }
                    
                }
                inFile.close();
                cout << "Success... "<<endl;
                cout << '\n';

                break;
                
            case 2:
                // Ordenamiento y depsliegue de datos ordenados
                cout << "N. de Temperaturas: " << tmpVec.size()<< endl;
                sorts.ordenaBurbuja(tmpVec);
                displayV(tmpVec);
                cout << '\n';
                
                break;
            
            case 3:
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
                cout << "FIN DE SESIÓN\n";
                exit = true;
            
        }
    }
    
}
