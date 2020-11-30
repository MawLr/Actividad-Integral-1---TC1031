// A01706212 Manolo Medina
// Integradora 5 Hashes

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "chain.h"

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

unsigned int myHash(const string s) {
	unsigned int acum = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		acum += (int) s[i];
	}
	return acum;
}


int main() {

    bool fileCheck = false;
    ifstream inFile;
    ofstream output;
    string fileName, line;
    string nLine [84] = { };
    string mes;
    string hashT;
    //Se crea vector de trabajo
    vector<int> tmpVec;
    vector<int> hashV;

    Chain <string, int> chain_hash(20, myHash);
    
    bool exit = false;
    while(exit == false){
        vector<vector <int>> data;
        int j = 0;
        int option;
        string addMes;
        int addLtemp;
        cout << "Selecciona una opción: "<< endl;
        cout << "Los valores con los que se trabaje deben de ser ENTEROS: "<< endl;
        cout << "(1) Leer archivo de Temperaturas"<< endl;
        cout << "(2) Leer Tabla Hash"<< endl;
        cout << "(3) Modificar datos Hash"<<endl;
        cout << "(4) Generar Archivo con tabla Hash" << endl;
        cout << "(5) Salir" << endl;
        cin>> option;
        if (option == 1){
          fileCheck = true;
        }
        switch(option){
            case 1:
                cout << "Introduzca ruta o nombre del archivo: "<< endl;
                cin >> fileName;
                inFile.open(fileName);
                while(getline(inFile, line)){
                    stringstream ss(line);
                    getline(ss, mes, ':');
                    for(int i = 0; i <= 6; i++){
                        int num = 0;
                        getline(ss, nLine[i], ',');
                        cout << nLine[i];
                        
                        num = stoi(nLine[i]);

                        chain_hash.put(mes, num);
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
                cout << chain_hash.toString() << endl;
                break;
            
            case 3:
            if (fileCheck == false){
              cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
              cout << '\n';
              break;
            }
                cout << "Ingrese mes que desee modificar: " << endl;
                cin >> addMes;
                cout << "Ingrese última temperatura registrada de dicho mes que desee modificar: " << endl;
                cin >> addLtemp;
                chain_hash.put(addMes, addLtemp);
                break;
                
            case 4:
            if (fileCheck == false){
              cout << "Se requiere un archivo para poder ejecutar esta opción" << endl;
              cout << '\n';
              break;
            }
                cout << "Generando bitacora de hash: " << endl;
                cout << '\n';
                output.open("hash.txt");
                if (output.is_open()){
                  output << chain_hash.toString();
                  cout << chain_hash.toString()<<endl;
                }
                output.close();
                break;
            
            case 5:
                cout << "FIN DE SESIÓN\n";
                exit = true;
            
        }
    }
    
}
