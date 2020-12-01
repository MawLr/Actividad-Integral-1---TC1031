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
#include <cstring>
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

template <class T>
string arrayToString(const vector<T> &v) {
	stringstream aux;

	aux << "[" << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << ", " << v[i];
	}
	aux << "]";
	return aux.str();
}

int main() {

    //Se crea objeto sorts para trabajar con este
    Sorts<int> sorts;
    Sorts<int> testsorts;
    int tArray[] = {21, 78, 37, 26, 99, 77, 55, 52, 23, 14};
    vector<int> original1 (tArray, tArray + sizeof(tArray) / sizeof(int) ); 
    string ans = "[14, 21, 23, 26, 37, 52, 55, 77, 78, 99]";
    vector<int> prueba;

    bool fileCheck = false;
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
        cout << "(5) Casos de Prueba" << endl;
        cout << "(6) Salir" << endl;
        cin>> option;
        if (option == 1){
          fileCheck = true;
        }
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
              prueba = original1;
              testsorts.ordenaSeleccion(prueba);

              cout << " 1 " <<	(!ans.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

              prueba = original1;
              testsorts.ordenaBurbuja(prueba);

              cout << " 2 " <<	(!ans.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

              prueba = original1;
              testsorts.ordenaMerge(prueba);

              cout << " 3 " <<	(!ans.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

              cout << " 4 " <<	(-1 == testsorts.busqSecuencial(prueba, 100) ? "success\n" : "fail\n");

              cout << " 5 " <<	(1 == testsorts.busqBinaria(prueba, 21) ? "success\n" : "fail\n");

              break;
            case 6:
                cout << "FIN DE SESIÓN\n";
                exit = true;
            
        }
    }
    
}
