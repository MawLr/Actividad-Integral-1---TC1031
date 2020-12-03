//
//  main.cpp
//  proyecto 1 tc1031
//
//  AVANCE 6
//  Created by Manolo Medina on 2/12/20.
//  Copyright © 2020 Manolo Medina. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include "bucketsort.h"

using namespace std;

// Funcion para desplegar los contenidos del vector

void displayV(vector <float> const &tmpVec){
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
    // todo esto es de pruebas
    float tArray[] = {0.651, 0.555, 0.237, 0.997, 0.886};
    float tArray2[] = {0.887, 0.221, 0.543, 0.906, 0.023};
    float tArray3[] = {0.334, 0.112, 0.678, 0.542, 0.443};
    float tArray4[] = {0.655, 0.778, 0.235, 0.364, 0.110};

    string ans = "[0.237, 0.555, 0.651, 0.886, 0.997]";
    string ans2 = "[0.023, 0.221, 0.543, 0.887, 0.906]";
    string ans3 = "[0.112, 0.334, 0.443, 0.542, 0.678]";
    string ans4 = "[0.11, 0.235, 0.364, 0.655, 0.778]";
    vector<float> prueba;
    vector<float> prueba2;
    vector<float> prueba3;
    vector<float> prueba4;
    // aquí termina lo de pruebas

    bool fileCheck = false;
    bool testCheck = true;
    bool bucketCheck = false;

    ifstream inFile;
    ofstream output;
    string fileName, line;
    string bucket [4] = {};
    
    // para pruebas
    int t1 = 0; 
    int t2 = 0; 
    int t3 = 0;
    int t4 = 0;
    
    //Se crea vector de trabajo temporal
    vector<float> tmpVec;
    vector<float> fileVec;
    
    bool exit = false;
    while(exit == false){
        vector<vector <int>> data;
        int n = 0;
        
        int option;
        float sortedb[tmpVec.size()];
        cout << "Selecciona una opción: "<< endl;
        cout << "(1) Leer archivo de miligrajes"<< endl;
        cout << "(2) Ordenar miligrajes"<< endl;
        cout << "(3) Generar Archivo" << endl;
        cout << "(4) Casos de Prueba" << endl;
        cout << "(5) Salir" << endl;
        cin>> option;
        if (option == 1){
          fileCheck = true;
        }
        if (option == 2){
          bucketCheck = true;
        }
        switch(option){
            case 1:
                // Aquí se lee el archivo, se almacenan los datos en un arreglo que después pasa los datos convertidos a string con la función stof() a un vector temporal.
                cout << "Introduzca ruta o nombre del archivo: "<< endl;
                cin >> fileName;
                inFile.open(fileName);
                while(getline(inFile, line)){
                    stringstream ss(line);
                    for(int i = 0; i <= 4; i++){
                        int n = 0;
                        float buc = 0;
                        getline(ss, bucket[i], ',');
                        cout << bucket[i];
                        
                        buc = stof(bucket[i]);
                        tmpVec.push_back(buc); // <-- vector temporal
                    }
                    
                }
                inFile.close();
                cout << '\n';
                cout << "Success... "<<endl;
                cout << '\n';

                break;
                
            case 2:
                if (fileCheck == false){
                  cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
                  cout << '\n';
                  break;
                }
                // del vector temporal con nuestros datos leídos del archivo se pasan a un arreglo para poder hacer el sorting
                n = tmpVec.size();
                copy(tmpVec.begin(), tmpVec.end(), sortedb); // <-- arreglo copia del vector temporal
                bucketSort(sortedb, n); // <-- se hace el sorting con ese arreglo, como va a ser igual que el vector, n se saca con el tamaño del vector

                // Ordenamiento y depsliegue de datos ordenados
                cout << "Array acomodado: " << endl; 
                for (int i = 0; i < n; i++){
                  cout << sortedb[i] << " "; 
                  fileVec.push_back(sortedb[i]);
                }
                cout << '\n';   
                break;
            
            case 3:
                // Generación del archivo
                if (fileCheck == false){
                  cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
                  cout << '\n';
                  break;
                }
                if (bucketCheck == false){
                  cout << "Se requiere que primero se haga sorting" << endl;
                  cout << '\n';
                  break;
                }
                cout << "Generando bitacora ordenada de BUCKET: " << endl;
                cout << '\n';
                output.open("BUCKET.txt");
                if (output.is_open()){
                    output << "Bitacora ordenada de BUCKET: " << endl;
                    for (int i = 0; i < fileVec.size(); i++){
                        output << fileVec.at(i) << ", ";
                        cout << fileVec.at(i) << ", ";
                    }
                }
                output.close();
                cout << '\n';
                cout << "Archivo Generado Exitosamente"<<endl;
                cout << '\n';
                break;
                
            case 4:
              if (testCheck == false){
                  cout << "Los casos de prueba ya fueron ejecutados, correrlos de nuevo causarían sesgo" << endl;
                  cout << '\n';
                  break;
                };
              t1 = sizeof(tArray) / sizeof(tArray[0]); 
              
              bucketSort(tArray, t1);              
              for (int i = 0; i < t1; i++){
                  //cout << tArray[i] << " ";
                  prueba.push_back(tArray[i]);
                  //displayV(prueba);
                };

              cout << " 1 " <<	(!ans.compare(arrayToString(prueba)) ? "success\n" : "fail\n");

              t2 = sizeof(tArray2) / sizeof (tArray2[0]);

              bucketSort(tArray2, t2);
              for (int i = 0; i < t2; i++){
                  //cout << tArray2[i] << " ";
                  prueba2.push_back(tArray2[i]);
                  //displayV(prueba2);
              };

              cout << " 2 " <<	(!ans2.compare(arrayToString(prueba2)) ? "success\n" : "fail\n");

              t3 = sizeof(tArray3) / sizeof (tArray3[0]);
              
              bucketSort(tArray3, t3);
              for (int i = 0; i < t3; i++){
                  //cout << tArray3[i] << " ";
                  prueba3.push_back(tArray3[i]);
                  //displayV(prueba3);
              };

              cout << " 3 " <<	(!ans3.compare(arrayToString(prueba3)) ? "success\n" : "fail\n");

              t4 = sizeof(tArray4) / sizeof (tArray4[0]);
              
              bucketSort(tArray4, t4);
              for (int i = 0; i < t4; i++){
                  //cout << tArray4[i] << " ";
                  prueba4.push_back(tArray4[i]);
                  //displayV(prueba4);
              };

              cout << " 4 " <<	(!ans4.compare(arrayToString(prueba4)) ? "success\n" : "fail\n");
              testCheck = false;

              break;
            case 5:
                cout << "FIN DE SESIÓN\n";
                exit = true;
            
        }
    }
    
}
